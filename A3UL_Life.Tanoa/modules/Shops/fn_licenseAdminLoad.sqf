#include "..\..\script_macros.hpp"
/*
    File: fn_licenseAdminLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8350;
if (isNull _display) exitWith {};

private _target = missionNamespace getVariable ["life_license_admin_target",objNull];
if (isNull _target) exitWith {closeDialog 0;};

(_display displayCtrl 8353) ctrlSetText format ["Target: %1",_target getVariable ["realname",name _target]];

lbClear 8351;
{
    private _license = configName _x;
    if (getText (_x >> "side") isEqualTo "civ") then {
        private _idx = lbAdd [8351,localize getText (_x >> "displayName")];
        lbSetData [8351,_idx,_license];
    };
} forEach ("true" configClasses (missionConfigFile >> "Licenses"));

if ((lbSize 8351) > 0) then {
    lbSetCurSel [8351,0];
} else {
    (_display displayCtrl 8352) ctrlSetStructuredText parseText "No civilian licenses are configured.";
};
