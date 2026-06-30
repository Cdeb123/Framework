#include "..\..\script_macros.hpp"
/*
    File: fn_elsGetConfig.sqf
*/
params [
    ["_vehicle",objNull,[objNull]]
];

private _vehicleClass = typeOf _vehicle;
private _match = configNull;
private _profile = "";

{
    private _classes = getArray (_x >> "classNames");
    if (_vehicleClass in _classes) exitWith {
        _match = _x;
        _profile = getText (_x >> "profile");
    };
} forEach ("true" configClasses (missionConfigFile >> "Life_ELS" >> "Vehicles"));

[_match,_profile];
