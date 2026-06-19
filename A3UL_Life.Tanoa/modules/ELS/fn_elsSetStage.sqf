#include "..\..\script_macros.hpp"
/*
    File: fn_elsSetStage.sqf
*/
params [
    ["_vehicle",objNull,[objNull]],
    ["_stage",1,[0]],
    ["_sirenMode","normal",[""]]
];

if (isNull _vehicle) exitWith {};
private _configData = [_vehicle] call life_fnc_elsGetConfig;
_configData params [
    ["_vehicleCfg",configNull,[configNull]],
    ["_profile","",[""]]
];
if (_vehicleCfg isEqualTo configNull) exitWith {};
if (_profile isEqualTo "") exitWith {};

_stage = (_stage max 1) min 3;
if (_stage < 3 || {!(_sirenMode in ["normal","priority"])}) then {_sirenMode = "normal";};
private _profileCfg = missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile;
private _stageCfg = _profileCfg >> "Stages" >> format ["Code%1",_stage];
private _lightValue = getNumber (_stageCfg >> "lightValue");
private _sirenValue = getNumber (_stageCfg >> "sirenValue");
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
private _lightVariables = [_profileCfg >> "lightVariables",getText (_profileCfg >> "lightVariable")] call _readTextList;
private _sirenVariables = [_profileCfg >> "sirenVariables",getText (_profileCfg >> "sirenVariable")] call _readTextList;
private _lightBooleanVariables = [_profileCfg >> "lightBooleanVariables",""] call _readTextList;
private _sirenBooleanVariables = [_profileCfg >> "sirenBooleanVariables",""] call _readTextList;

_vehicle setVariable ["life_els_stage",_stage,true];
_vehicle setVariable ["life_els_profile",_profile,true];
_vehicle setVariable ["life_els_lights_on",_lightValue > 0,true];
_vehicle setVariable ["life_els_siren_on",_sirenValue > 0,true];
_vehicle setVariable ["life_els_siren_mode",_sirenMode,true];
{_vehicle setVariable [_x,_lightValue,true];} forEach _lightVariables;
{_vehicle setVariable [_x,_sirenValue,true];} forEach _sirenVariables;
{_vehicle setVariable [_x,_lightValue > 0,true];} forEach _lightBooleanVariables;
{_vehicle setVariable [_x,_sirenValue > 0,true];} forEach _sirenBooleanVariables;
life_els_stage = _stage;
life_els_profile = _profile;
life_els_siren_mode = _sirenMode;
life_els_last_vehicle = _vehicle;

if !(isNil {_vehicle getVariable "life_els_jip"}) then {
    private _oldJip = _vehicle getVariable "life_els_jip";
    _vehicle setVariable ["life_els_jip",nil,true];
    remoteExec ["",_oldJip];
};
private _jip = [_vehicle,_stage,_profile,_sirenMode] remoteExecCall ["life_fnc_elsApplyStage",RCLIENT,true];
_vehicle setVariable ["life_els_jip",_jip,true];

private _title = getText (missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile >> "Stages" >> format ["Code%1",_stage] >> "title");
if (_stage isEqualTo 3 && {_sirenMode isEqualTo "priority"}) then {
    private _priorityTitle = getText (_profileCfg >> "priorityTitle");
    if !(_priorityTitle isEqualTo "") then {_title = _priorityTitle;};
};
if (_title isEqualTo "") then {_title = format ["Code %1",_stage];};
titleText [_title,"PLAIN"];
