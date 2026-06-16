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
private _lightsOn = _lightValue > 0;
private _sirenOn = _sirenValue > 0;

private _readTextList = {
    params [
        ["_cfg",configNull,[configNull]],
        ["_legacy","",[""]]
    ];
    private _values = [];
    if (isArray _cfg) then {
        {
            if (_x isEqualType "" && {!(_x isEqualTo "")}) then {_values pushBackUnique _x;};
        } forEach (getArray _cfg);
    };
    if (isText _cfg) then {
        private _value = getText _cfg;
        if !(_value isEqualTo "") then {_values pushBackUnique _value;};
    };
    if !(_legacy isEqualTo "") then {_values pushBackUnique _legacy;};
    _values;
};

private _sourceMatches = {
    params [
        ["_source","",[""]],
        ["_terms",[],[[]]]
    ];
    private _sourceLower = toLower _source;
    (_terms findIf {[_x,_sourceLower] call BIS_fnc_inString}) >= 0;
};

private _autoSources = {
    params [
        ["_target",objNull,[objNull]],
        ["_terms",[],[[]]]
    ];
    private _sources = [];
    {
        private _name = configName _x;
        if ([_name,_terms] call _sourceMatches) then {_sources pushBackUnique _name;};
    } forEach ("true" configClasses (configFile >> "CfgVehicles" >> typeOf _target >> "AnimationSources"));
    _sources;
};

private _lightVariables = [_profileCfg >> "lightVariables",getText (_profileCfg >> "lightVariable")] call _readTextList;
private _sirenVariables = [_profileCfg >> "sirenVariables",getText (_profileCfg >> "sirenVariable")] call _readTextList;
private _lightBooleanVariables = [_profileCfg >> "lightBooleanVariables",""] call _readTextList;
private _sirenBooleanVariables = [_profileCfg >> "sirenBooleanVariables",""] call _readTextList;
private _lightAnimations = [_profileCfg >> "lightAnimations",getText (_profileCfg >> "lightAnimation")] call _readTextList;
private _sirenAnimations = [_profileCfg >> "sirenAnimations",getText (_profileCfg >> "sirenAnimation")] call _readTextList;
private _lightSources = [_profileCfg >> "lightSources",""] call _readTextList;
private _sirenSources = [_profileCfg >> "sirenSources",""] call _readTextList;

if ((getNumber (_profileCfg >> "autoDetectLightSources")) isEqualTo 1) then {
    {_lightSources pushBackUnique _x;} forEach ([_vehicle,["light","beacon","strobe","emergency","led"]] call _autoSources);
};

if ((getNumber (_profileCfg >> "autoDetectSirenSources")) isEqualTo 1) then {
    {_sirenSources pushBackUnique _x;} forEach ([_vehicle,["siren","speaker"]] call _autoSources);
};

_vehicle setVariable ["life_els_lights_on",_lightsOn,false];
_vehicle setVariable ["life_els_siren_on",_sirenOn,false];
{_vehicle setVariable [_x,_lightValue,false];} forEach _lightVariables;
{_vehicle setVariable [_x,_sirenValue,false];} forEach _sirenVariables;
{_vehicle setVariable [_x,_lightsOn,false];} forEach _lightBooleanVariables;
{_vehicle setVariable [_x,_sirenOn,false];} forEach _sirenBooleanVariables;

{
    _vehicle animate [_x,_lightValue,true];
    _vehicle animateSource [_x,_lightValue,true];
} forEach _lightAnimations;

{_vehicle animateSource [_x,_lightValue,true];} forEach _lightSources;

{
    _vehicle animate [_x,_sirenValue,true];
    _vehicle animateSource [_x,_sirenValue,true];
} forEach _sirenAnimations;

{_vehicle animateSource [_x,_sirenValue,true];} forEach _sirenSources;

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

if ((getNumber (_profileCfg >> "localLightpoints")) isEqualTo 1 && {_lightsOn}) then {
    private _existingLightLoop = _vehicle getVariable ["life_els_light_loop",scriptNull];
    if (isNull _existingLightLoop || {scriptDone _existingLightLoop}) then {
        private _lightLoop = [_vehicle,_profile] spawn {
            params [
                ["_veh",objNull,[objNull]],
                ["_profileName","",[""]]
            ];
            if (isNull _veh || {_profileName isEqualTo ""}) exitWith {};

            private _cfg = missionConfigFile >> "Life_ELS" >> "Profiles" >> _profileName;
            private _box = boundingBoxReal _veh;
            _box params ["_min","_max"];
            private _halfWidth = ((abs (_min select 0)) max (abs (_max select 0))) max 0.7;
            private _centerY = ((_min select 1) + (_max select 1)) / 2;
            private _roofZ = ((_max select 2) * 0.65) max 0.6;
            private _leftOffset = getArray (_cfg >> "lightLeftOffset");
            private _rightOffset = getArray (_cfg >> "lightRightOffset");
            if !((count _leftOffset) isEqualTo 3) then {_leftOffset = [0 - (0.45 * _halfWidth),_centerY,_roofZ];};
            if !((count _rightOffset) isEqualTo 3) then {_rightOffset = [0.45 * _halfWidth,_centerY,_roofZ];};

            private _leftColor = getArray (_cfg >> "leftLightColor");
            private _rightColor = getArray (_cfg >> "rightLightColor");
            if !((count _leftColor) isEqualTo 3) then {_leftColor = [20,0.1,0.1];};
            if !((count _rightColor) isEqualTo 3) then {_rightColor = [0.1,0.1,20];};
            private _leftAmbient = [(_leftColor select 0) min 0.3,(_leftColor select 1) min 0.3,(_leftColor select 2) min 0.3];
            private _rightAmbient = [(_rightColor select 0) min 0.3,(_rightColor select 1) min 0.3,(_rightColor select 2) min 0.3];

            private _flashDelay = getNumber (_cfg >> "lightTime");
            if (_flashDelay <= 0) then {_flashDelay = 0.18;};
            private _brightness = getNumber (_cfg >> "lightBrightness");
            if (_brightness <= 0) then {_brightness = 6;};
            private _intensity = getNumber (_cfg >> "lightIntensity");
            if (_intensity <= 0) then {_intensity = 10;};
            private _flareSize = getNumber (_cfg >> "lightFlareSize");
            if (_flareSize <= 0) then {_flareSize = 0.38;};
            private _flareMaxDistance = getNumber (_cfg >> "lightFlareMaxDistance");
            if (_flareMaxDistance <= 0) then {_flareMaxDistance = 150;};

            private _lightLeft = "#lightpoint" createVehicleLocal getPos _veh;
            private _lightRight = "#lightpoint" createVehicleLocal getPos _veh;

            _lightLeft setLightColor _leftColor;
            _lightLeft setLightAmbient _leftAmbient;
            _lightLeft setLightBrightness 0;
            _lightLeft setLightAttenuation [0.181,0,1000,130];
            _lightLeft setLightIntensity _intensity;
            _lightLeft setLightFlareSize _flareSize;
            _lightLeft setLightFlareMaxDistance _flareMaxDistance;
            _lightLeft setLightUseFlare true;
            _lightLeft setLightDayLight true;
            _lightLeft lightAttachObject [_veh,_leftOffset];

            _lightRight setLightColor _rightColor;
            _lightRight setLightAmbient _rightAmbient;
            _lightRight setLightBrightness 0;
            _lightRight setLightAttenuation [0.181,0,1000,130];
            _lightRight setLightIntensity _intensity;
            _lightRight setLightFlareSize _flareSize;
            _lightRight setLightFlareMaxDistance _flareMaxDistance;
            _lightRight setLightUseFlare true;
            _lightRight setLightDayLight true;
            _lightRight lightAttachObject [_veh,_rightOffset];

            private _leftActive = true;
            while {alive _veh && {_veh getVariable ["life_els_lights_on",false]}} do {
                if (_leftActive) then {
                    _lightRight setLightBrightness 0;
                    sleep 0.05;
                    _lightLeft setLightBrightness _brightness;
                } else {
                    _lightLeft setLightBrightness 0;
                    sleep 0.05;
                    _lightRight setLightBrightness _brightness;
                };
                _leftActive = !_leftActive;
                sleep _flashDelay;
            };

            deleteVehicle _lightLeft;
            deleteVehicle _lightRight;
        };
        _vehicle setVariable ["life_els_light_loop",_lightLoop,false];
    };
};

private _sound = getText (_profileCfg >> "fallbackSirenSound");
if !(_sound isEqualTo "") then {
    if (_sirenOn) then {
        private _existingSirenLoop = _vehicle getVariable ["life_els_siren_loop",scriptNull];
        if (isNull _existingSirenLoop || {scriptDone _existingSirenLoop}) then {
            private _sirenLoop = [_vehicle,_sound,getNumber (_profileCfg >> "fallbackSirenDistance"),getNumber (_profileCfg >> "fallbackSirenDuration")] spawn {
                params [
                    ["_veh",objNull,[objNull]],
                    ["_snd","",[""]],
                    ["_distance",500,[0]],
                    ["_duration",4.87,[0]]
                ];
                if (_distance <= 0) then {_distance = 500;};
                if (_duration <= 0) then {_duration = 4.87;};
                while {alive _veh && {_veh getVariable ["life_els_siren_on",false]}} do {
                    _veh say3D [_snd,_distance,1];
                    sleep _duration;
                };
            };
            _vehicle setVariable ["life_els_siren_loop",_sirenLoop,false];
            life_els_fallback_siren_loop = _sirenLoop;
        };
    };
};
