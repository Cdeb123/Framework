#include "..\..\script_macros.hpp"
/*
    File: fn_radialPutInVehicle.sqf

    Places the escorted player into a nearby vehicle.
*/
params [
    ["_unit",objNull,[objNull]]
];

if !(playerSide isEqualTo west) exitWith {};
if (isNull _unit) then {
    _unit = player getVariable ["escortingPlayer",objNull];
};

if (isNull _unit) exitWith {hint "No escorted player selected.";};
if (!isPlayer _unit) exitWith {};
if (player distance _unit > 6) exitWith {hint "Move closer to the escorted player.";};

[_unit] call life_fnc_putInCar;
