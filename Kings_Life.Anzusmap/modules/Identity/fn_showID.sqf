#include "..\..\script_macros.hpp"
/*
    File: fn_showID.sqf
*/
params [
    ["_target",cursorObject,[objNull]]
];

if (isNull _target || {!isPlayer _target}) exitWith {hint "No player selected.";};
if (player distance _target > 5) exitWith {hint "Move closer to view identification.";};

[player] remoteExecCall ["life_fnc_sendID",_target];
