#include "..\..\script_macros.hpp"
/*
    File: fn_radialVehicleLock.sqf

    F1 convenience wrapper for the normal vehicle lock flow.
*/
params [
    ["_vehicle",objNull,[objNull]]
];

private _filters = ["LandVehicle","Ship","Air"];
if (isNull _vehicle) then {
    _vehicle = if (isNull objectParent player) then {cursorObject} else {vehicle player};
};

if (isNull _vehicle || {!(KINDOF_ARRAY(_vehicle,_filters))}) exitWith {hint "No vehicle selected.";};
if (!alive _vehicle) exitWith {hint "That vehicle is disabled.";};
if !(_vehicle in life_vehicles) exitWith {hint "You do not have keys to that vehicle.";};
if (player distance _vehicle > 20) exitWith {hint localize "STR_NOTF_VehicleNear";};

private _newState = [2,0] select ((locked _vehicle) isEqualTo 2);
private _vehicleName = getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName");
if (_vehicleName isEqualTo "") then {_vehicleName = "Vehicle";};

if (local _vehicle) then {
    _vehicle lock _newState;
} else {
    [_vehicle,_newState] remoteExecCall ["life_fnc_lockVehicle",_vehicle];
};

if (_newState isEqualTo 0) then {
    ["VehicleUnlocked",[_vehicleName]] call BIS_fnc_showNotification;
    [_vehicle,"unlockCarSound",50,1] remoteExec ["life_fnc_say3D",RANY];
} else {
    ["VehicleLocked",[_vehicleName]] call BIS_fnc_showNotification;
    [_vehicle,"lockCarSound",50,1] remoteExec ["life_fnc_say3D",RANY];
};
