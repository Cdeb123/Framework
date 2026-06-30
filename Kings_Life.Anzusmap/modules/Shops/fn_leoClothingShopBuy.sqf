#include "..\..\script_macros.hpp"
/*
    File: fn_leoClothingShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8954) < 0) exitWith {hint "Select clothing first.";};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};

private _shop = missionNamespace getVariable ["life_leo_clothing_shop_type","cop"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "LEOClothingShops" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};
if !(playerSide isEqualTo west) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _shopCondition = getText (_shopCfg >> "condition");
if !([_shopCondition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "tcsd";};

private _data = call compile (lbData [8954,lbCurSel 8954]);
_data params [
    ["_itemType","",[""]],
    ["_className","",[""]],
    ["_displayName","",[""]],
    ["_price",0,[0]],
    ["_condition","",[""]],
    ["_rank","",[""]],
    ["_subdivisions",[],[[]]],
    ["_rolePermissions",[],[[]]],
    ["_text","",[""]],
    ["_categoryTitle","",[""]],
    ["_picture","",[""]]
];

private _accessData = [_condition,_rank,_department,_subdivisions,_rolePermissions] call life_fnc_leoClothingShopAccess;
_accessData params ["_access","_reason"];
if !(_access) exitWith {hint _reason;};

if (_className isEqualTo "NONE") exitWith {
    switch (_itemType) do {
        case "uniform": {removeUniform player;};
        case "headgear": {removeHeadgear player;};
        case "goggles": {removeGoggles player;};
        case "vest": {removeVest player;};
        case "backpack": {removeBackpack player;};
    };
    life_action_delay = time;
    [3] call SOCK_fnc_updatePartial;
    [] call life_fnc_playerSkins;
    hint "Removed selected clothing slot.";
    [] call life_fnc_leoClothingShopSelect;
};

private _details = [_className] call life_fnc_fetchCfgDetails;
if (_details isEqualTo []) exitWith {hint "This clothing class is not available in the current modset.";};
if (_displayName isEqualTo "") then {_displayName = _details select 1;};
if (_displayName isEqualTo "") then {_displayName = _className;};

private _taxData = [_price,"clothing",_className,false] call life_fnc_applyTax;
_taxData params ["_base","_tax","_purchasePrice","_rate"];
if (CASH < _purchasePrice) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};

[_className,true,nil,nil,nil,nil,nil,true] call life_fnc_handleItem;

CASH = CASH - _purchasePrice;
if (_tax > 0) then {[_tax] call life_fnc_governmentAddRevenue;};
[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;
life_action_delay = time;

[] call life_fnc_playerSkins;
hint parseText format [
    "Purchased <t color='#8cff9b'>%1</t> for <t color='#8cff9b'>$%2</t>.",
    _displayName,
    [_purchasePrice] call life_fnc_numberText
];

[] call life_fnc_leoClothingShopSelect;
