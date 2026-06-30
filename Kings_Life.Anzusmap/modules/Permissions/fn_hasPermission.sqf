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

_permission in (missionNamespace getVariable ["life_permissions",[]]);
