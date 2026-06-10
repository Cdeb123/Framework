#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8200;
if (isNull _display) exitWith {};

lbClear 8201;
{
    _x params [
        ["_id",0,[0]],
        ["_department","",[""]],
        ["_title","",[""]],
        ["_body","",[""]],
        ["_createdBy","",[""]],
        ["_createdAt","",[""]]
    ];
    private _idx = lbAdd [8201,format ["%1 | %2",_department,_title]];
    lbSetData [8201,_idx,str _x];
} forEach (missionNamespace getVariable ["life_leo_training_docs",[]]);
if ((lbSize 8201) > 0) then {lbSetCurSel [8201,0]; [] call life_fnc_leoTrainingSelectDocument;};

lbClear 8205;
{
    _x params [
        ["_traineePid","",[""]],
        ["_characterUid","",[""]],
        ["_department","",[""]],
        ["_phase","",[""]],
        ["_ftoPid","",[""]],
        ["_notes","",[""]]
    ];
    private _idx = lbAdd [8205,format ["%1 | %2 | FTO %3",_department,_phase,_ftoPid]];
    lbSetData [8205,_idx,str _x];
} forEach (missionNamespace getVariable ["life_leo_training_roster",[]]);

lbClear 8206;
{
    private _uid = getPlayerUID _x;
    private _charUid = _x getVariable ["characterUID",_uid];
    private _idx = lbAdd [8206,format ["%1 | %2",name _x,_uid]];
    lbSetData [8206,_idx,str [_uid,name _x,_charUid]];
} forEach allPlayers;
if ((lbSize 8206) > 0) then {lbSetCurSel [8206,0];};

lbClear 8207;
{
    private _idx = lbAdd [8207,_x];
    lbSetData [8207,_idx,_x];
} forEach ["Candidate","Academy","Ride Along","Released to Patrol","Remedial","Removed"];
lbSetCurSel [8207,0];

private _canEdit = ["leo.training.edit"] call life_fnc_hasPermission;
(_display displayCtrl 8211) ctrlEnable _canEdit;
(_display displayCtrl 8212) ctrlEnable _canEdit;
