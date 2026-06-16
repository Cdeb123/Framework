#include "..\script_macros.hpp"
/*
    File: fn_initCiv.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the civilian.
*/
private _altisArray = ["Land_i_Shop_01_V1_F","Land_i_Shop_01_V2_F","Land_i_Shop_01_V3_F","Land_i_Shop_02_V1_F","Land_i_Shop_02_V2_F","Land_i_Shop_02_V3_F"];
private _tanoaArray = ["Land_House_Small_01_F"];
private _spawnBuildings = [[["Altis", _altisArray], ["Tanoa", _tanoaArray]]] call TON_fnc_terrainSort;

civ_spawn_1 = nearestObjects[getMarkerPos  "civ_spawn_1", _spawnBuildings,350];
civ_spawn_2 = nearestObjects[getMarkerPos  "civ_spawn_2", _spawnBuildings,350];
civ_spawn_3 = nearestObjects[getMarkerPos  "civ_spawn_3", _spawnBuildings,350];
civ_spawn_4 = nearestObjects[getMarkerPos  "civ_spawn_4", _spawnBuildings,350];

waitUntil {!(isNull (findDisplay 46))};

if (life_is_arrested) exitWith {
    life_is_arrested = false;
    [player,true] spawn life_fnc_jail;
};

[] call life_fnc_characterGate;

private _hasSavedPosition = (life_civ_position isEqualType []) && {(count life_civ_position) isEqualTo 3} && {(life_civ_position distance (getMarkerPos "respawn_civilian")) >= 300};

if (life_is_alive && {_hasSavedPosition}) exitWith {
    detach player;
    player allowDamage true;
    player setVelocity [0,0,0];
    player setPosATL life_civ_position;
    cutText ["","BLACK IN"];
    titleText ["Welcome back. You have been restored to your last saved location.","BLACK IN"];

    if (life_firstSpawn) then {
        life_firstSpawn = false;
        [] call life_fnc_welcomeNotification;
    };

    [] call life_fnc_playerSkins;
    [] call life_fnc_hudSetup;
    [3] call SOCK_fnc_updatePartial;
};

if (!life_is_alive && {!_hasSavedPosition} && {LIFE_SETTINGS(getNumber,"save_civilian_positionStrict") isEqualTo 1}) then {
    [] call life_fnc_startLoadout;
    CASH = 0;
    [0] call SOCK_fnc_updatePartial;
};

[] call life_fnc_spawnMenu;
waitUntil{!isNull (findDisplay 38500)}; //Wait for the spawn selection to be open.
waitUntil{isNull (findDisplay 38500)}; //Wait for the spawn selection to be done.
life_is_alive = true;
[3] call SOCK_fnc_updatePartial;
