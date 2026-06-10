#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8100;
if (isNull _display) exitWith {};

lbClear 8101;
{
    private _uid = getPlayerUID _x;
    private _charUid = _x getVariable ["characterUID",_uid];
    private _idx = lbAdd [8101,format ["%1 | %2",name _x,_uid]];
    lbSetData [8101,_idx,str [_uid,name _x,_charUid]];
} forEach allPlayers;
if ((lbSize 8101) > 0) then {lbSetCurSel [8101,0];};

lbClear 8102;
private _defaultIndex = 0;
{
    private _idx = lbAdd [8102,getText (_x >> "displayName")];
    lbSetData [8102,_idx,configName _x];
    if ((configName _x) isEqualTo (missionNamespace getVariable ["life_leo_department","tcsd"])) then {_defaultIndex = _idx;};
} forEach ("true" configClasses (missionConfigFile >> "Life_LEO" >> "Departments"));
lbSetCurSel [8102,_defaultIndex];

[] call life_fnc_leoCommandLoadDepartment;
[] call life_fnc_leoCommandSelectPlayer;
