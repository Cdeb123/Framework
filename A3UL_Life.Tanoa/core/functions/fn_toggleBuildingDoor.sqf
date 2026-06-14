#include "..\..\script_macros.hpp"
/*
    File: fn_toggleBuildingDoor.sqf

    Opens or closes the nearest unlocked map/building door.
*/
params [
    ["_building",objNull,[objNull]],
    ["_door",0,[0]]
];

if (isNull _building || {_door <= 0}) then {
    private _nearest = [] call life_fnc_nearestBuildingDoor;
    if (_nearest isEqualTo []) exitWith {hint localize "STR_House_Door_NotNear"; false};
    _building = _nearest select 0;
    _door = _nearest select 1;
};

if ((_building getVariable [format ["bis_disabled_Door_%1",_door],0]) isEqualTo 1) exitWith {
    hint localize "STR_House_FedDoor_Locked";
    false
};

if ((_building getVariable [format ["life_door_locked_%1",_door],_building getVariable ["life_door_locked",0]]) isEqualTo 1) exitWith {
    hint localize "STR_House_FedDoor_Locked";
    false
};

private _doorCfg = missionConfigFile >> "Life_DoorAccess";
private _sourcePatterns = getArray (_doorCfg >> "sourcePatterns");
private _animationPatterns = getArray (_doorCfg >> "animationPatterns");

if (_sourcePatterns isEqualTo []) then {
    _sourcePatterns = ["Door_%1_source","Door_%1_sound_source","Door_%1_noSound_source"];
};

if (_animationPatterns isEqualTo []) then {
    _animationPatterns = ["door_%1a_move","door_%1_rot","door_%1a_rot"];
};

private _sourceNames = [];
private _animationNames = [];
private _pushDoorName = {
    params [
        ["_target",[],[[]]],
        ["_name","",[""]]
    ];

    if (_name isEqualTo "") exitWith {};

    if ((["%1",_name] call BIS_fnc_inString)) then {
        _target pushBackUnique format [_name,_door];
    } else {
        _target pushBackUnique _name;
    };
};

{
    _sourceNames pushBackUnique format [_x,_door];
} forEach _sourcePatterns;

{
    _animationNames pushBackUnique format [_x,_door];
} forEach _animationPatterns;

{
    [_sourceNames,_x] call _pushDoorName;
} forEach (_building getVariable [format ["life_door_sources_%1",_door],_building getVariable ["life_door_sources",[]]]);

{
    [_animationNames,_x] call _pushDoorName;
} forEach (_building getVariable [format ["life_door_animations_%1",_door],_building getVariable ["life_door_animations",[]]]);

private _open = false;
{
    if ((_building animationSourcePhase _x) >= 0.5 || {(_building animationPhase _x) >= 0.5}) exitWith {
        _open = true;
    };
} forEach (_sourceNames + _animationNames);

private _target = [1,0] select _open;
{
    _building animateSource [_x,_target];
} forEach _sourceNames;

{
    _building animate [_x,_target];
} forEach _animationNames;

true
