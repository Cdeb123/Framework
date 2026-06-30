#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 9000;
if (isNull _display) exitWith {};
if ((lbCurSel 9004) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","civ_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "Civilian" >> _shop;
private _context = missionNamespace getVariable ["life_vehicle_shop_context",[_shop,"","civ",false]];
_context params ["_contextShop","_spawnPoints","_shopFlag","_disableBuy"];

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

private _vehInfo = [_className] call life_fnc_fetchVehInfo;
private _picture = "";
private _speed = 0;
private _armor = 0;
private _seats = 0;
private _fuel = 0;
private _hp = 0;
if !(_vehInfo isEqualTo []) then {
    if (_displayName isEqualTo "") then {_displayName = _vehInfo select 3;};
    _picture = _vehInfo select 2;
    _speed = _vehInfo select 8;
    _armor = _vehInfo select 9;
    _seats = _vehInfo select 10;
    _hp = _vehInfo select 11;
    _fuel = _vehInfo select 12;
};
if (_displayName isEqualTo "") then {_displayName = _className;};
if (_text isEqualTo "") then {_text = "No description is available for this vehicle.";};

private _basePrice = if (_priceOverride >= 0) then {
    _priceOverride
} else {
    getNumber (missionConfigFile >> "LifeCfgVehicles" >> _className >> "price")
};
private _buyPrice = if (_priceOverride >= 0) then {_basePrice} else {round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN"))};
private _rentPrice = round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_CIVILIAN"));
if (_basePrice < 0) then {_buyPrice = -1; _rentPrice = -1;};

private _vehicleCondition = getText (missionConfigFile >> "LifeCfgVehicles" >> _className >> "conditions");
private _access = [_condition] call life_fnc_levelCheck;
private _licensed = [_vehicleCondition] call life_fnc_levelCheck;
private _rentEnabled = (getNumber (_shopCfg >> "allowRent")) isEqualTo 1;
private _storeEnabled = (getNumber (_shopCfg >> "allowStore")) isEqualTo 1;
private _returnEnabled = (getNumber (_shopCfg >> "allowReturn")) isEqualTo 1;

private _featureText = "";
{
    _featureText = _featureText + format ["<br/>- %1",_x];
} forEach _features;
if (_featureText isEqualTo "") then {_featureText = "<br/>- Standard civilian configuration";};

private _trunkSpace = [_className] call life_fnc_vehicleWeightCfg;
[_className] call life_fnc_3dPreviewDisplay;

(_display displayCtrl 9006) ctrlSetText _picture;
(_display displayCtrl 9005) ctrlSetStructuredText parseText format [
    "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Category</t><br/>%2<br/><br/><t color='#7dcbd0'>Purchase</t> $%3 | <t color='#7dcbd0'>Rent</t> $%4<br/><t color='#7dcbd0'>Cash</t> $%5<br/><br/><t color='#7dcbd0'>Access</t><br/>%6<br/><br/><t color='#7dcbd0'>Features</t>%7<br/><br/><t color='#7dcbd0'>Specs</t><br/>%8 km/h | %9 seats | trunk %10 | armor %11 | fuel %12",
    _displayName,
    _categoryTitle,
    [(_buyPrice max 0)] call life_fnc_numberText,
    [(_rentPrice max 0)] call life_fnc_numberText,
    [CASH] call life_fnc_numberText,
    ["Locked",["License required","Available"] select _licensed] select _access,
    _featureText,
    _speed,
    _seats,
    if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
    _armor,
    _fuel
];

lbClear 9008;
private _classNameLife = _className;
if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {_classNameLife = "Default";};
private _colorArray = getArray (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife >> "textures");
{
    _x params [
        ["_textureName","",[""]],
        ["_flag","",[""]],
        ["_textures",[],[[]]],
        ["_textureCondition","",[""]]
    ];
    if ((_shopFlag isEqualTo "" || {_shopFlag isEqualTo _flag}) && {[_textureCondition] call life_fnc_levelCheck}) then {
        private _idx = lbAdd [9008,_textureName];
        lbSetValue [9008,_idx,_forEachIndex];
    };
} forEach _colorArray;
if ((lbSize 9008) isEqualTo 0) then {
    private _idx = lbAdd [9008,"Default"];
    lbSetValue [9008,_idx,0];
};
lbSetCurSel [9008,0];

private _canBuy = _access && {_licensed} && {!_disableBuy} && {_buyPrice >= 0};
(_display displayCtrl 9007) ctrlEnable _canBuy;
(_display displayCtrl 9009) ctrlEnable (_canBuy && {_rentEnabled} && {_rentPrice >= 0});
(_display displayCtrl 9010) ctrlEnable _returnEnabled;
(_display displayCtrl 9011) ctrlEnable _storeEnabled;
