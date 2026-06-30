#include "..\..\script_macros.hpp"
/*
    File: fn_spawnPointCfg.sqf
    Author: Bryan "Tonic" Boardwine
    Reworked for typed, deterministic spawn destinations.

    Return:
    [marker/id, display name, icon, type, description, position, direction, object, offsets]
*/

params [["_side",civilian,[civilian]]];

private _sideName = switch (_side) do {
    case west: {"Cop"};
    case independent: {"Medic"};
    default {"Civilian"};
};

private _return = [];
private _savedPosition = missionNamespace getVariable ["life_civ_position",[]];
private _hasSavedPosition = (_savedPosition isEqualType []) && {(count _savedPosition) isEqualTo 3} && {(_savedPosition distance (getMarkerPos "respawn_civilian")) >= 300};
private _hasInitialSpawn = !(missionNamespace getVariable ["life_firstSpawn",true]);
private _isAliveFromSession = missionNamespace getVariable ["life_is_alive",false];
private _allowAdvanced = _hasInitialSpawn || {_isAliveFromSession};
private _isCivilian = _sideName isEqualTo "Civilian";

if (_isCivilian && {_isAliveFromSession} && {_hasSavedPosition}) then {
    _return pushBack [
        "last_location",
        "Last Location",
        "\a3\ui_f\data\map\MapControl\waypoint_ca.paa",
        "Last Location",
        "Continue from your last saved civilian position.",
        _savedPosition,
        0,
        objNull,
        []
    ];
};

private _spawnCfg = missionConfigFile >> "CfgSpawnPoints" >> worldName >> _sideName;

for "_i" from 0 to count(_spawnCfg)-1 do {
    private _curConfig = _spawnCfg select _i;
    private _conditions = getText(_curConfig >> "conditions");
    private _flag = [_conditions] call life_fnc_levelCheck;
    private _isAdvanced = (getNumber(_curConfig >> "advanced")) isEqualTo 1;

    if (_flag && {!(_isAdvanced && {!_allowAdvanced})}) then {
        private _marker = getText(_curConfig >> "spawnMarker");
        private _name = getText(_curConfig >> "displayName");
        private _type = getText(_curConfig >> "spawnType");
        private _description = getText(_curConfig >> "description");
        private _position = getMarkerPos _marker;

        if (_type isEqualTo "") then {
            _type = switch (_sideName) do {
                case "Cop": {"LEO Station"};
                case "Medic": {"EMS Station"};
                default {"Town Center"};
            };
        };

        if (_description isEqualTo "") then {
            _description = format ["Spawn at %1.",_name];
        };

        _return pushBack [
            _marker,
            _name,
            getText(_curConfig >> "icon"),
            _type,
            _description,
            _position,
            markerDir _marker,
            objNull,
            getArray(_curConfig >> "spawnOffsets")
        ];
    };
};

if (_isCivilian && {_allowAdvanced}) then {
    {
        private _rawPos = _x param [0,[],[[],""]];
        private _pos = if (_rawPos isEqualType "") then {call compile _rawPos} else {_rawPos};

        if (_pos isEqualType [] && {(count _pos) >= 2}) then {
            private _nearHouses = nearestObjects [_pos,["House_F"],25];

            if !(_nearHouses isEqualTo []) then {
                private _house = _nearHouses select 0;
                private _houseName = getText(configFile >> "CfgVehicles" >> (typeOf _house) >> "displayName");
                if (_houseName isEqualTo "") then {_houseName = "Owned Property";};

                _return pushBack [
                    format ["house_%1",_house getVariable ["uid",_forEachIndex]],
                    format ["Home - %1",_houseName],
                    "\a3\ui_f\data\map\MapControl\lighthouse_ca.paa",
                    "Owned Home",
                    "Spawn at your owned property using the first open interior position.",
                    getPosATL _house,
                    getDir _house,
                    _house,
                    []
                ];
            };
        };
    } forEach (missionNamespace getVariable ["life_houses",[]]);
};

_return;
