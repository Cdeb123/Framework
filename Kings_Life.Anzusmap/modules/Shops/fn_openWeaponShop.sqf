#include "..\..\script_macros.hpp"
/*
    File: fn_openWeaponShop.sqf
*/
private _input = _this;
private _shop = "gun";
if (_input isEqualType "") then {
    _shop = _input;
} else {
    if ((count _input) > 3 && {(_input select 3) isEqualType ""}) then {
        _shop = _input param [3,"gun",[""]];
    } else {
        if ((count _input) > 0 && {(_input select 0) isEqualType ""}) then {
            _shop = _input param [0,"gun",[""]];
        };
    };
};

private _group = switch (playerSide) do {
    case west: {"LawEnforcement"};
    case civilian: {"Civilian"};
    default {""};
};

if (_group isEqualTo "") exitWith {};
if (_shop isEqualTo "cop_basic") then {
    _shop = switch (missionNamespace getVariable ["life_leo_department","kcso"]) do {
        case "usms": {"usms_armory"};
        case "dea": {"dea_armory"};
        case "fbi": {"fbi_armory"};
        default {"kcso_armory"};
    };
};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop;
if !(isClass _shopCfg) exitWith {};

private _side = getText (_shopCfg >> "side");
private _allowed = switch (_side) do {
    case "civ": {playerSide isEqualTo civilian};
    case "cop": {playerSide isEqualTo west};
    case "med": {playerSide isEqualTo independent};
    default {true};
};
if !(_allowed) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _condition = getText (_shopCfg >> "condition");
if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

if (dialog) exitWith {};
life_weapon_shop_type = _shop;
life_weapon_shop_group = _group;
createDialog "life_weapon_shop_modern";
[] spawn {
    disableSerialization;
    uiSleep 0.05;
    [missionNamespace getVariable ["life_weapon_shop_type","gun"]] call life_fnc_weaponShopLoad;
};
