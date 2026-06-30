#include "..\..\script_macros.hpp"
/*
    File: fn_statusEffect.sqf

    Params:
        0: STRING - poison, virus, drunk, toxicity, overdose, clear
        1: NUMBER - duration in seconds
        2: NUMBER - intensity
        3: STRING - source label
*/
params [
    ["_effect","",[""]],
    ["_duration",60,[0]],
    ["_intensity",1,[0]],
    ["_source","",[""]]
];

_effect = toLower _effect;
if (_effect isEqualTo "") exitWith {};

private _effects = missionNamespace getVariable ["life_status_effects",[]];
private _now = time;

if (_effect isEqualTo "clear") exitWith {
    life_status_effects = [];
    life_toxicity = 0;
    life_alcohol = 0;
    life_effect_poisoned = false;
    life_effect_virus = false;
    life_effect_drunk = false;
    life_effect_overdose = false;
    [] call life_fnc_hudUpdate;
};

if (_effect in ["toxicity","overdose"]) then {
    life_toxicity = ((missionNamespace getVariable ["life_toxicity",0]) + _intensity) min 2;
    if (life_toxicity >= 1 || {_effect isEqualTo "overdose"}) then {
        _effect = "overdose";
        _duration = _duration max 90;
    };
};

if (_effect isEqualTo "drunk") then {
    life_alcohol = ((missionNamespace getVariable ["life_alcohol",0]) + _intensity) min 2;
};

_effects = _effects select {(_x select 0) != _effect};
_effects pushBack [_effect,_now + (_duration max 1),_intensity,_source];
life_status_effects = _effects;

switch (_effect) do {
    case "poison": {life_effect_poisoned = true;};
    case "virus": {life_effect_virus = true;};
    case "drunk": {life_effect_drunk = true;};
    case "overdose": {
        life_effect_overdose = true;
        life_effect_poisoned = true;
    };
};

[] call life_fnc_hudUpdate;
