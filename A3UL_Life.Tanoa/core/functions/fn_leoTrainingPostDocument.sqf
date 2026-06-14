#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingPostDocument.sqf
*/
disableSerialization;
private _autoFtoRanks = ["lieutenant","captain","assistant_sheriff","undersheriff","sheriff"];
private _isAutoFto = (missionNamespace getVariable ["life_leo_rank",""]) in _autoFtoRanks || {["lieutenant","tcsd"] call life_fnc_leoAtLeastRank};
if (!((["leo.training.edit"] call life_fnc_hasPermission) || {["leo.training.fto"] call life_fnc_hasPermission} || {_isAutoFto})) exitWith {hint "You only have view access to the training terminal.";};

private _display = findDisplay 8200;
if (isNull _display) exitWith {};

private _title = ctrlText (_display displayCtrl 8203);
private _body = ctrlText (_display displayCtrl 8204);
if (_title isEqualTo "" || {_body isEqualTo ""}) exitWith {hint "Training documents need a title and body.";};

private _department = missionNamespace getVariable ["life_leo_department","tcsd"];
if (_department isEqualTo "") then {_department = "tcsd";};

[getPlayerUID player,"document",[_department,_title,_body]] remoteExecCall ["DB_fnc_updateLEOTraining",RSERV];
hint "Training document posted.";
