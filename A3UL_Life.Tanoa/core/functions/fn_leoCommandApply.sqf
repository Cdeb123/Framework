#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandApply.sqf
*/
disableSerialization;
if !([] call life_fnc_leoCanCommand) exitWith {hint "You do not have command terminal permissions.";};

private _display = findDisplay 8100;
if (isNull _display) exitWith {};

private _targetUid = ctrlText (_display displayCtrl 8113);
private _characterUid = ctrlText (_display displayCtrl 8114);
if (_targetUid isEqualTo "" && {(lbCurSel 8101) >= 0}) then {
    private _data = call compile (lbData [8101,lbCurSel 8101]);
    _targetUid = _data select 0;
    _characterUid = _data select 2;
};
if (_targetUid isEqualTo "") exitWith {hint "Select an online player or enter a Steam ID.";};
if (_characterUid isEqualTo "") then {_characterUid = _targetUid;};

private _targetName = if ((lbCurSel 8101) >= 0) then {
    (call compile (lbData [8101,lbCurSel 8101])) select 1
} else {
    _targetUid
};

private _department = lbData [8102,lbCurSel 8102];
private _rank = lbData [8103,lbCurSel 8103];
private _primary = lbData [8104,lbCurSel 8104];
private _subdivisions = [_primary];
{
    private _clean = _x splitString " " joinString "";
    if !(_clean isEqualTo "") then {_subdivisions pushBackUnique _clean;};
} forEach ((ctrlText (_display displayCtrl 8115)) splitString ",");

private _permissions = [];
{
    private _clean = _x splitString " " joinString "";
    if !(_clean isEqualTo "") then {_permissions pushBackUnique _clean;};
} forEach ((ctrlText (_display displayCtrl 8116)) splitString ",");

[
    getPlayerUID player,
    _targetUid,
    _targetName,
    _characterUid,
    _department,
    _rank,
    _primary,
    _subdivisions,
    _permissions,
    "active"
] remoteExecCall ["DB_fnc_updateLEOMembership",RSERV];

hint "LEO membership update sent to the server.";
