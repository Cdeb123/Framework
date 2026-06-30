#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingRosterUpdate.sqf
*/
disableSerialization;
private _autoFtoRanks = ["lieutenant","captain","assistant_sheriff","undersheriff","sheriff"];
private _isAutoFto = (missionNamespace getVariable ["life_leo_rank",""]) in _autoFtoRanks || {["lieutenant","tcsd"] call life_fnc_leoAtLeastRank};
private _hasRosterAccess = (["leo.training.edit"] call life_fnc_hasPermission)
    || {["leo.training.fto"] call life_fnc_hasPermission}
    || {["leo.training.roster"] call life_fnc_hasPermission}
    || {_isAutoFto};
if (!_hasRosterAccess) exitWith {hint "You only have view access to the training terminal.";};

private _display = findDisplay 8200;
if (isNull _display) exitWith {};
if ((lbCurSel 8206) < 0) exitWith {hint "Select a trainee.";};

private _target = call compile (lbData [8206,lbCurSel 8206]);
_target params [
    ["_targetUid","",[""]],
    ["_targetName","",[""]],
    ["_characterUid","",[""]],
    ["_targetRank","",[""]],
    ["_targetRankDisplay","",[""]]
];

private _phase = lbData [8207,lbCurSel 8207];
private _notes = ctrlText (_display displayCtrl 8208);
private _department = missionNamespace getVariable ["life_leo_department","tcsd"];
if (_department isEqualTo "") then {_department = "tcsd";};

private _hasOversight = (["leo.department.oversight"] call life_fnc_hasPermission)
    || {["leo.command.owner"] call life_fnc_hasPermission}
    || {[] call life_fnc_isCommunityOwner};
if (!_hasOversight && {_targetUid isEqualTo getPlayerUID player}) exitWith {
    hint "FTO roster updates must be entered by another trainer or command member.";
};

private _myOrder = [missionNamespace getVariable ["life_leo_rank",""],_department] call life_fnc_leoRankOrder;
private _targetOrder = [_targetRank,_department] call life_fnc_leoRankOrder;
if (!_hasOversight && {_targetOrder > 0} && {_myOrder >= 0} && {_targetOrder >= _myOrder}) exitWith {
    hint format ["%1 must be evaluated by a higher-ranking FTO or command member.",_targetName];
};

[getPlayerUID player,"roster",[_targetUid,_characterUid,_department,_phase,getPlayerUID player,_notes]] remoteExecCall ["DB_fnc_updateLEOTraining",RSERV];
hint format ["Training roster updated for %1.",_targetName];
