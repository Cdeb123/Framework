#include "..\..\script_macros.hpp"
/*
    File: fn_nearestBuildingDoor.sqf

    Finds the closest usable building door near the player. This covers vanilla
    map buildings and modded buildings that expose door animation sources.
*/
params [
    ["_maxDistance",-1,[0]]
];

private _doorCfg = missionConfigFile >> "Life_DoorAccess";
if (_maxDistance <= 0) then {
    _maxDistance = getNumber (_doorCfg >> "doorSearchDistance");
    if (_maxDistance <= 0) then {_maxDistance = 3.4;};
};

private _searchRadius = getNumber (_doorCfg >> "buildingSearchRadius");
if (_searchRadius <= 0) then {_searchRadius = 9;};

private _selectionPatterns = getArray (_doorCfg >> "selectionPatterns");
if (_selectionPatterns isEqualTo []) then {
    _selectionPatterns = ["Door_%1_trigger","Door_%1_action","Door_%1_button","Door_%1_handle"];
};

private _candidates = [];
private _doorCount = {
    params [["_object",objNull,[objNull]]];
    if (isNull _object) exitWith {0};

    private _objectCount = _object getVariable ["life_door_count",-1];
    if (_objectCount > 0) exitWith {_objectCount};

    private _cachedCount = _object getVariable ["life_detected_door_count",-1];
    if (_cachedCount >= 0) exitWith {_cachedCount};

    private _vehicleCfg = configFile >> "CfgVehicles" >> (typeOf _object);
    private _count = getNumber (_vehicleCfg >> "numberOfDoors");
    if (_count > 0) exitWith {
        _object setVariable ["life_detected_door_count",_count,false];
        _count
    };

    private _doorNames = [];
    private _numbers = [];
    {
        private _name = configName _x;
        private _lowerName = toLower _name;
        if (["door",_lowerName] call BIS_fnc_inString) then {
            _doorNames pushBackUnique _lowerName;

            private _digits = [];
            {
                if (_x >= 48 && {_x <= 57}) then {
                    _digits pushBack _x;
                };
            } forEach toArray _name;

            if ((count _digits) > 0) then {
                _numbers pushBackUnique parseNumber (toString _digits);
            };
        };
    } forEach ("true" configClasses (_vehicleCfg >> "AnimationSources"));

    private _maxNumber = 0;
    {
        if (_x > _maxNumber) then {_maxNumber = _x;};
    } forEach _numbers;

    if (_maxNumber > 0) exitWith {
        _object setVariable ["life_detected_door_count",_maxNumber,false];
        _maxNumber
    };

    private _result = count _doorNames;
    _object setVariable ["life_detected_door_count",_result,false];
    _result
};

private _hasDoors = {
    params [["_object",objNull,[objNull]]];
    ([_object] call _doorCount) > 0
};

if ([cursorObject] call _hasDoors && {player distance cursorObject < (_searchRadius + 4)}) then {
    _candidates pushBackUnique cursorObject;
};

private _nearestBuilding = nearestBuilding player;
if ([_nearestBuilding] call _hasDoors && {player distance _nearestBuilding < _searchRadius}) then {
    _candidates pushBackUnique _nearestBuilding;
};

{
    if ([_x] call _hasDoors) then {
        _candidates pushBackUnique _x;
    };
} forEach (nearestObjects [player,["House_F"],_searchRadius]);

{
    if ([_x] call _hasDoors) then {
        _candidates pushBackUnique _x;
    };
} forEach (nearestObjects [player,[],_searchRadius]);

{
    if ([_x] call _hasDoors) then {
        _candidates pushBackUnique _x;
    };
} forEach (nearestTerrainObjects [getPosATL player,["HOUSE","BUILDING"],_searchRadius,false,true]);

private _best = [objNull,0,999];
{
    private _building = _x;
    private _doors = [_building] call _doorCount;
    private _foundTrigger = false;

    for "_i" from 1 to _doors do {
        private _selectionPos = [0,0,0];
        {
            _selectionPos = _building selectionPosition format [_x,_i];
            if !(_selectionPos isEqualTo [0,0,0]) exitWith {};
        } forEach _selectionPatterns;

        if !(_selectionPos isEqualTo [0,0,0]) then {
            _foundTrigger = true;
            private _worldSpace = _building modelToWorld _selectionPos;
            private _distance = player distance _worldSpace;
            if (_distance < (_best select 2) && {_distance <= _maxDistance}) then {
                _best = [_building,_i,_distance];
            };
        };
    };

    if (!_foundTrigger && {_doors > 0}) then {
        private _distance = player distance _building;
        if (_distance < (_best select 2) && {_distance <= (_maxDistance + 4.5)}) then {
            _best = [_building,1,_distance];
        };
    };
} forEach _candidates;

if (isNull (_best select 0)) exitWith {[]};
[_best select 0,_best select 1]
