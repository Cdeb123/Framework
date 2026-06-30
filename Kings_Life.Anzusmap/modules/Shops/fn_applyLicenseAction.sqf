#include "..\..\script_macros.hpp"
/*
    File: fn_applyLicenseAction.sqf
*/
params [
    ["_officer",objNull,[objNull]],
    ["_license","",[""]],
    ["_action","",[""]]
];

if (isNull _officer || {!isPlayer _officer}) exitWith {};
if !(isClass (missionConfigFile >> "Licenses" >> _license)) exitWith {};

private _side = getText (missionConfigFile >> "Licenses" >> _license >> "side");
if !(_side isEqualTo "civ") exitWith {};

private _displayName = localize getText (missionConfigFile >> "Licenses" >> _license >> "displayName");
private _value = switch (_action) do {
    case "issue_gun": {true};
    case "suspend": {false};
    case "revoke": {false};
    default {missionNamespace getVariable [LICENSE_VARNAME(_license,_side),false]};
};

missionNamespace setVariable [LICENSE_VARNAME(_license,_side),_value];
player setVariable [format ["licenseKnown_%1",_license],["Not owned","Owned"] select _value,true];
[2] call SOCK_fnc_updatePartial;

private _actionName = switch (_action) do {
    case "issue_gun": {"issued"};
    case "suspend": {"suspended"};
    case "revoke": {"revoked"};
    default {"updated"};
};

hint format ["%1 has been %2 by %3.",_displayName,_actionName,_officer getVariable ["realname",name _officer]];
[player getVariable ["realname",name player],_displayName,_actionName] remoteExecCall ["life_fnc_licenseAdminNotify",_officer];
