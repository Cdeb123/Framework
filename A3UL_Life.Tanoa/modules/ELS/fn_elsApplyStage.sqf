#include "..\..\script_macros.hpp"
/*
    File: fn_elsApplyStage.sqf
*/
params [
    ["_vehicle",objNull,[objNull]],
    ["_stage",1,[0]],
    ["_profile","",[""]]
];

if (isNull _vehicle) exitWith {};
if (_profile isEqualTo "") then {_profile = _vehicle getVariable ["life_els_profile",""];};
if (_profile isEqualTo "") exitWith {};

private _profileCfg = missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile;
private _stageCfg = _profileCfg >> "Stages" >> format ["Code%1",(_stage max 1) min 3];
if !(isClass _stageCfg) exitWith {};

private _lightValue = getNumber (_stageCfg >> "lightValue");
private _sirenValue = getNumber (_stageCfg >> "sirenValue");
private _lightVariable = getText (_profileCfg >> "lightVariable");
private _sirenVariable = getText (_profileCfg >> "sirenVariable");
private _lightAnimation = getText (_profileCfg >> "lightAnimation");
private _sirenAnimation = getText (_profileCfg >> "sirenAnimation");
private _animationMode = toLower getText (_profileCfg >> "animationMode");

if !(_lightVariable isEqualTo "") then {_vehicle setVariable [_lightVariable,_lightValue,false];};
if !(_sirenVariable isEqualTo "") then {_vehicle setVariable [_sirenVariable,_sirenValue,false];};

if !(_lightAnimation isEqualTo "") then {
    if (_animationMode isEqualTo "animatesource") then {
        _vehicle animateSource [_lightAnimation,_lightValue,true];
    } else {
        _vehicle animate [_lightAnimation,_lightValue,true];
    };
};

if !(_sirenAnimation isEqualTo "") then {
    if (_animationMode isEqualTo "animatesource") then {
        _vehicle animateSource [_sirenAnimation,_sirenValue,true];
    } else {
        _vehicle animate [_sirenAnimation,_sirenValue,true];
    };
};

if ((getNumber (_profileCfg >> "engineOn")) isEqualTo 1 && {_stage > 1}) then {
    _vehicle engineOn true;
};

if ((getNumber (_profileCfg >> "forceHeadlights")) isEqualTo 1) then {
    if (_stage > 1) then {
        player action ["lightOn",_vehicle];
    } else {
        player action ["lightOff",_vehicle];
    };
};

private _sound = getText (_profileCfg >> "fallbackSirenSound");
if !(_sound isEqualTo "") then {
    if (_stage isEqualTo 3) then {
        if ((isNil "life_els_fallback_siren_loop") || {scriptDone life_els_fallback_siren_loop}) then {
            life_els_fallback_siren_loop = [_vehicle,_sound,getNumber (_profileCfg >> "fallbackSirenDistance"),getNumber (_profileCfg >> "fallbackSirenDuration")] spawn {
                params ["_veh","_snd","_distance","_duration"];
                while {alive _veh && {(_veh getVariable ["life_els_stage",1]) isEqualTo 3}} do {
                    _veh say3D [_snd,_distance,1];
                    sleep _duration;
                };
            };
        };
    };
};
