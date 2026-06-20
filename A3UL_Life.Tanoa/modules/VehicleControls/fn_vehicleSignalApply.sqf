/* Applies indicator animations and a local amber-light fallback on each client. */
params [
    ["_vehicle",objNull,[objNull]],
    ["_state","off",[""]]
];
if (isNull _vehicle) exitWith {};

private _oldLoop = _vehicle getVariable ["life_signal_local_loop",scriptNull];
if (!isNull _oldLoop && {!scriptDone _oldLoop}) then {terminate _oldLoop;};
_vehicle setVariable ["life_signal_local_loop",scriptNull,false];

private _loop = [_vehicle,_state] spawn {
    params ["_veh","_wantedState"];
    private _left = getArray (missionConfigFile >> "Life_VehicleControls" >> "leftSignalSources");
    private _right = getArray (missionConfigFile >> "Life_VehicleControls" >> "rightSignalSources");
    private _hasSignalTerm = {
        params ["_name"];
        private _n = toLower _name;
        (["signal",_n] call BIS_fnc_inString) || {(["indicator",_n] call BIS_fnc_inString)} || {(["blinker",_n] call BIS_fnc_inString)} || {(["turn",_n] call BIS_fnc_inString)}
    };
    if ((getNumber (missionConfigFile >> "Life_VehicleControls" >> "signalAutoDetectSources")) isEqualTo 1) then {
        {
            private _name = configName _x;
            private _lower = toLower _name;
            if ([_name] call _hasSignalTerm) then {
                if ((["left",_lower] call BIS_fnc_inString) || {(["_l",_lower] call BIS_fnc_inString)} || {(["l_",_lower] call BIS_fnc_inString)}) then {_left pushBackUnique _name;};
                if ((["right",_lower] call BIS_fnc_inString) || {(["_r",_lower] call BIS_fnc_inString)} || {(["r_",_lower] call BIS_fnc_inString)}) then {_right pushBackUnique _name;};
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles" >> typeOf _veh >> "AnimationSources"));
    };

    private _apply = {
        params ["_sources","_phase"];
        if (_phase isEqualType true) then {_phase = [0,1] select _phase;};
        {_veh animate [_x,_phase,true]; _veh animateSource [_x,_phase,true];} forEach _sources;
    };
    private _leftLight = objNull;
    private _rightLight = objNull;
    if (_left isEqualTo [] && {_right isEqualTo []} && {(getNumber (missionConfigFile >> "Life_VehicleControls" >> "signalFallbackLights")) isEqualTo 1}) then {
        private _box = boundingBoxReal _veh;
        private _min = _box select 0;
        private _max = _box select 1;
        private _rear = (_min select 1) - 0.08;
        private _z = ((_min select 2) + 0.45) max 0.35;
        private _halfWidth = ((abs (_min select 0)) max (abs (_max select 0))) * 0.78;
        _leftLight = "#lightpoint" createVehicleLocal getPos _veh;
        _rightLight = "#lightpoint" createVehicleLocal getPos _veh;
        {
            _x setLightColor [18,5.4,0.05];
            _x setLightAmbient [0.18,0.05,0];
            _x setLightBrightness 0;
            _x setLightUseFlare true;
            _x setLightFlareSize 0.20;
            _x setLightFlareMaxDistance 90;
            _x setLightDayLight true;
        } forEach [_leftLight,_rightLight];
        _leftLight lightAttachObject [_veh,[0 - _halfWidth,_rear,_z]];
        _rightLight lightAttachObject [_veh,[_halfWidth,_rear,_z]];
    };

    private _interval = getNumber (missionConfigFile >> "Life_VehicleControls" >> "signalInterval");
    if (_interval <= 0) then {_interval = 0.46;};
    while {alive _veh && {(_veh getVariable ["life_signal_state","off"]) isEqualTo _wantedState} && {!(_wantedState isEqualTo "off")}} do {
        private _leftOn = _wantedState in ["left","hazard"];
        private _rightOn = _wantedState in ["right","hazard"];
        [_left,_leftOn] call _apply;
        [_right,_rightOn] call _apply;
        if (!isNull _leftLight) then {_leftLight setLightBrightness ([0,5] select _leftOn);};
        if (!isNull _rightLight) then {_rightLight setLightBrightness ([0,5] select _rightOn);};
        uiSleep _interval;
        [_left,0] call _apply;
        [_right,0] call _apply;
        if (!isNull _leftLight) then {_leftLight setLightBrightness 0;};
        if (!isNull _rightLight) then {_rightLight setLightBrightness 0;};
        uiSleep _interval;
    };
    [_left,0] call _apply;
    [_right,0] call _apply;
    if (!isNull _leftLight) then {deleteVehicle _leftLight;};
    if (!isNull _rightLight) then {deleteVehicle _rightLight;};
};
_vehicle setVariable ["life_signal_local_loop",_loop,false];
