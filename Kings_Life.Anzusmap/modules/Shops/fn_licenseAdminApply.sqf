#include "..\..\script_macros.hpp"
/*
    File: fn_licenseAdminApply.sqf
*/
params [
    ["_action","",[""]]
];

if (playerSide != west) exitWith {};
private _target = missionNamespace getVariable ["life_license_admin_target",objNull];
if (isNull _target || {!isPlayer _target}) exitWith {hint "No valid citizen selected.";};
if (player distance _target > 5) exitWith {hint "Move closer to the citizen.";};

private _license = "";
if (_action isEqualTo "issue_gun") then {
    _license = "gun";
} else {
    if ((lbCurSel 8351) >= 0) then {
        _license = lbData [8351,lbCurSel 8351];
    };
};
if (_license isEqualTo "") exitWith {};

[player,_license,_action] remoteExecCall ["life_fnc_applyLicenseAction",_target];
hint "License action sent.";
