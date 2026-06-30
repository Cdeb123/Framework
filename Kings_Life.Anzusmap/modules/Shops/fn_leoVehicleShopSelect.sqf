#include "..\..\script_macros.hpp"
/*
    File: fn_leoVehicleShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8800;
if (isNull _display) exitWith {};
if ((lbCurSel 8804) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","cop_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "LawEnforcement" >> _shop;
private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "tcsd";};
private _context = missionNamespace getVariable ["life_vehicle_shop_context",[_shop,"","cop",false]];
_context params ["_contextShop","_spawnPoints","_shopFlag","_disableBuy"];

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
private _price = if (_priceOverride >= 0) then {
    _basePrice
} else {
    round (_basePrice * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP"))
};

private _conditionOk = [_condition] call life_fnc_levelCheck;
private _rankOk = (_rank isEqualTo "") || {[_rank,_department] call life_fnc_leoAtLeastRank};
private _subdivisionOk = (count _subdivisions) isEqualTo 0;
if !(_subdivisionOk) then {
    {
        if ([_x,_department] call life_fnc_leoHasSubdivision) exitWith {_subdivisionOk = true;};
    } forEach _subdivisions;
};
private _access = _conditionOk && {_rankOk} && {_subdivisionOk};

private _featureText = "";
{
    _featureText = _featureText + format ["<br/>- %1",_x];
} forEach _features;
if (_featureText isEqualTo "") then {_featureText = "<br/>- Standard TCSD configuration";};

private _trunkSpace = [_className] call life_fnc_vehicleWeightCfg;
private _funds = missionNamespace getVariable ["life_faction_bank_law_enforcement",0];

(_display displayCtrl 8806) ctrlSetText _picture;
(_display displayCtrl 8805) ctrlSetStructuredText parseText format [
    "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Category</t><br/>%2<br/><br/><t color='#7dcbd0'>Purchase</t><br/>$%3<br/><t color='#7dcbd0'>TCSD Bank</t> $%4<br/><t color='#7dcbd0'>Personal Bank</t> $%5<br/><br/><t color='#7dcbd0'>Access</t><br/>%6<br/><br/><t color='#7dcbd0'>Features</t>%7<br/><br/><t color='#7dcbd0'>Specs</t><br/>%8 km/h | %9 seats | trunk %10 | armor %11 | fuel %12",
    _displayName,
    _categoryTitle,
    [_price] call life_fnc_numberText,
    [_funds] call life_fnc_numberText,
    [BANK] call life_fnc_numberText,
    ["Locked", "Available"] select _access,
    _featureText,
    _speed,
    _seats,
    if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
    _armor,
    _fuel
];

lbClear 8808;
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
        private _idx = lbAdd [8808,_textureName];
        lbSetValue [8808,_idx,_forEachIndex];
    };
} forEach _colorArray;
if ((lbSize 8808) isEqualTo 0) then {
    private _idx = lbAdd [8808,"Default"];
    lbSetValue [8808,_idx,0];
};
lbSetCurSel [8808,0];

(_display displayCtrl 8807) ctrlEnable (_access && {!_disableBuy});
