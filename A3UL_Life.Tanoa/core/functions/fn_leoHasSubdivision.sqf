#include "..\..\script_macros.hpp"
/*
    File: fn_leoHasSubdivision.sqf
*/
params [
    ["_subdivision","",[""]],
    ["_department","",[""]]
];

if (_subdivision isEqualTo "") exitWith {false};
if ([] call life_fnc_isCommunityOwner) exitWith {true};

private _ok = false;
{
    _x params [
        ["_dept","",[""]],
        ["_rank","",[""]],
        ["_primary","",[""]],
        ["_subdivisions",[],[[]]]
    ];

    if ((_department isEqualTo "" || {_dept isEqualTo _department}) && {(_primary isEqualTo _subdivision) || {_subdivision in _subdivisions}}) exitWith {
        _ok = true;
    };
} forEach (missionNamespace getVariable ["life_leo_memberships",[]]);

_ok;
