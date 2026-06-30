#include "..\..\script_macros.hpp"
/*
    File: fn_leoCanCommand.sqf
*/
if ([] call life_fnc_isCommunityOwner) exitWith {true};
if (["leo.command.terminal"] call life_fnc_hasPermission) exitWith {true};

private _ok = false;
{
    _x params [
        ["_dept","",[""]],
        ["_rank","",[""]]
    ];

    private _rankCfg = missionConfigFile >> "Life_LEO" >> "Departments" >> _dept >> "Ranks" >> _rank;
    if (isClass _rankCfg && {getNumber (_rankCfg >> "command") isEqualTo 1}) exitWith {
        _ok = true;
    };
} forEach (missionNamespace getVariable ["life_leo_memberships",[]]);

_ok;
