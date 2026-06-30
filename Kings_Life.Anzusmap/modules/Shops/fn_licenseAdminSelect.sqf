#include "..\..\script_macros.hpp"
/*
    File: fn_licenseAdminSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8350;
if (isNull _display) exitWith {};
if ((lbCurSel 8351) < 0) exitWith {};

private _license = lbData [8351,lbCurSel 8351];
private _cfg = missionConfigFile >> "Licenses" >> _license;
private _target = missionNamespace getVariable ["life_license_admin_target",objNull];
private _knownStatus = "Unknown until target confirms ownership";
if !(isNull _target) then {
    private _public = _target getVariable [format ["licenseKnown_%1",_license],""];
    if !(_public isEqualTo "") then {_knownStatus = _public;};
};

(_display displayCtrl 8352) ctrlSetStructuredText parseText format [
    "<t color='#f2fbff' size='1.15'>%1</t><br/><t color='#73b8e8'>Administrative Actions</t><br/>Suspend or revoke removes the selected license from the citizen. Issue Firearm grants a separate firearm license.<br/><br/><t color='#73b8e8'>Visible Status</t><br/>%2",
    localize getText (_cfg >> "displayName"),
    _knownStatus
];
