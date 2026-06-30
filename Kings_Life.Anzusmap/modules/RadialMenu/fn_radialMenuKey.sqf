#include "..\..\script_macros.hpp"
/*
    File: fn_radialMenuKey.sqf
*/
params [
    "_display",
    "_code",
    "_shift",
    "_ctrl",
    "_alt"
];

private _handled = false;
private _page = missionNamespace getVariable ["life_radial_page",0];
private _numberKeys = [2,3,4,5,6,7,8,9];
private _slot = _numberKeys find _code;

if (_slot >= 0) exitWith {
    [(_page * 8) + _slot] call life_fnc_radialMenuExecute;
    true
};

if (_code in [30,203]) exitWith {
    [-1] call life_fnc_radialMenuPage;
    true
};

if (_code in [32,205]) exitWith {
    [1] call life_fnc_radialMenuPage;
    true
};

if (_code isEqualTo 1) exitWith {
    closeDialog 0;
    true
};

private _radialKey = LIFE_SETTINGS(getNumber,"radial_menu_key");
private _radialCustom = LIFE_SETTINGS(getText,"radial_menu_customAction");
private _radialCustomKeys = if (_radialCustom isEqualTo "") then {[]} else {actionKeys _radialCustom};
if (_code isEqualTo _radialKey || {_code in _radialCustomKeys}) exitWith {
    closeDialog 0;
    true
};

_handled
