#include "..\script_macros.hpp"
/*
    File: fn_initCiv.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the civilian.
*/
waitUntil {!(isNull (findDisplay 46))};

if (life_is_arrested) exitWith {
    life_is_arrested = false;
    [player,true] spawn life_fnc_jail;
};

[] call life_fnc_characterGate;

private _hasSavedPosition = (life_civ_position isEqualType []) && {(count life_civ_position) isEqualTo 3} && {(life_civ_position distance (getMarkerPos "respawn_civilian")) >= 300};

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
