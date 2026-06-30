#include "..\..\script_macros.hpp"
/*
    File: fn_craftingItemTitle.sqf
*/
params [
    ["_className","",[""]],
    ["_outputType","gear",[""]]
];

if (_className isEqualTo "") exitWith {""};

if ((toLower _outputType) isEqualTo "virtual" || {isClass (missionConfigFile >> "VirtualItems" >> _className)}) exitWith {
    private _name = getText (missionConfigFile >> "VirtualItems" >> _className >> "displayName");
    if (_name isEqualTo "") exitWith {_className};
    if ((_name select [0,4]) isEqualTo "STR_") then {localize _name} else {_name}
};

private _details = [_className] call life_fnc_fetchCfgDetails;
private _name = _details param [1,"",[""]];
if (_name isEqualTo "") then {
    _name = getText (configFile >> "CfgVehicles" >> _className >> "displayName");
};
if (_name isEqualTo "") then {_name = _className;};
_name
