/*
    File: fn_progressionNextUnlock.sqf
*/
params [
    ["_category","character",[""]]
];

private _info = [_category] call life_fnc_progressionLevelInfo;
private _level = _info select 0;
private _unlocks = getArray (missionConfigFile >> "Life_Progression" >> "Unlocks" >> _category >> "unlocks");
private _next = [];
{
    _x params ["_unlockLevel","_name"];
    if (_unlockLevel > _level) exitWith {_next = [_unlockLevel,_name];};
} forEach _unlocks;

if (_next isEqualTo []) exitWith {["Max known unlocks reached",""]};
[format ["Level %1",_next select 0],_next select 1]
