#include "..\..\script_macros.hpp"
/*
    File: fn_leoVehicleShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8804) < 0) exitWith {hint localize "STR_Shop_Veh_DidntPick";};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};
life_action_delay = time;

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","cop_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "LawEnforcement" >> _shop;
private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "kcso";};
private _context = missionNamespace getVariable ["life_vehicle_shop_context",[_shop,"","cop",false]];
_context params ["_contextShop","_spawnPoints","_shopFlag","_disableBuy"];
if (_disableBuy) exitWith {};

private _data = call compile (lbData [8804,lbCurSel 8804]);
_data params [
    ["_className","",[""]],
    ["_displayName","",[""]],
    ["_priceOverride",-1,[0]],
    ["_condition","",[""]],
    ["_rank","",[""]],
    ["_subdivisions",[],[[]]],
    ["_text","",[""]],
    ["_features",[],[[]]],
    ["_categoryTitle","",[""]]
];

private _shopCondition = getText (_shopCfg >> "condition");
if !([_shopCondition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _cert = getText (_shopCfg >> "requiredCertification");
private _missingCert = false;
if !(_cert isEqualTo "") then {
    _missingCert = !(missionNamespace getVariable [format ["license_cop_%1",_cert],false]);
};
if (_missingCert) exitWith {hint "You need the required KCSO certification before buying this vehicle.";};

private _conditionOk = [_condition] call life_fnc_levelCheck;
private _rankOk = (_rank isEqualTo "") || {[_rank,_department] call life_fnc_leoAtLeastRank};
private _subdivisionOk = (count _subdivisions) isEqualTo 0;
if !(_subdivisionOk) then {
    {
        if ([_x,_department] call life_fnc_leoHasSubdivision) exitWith {_subdivisionOk = true;};
    } forEach _subdivisions;
};
if !(_conditionOk && {_rankOk} && {_subdivisionOk}) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _basePrice = if (_priceOverride >= 0) then {
    _priceOverride
} else {
    getNumber (missionConfigFile >> "LifeCfgVehicles" >> _className >> "price")
};
private _purchasePrice = if (_priceOverride >= 0) then {
    _basePrice
} else {
    round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP"))
};
if (_purchasePrice < 0) exitWith {closeDialog 0;};

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

private _paymentSource = "";
private _useFaction = (getNumber (_shopCfg >> "useFactionBank")) isEqualTo 1;
if (_useFaction) then {
    private _funds = missionNamespace getVariable ["life_faction_bank_law_enforcement",0];
    if (_funds >= _purchasePrice) then {
        missionNamespace setVariable ["life_faction_bank_law_enforcement",_funds - _purchasePrice,true];
        publicVariable "life_faction_bank_law_enforcement";
        _paymentSource = "KCSO bank";
    };
};
if (_paymentSource isEqualTo "") then {
    if (BANK < _purchasePrice) exitWith {
        hint format [localize "STR_Shop_Veh_NotEnough",[_purchasePrice - BANK] call life_fnc_numberText];
        closeDialog 0;
    };
    BANK = BANK - _purchasePrice;
    [1] call SOCK_fnc_updatePartial;
    _paymentSource = "personal bank";
};

if (_paymentSource isEqualTo "") exitWith {};

private _colorIndex = 0;
if ((lbCurSel 8808) >= 0) then {_colorIndex = lbValue [8808,lbCurSel 8808];};

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
_vehicle setVariable ["characterUID",missionNamespace getVariable ["life_character_uid",getPlayerUID player],true];
_vehicle setVariable ["vehicleSide","cop",true];
_vehicle disableTIEquipment true;
[_vehicle,"cop_offroad",true] spawn life_fnc_vehicleAnimate;
_vehicle allowDamage true;

life_vehicles pushBack _vehicle;
[getPlayerUID player,playerSide,_vehicle,1] remoteExecCall ["TON_fnc_keyManagement",RSERV];

if !(_className in LIFE_SETTINGS(getArray,"vehicleShop_rentalOnly")) then {
    if (life_HC_isActive) then {
        [(getPlayerUID player),playerSide,_vehicle,_colorIndex,missionNamespace getVariable ["life_character_uid",getPlayerUID player]] remoteExecCall ["HC_fnc_vehicleCreate",HC_Life];
    } else {
        [(getPlayerUID player),playerSide,_vehicle,_colorIndex,missionNamespace getVariable ["life_character_uid",getPlayerUID player]] remoteExecCall ["TON_fnc_vehicleCreate",RSERV];
    };
};

hint format [
    "Purchased %1 for $%2 using the %3.",
    getText (configFile >> "CfgVehicles" >> _className >> "displayName"),
    [_purchasePrice] call life_fnc_numberText,
    _paymentSource
];

closeDialog 0;
true;
