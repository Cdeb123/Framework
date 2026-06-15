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
private _phase = [0,1] select (_newState isEqualTo 0);
private _doorAnimations = [
    "door_back_R","door_back_L","door_R","door_L","Door_L_source","Door_rear","Door_rear_source",
    "Door_1_source","Door_2_source","Door_3_source","Door_LM","Door_RM","Door_LF","Door_RF",
    "Door_LB","Door_RB","DoorL_Front_Open","DoorR_Front_Open","DoorL_Back_Open","DoorR_Back_Open "
];

if (local _vehicle) then {
    _vehicle lock _newState;
} else {
    [_vehicle,_newState] remoteExecCall ["life_fnc_lockVehicle",_vehicle];
};

{
    _vehicle animateDoor [_x,_phase];
} forEach _doorAnimations;

if (_newState isEqualTo 0) then {
    systemChat localize "STR_MISC_VehUnlock";
    [_vehicle,"unlockCarSound",50,1] remoteExec ["life_fnc_say3D",RANY];
} else {
    systemChat localize "STR_MISC_VehLock";
    [_vehicle,"lockCarSound",50,1] remoteExec ["life_fnc_say3D",RANY];
};
