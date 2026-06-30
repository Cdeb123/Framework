#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandFire.sqf
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

private _department = lbData [8102,lbCurSel 8102];
private _rank = lbData [8103,lbCurSel 8103];
private _primary = lbData [8104,lbCurSel 8104];

[
    getPlayerUID player,
    _targetUid,
    _targetUid,
    _characterUid,
    _department,
    _rank,
    _primary,
    [_primary],
    [],
    "fired"
] remoteExecCall ["DB_fnc_updateLEOMembership",RSERV];

hint "LEO termination sent to the server.";
