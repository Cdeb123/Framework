#include "..\..\script_macros.hpp"
/*
    File: fn_elsSetStage.sqf
*/
params [
    ["_vehicle",objNull,[objNull]],
    ["_stage",1,[0]]
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
private _profileCfg = missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile;
private _stageCfg = _profileCfg >> "Stages" >> format ["Code%1",_stage];
private _lightVariable = getText (_profileCfg >> "lightVariable");
private _sirenVariable = getText (_profileCfg >> "sirenVariable");
private _lightValue = getNumber (_stageCfg >> "lightValue");
private _sirenValue = getNumber (_stageCfg >> "sirenValue");

_vehicle setVariable ["life_els_stage",_stage,true];
_vehicle setVariable ["life_els_profile",_profile,true];
if !(_lightVariable isEqualTo "") then {_vehicle setVariable [_lightVariable,_lightValue,true];};
if !(_sirenVariable isEqualTo "") then {_vehicle setVariable [_sirenVariable,_sirenValue,true];};
life_els_stage = _stage;
life_els_profile = _profile;
life_els_last_vehicle = _vehicle;

if !(isNil {_vehicle getVariable "life_els_jip"}) then {
    private _oldJip = _vehicle getVariable "life_els_jip";
    _vehicle setVariable ["life_els_jip",nil,true];
    remoteExec ["",_oldJip];
};
private _jip = [_vehicle,_stage,_profile] remoteExecCall ["life_fnc_elsApplyStage",RCLIENT,true];
_vehicle setVariable ["life_els_jip",_jip,true];

private _title = getText (missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile >> "Stages" >> format ["Code%1",_stage] >> "title");
if (_title isEqualTo "") then {_title = format ["Code %1",_stage];};
titleText [_title,"PLAIN"];
