#include "..\..\script_macros.hpp"
/*
    File: fn_elsKey.sqf
*/
params [
    ["_code",-1,[0]]
];

private _request = switch (_code) do {
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code1Key")): {["stage",1]};
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code2Key")): {["stage",2]};
    case (getNumber (missionConfigFile >> "Life_ELS" >> "code3Key")): {["stage",3]};
    case (getNumber (missionConfigFile >> "Life_ELS" >> "airhornKey")): {["airhorn",0]};
    default {["",0]};
};

_request params [
    ["_action","",[""]],
    ["_stage",0,[0]]
];

if (_action isEqualTo "") exitWith {false};
if ((getNumber (missionConfigFile >> "Life_ELS" >> "enabled")) isEqualTo 0) exitWith {false};
if ((getNumber (missionConfigFile >> "Life_ELS" >> "policeOnly")) isEqualTo 1 && {!(playerSide isEqualTo west)}) exitWith {false};
if (vehicle player isEqualTo player) exitWith {false};

private _vehicle = vehicle player;
if ((getNumber (missionConfigFile >> "Life_ELS" >> "requireDriver")) isEqualTo 1 && {!(driver _vehicle isEqualTo player)}) exitWith {false};
if !([_vehicle] call life_fnc_elsIsConfigured) exitWith {false};

if (_action isEqualTo "airhorn") exitWith {
    [_vehicle] call life_fnc_elsAirhorn;
    true;
};

[_vehicle,_stage] call life_fnc_elsSetStage;
true;
