#include "..\..\script_macros.hpp"
/*
    File: fn_itemShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8904) < 0) exitWith {hint "Select an item first.";};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};

private _shop = missionNamespace getVariable ["life_item_shop_type","market"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "ItemShops" >> _shop;
private _data = call compile (lbData [8904,lbCurSel 8904]);

if ((_data param [0,"",[""]]) isEqualTo "license") exitWith {
    private _licenseCfg = _shopCfg >> "License";
    private _variable = getText (_licenseCfg >> "variable");
    private _side = getText (_licenseCfg >> "side");
    if (_side isEqualTo "") then {_side = "civ";};
    if !(_side isEqualTo "civ") exitWith {hint "This license cannot be purchased here.";};
    private _varName = format ["license_%1_%2",_side,_variable];
    if (missionNamespace getVariable [_varName,false]) exitWith {hint "You already own that license.";};

    private _price = getNumber (_licenseCfg >> "price");
    private _displayName = getText (_licenseCfg >> "displayName");
    private _name = if (_displayName isEqualTo "") then {_variable} else {localize _displayName};
    if (CASH < _price) exitWith {hint format [localize "STR_NOTF_NE_1",[_price] call life_fnc_numberText,_name];};

    CASH = CASH - _price;
    [0] call SOCK_fnc_updatePartial;
    missionNamespace setVariable [_varName,true];
    [2] call SOCK_fnc_updatePartial;
    life_action_delay = time;
    titleText [format [localize "STR_NOTF_B_1",_name,[_price] call life_fnc_numberText],"PLAIN"];
    [_shop] call life_fnc_itemShopLoad;
};

_data params [
    ["_rowType","",[""]],
    ["_itemType","",[""]],
    ["_className","",[""]],
    ["_displayName","",[""]],
    ["_price",0,[0]],
    ["_sellPrice",-1,[0]],
    ["_condition","",[""]],
    ["_text","",[""]],
    ["_taxCategory","",[""]],
    ["_categoryTitle","",[""]],
    ["_picture","",[""]]
];

if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _requiredLicense = getText (_shopCfg >> "requiredLicense");
private _licenseSide = getText (_shopCfg >> "requiredLicenseSide");
if (_licenseSide isEqualTo "") then {_licenseSide = "civ";};
private _missingLicense = false;
if !(_requiredLicense isEqualTo "") then {
    _missingLicense = !(missionNamespace getVariable [format ["license_%1_%2",_licenseSide,_requiredLicense],false]);
};
if (_missingLicense) exitWith {hint "You need the required license before buying from this shop.";};

if (!(_itemType isEqualTo "virtual") && {_className isEqualTo "NONE"}) exitWith {
    switch (_itemType) do {
        case "uniform": {removeUniform player;};
        case "headgear": {removeHeadgear player;};
        case "goggles": {removeGoggles player;};
        case "vest": {removeVest player;};
        case "backpack": {removeBackpack player;};
    };
    life_action_delay = time;
    [3] call SOCK_fnc_updatePartial;
    hint "Removed selected clothing slot.";
};

private _amount = 1;
private _amountError = "";
if (_itemType isEqualTo "virtual") then {
    private _amountText = ctrlText 8908;
    if !([_amountText] call TON_fnc_isnumber) then {
        _amountError = localize "STR_Shop_Virt_NoNum";
    } else {
        _amount = parseNumber _amountText;
        if (_amount <= 0) then {
            _amountError = localize "STR_Shop_Virt_NoNum";
        } else {
            private _diff = [_className,_amount,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
            if (_diff <= 0) then {
                _amountError = localize "STR_NOTF_NoSpace";
            } else {
                _amount = _diff;
            };
        };
    };
};
if !(_amountError isEqualTo "") exitWith {hint _amountError;};
private _wearableTypes = ["uniform","headgear","goggles","vest","backpack"];
if (!(_itemType isEqualTo "virtual") && {!(_itemType in _wearableTypes)} && {!(player canAdd _className)}) exitWith {hint localize "STR_NOTF_NoRoom";};

private _taxData = [_price,_taxCategory,_className,true] call life_fnc_applyTax;
_taxData params ["_base","_tax","_total","_rate"];
private _purchasePrice = _total * _amount;
if (CASH < _purchasePrice) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};

private _added = true;
if (_itemType isEqualTo "virtual") then {
    _added = [true,_className,_amount] call life_fnc_handleInv;
} else {
    _added = [_className,true,nil,nil,nil,nil,nil,true] call life_fnc_handleItem;
};
if !(_added) exitWith {hint localize "STR_NOTF_NoRoom";};

CASH = CASH - _purchasePrice;
[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;
life_action_delay = time;

hint parseText format [
    "Purchased <t color='#8cff9b'>%1%2</t> for <t color='#8cff9b'>$%3</t>.",
    ["",format ["%1x ",_amount]] select (_amount > 1),
    _displayName,
    [_purchasePrice] call life_fnc_numberText
];

[] call life_fnc_itemShopSelect;
