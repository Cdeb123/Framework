#include "..\..\script_macros.hpp"
/*
    File: fn_elsIsConfigured.sqf
*/
params [
    ["_vehicle",objNull,[objNull]]
];

if ((getNumber (missionConfigFile >> "Life_ELS" >> "enabled")) isEqualTo 0) exitWith {false};
if (isNull _vehicle) exitWith {false};
private _data = [_vehicle] call life_fnc_elsGetConfig;
!((_data select 0) isEqualTo configNull);
