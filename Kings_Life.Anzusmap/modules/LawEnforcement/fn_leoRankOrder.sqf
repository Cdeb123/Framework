#include "..\..\script_macros.hpp"
/*
    File: fn_leoRankOrder.sqf

    Returns the numeric order for a named LEO rank key inside a department.
*/
params [
    ["_rank","",[""]],
    ["_department",missionNamespace getVariable ["life_leo_department","kcso"],[""]]
];

if (_rank isEqualTo "") exitWith {-1};
if (_department isEqualTo "") then {_department = getText (missionConfigFile >> "Life_LEO" >> "defaultDepartment");};

private _deptCfg = missionConfigFile >> "Life_LEO" >> "Departments" >> _department;
private _rankCfg = _deptCfg >> "Ranks" >> _rank;
if (isClass _rankCfg) exitWith {getNumber (_rankCfg >> "order")};

private _rankList = getArray (_deptCfg >> "ranks");
private _index = _rankList find _rank;
if (_index < 0) exitWith {-1};

_index + 1;
