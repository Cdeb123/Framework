#include "..\..\script_macros.hpp"
/*
    File: fn_radialPulloutVehicle.sqf

    LEO convenience action to remove all non-LEO occupants from a vehicle.
*/
params [
    ["_vehicle",objNull,[objNull]]
];

private _filters = ["LandVehicle","Ship","Air"];
if !(playerSide isEqualTo west) exitWith {};
if (isNull _vehicle) then {_vehicle = cursorObject;};
if (isNull _vehicle || {!(KINDOF_ARRAY(_vehicle,_filters))}) exitWith {hint "No vehicle selected.";};
if (player distance _vehicle > 10) exitWith {hint localize "STR_NOTF_VehicleNear";};
if ((crew _vehicle) isEqualTo []) exitWith {hint "No occupants to eject.";};

{
    if !(side _x isEqualTo west) then {
        _x setVariable ["transporting",false,true];
        _x setVariable ["Escorting",false,true];
        [_x] remoteExecCall ["life_fnc_pulloutVeh",_x];
    };
} forEach crew _vehicle;
