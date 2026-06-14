#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandPostDocument.sqf
*/
disableSerialization;
if !([] call life_fnc_leoCanCommand) exitWith {hint "You do not have command document permissions.";};

private _display = findDisplay 8100;
if (isNull _display) exitWith {};

private _title = ctrlText (_display displayCtrl 8121);
private _body = ctrlText (_display displayCtrl 8122);
if (_title isEqualTo "" || {_body isEqualTo ""}) exitWith {hint "Command documents need a title and body.";};

private _department = lbData [8102,lbCurSel 8102];
if (_department isEqualTo "") then {_department = missionNamespace getVariable ["life_leo_department","tcsd"];};
if (_department isEqualTo "") then {_department = "tcsd";};

[getPlayerUID player,[_department,_title,_body]] remoteExecCall ["DB_fnc_updateLEOCommandDocument",RSERV];
hint "Command document posted.";
