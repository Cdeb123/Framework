#include "..\..\script_macros.hpp"
/*
    File: fn_leoVehicleShopCategory.sqf
*/
disableSerialization;
private _display = findDisplay 8800;
if (isNull _display) exitWith {};
if ((lbCurSel 8803) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_vehicle_shop_type","cop_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "LawEnforcement" >> _shop;
private _category = lbData [8803,lbCurSel 8803];
private _categoryCfg = _shopCfg >> "Categories" >> _category;
private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "kcso";};

lbClear 8804;
lbClear 8808;
life_vehicle_shop_items = [];
(_display displayCtrl 8806) ctrlSetText "";
(_display displayCtrl 8807) ctrlEnable false;

{
    private _className = getText (_x >> "className");
    private _displayName = getText (_x >> "displayName");
    private _condition = getText (_x >> "condition");
    private _rank = getText (_x >> "rank");
    private _subdivisions = getArray (_x >> "subdivisions");
    private _conditionOk = [_condition] call life_fnc_levelCheck;
    private _rankOk = (_rank isEqualTo "") || {[_rank,_department] call life_fnc_leoAtLeastRank};
    private _subdivisionOk = (count _subdivisions) isEqualTo 0;
    if !(_subdivisionOk) then {
        {
            if ([_x,_department] call life_fnc_leoHasSubdivision) exitWith {_subdivisionOk = true;};
        } forEach _subdivisions;
    };
    private _access = _conditionOk && {_rankOk} && {_subdivisionOk};

    private _vehInfo = [_className] call life_fnc_fetchVehInfo;
    if (_displayName isEqualTo "" && {!(_vehInfo isEqualTo [])}) then {_displayName = _vehInfo select 3;};
    if (_displayName isEqualTo "") then {_displayName = _className;};

    private _idx = lbAdd [8804,_displayName];
    lbSetData [8804,_idx,str [
        _className,
        _displayName,
        getNumber (_x >> "price"),
        _condition,
        _rank,
        _subdivisions,
        getText (_x >> "text"),
        getArray (_x >> "features"),
        getText (_categoryCfg >> "title")
    ]];
    lbSetColor [8804,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
} forEach ("true" configClasses (_categoryCfg >> "Vehicles"));

if ((lbSize 8804) > 0) then {
    lbSetCurSel [8804,0];
} else {
    (_display displayCtrl 8805) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No vehicles are configured under %1.</t>",
        getText (_categoryCfg >> "title")
    ];
};
