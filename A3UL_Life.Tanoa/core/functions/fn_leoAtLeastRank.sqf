#include "..\..\script_macros.hpp"
/*
    File: fn_leoAtLeastRank.sqf

    Checks named LEO rank order. Intended for shops, loadouts, vehicles, and
    command logic.
*/
params [
    ["_rank","",[""]],
    ["_department","",[""]]
];

if (_rank isEqualTo "") exitWith {false};
if ([] call life_fnc_isCommunityOwner) exitWith {true};

private _memberships = missionNamespace getVariable ["life_leo_memberships",[]];
private _ok = false;

{
    _x params [
        ["_dept","",[""]],
        ["_currentRank","",[""]]
    ];

    private _deptToCheck = if (_department isEqualTo "") then {_dept} else {_department};
    private _required = [_rank,_deptToCheck] call life_fnc_leoRankOrder;
    private _current = [_currentRank,_dept] call life_fnc_leoRankOrder;

    if ((_department isEqualTo "" || {_dept isEqualTo _department}) && {_required >= 0} && {_current >= _required}) exitWith {
        _ok = true;
    };
} forEach _memberships;

_ok;
