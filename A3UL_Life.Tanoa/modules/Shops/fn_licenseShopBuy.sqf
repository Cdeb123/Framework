#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8401) < 0) exitWith {};

private _license = lbData [8401,lbCurSel 8401];
private _cfg = missionConfigFile >> "Licenses" >> _license;
if !(isClass _cfg) exitWith {};

private _side = getText (_cfg >> "side");
if !(_side isEqualTo "civ") exitWith {hint "This office only serves civilian licenses.";};
if (LICENSE_VALUE(_license,_side)) exitWith {hint "You already own that license.";};

private _price = getNumber (_cfg >> "price");
private _name = localize getText (_cfg >> "displayName");
if (CASH < _price) exitWith {hint format [localize "STR_NOTF_NE_1",[_price] call life_fnc_numberText,_name];};

CASH = CASH - _price;
[0] call SOCK_fnc_updatePartial;
missionNamespace setVariable [LICENSE_VARNAME(_license,_side),true];
[2] call SOCK_fnc_updatePartial;

titleText [format [localize "STR_NOTF_B_1",_name,[_price] call life_fnc_numberText],"PLAIN"];
[missionNamespace getVariable ["life_license_shop_type","dmv"]] call life_fnc_licenseShopLoad;
