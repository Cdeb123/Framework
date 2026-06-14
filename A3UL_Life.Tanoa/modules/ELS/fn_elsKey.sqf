#include "..\..\script_macros.hpp"
/*
    File: fn_elsKey.sqf
*/
params [
    ["_code",-1,[0]]
];

private _stage = switch (_code) do {
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code1Key")): {1};
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code2Key")): {2};
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code3Key")): {3};
    default {0};
};

if (_stage isEqualTo 0) exitWith {false};
if ((getNumber (missionConfigFile >> "Life_ELS" >> "enabled")) isEqualTo 0) exitWith {false};
if ((getNumber (missionConfigFile >> "Life_ELS" >> "policeOnly")) isEqualTo 1 && {!(playerSide isEqualTo west)}) exitWith {false};
if (vehicle player isEqualTo player) exitWith {false};

private _vehicle = vehicle player;
if ((getNumber (missionConfigFile >> "Life_ELS" >> "requireDriver")) isEqualTo 1 && {!(driver _vehicle isEqualTo player)}) exitWith {false};
if !([_vehicle] call life_fnc_elsIsConfigured) exitWith {false};

[_vehicle,_stage] call life_fnc_elsSetStage;
true;
