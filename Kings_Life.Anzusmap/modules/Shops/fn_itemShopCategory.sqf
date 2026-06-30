#include "..\..\script_macros.hpp"
/*
    File: fn_itemShopCategory.sqf
*/
disableSerialization;
private _display = findDisplay 8900;
if (isNull _display) exitWith {};
if ((lbCurSel 8903) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_item_shop_type","market"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "ItemShops" >> _shop;
private _categoryData = call compile (lbData [8903,lbCurSel 8903]);
_categoryData params [
    ["_type","",[""]],
    ["_category","",[""]]
];

lbClear 8904;
life_item_shop_items = [];
(_display displayCtrl 8906) ctrlSetText "";
(_display displayCtrl 8907) ctrlEnable false;
(_display displayCtrl 8908) ctrlSetText "1";
(_display displayCtrl 8908) ctrlEnable false;

if (_type isEqualTo "license") exitWith {
    private _licenseCfg = _shopCfg >> "License";
    private _variable = getText (_licenseCfg >> "variable");
    private _side = getText (_licenseCfg >> "side");
    if (_side isEqualTo "") then {_side = "civ";};
    private _displayName = getText (_licenseCfg >> "displayName");
    private _name = if (_displayName isEqualTo "") then {_variable} else {localize _displayName};
    private _owned = missionNamespace getVariable [format ["license_%1_%2",_side,_variable],false];
    private _price = getNumber (_licenseCfg >> "price");
    private _idx = lbAdd [8904,format ["%1    $%2    %3",_name,[_price] call life_fnc_numberText,["Available","Owned"] select _owned]];
    lbSetData [8904,_idx,str ["license"]];
    lbSetColor [8904,_idx,[[0.92,0.96,0.96,1],[0.42,0.88,0.58,1]] select _owned];
    lbSetCurSel [8904,0];
};

private _categoryCfg = _shopCfg >> "Categories" >> _category;
if !(isClass _categoryCfg) exitWith {};

private _categoryTitle = getText (_categoryCfg >> "title");
private _taxCategory = getText (_categoryCfg >> "taxCategory");
if (_taxCategory isEqualTo "") then {_taxCategory = "general";};

private _addRow = {
    params [
        ["_itemType","",[""]],
        ["_className","",[""]],
        ["_displayName","",[""]],
        ["_price",0,[0]],
        ["_sellPrice",-1,[0]],
        ["_condition","",[""]],
        ["_text","",[""]],
        ["_tax","",[""]],
        ["_picture","",[""]]
    ];
    if (_className isEqualTo "") exitWith {};
    private _name = _displayName;
    if ((_name find "STR_") isEqualTo 0) then {_name = localize _name;};
    if ((_name find "$STR_") isEqualTo 0) then {_name = localize (_name select [1]);};
    if (_name isEqualTo "") then {
        if (_itemType isEqualTo "virtual") then {
            _name = localize getText (missionConfigFile >> "VirtualItems" >> _className >> "displayName");
        } else {
            private _info = [_className] call life_fnc_fetchCfgDetails;
            if !(_info isEqualTo []) then {_name = _info select 1;};
        };
    };
    if (_name isEqualTo "") then {_name = _className;};

    private _access = [_condition] call life_fnc_levelCheck;
    private _idx = lbAdd [8904,format ["%1    $%2",_name,[_price] call life_fnc_numberText]];
    lbSetData [8904,_idx,str ["item",_itemType,_className,_name,_price,_sellPrice,_condition,_text,_tax,_categoryTitle,_picture]];
    lbSetColor [8904,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
};

private _legacyVirtual = getText (_categoryCfg >> "legacyVirtual");
if !(_legacyVirtual isEqualTo "") then {
    {
        private _price = getNumber (missionConfigFile >> "VirtualItems" >> _x >> "buyPrice");
        if (_price >= 0) then {
            private _displayName = getText (missionConfigFile >> "VirtualItems" >> _x >> "displayName");
            private _icon = getText (missionConfigFile >> "VirtualItems" >> _x >> "icon");
            ["virtual",_x,_displayName,_price,getNumber (missionConfigFile >> "VirtualItems" >> _x >> "sellPrice"),"","",_taxCategory,_icon] call _addRow;
        };
    } forEach getArray (missionConfigFile >> "VirtualShops" >> _legacyVirtual >> "items");
};

private _legacyClothing = getText (_categoryCfg >> "legacyClothing");
private _legacySection = getText (_categoryCfg >> "legacySection");
if !(_legacyClothing isEqualTo "") then {
    private _itemType = switch (_legacySection) do {
        case "uniforms": {"uniform"};
        case "headgear": {"headgear"};
        case "goggles": {"goggles"};
        case "vests": {"vest"};
        case "backpacks": {"backpack"};
        default {"gear"};
    };
    {
        _x params [
            ["_className","",[""]],
            ["_name","",[""]],
            ["_price",0,[0]],
            ["_condition","",[""]]
        ];
        [_itemType,_className,_name,_price,-1,_condition,"",_taxCategory,""] call _addRow;
    } forEach getArray (missionConfigFile >> "Clothing" >> _legacyClothing >> _legacySection);
};

private _legacyWeaponShop = getText (_categoryCfg >> "legacyWeaponShop");
private _legacyWeaponArray = getText (_categoryCfg >> "legacyWeaponArray");
if !(_legacyWeaponShop isEqualTo "") then {
    {
        _x params [
            ["_className","",[""]],
            ["_name","",[""]],
            ["_price",0,[0]],
            ["_sellPrice",-1,[0]],
            ["_condition","",[""]]
        ];
        ["gear",_className,_name,_price,_sellPrice,_condition,"",_taxCategory,""] call _addRow;
    } forEach getArray (missionConfigFile >> "WeaponShops" >> _legacyWeaponShop >> _legacyWeaponArray);
};

{
    private _itemTax = getText (_x >> "taxCategory");
    if (_itemTax isEqualTo "") then {_itemTax = _taxCategory;};
    [
        getText (_x >> "itemType"),
        getText (_x >> "className"),
        getText (_x >> "displayName"),
        getNumber (_x >> "buyPrice"),
        getNumber (_x >> "sellPrice"),
        getText (_x >> "condition"),
        getText (_x >> "text"),
        _itemTax,
        getText (_x >> "picture")
    ] call _addRow;
} forEach ("true" configClasses (_categoryCfg >> "Items"));

if ((lbSize 8904) > 0) then {
    lbSetCurSel [8904,0];
} else {
    (_display displayCtrl 8905) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No items are configured under %1.</t>",
        _categoryTitle
    ];
};
