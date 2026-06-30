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

private _isMagazine = !(_itemInfo isEqualTo []) && {(_itemInfo select 6) isEqualTo "CfgMagazines"};
private _magazineCapacity = if (_isMagazine) then {getNumber (configFile >> "CfgMagazines" >> _className >> "count")} else {0};
if (_isMagazine && {_magazineCapacity < 1}) then {_magazineCapacity = 1;};
private _quantity = 1;
if (_isMagazine) then {
    private _quantityText = ctrlText 8708;
    if !([_quantityText] call TON_fnc_isnumber) exitWith {_quantity = 0;};
    _quantity = floor (parseNumber _quantityText);
};
if (_quantity < 1 || {_quantity > 100}) exitWith {hint "Enter a magazine quantity from 1 to 100.";};

if !(player canAdd _className) exitWith {hint localize "STR_NOTF_NoRoom";};
if (_isMagazine) then {
    private _magazineMass = getNumber (configFile >> "CfgMagazines" >> _className >> "mass");
    if (_magazineMass > 0 && {(loadAbs player) + (_magazineMass * _quantity) > (maxLoad player)}) exitWith {
        _quantity = 0;
    };
};
if (_quantity isEqualTo 0) exitWith {hint "You do not have room for that many magazines.";};

private _taxData = [_price,"weapons",_className,true] call life_fnc_applyTax;
_taxData params ["_base","_tax","_total","_rate"];
private _purchasePrice = _total * _quantity;
if (CASH < _purchasePrice) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};

CASH = CASH - _purchasePrice;
if (_isMagazine) then {
    for "_i" from 1 to _quantity do {player addMagazine [_className,_magazineCapacity];};
} else {
    [_className,true] call life_fnc_handleItem;
};
[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;

life_action_delay = time;
hint parseText format [
    "Purchased <t color='#8cff9b'>%1%2</t> for <t color='#8cff9b'>$%3</t>.",
    ["",format ["%1x ",_quantity]] select (_quantity > 1),
    _displayName,
    [_purchasePrice] call life_fnc_numberText
];
[] call life_fnc_weaponShopSelect;
