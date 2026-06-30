/*
    File: fn_spawnConfirm.sqf
    Author: Bryan "Tonic" Boardwine
    Reworked for typed, deterministic spawn destinations.

    Description:
    Spawns the player where they selected.
*/
private _spCfg = [playerSide] call life_fnc_spawnPointCfg;
private _sp = if ((missionNamespace getVariable ["life_spawn_point",[]]) isEqualTo [] && {!(_spCfg isEqualTo [])}) then {
    _spCfg select 0
} else {
    missionNamespace getVariable ["life_spawn_point",[]]
};

if (_sp isEqualTo []) exitWith {
    closeDialog 0;
    hint "No spawn points are available.";
};

_sp params [
    ["_marker","",[""]],
    ["_name","Spawn",[""]],
    ["_icon","",[""]],
    ["_type","Town Center",[""]],
    ["_description","",[""]],
    ["_position",[],[[]]],
    ["_direction",0,[0]],
    ["_object",objNull,[objNull]],
    ["_offsets",[],[[]]]
];

private _defaultOffsets = [[0,0,0],[2.2,1.4,0],[-2.2,1.4,0],[2.2,-1.4,0],[-2.2,-1.4,0],[0,2.5,0],[0,-2.5,0]];
private _resolvePad = {
    params [["_base",[],[[]]],["_dir",0,[0]],["_pads",[],[[]]]];

    if !(_base isEqualType [] && {(count _base) >= 2}) exitWith {_base};
    if (_pads isEqualTo []) then {_pads = _defaultOffsets;};
    if (_pads isEqualTo []) exitWith {_base};

    private _hash = 0;
    {_hash = _hash + _x;} forEach toArray (getPlayerUID player);

    private _offset = _pads select (_hash mod (count _pads));
    private _offX = _offset param [0,0,[0]];
    private _offY = _offset param [1,0,[0]];
    private _offZ = _offset param [2,0,[0]];
    private _cos = cos _dir;
    private _sin = sin _dir;

    [
        (_base select 0) + (_offX * _cos) - (_offY * _sin),
        (_base select 1) + (_offX * _sin) + (_offY * _cos),
        (_base param [2,0,[0]]) + _offZ
    ]
};

private _spawnPos = [];
private _spawnDir = _direction;
private _useMarkerPlacement = true;

switch (toLower _type) do {
    case "owned home": {
        _useMarkerPlacement = false;
        if (!isNull _object) then {
            private _buildingPositions = [_object] call life_fnc_getBuildingPositions;
            {_buildingPositions = _buildingPositions - [(_object buildingPos _x)];} forEach (_object getVariable ["slots",[]]);

            _spawnPos = if (_buildingPositions isEqualTo []) then {
                getPosATL _object
            } else {
                _buildingPositions select 0
            };
            _spawnDir = getDir _object;
        } else {
            _spawnPos = _position;
        };
    };

    case "last location": {
        _useMarkerPlacement = false;
        _spawnPos = _position;
    };

    default {
        if (_position isEqualTo [] && {!(_marker isEqualTo "")}) then {
            _position = getMarkerPos _marker;
            _spawnDir = markerDir _marker;
        };

        _spawnPos = [_position,_spawnDir,_offsets] call _resolvePad;
    };
};

if (_spawnPos isEqualTo []) exitWith {
    closeDialog 0;
    hint "That spawn point could not be resolved.";
};

closeDialog 0;
detach player;
player allowDamage true;
player setVelocity [0,0,0];
player setDir _spawnDir;
if (_useMarkerPlacement) then {
    player setPos _spawnPos;
} else {
    player setPosATL _spawnPos;
};
cutText ["","BLACK IN"];
titleText[format ["%2 %1",_name,localize "STR_Spawn_Spawned"],"BLACK IN"];

if (life_firstSpawn) then {
    life_firstSpawn = false;
    [] call life_fnc_welcomeNotification;
};

if (playerSide isEqualTo civilian) then {
    life_is_alive = true;
    [3] call SOCK_fnc_updatePartial;
};

[] call life_fnc_playerSkins;
[] call life_fnc_hudSetup;
[true,true] call life_fnc_resetSpawnState;
