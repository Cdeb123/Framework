#include "..\..\script_macros.hpp"
/*
    File: fn_hasPermission.sqf

    Returns:
    BOOL
*/
params [
    ["_permission","",[""]]
];

if (_permission isEqualTo "") exitWith {false};
if ([] call life_fnc_isCommunityOwner) exitWith {true};
if (!isNil "life_adminlevel" && {call life_adminlevel >= 5}) exitWith {true};

_permission in (missionNamespace getVariable ["life_permissions",[]]);
