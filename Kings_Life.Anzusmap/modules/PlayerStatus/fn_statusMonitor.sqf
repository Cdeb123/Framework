#include "..\..\script_macros.hpp"
/*
    File: fn_statusMonitor.sqf

    Description:
    Central loop for temporary medical/condition effects and weight severity.
*/
private _lastVehicle = vehicle player;

for "_i" from 0 to 1 step 0 do {
    private _now = time;
    private _vehicle = vehicle player;

    if (!(_vehicle isEqualTo _lastVehicle)) then {
        if (_vehicle isEqualTo player) then {
            life_seatbelt = false;
            player setVariable ["seatbelt",false,true];
        };
        _lastVehicle = _vehicle;
    };

    private _effects = missionNamespace getVariable ["life_status_effects",[]];
    _effects = _effects select {(_x select 1) > _now};
    life_status_effects = _effects;

    life_effect_poisoned = ({(_x select 0) in ["poison","overdose"]} count _effects) > 0;
    life_effect_virus = ({(_x select 0) isEqualTo "virus"} count _effects) > 0;
    life_effect_drunk = ({(_x select 0) isEqualTo "drunk"} count _effects) > 0 || {(missionNamespace getVariable ["life_alcohol",0]) > 0.20};
    life_effect_overdose = ({(_x select 0) isEqualTo "overdose"} count _effects) > 0;

    if (life_effect_poisoned && {alive player} && {!life_god}) then {
        player setDamage ((damage player + 0.006) min 0.92);
    };

    if (life_effect_virus && {alive player} && {!life_god}) then {
        if (LIFE_SETTINGS(getNumber,"enable_fatigue") isEqualTo 1) then {player setFatigue 1;};
        if ((random 1) > 0.72) then {player setDamage ((damage player + 0.003) min 0.85);};
    };

    if (life_effect_overdose && {alive player} && {!life_god}) then {
        addCamShake [4,1.4,25];
        player setDamage ((damage player + 0.012) min 0.96);
    };

    if (life_effect_drunk && {alive player}) then {
        addCamShake [1.5,0.9,18];
        life_alcohol = ((missionNamespace getVariable ["life_alcohol",0]) - 0.015) max 0;
        if ((missionNamespace getVariable ["life_alcohol",0]) > 1.35) then {
            ["overdose",90,0.15,"alcohol"] call life_fnc_statusEffect;
        };
    };

    if ((missionNamespace getVariable ["life_toxicity",0]) > 0) then {
        life_toxicity = ((missionNamespace getVariable ["life_toxicity",0]) - 0.01) max 0;
    };

    private _ratio = if (life_maxWeight <= 0) then {0} else {life_carryWeight / life_maxWeight};
    switch (true) do {
        case (_ratio >= 1.25): {
            player forceWalk true;
            player setAnimSpeedCoef 0.50;
        };
        case (_ratio >= 1.0): {
            player forceWalk true;
            player setAnimSpeedCoef 0.70;
        };
        case (_ratio >= 0.90): {
            player setAnimSpeedCoef 0.90;
        };
        default {
            if (!(player getVariable ["restrained",false]) && {!life_is_arrested}) then {
                if (isForcedWalk player) then {player forceWalk false;};
            };
            player setAnimSpeedCoef 1;
        };
    };

    [] call life_fnc_hudUpdate;
    uiSleep 5;
};
