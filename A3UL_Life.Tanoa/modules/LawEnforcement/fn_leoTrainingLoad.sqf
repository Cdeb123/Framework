#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8200;
if (isNull _display) exitWith {};

private _ftoRanks = ["senior_deputy","corporal","sergeant","lieutenant","captain","assistant_sheriff","undersheriff","sheriff"];
private _autoFtoRanks = ["lieutenant","captain","assistant_sheriff","undersheriff","sheriff"];
private _phaseLabel = {
    params [["_phase","",[""]]];
    switch (_phase) do {
        case "Candidate": {"Cadet"};
        case "Academy": {"Academy Orientation"};
        case "Ride Along": {"Ride-Along"};
        case "Remedial": {"Remedial Training"};
        default {_phase};
    };
};

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
    private _traineeName = _traineePid;
    {
        if ((getPlayerUID _x) isEqualTo _traineePid) exitWith {_traineeName = name _x;};
    } forEach allPlayers;
    private _idx = lbAdd [8205,format ["%1 | %2 | FTO: %3",_traineeName,[_phase] call _phaseLabel,_ftoPid]];
    lbSetData [8205,_idx,str _x];
} forEach (missionNamespace getVariable ["life_leo_training_roster",[]]);

lbClear 8206;
{
    private _uid = getPlayerUID _x;
    private _charUid = _x getVariable ["characterUID",_uid];
    private _rank = _x getVariable ["leoRank",""];
    private _rankDisplay = _x getVariable ["leoRankDisplay",""];
    if (_rankDisplay isEqualTo "") then {_rankDisplay = if (_rank isEqualTo "") then {"Cadet / Applicant"} else {_rank};};
    private _academyTag = if (_rank in _autoFtoRanks) then {
        "Auto FTO"
    } else {
        if (_rank in _ftoRanks) then {
            "FTO Eligible"
        } else {
            "Cadet"
        };
    };
    private _idx = lbAdd [8206,format ["%1 | %2 | %3",name _x,_rankDisplay,_academyTag]];
    lbSetData [8206,_idx,str [_uid,name _x,_charUid,_rank,_rankDisplay]];
} forEach allPlayers;
if ((lbSize 8206) > 0) then {lbSetCurSel [8206,0];};

lbClear 8207;
{
    private _idx = lbAdd [8207,_x];
    lbSetData [8207,_idx,_x];
} forEach ["Cadet","Academy Orientation","Classroom","Ride-Along","Field Training","Released to Patrol","Remedial Training","Removed"];
lbSetCurSel [8207,0];

private _isAutoFto = (missionNamespace getVariable ["life_leo_rank",""]) in _autoFtoRanks || {["lieutenant","tcsd"] call life_fnc_leoAtLeastRank};
private _canEdit = (["leo.training.edit"] call life_fnc_hasPermission) || {["leo.training.fto"] call life_fnc_hasPermission} || {_isAutoFto};
private _canRoster = _canEdit || {["leo.training.roster"] call life_fnc_hasPermission};
(_display displayCtrl 8211) ctrlEnable _canEdit;
(_display displayCtrl 8212) ctrlEnable _canRoster;
