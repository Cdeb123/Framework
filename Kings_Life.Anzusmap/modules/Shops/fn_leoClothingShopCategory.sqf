#include "..\..\script_macros.hpp"
/*
    File: fn_leoClothingShopCategory.sqf
*/
disableSerialization;
private _display = findDisplay 8950;
if (isNull _display) exitWith {};
if ((lbCurSel 8953) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_leo_clothing_shop_type","cop"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "LEOClothingShops" >> _shop;
private _category = lbData [8953,lbCurSel 8953];
private _categoryCfg = _shopCfg >> "Categories" >> _category;
private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "kcso";};

lbClear 8954;
life_leo_clothing_shop_items = [];
(_display displayCtrl 8956) ctrlSetText "";
(_display displayCtrl 8957) ctrlEnable false;

if !(isClass _categoryCfg) exitWith {};

private _categoryTitle = getText (_categoryCfg >> "title");

{
    private _className = getText (_x >> "className");
    private _itemType = getText (_x >> "itemType");
    private _displayName = getText (_x >> "displayName");
    private _price = getNumber (_x >> "price");
    private _condition = getText (_x >> "condition");
    private _rank = getText (_x >> "rank");
    private _subdivisions = getArray (_x >> "subdivisions");
    private _rolePermissions = getArray (_x >> "rolePermissions");
    {
        _rolePermissions pushBackUnique _x;
    } forEach getArray (_x >> "permissions");
    private _text = getText (_x >> "text");
    private _picture = getText (_x >> "picture");

    if ((_displayName find "STR_") isEqualTo 0) then {_displayName = localize _displayName;};
    if ((_displayName find "$STR_") isEqualTo 0) then {_displayName = localize (_displayName select [1]);};

    if (!(_className isEqualTo "NONE") && {_displayName isEqualTo ""}) then {
        private _info = [_className] call life_fnc_fetchCfgDetails;
        if !(_info isEqualTo []) then {
            _displayName = _info select 1;
            if (_picture isEqualTo "") then {_picture = _info select 2;};
        };
    };
    if (_displayName isEqualTo "") then {_displayName = _className;};

    private _accessData = [_condition,_rank,_department,_subdivisions,_rolePermissions] call life_fnc_leoClothingShopAccess;
    _accessData params ["_access"];

    private _slotLabel = switch (_itemType) do {
        case "uniform": {"Uniform"};
        case "headgear": {"Headgear"};
        case "goggles": {"Glasses"};
        case "vest": {"Vest"};
        case "backpack": {"Backpack"};
        default {"Gear"};
    };

    private _idx = lbAdd [8954,format ["%1    %2    $%3",_displayName,_slotLabel,[_price] call life_fnc_numberText]];
    lbSetData [8954,_idx,str [
        _itemType,
        _className,
        _displayName,
        _price,
        _condition,
        _rank,
        _subdivisions,
        _rolePermissions,
        _text,
        _categoryTitle,
        _picture
    ]];
    lbSetColor [8954,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
} forEach ("true" configClasses (_categoryCfg >> "Items"));

if ((lbSize 8954) > 0) then {
    lbSetCurSel [8954,0];
} else {
    (_display displayCtrl 8955) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No clothing is configured under %1.</t>",
        _categoryTitle
    ];
};
