#include "..\..\script_macros.hpp"
/*
    File: fn_leoSetLocalData.sqf

    Normalizes LEO database rows and expands them into local permissions.
    Row format:
    [department_key, rank_key, primary_subdivision, subdivisions[], role_permissions[], status]
*/
params [
    ["_rows",[],[[]]]
];

private _owner = [] call life_fnc_isCommunityOwner;
private _defaultDept = getText (missionConfigFile >> "Life_LEO" >> "defaultDepartment");
if (_defaultDept isEqualTo "") then {_defaultDept = "tcsd";};

if (_owner) then {
    _rows pushBackUnique [
        "tcsd",
        "sheriff",
        "patrol",
        ["patrol","academy","hse","ert","ia","mcu","cid"],
        [
            "leo.access",
            "leo.command.terminal",
            "leo.command.hire",
            "leo.command.fire",
            "leo.command.permissions",
            "leo.command.owner",
            "leo.training.view",
            "leo.training.edit",
            "leo.training.roster",
            "staff.whitelist",
            "staff.permissions"
        ],
        "active"
    ];
};

private _memberships = [];
private _permissions = [];
private _firstSet = false;

{
    _x params [
        ["_department",_defaultDept,[""]],
        ["_rank","",[""]],
        ["_primary","",[""]],
        ["_subdivisions",[],[[]]],
        ["_extraPermissions",[],[[]]],
        ["_status","active",[""]]
    ];

    if (_status isEqualTo "active") then {
        if (_department isEqualTo "") then {_department = _defaultDept;};
        private _deptCfg = missionConfigFile >> "Life_LEO" >> "Departments" >> _department;
        if (_rank isEqualTo "") then {_rank = getText (_deptCfg >> "defaultRank");};
        if (_primary isEqualTo "") then {_primary = getText (_deptCfg >> "defaultSubdivision");};
        if !(_primary in _subdivisions) then {_subdivisions pushBack _primary;};

        private _deptName = getText (_deptCfg >> "displayName");
        private _rankCfg = _deptCfg >> "Ranks" >> _rank;
        private _rankName = if (isClass _rankCfg) then {getText (_rankCfg >> "displayName")} else {_rank};

        _memberships pushBack [_department,_rank,_primary,_subdivisions,_extraPermissions,_deptName,_rankName];
        { _permissions pushBackUnique _x; } forEach getArray (_deptCfg >> "permissions");
        { _permissions pushBackUnique _x; } forEach getArray (_rankCfg >> "permissions");

        _permissions pushBackUnique "leo.access";
        _permissions pushBackUnique format ["leo.department.%1",_department];
        _permissions pushBackUnique format ["leo.rank.%1.%2",_department,_rank];

        {
            private _subCfg = _deptCfg >> "Subdivisions" >> _x;
            _permissions pushBackUnique format ["leo.subdivision.%1.%2",_department,_x];
            _permissions pushBackUnique format ["leo.subdivision.%1",_x];
            { _permissions pushBackUnique _x; } forEach getArray (_subCfg >> "permissions");
        } forEach _subdivisions;

        {
            if !(_x isEqualTo "") then {_permissions pushBackUnique _x;};
        } forEach _extraPermissions;

        if (!_firstSet) then {
            life_leo_department = _department;
            life_leo_department_display = _deptName;
            life_leo_rank = _rank;
            life_leo_rank_display = _rankName;
            life_leo_primary_subdivision = _primary;
            life_leo_subdivisions = _subdivisions;
            _firstSet = true;
        };
    };
} forEach _rows;

life_leo_memberships = _memberships;
life_leo_permissions = _permissions;

if (!_firstSet) then {
    life_leo_department = "";
    life_leo_department_display = "";
    life_leo_rank = "";
    life_leo_rank_display = "";
    life_leo_primary_subdivision = "";
    life_leo_subdivisions = [];
};

player setVariable ["leoDepartment",life_leo_department,true];
player setVariable ["leoRank",life_leo_rank,true];
player setVariable ["leoRankDisplay",life_leo_rank_display,true];
player setVariable ["leoSubdivisions",life_leo_subdivisions,true];
