#include "..\..\script_macros.hpp"
/*
    File: fn_radialVehicleTrunk.sqf

    Opens vehicle storage through the F1 menu without changing the trunk system.
*/
params [
    ["_vehicle",objNull,[objNull]]
];

private _filters = ["LandVehicle","Ship","Air"];
if (isNull _vehicle) then {
    _vehicle = if (isNull objectParent player) then {vehicle player} else {cursorObject};
};

if (isNull _vehicle || {!(KINDOF_ARRAY(_vehicle,_filters))}) exitWith {hint "No vehicle selected.";};
if (!alive _vehicle) exitWith {hint "That vehicle is disabled.";};
if (player distance _vehicle > 7 && {vehicle player != _vehicle}) exitWith {hint localize "STR_NOTF_VehicleNear";};
if !(_vehicle in life_vehicles || {locked _vehicle isEqualTo 0}) exitWith {hint "That vehicle is locked.";};

[_vehicle] spawn life_fnc_openInventory;
