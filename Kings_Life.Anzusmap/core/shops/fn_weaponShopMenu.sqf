#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Something
*/

private _requestedShop = _this param [3,"",[""]];
private _modernGroup = switch (playerSide) do {
    case west: {"LawEnforcement"};
    case civilian: {"Civilian"};
    default {""};
};
private _modernShop = _requestedShop;
if (_modernShop isEqualTo "cop_basic") then {
    _modernShop = switch (missionNamespace getVariable ["life_leo_department","kcso"]) do {
        case "usms": {"usms_armory"};
        case "dea": {"dea_armory"};
        case "fbi": {"fbi_armory"};
        default {"kcso_armory"};
    };
};
private _useModernShop = false;
if !(_modernGroup isEqualTo "") then {
    _useModernShop = isClass (missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _modernGroup >> _modernShop);
};
if (_useModernShop) exitWith {_this call life_fnc_openWeaponShop;};

private _shopTitle = M_CONFIG(getText,"WeaponShops",(_this select 3),"name");
private _shopSide = M_CONFIG(getText,"WeaponShops",(_this select 3),"side");
private _conditions = M_CONFIG(getText,"WeaponShops",(_this select 3),"conditions");

private _exit = false;
if !(_shopSide isEqualTo "") then {
    private _flag = switch (playerSide) do {case west: {"cop"}; case independent: {"med"}; default {"civ"};};
    if !(_flag isEqualTo _shopSide) then {_exit = true;};
};

if (_exit) exitWith {};

_exit = [_conditions] call life_fnc_levelCheck;
if !(_exit) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

uiNamespace setVariable ["Weapon_Shop",(_this select 3)];
uiNamespace setVariable ["Weapon_Magazine",0];
uiNamespace setVariable ["Weapon_Accessories",0];
uiNamespace setVariable ["Magazine_Array",[]];
uiNamespace setVariable ["Accessories_Array",[]];

if !(createDialog "life_weapon_shop") exitWith {};
if (!isClass(missionConfigFile >> "WeaponShops" >> (_this select 3))) exitWith {}; //Bad config entry.

disableSerialization;

ctrlSetText[38401,_shopTitle];

private _filters = ((findDisplay 38400) displayCtrl 38402);
lbClear _filters;

ctrlShow [38406,true];
ctrlEnable [38406,false];
ctrlShow [38407,true];
ctrlEnable [38407,false];
ctrlShow [38408,false];
ctrlShow [38409,false];
ctrlShow [38410,false];
ctrlSetText [38408,"1"];

_filters lbAdd localize "STR_Shop_Weapon_ShopInv";
_filters lbAdd localize "STR_Shop_Weapon_YourInv";

_filters lbSetCurSel 0;
