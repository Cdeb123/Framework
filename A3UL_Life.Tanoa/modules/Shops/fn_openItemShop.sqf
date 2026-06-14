#include "..\..\script_macros.hpp"
/*
    File: fn_openItemShop.sqf
*/
private _input = _this;
private _shop = "market";
private _shopNpc = objNull;

if (_input isEqualType "") then {
    _shop = _input;
} else {
    if (_input isEqualType []) then {
        if ((count _input) > 0 && {(_input select 0) isEqualType objNull}) then {
            _shopNpc = _input select 0;
        };
        if ((count _input) > 3 && {(_input select 3) isEqualType ""}) then {
            _shop = _input select 3;
        } else {
            if ((count _input) > 0 && {(_input select 0) isEqualType ""}) then {
                _shop = _input select 0;
            };
        };
    };
};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "ItemShops" >> _shop;
if !(isClass _shopCfg) exitWith {};

private _side = getText (_shopCfg >> "side");
private _flag = switch (playerSide) do {case west: {"cop"}; case independent: {"med"}; default {"civ"};};
if !(_side isEqualTo "") then {
    if !(_side isEqualTo _flag) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};
};

private _condition = getText (_shopCfg >> "condition");
if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

if (dialog) exitWith {};
life_item_shop_type = _shop;
life_item_shop_npc = _shopNpc;
life_shop_type = _shop;
life_shop_npc = _shopNpc;
createDialog "life_item_shop_modern";

[] spawn {
    disableSerialization;
    uiSleep 0.05;
    [missionNamespace getVariable ["life_item_shop_type","market"]] call life_fnc_itemShopLoad;
};
