#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8704) < 0) exitWith {hint localize "STR_Shop_Weapon_NoSelect";};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};

private _shop = missionNamespace getVariable ["life_weapon_shop_type","gun"];
private _group = missionNamespace getVariable ["life_weapon_shop_group","Civilian"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop;
private _data = call compile (lbData [8704,lbCurSel 8704]);

if ((_data param [0,"",[""]]) isEqualTo "license") exitWith {
    [] call life_fnc_weaponShopBuyLicense;
};

_data params [
    ["_className","",[""]],
    ["_nickname","",[""]],
    ["_price",0,[0]],
    ["_sellPrice",-1,[0]],
    ["_condition","",[""]],
    ["_text","",[""]],
    ["_category","",[""]],
    ["_categoryTitle","",[""]]
];

if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _requiredLicense = getText (_shopCfg >> "requiredLicense");
private _licenseSide = getText (_shopCfg >> "requiredLicenseSide");
if (_licenseSide isEqualTo "") then {_licenseSide = "civ";};
private _missingLicense = false;
if !(_requiredLicense isEqualTo "") then {
    _missingLicense = !(missionNamespace getVariable [format ["license_%1_%2",_licenseSide,_requiredLicense],false]);
};
if (_missingLicense) exitWith {hint "You need the firearm license before buying from this shop.";};

private _itemInfo = [_className] call life_fnc_fetchCfgDetails;
private _displayName = _nickname;
if (_displayName isEqualTo "" && {!(_itemInfo isEqualTo [])}) then {_displayName = _itemInfo select 1;};
if (_displayName isEqualTo "") then {_displayName = _className;};
if ((_displayName find "STR_") isEqualTo 0) then {_displayName = localize _displayName;};

if !(player canAdd _className) exitWith {hint localize "STR_NOTF_NoRoom";};

private _taxData = [_price,"weapons",_className,true] call life_fnc_applyTax;
_taxData params ["_base","_tax","_total","_rate"];
if (CASH < _total) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};

CASH = CASH - _total;
[_className,true] call life_fnc_handleItem;
[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;

life_action_delay = time;
hint parseText format [
    "Purchased <t color='#8cff9b'>%1</t> for <t color='#8cff9b'>$%2</t>.",
    _displayName,
    [_total] call life_fnc_numberText
];
[] call life_fnc_weaponShopSelect;
