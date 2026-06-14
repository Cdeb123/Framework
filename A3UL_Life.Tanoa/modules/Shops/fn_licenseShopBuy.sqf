#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopBuy.sqf
*/
disableSerialization;
if ((lbCurSel 8401) < 0) exitWith {};

private _data = call compile (lbData [8401,lbCurSel 8401]);
_data params [
    ["_license","",[""]],
    ["_variable","",[""]],
    ["_displayName","",[""]],
    ["_price",0,[0]],
    ["_side","civ",[""]],
    ["_desc","",[""]]
];

if !(_side isEqualTo "civ") exitWith {hint "This office only serves civilian licenses.";};
if (_variable isEqualTo "") then {_variable = _license;};
private _varName = format ["license_%1_%2",_side,_variable];
if (missionNamespace getVariable [_varName,false]) exitWith {hint "You already own that license.";};

private _name = localize _displayName;
if (CASH < _price) exitWith {hint format [localize "STR_NOTF_NE_1",[_price] call life_fnc_numberText,_name];};

CASH = CASH - _price;
[0] call SOCK_fnc_updatePartial;
missionNamespace setVariable [_varName,true];
[2] call SOCK_fnc_updatePartial;

titleText [format [localize "STR_NOTF_B_1",_name,[_price] call life_fnc_numberText],"PLAIN"];
[missionNamespace getVariable ["life_license_shop_type","dmv"]] call life_fnc_licenseShopLoad;
