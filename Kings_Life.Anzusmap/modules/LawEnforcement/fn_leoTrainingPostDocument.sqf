#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingPostDocument.sqf
*/
disableSerialization;
private _autoTrainerRanks = ["lieutenant","captain","major","undersheriff","sheriff","commissioner"];
private _isAutoTrainer = (missionNamespace getVariable ["life_leo_rank",""]) in _autoTrainerRanks || {["lieutenant","kcso"] call life_fnc_leoAtLeastRank};
if (!((["leo.training.edit"] call life_fnc_hasPermission) || {["leo.training.admin_services"] call life_fnc_hasPermission} || {_isAutoTrainer})) exitWith {hint "You only have view access to the Admin Services terminal.";};

private _display = findDisplay 8200;
if (isNull _display) exitWith {};

private _title = ctrlText (_display displayCtrl 8203);
private _body = ctrlText (_display displayCtrl 8204);
if (_title isEqualTo "" || {_body isEqualTo ""}) exitWith {hint "Admin Services documents need a title and body.";};

private _department = missionNamespace getVariable ["life_leo_department","kcso"];
if (_department isEqualTo "") then {_department = "kcso";};

[getPlayerUID player,"document",[_department,_title,_body]] remoteExecCall ["DB_fnc_updateLEOTraining",RSERV];
hint "Admin Services document posted.";
