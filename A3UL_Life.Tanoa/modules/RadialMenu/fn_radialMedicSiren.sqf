#include "..\..\script_macros.hpp"
/*
    File: fn_radialMedicSiren.sqf

    EMS siren toggle for the F1 menu.
*/
params [
    ["_vehicle",objNull,[objNull]]
];

if !(playerSide isEqualTo independent) exitWith {};
if (isNull _vehicle) then {_vehicle = vehicle player;};
if (isNull _vehicle || {_vehicle isEqualTo player}) exitWith {};
if !(driver _vehicle isEqualTo player) exitWith {};
if (life_siren_active) exitWith {};

[] spawn {
    life_siren_active = true;
    sleep 4.7;
    life_siren_active = false;
};

if (isNil {_vehicle getVariable "siren"}) then {_vehicle setVariable ["siren",false,true];};

if (_vehicle getVariable ["siren",false]) then {
    titleText [localize "STR_MISC_SirensOFF","PLAIN"];
    _vehicle setVariable ["siren",false,true];
    if !(isNil {_vehicle getVariable "sirenJIP"}) then {
        private _jip = _vehicle getVariable "sirenJIP";
        _vehicle setVariable ["sirenJIP",nil,true];
        remoteExec ["",_jip];
    };
} else {
    titleText [localize "STR_MISC_SirensON","PLAIN"];
    _vehicle setVariable ["siren",true,true];
    private _jip = [_vehicle] remoteExec ["life_fnc_medicSiren",RCLIENT,true];
    _vehicle setVariable ["sirenJIP",_jip,true];
};
