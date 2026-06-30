#include "..\..\script_macros.hpp"
/*
    File: fn_hudSetup.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Setups the hud for the player?
*/
disableSerialization;

// Replace Arma's weapon and stamina widgets with the client-configurable framework HUD.
showHUD [true,false,false,false,false,true,false,true,false,false,false];
cutRsc ["playerHUD", "PLAIN", 2, false];
[] spawn {
    disableSerialization;
    uiSleep 0.10;
    [] call life_fnc_hudUpdate;
};

if ((isNil "life_hud_damage_loop") || {scriptDone life_hud_damage_loop}) then {
    life_hud_damage_loop = [] spawn {
        private ["_dam"];
        for "_i" from 0 to 1 step 0 do {
            _dam = damage player;
            waitUntil {!((damage player) isEqualTo _dam)};
            [] call life_fnc_hudUpdate;
        };
    };
};

if ((isNil "life_hud_loop") || {scriptDone life_hud_loop}) then {
    life_hud_loop = [] spawn {
        for "_i" from 0 to 1 step 0 do {
            if (isNull LIFEdisplay) then {
                cutRsc ["playerHUD", "PLAIN", 0, false];
                uiSleep 0.10;
            };
            [] call life_fnc_hudUpdate;
            uiSleep 0.10;
        };
    };
};
