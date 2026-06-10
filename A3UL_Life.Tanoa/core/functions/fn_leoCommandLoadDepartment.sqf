#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandLoadDepartment.sqf
*/
disableSerialization;
private _display = findDisplay 8100;
if (isNull _display) exitWith {};

private _department = lbData [8102,lbCurSel 8102];
private _deptCfg = missionConfigFile >> "Life_LEO" >> "Departments" >> _department;

lbClear 8103;
private _rankClasses = "true" configClasses (_deptCfg >> "Ranks");
if ((count _rankClasses) > 0) then {
    {
        private _idx = lbAdd [8103,getText (_x >> "displayName")];
        lbSetData [8103,_idx,configName _x];
    } forEach _rankClasses;
} else {
    {
        private _idx = lbAdd [8103,_x];
        lbSetData [8103,_idx,_x];
    } forEach getArray (_deptCfg >> "ranks");
};
if ((lbSize 8103) > 0) then {lbSetCurSel [8103,0];};

lbClear 8104;
private _subClasses = "true" configClasses (_deptCfg >> "Subdivisions");
if ((count _subClasses) > 0) then {
    {
        private _idx = lbAdd [8104,getText (_x >> "displayName")];
        lbSetData [8104,_idx,configName _x];
    } forEach _subClasses;
} else {
    {
        private _idx = lbAdd [8104,_x];
        lbSetData [8104,_idx,_x];
    } forEach getArray (_deptCfg >> "subdivisions");
};
if ((lbSize 8104) > 0) then {lbSetCurSel [8104,0];};

ctrlSetText [8115,""];
ctrlSetText [8116,""];
