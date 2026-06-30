#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopBuyLicense.sqf
*/
private _shop = missionNamespace getVariable ["life_weapon_shop_type","gun"];
private _group = missionNamespace getVariable ["life_weapon_shop_group","Civilian"];
private _licenseCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop >> "License";
if !(isClass _licenseCfg) exitWith {};

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

titleText [format [localize "STR_NOTF_B_1",_name,[_price] call life_fnc_numberText],"PLAIN"];
[missionNamespace getVariable ["life_weapon_shop_type","gun"]] call life_fnc_weaponShopLoad;
