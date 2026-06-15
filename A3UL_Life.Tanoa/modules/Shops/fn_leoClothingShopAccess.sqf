#include "..\..\script_macros.hpp"
/*
    File: fn_leoClothingShopAccess.sqf

    Returns [canAccess, reason] for a LEO clothing config row.
*/
params [
    ["_condition","",[""]],
    ["_rank","",[""]],
    ["_department","",[""]],
    ["_subdivisions",[],[[]]],
    ["_rolePermissions",[],[[]]]
];

if (_department isEqualTo "") then {
    _department = getText (missionConfigFile >> "Life_LEO" >> "defaultDepartment");
};
if (_department isEqualTo "") then {_department = "tcsd";};

private _conditionOk = [_condition] call life_fnc_levelCheck;
private _rankOk = (_rank isEqualTo "") || {[_rank,_department] call life_fnc_leoAtLeastRank};
private _subdivisionOk = (count _subdivisions) isEqualTo 0;
if !(_subdivisionOk) then {
    {
        if ([_x,_department] call life_fnc_leoHasSubdivision) exitWith {_subdivisionOk = true;};
    } forEach _subdivisions;
};

private _permissionOk = true;
private _missingPermission = "";
private _leoPermissions = missionNamespace getVariable ["life_leo_permissions",[]];
{
    if !(([_x] call life_fnc_hasPermission) || {_x in _leoPermissions}) exitWith {
        _permissionOk = false;
        _missingPermission = _x;
    };
} forEach _rolePermissions;

private _reason = "Available";
if !(_conditionOk) then {
    _reason = "Condition locked";
} else {
    if !(_rankOk) then {
        private _rankName = getText (missionConfigFile >> "Life_LEO" >> "Departments" >> _department >> "Ranks" >> _rank >> "displayName");
        if (_rankName isEqualTo "") then {_rankName = _rank;};
        _reason = format ["Requires %1 or higher",_rankName];
    } else {
        if !(_subdivisionOk) then {
            private _subdivisionNames = [];
            {
                private _subName = getText (missionConfigFile >> "Life_LEO" >> "Departments" >> _department >> "Subdivisions" >> _x >> "displayName");
                if (_subName isEqualTo "") then {_subName = _x;};
                _subdivisionNames pushBack _subName;
            } forEach _subdivisions;
            _reason = format ["Requires %1 assignment",_subdivisionNames joinString " or "];
        } else {
            if !(_permissionOk) then {
                _reason = format ["Requires role permission: %1",_missingPermission];
            };
        };
    };
};

[_conditionOk && {_rankOk} && {_subdivisionOk} && {_permissionOk},_reason];
