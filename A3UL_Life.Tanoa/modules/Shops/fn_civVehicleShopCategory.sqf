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

private _addedVehicleClasses = [];
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
    if (_className in _addedVehicleClasses) exitWith {};
    _addedVehicleClasses pushBack _className;
    private _vehInfo = [_className] call life_fnc_fetchVehInfo;
    if (_displayName isEqualTo "" && {!(_vehInfo isEqualTo [])}) then {_displayName = _vehInfo select 3;};
    if (_displayName isEqualTo "") then {_displayName = _className;};
    private _access = [_condition] call life_fnc_levelCheck;
    private _idx = lbAdd [9004,_displayName];
    lbSetData [9004,_idx,str [_className,_displayName,_priceOverride,_condition,_text,_features,_categoryTitle]];
    lbSetColor [9004,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
};

private _categoryTitle = getText (_categoryCfg >> "title");
private _categoryDescription = getText (_categoryCfg >> "description");
private _categoryFeatures = getArray (_categoryCfg >> "features");
private _legacyVehicles = getText (_categoryCfg >> "legacyVehicles");
if !(_legacyVehicles isEqualTo "") then {
    {
        _x params [
            ["_className","",[""]],
            ["_condition","",[""]]
        ];
        [_className,"",-1,_condition,_categoryDescription,_categoryFeatures,_categoryTitle] call _addVehicle;
    } forEach getArray (missionConfigFile >> "CarShops" >> _legacyVehicles >> "vehicles");
};

{
    private _entryPrice = if (isNumber (_x >> "price")) then {getNumber (_x >> "price")} else {-1};
    private _entryText = getText (_x >> "text");
    if (_entryText isEqualTo "") then {_entryText = _categoryDescription;};
    private _entryFeatures = getArray (_x >> "features");
    if (_entryFeatures isEqualTo []) then {_entryFeatures = _categoryFeatures;};
    [
        getText (_x >> "className"),
        getText (_x >> "displayName"),
        _entryPrice,
        getText (_x >> "condition"),
        _entryText,
        _entryFeatures,
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
