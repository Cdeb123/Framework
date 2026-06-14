#include "..\..\script_macros.hpp"
/*
    File: fn_doorInteraction.sqf

    Main interaction entry point for vanilla and modded building doors.
*/
params [
    ["_building",objNull,[objNull]],
    ["_door",0,[0]]
];

if (dialog) exitWith {false};
if !(isNull objectParent player) exitWith {false};

if (isNull _building || {_door <= 0}) then {
    private _nearest = [] call life_fnc_nearestBuildingDoor;
    if (_nearest isEqualTo []) exitWith {hint localize "STR_House_Door_NotNear"; false};
    _building = _nearest select 0;
    _door = _nearest select 1;
};

if (isNull _building || {_door <= 0}) exitWith {false};

private _access = [_building,_door] call life_fnc_doorAccessFor;
_access params [
    ["_mode","public",[""]],
    ["_label","Door Access",[""]],
    ["_keypad",false,[false]]
];

if ([_access] call life_fnc_canUseDoor) exitWith {
    [_building,_door] call life_fnc_toggleBuildingDoor;
};

if (_keypad) exitWith {
    [_building,_door,_access] call life_fnc_openDoorKeypad;
};

hint format ["Access denied: %1",_label];
false
