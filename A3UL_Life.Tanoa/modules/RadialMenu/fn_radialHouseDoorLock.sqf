#include "..\..\script_macros.hpp"
/*
    File: fn_radialHouseDoorLock.sqf

    Locks or unlocks the owned house door nearest to the player.
*/
params [
    ["_house",objNull,[objNull]],
    ["_door",0,[0]]
];

if (isNull _house || {_door <= 0}) then {
    private _nearest = [] call life_fnc_nearestBuildingDoor;
    if (_nearest isEqualTo []) then {
        _house = objNull;
        _door = 0;
    } else {
        _house = _nearest select 0;
        _door = _nearest select 1;
    };
};

if (isNull _house || {_door <= 0}) exitWith {hint localize "STR_House_Door_NotNear";};
if !(_house isKindOf "House_F") exitWith {hint localize "STR_House_Door_NotNear";};
if !(_house in life_vehicles) exitWith {hint localize "STR_Garage_NotOwner";};

private _owner = _house getVariable ["house_owner",[]];
if ((count _owner) > 0 && {!((_owner select 0) isEqualTo getPlayerUID player)}) exitWith {
    hint localize "STR_Garage_NotOwner";
};

private _var = format ["bis_disabled_Door_%1",_door];
private _locked = _house getVariable [_var,0];

if (_locked isEqualTo 0) then {
    _house setVariable [_var,1,true];
    _house animateSource [format ["Door_%1_source",_door],0];
    systemChat localize "STR_House_Door_Lock";
} else {
    _house setVariable [_var,0,true];
    _house animateSource [format ["Door_%1_source",_door],1];
    systemChat localize "STR_House_Door_Unlock";
};
