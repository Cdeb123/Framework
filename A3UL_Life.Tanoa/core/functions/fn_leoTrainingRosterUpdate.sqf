#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingRosterUpdate.sqf
*/
disableSerialization;
if !(["leo.training.edit"] call life_fnc_hasPermission) exitWith {hint "You only have view access to the training terminal.";};

private _display = findDisplay 8200;
if (isNull _display) exitWith {};
if ((lbCurSel 8206) < 0) exitWith {hint "Select a trainee.";};

private _target = call compile (lbData [8206,lbCurSel 8206]);
_target params [
    ["_targetUid","",[""]],
    ["_targetName","",[""]],
    ["_characterUid","",[""]]
];

private _phase = lbData [8207,lbCurSel 8207];
private _notes = ctrlText (_display displayCtrl 8208);
private _department = missionNamespace getVariable ["life_leo_department","tcsd"];
if (_department isEqualTo "") then {_department = "tcsd";};

[getPlayerUID player,"roster",[_targetUid,_characterUid,_department,_phase,getPlayerUID player,_notes]] remoteExecCall ["DB_fnc_updateLEOTraining",RSERV];
hint format ["Training roster updated for %1.",_targetName];
