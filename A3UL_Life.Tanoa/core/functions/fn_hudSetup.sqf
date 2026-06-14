#include "..\..\script_macros.hpp"
/*
    File: fn_hudSetup.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Setups the hud for the player?
*/
disableSerialization;

showHUD [false,false,false,false,false,false,false,false,true,false,false];
cutRsc ["playerHUD", "PLAIN", 2, false];
[] call life_fnc_hudUpdate;

[] spawn
{
    private ["_dam"];
    for "_i" from 0 to 1 step 0 do {
        _dam = damage player;
        waitUntil {!((damage player) isEqualTo _dam)};
        [] call life_fnc_hudUpdate;
    };
};

if (isNil "life_hud_loop") then {
    life_hud_loop = [] spawn {
        for "_i" from 0 to 1 step 0 do {
            [] call life_fnc_hudUpdate;
            uiSleep 0.35;
        };
    };
};
