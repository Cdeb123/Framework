#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopCategory.sqf
*/
disableSerialization;
private _display = findDisplay 9000;
if (isNull _display) exitWith {};
if ((lbCurSel 9003) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","civ_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "Civilian" >> _shop;
private _category = lbData [9003,lbCurSel 9003];
private _categoryCfg = _shopCfg >> "Categories" >> _category;

lbClear 9004;
lbClear 9008;
life_vehicle_shop_items = [];
(_display displayCtrl 9006) ctrlSetText "";
(_display displayCtrl 9007) ctrlEnable false;
(_display displayCtrl 9009) ctrlEnable false;

private _addVehicle = {
    params [
        ["_className","",[""]],
        ["_displayName","",[""]],
        ["_priceOverride",-1,[0]],
        ["_condition","",[""]],
        ["_text","",[""]],
        ["_features",[],[[]]],
        ["_categoryTitle","",[""]]
    ];
    if (_className isEqualTo "") exitWith {};
    private _vehInfo = [_className] call life_fnc_fetchVehInfo;
    if (_displayName isEqualTo "" && {!(_vehInfo isEqualTo [])}) then {_displayName = _vehInfo select 3;};
    if (_displayName isEqualTo "") then {_displayName = _className;};
    private _access = [_condition] call life_fnc_levelCheck;
    private _idx = lbAdd [9004,_displayName];
    lbSetData [9004,_idx,str [_className,_displayName,_priceOverride,_condition,_text,_features,_categoryTitle]];
    lbSetColor [9004,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
};

private _categoryTitle = getText (_categoryCfg >> "title");
private _legacyVehicles = getText (_categoryCfg >> "legacyVehicles");
if !(_legacyVehicles isEqualTo "") then {
    {
        _x params [
            ["_className","",[""]],
            ["_condition","",[""]]
        ];
        [_className,"",-1,_condition,getText (_categoryCfg >> "description"),getArray (_categoryCfg >> "features"),_categoryTitle] call _addVehicle;
    } forEach getArray (missionConfigFile >> "CarShops" >> _legacyVehicles >> "vehicles");
};

{
    [
        getText (_x >> "className"),
        getText (_x >> "displayName"),
        getNumber (_x >> "price"),
        getText (_x >> "condition"),
        getText (_x >> "text"),
        getArray (_x >> "features"),
        _categoryTitle
    ] call _addVehicle;
} forEach ("true" configClasses (_categoryCfg >> "Vehicles"));

if ((lbSize 9004) > 0) then {
    lbSetCurSel [9004,0];
} else {
    (_display displayCtrl 9005) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No vehicles are configured under %1.</t>",
        _categoryTitle
    ];
};
