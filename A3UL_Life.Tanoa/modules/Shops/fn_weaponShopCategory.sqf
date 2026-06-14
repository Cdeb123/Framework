#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopCategory.sqf
*/
disableSerialization;
private _display = findDisplay 8700;
if (isNull _display) exitWith {};
if ((lbCurSel 8703) < 0) exitWith {};

private _categoryData = call compile (lbData [8703,lbCurSel 8703]);
_categoryData params [
    ["_type","",[""]],
    ["_category","",[""]]
];

private _shop = missionNamespace getVariable ["life_weapon_shop_type","gun"];
private _group = missionNamespace getVariable ["life_weapon_shop_group","Civilian"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop;

lbClear 8704;
life_weapon_shop_items = [];
(_display displayCtrl 8706) ctrlSetText "";
(_display displayCtrl 8707) ctrlEnable false;

if (_type isEqualTo "license") exitWith {
    private _licenseCfg = _shopCfg >> "License";
    private _variable = getText (_licenseCfg >> "variable");
    private _side = getText (_licenseCfg >> "side");
    if (_side isEqualTo "") then {_side = "civ";};
    private _displayName = getText (_licenseCfg >> "displayName");
    private _name = if (_displayName isEqualTo "") then {_variable} else {localize _displayName};
    private _owned = missionNamespace getVariable [format ["license_%1_%2",_side,_variable],false];
    private _idx = lbAdd [8704,format ["%1    $%2    %3",_name,[(getNumber (_licenseCfg >> "price"))] call life_fnc_numberText,["Available","Owned"] select _owned]];
    lbSetData [8704,_idx,str ["license"]];
    lbSetColor [8704,_idx,[[0.92,0.96,0.96,1],[0.42,0.88,0.58,1]] select _owned];
    lbSetCurSel [8704,0];
};

private _categoryCfg = _shopCfg >> "Categories" >> _category;
if !(isClass _categoryCfg) exitWith {};

private _legacyShop = getText (_categoryCfg >> "legacyShop");
private _legacyArray = getText (_categoryCfg >> "legacyArray");
if !(_legacyShop isEqualTo "") then {
    {
        _x params [
            ["_className","",[""]],
            ["_nickname","",[""]],
            ["_buyPrice",0,[0]],
            ["_sellPrice",-1,[0]],
            ["_condition","",[""]]
        ];
        private _info = [_className] call life_fnc_fetchCfgDetails;
        private _displayName = _nickname;
        if (_displayName isEqualTo "" && {!(_info isEqualTo [])}) then {_displayName = _info select 1;};
        if (_displayName isEqualTo "") then {_displayName = _className;};
        if ((_displayName find "STR_") isEqualTo 0) then {_displayName = localize _displayName;};

        private _access = [_condition] call life_fnc_levelCheck;
        private _idx = lbAdd [8704,format ["%1    $%2",_displayName,[_buyPrice] call life_fnc_numberText]];
        lbSetData [8704,_idx,str [_className,_nickname,_buyPrice,_sellPrice,_condition,getText (_categoryCfg >> "description"),_category,getText (_categoryCfg >> "title")]];
        lbSetColor [8704,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
    } forEach getArray (missionConfigFile >> "WeaponShops" >> _legacyShop >> _legacyArray);
};

{
    private _className = getText (_x >> "className");
    private _nickname = getText (_x >> "nickname");
    private _buyPrice = getNumber (_x >> "buyPrice");
    private _sellPrice = getNumber (_x >> "sellPrice");
    private _condition = getText (_x >> "condition");
    private _text = getText (_x >> "text");
    private _info = [_className] call life_fnc_fetchCfgDetails;
    private _displayName = _nickname;
    if (_displayName isEqualTo "" && {!(_info isEqualTo [])}) then {_displayName = _info select 1;};
    if (_displayName isEqualTo "") then {_displayName = _className;};
    if ((_displayName find "STR_") isEqualTo 0) then {_displayName = localize _displayName;};

    private _access = [_condition] call life_fnc_levelCheck;
    private _idx = lbAdd [8704,format ["%1    $%2",_displayName,[_buyPrice] call life_fnc_numberText]];
    lbSetData [8704,_idx,str [_className,_nickname,_buyPrice,_sellPrice,_condition,_text,_category,getText (_categoryCfg >> "title")]];
    lbSetColor [8704,_idx,[[0.95,0.78,0.42,1],[0.92,0.96,0.96,1]] select _access];
} forEach ("true" configClasses (_categoryCfg >> "Items"));

if ((lbSize 8704) > 0) then {
    lbSetCurSel [8704,0];
} else {
    (_display displayCtrl 8705) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No items are configured under %1.</t>",
        getText (_categoryCfg >> "title")
    ];
};
