#include "..\..\script_macros.hpp"
/*
    File: fn_weaponFireMode.sqf

    Description:
    Cycles a framework-level fire mode. Modded weapon scripts can read
    life_fireMode or set life_weapon_fireModes to override the default modes.
*/
private _weapon = currentWeapon player;
if (_weapon isEqualTo "") exitWith {
    life_fireMode = "SAFE";
    [] call life_fnc_hudUpdate;
};

private _modes = missionNamespace getVariable ["life_weapon_fireModes",["SAFE","SEMI","AUTO"]];
if !(_modes isEqualType []) then {_modes = ["SAFE","SEMI","AUTO"];};
if ((count _modes) isEqualTo 0) then {_modes = ["SAFE","SEMI","AUTO"];};

private _current = missionNamespace getVariable ["life_fireMode","SAFE"];
private _index = _modes find _current;
if (_index < 0) then {_index = 0;} else {_index = (_index + 1) mod (count _modes);};

life_fireMode = _modes select _index;
player setVariable ["fireMode",life_fireMode,true];

[player,"fireModeSound",12,1] remoteExecCall ["life_fnc_say3D",RCLIENT];
titleText [format ["Fire mode: %1",life_fireMode],"PLAIN"];
[] call life_fnc_hudUpdate;
