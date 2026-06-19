#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopBuy.sqf
*/
disableSerialization;
params [
    ["_mode",true,[true]]
];

if ((lbCurSel 9004) < 0) exitWith {hint localize "STR_Shop_Veh_DidntPick";};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};
life_action_delay = time;

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","civ_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "Civilian" >> _shop;
private _context = missionNamespace getVariable ["life_vehicle_shop_context",[_shop,"","civ",false]];
_context params ["_contextShop","_spawnPoints","_shopFlag","_disableBuy"];
if (_disableBuy) exitWith {};

private _data = call compile (lbData [9004,lbCurSel 9004]);
_data params [
    ["_className","",[""]],
    ["_displayName","",[""]],
    ["_priceOverride",-1,[0]],
    ["_condition","",[""]],
    ["_text","",[""]],
    ["_features",[],[[]]],
    ["_categoryTitle","",[""]]
];

private _shopCondition = getText (_shopCfg >> "condition");
if !([_shopCondition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};
if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};
private _vehicleCondition = getText (missionConfigFile >> "LifeCfgVehicles" >> _className >> "conditions");
if !([_vehicleCondition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NoLicense";};

private _basePrice = if (_priceOverride >= 0) then {
    _priceOverride
} else {
    getNumber (missionConfigFile >> "LifeCfgVehicles" >> _className >> "price")
};
if (_basePrice < 0) exitWith {closeDialog 0;};

private _purchasePrice = -1;
if (_mode) then {
    _purchasePrice = if (_priceOverride >= 0) then {_basePrice} else {round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN"))};
} else {
    if ((getNumber (_shopCfg >> "allowRent")) isEqualTo 1) then {
        _purchasePrice = round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_CIVILIAN"));
    };
};
if (_purchasePrice < 0) exitWith {hint "Rentals are not available at this shop.";};
if (CASH < _purchasePrice) exitWith {hint format [localize "STR_Shop_Veh_NotEnough",[_purchasePrice - CASH] call life_fnc_numberText]; closeDialog 0;};

private _spawnPoint = "";
if (_spawnPoints isEqualType []) then {
    {
        if ((nearestObjects [(getMarkerPos _x),["Car","Ship","Air"],5]) isEqualTo []) exitWith {_spawnPoint = _x;};
        true
    } count _spawnPoints;
} else {
    if !(_spawnPoints isEqualTo "") then {
        if ((nearestObjects [(getMarkerPos _spawnPoints),["Car","Ship","Air"],5]) isEqualTo []) then {_spawnPoint = _spawnPoints;};
    };
};
if (_spawnPoint isEqualTo "") exitWith {hint localize "STR_Shop_Veh_Block"; closeDialog 0;};

private _colorIndex = 0;
if ((lbCurSel 9008) >= 0) then {_colorIndex = lbValue [9008,lbCurSel 9008];};

CASH = CASH - _purchasePrice;
[0] call SOCK_fnc_updatePartial;

private _vehicle = createVehicle [_className,(getMarkerPos _spawnPoint),[],0,"NONE"];
waitUntil {!isNil "_vehicle" && {!isNull _vehicle}};
_vehicle allowDamage false;
_vehicle setPos (getMarkerPos _spawnPoint);
_vehicle setVectorUp (surfaceNormal (getMarkerPos _spawnPoint));
_vehicle setDir (markerDir _spawnPoint);
_vehicle lock 2;

[_vehicle,_colorIndex] call life_fnc_colorVehicle;
[_vehicle] call life_fnc_clearVehicleAmmo;

_vehicle setVariable ["trunk_in_use",false,true];
_vehicle setVariable ["vehicle_info_owners",[[getPlayerUID player,profileName]],true];
_vehicle setVariable ["life_vehicle_rental",!_mode,true];
_vehicle setVariable ["characterUID",missionNamespace getVariable ["life_character_uid",getPlayerUID player],true];
_vehicle setVariable ["vehicleSide","civ",true];
_vehicle disableTIEquipment true;

if (_shopFlag isEqualTo "civ" && {_className == "B_Heli_Light_01_F"}) then {
    [_vehicle,"civ_littlebird",true] spawn life_fnc_vehicleAnimate;
};

_vehicle allowDamage true;
life_vehicles pushBack _vehicle;
[getPlayerUID player,playerSide,_vehicle,1] remoteExecCall ["TON_fnc_keyManagement",RSERV];

if (_mode) then {
    if !(_className in LIFE_SETTINGS(getArray,"vehicleShop_rentalOnly")) then {
        if (life_HC_isActive) then {
            [(getPlayerUID player),playerSide,_vehicle,_colorIndex,missionNamespace getVariable ["life_character_uid",getPlayerUID player]] remoteExecCall ["HC_fnc_vehicleCreate",HC_Life];
        } else {
            [(getPlayerUID player),playerSide,_vehicle,_colorIndex,missionNamespace getVariable ["life_character_uid",getPlayerUID player]] remoteExecCall ["TON_fnc_vehicleCreate",RSERV];
        };
    };
};

hint format [
    ["Rented %1 for $%2.","Purchased %1 for $%2."] select _mode,
    getText (configFile >> "CfgVehicles" >> _className >> "displayName"),
    [_purchasePrice] call life_fnc_numberText
];

closeDialog 0;
true;
