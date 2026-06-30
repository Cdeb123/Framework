#include "..\..\script_macros.hpp"
/*
    File: fn_characterGate.sqf

    Description:
    Required character setup step before spawn selection.
*/
life_character_completed = false;
life_character_gate_active = true;

cutText ["","BLACK FADED"];
0 cutFadeOut 9999999;

while {!life_character_completed} do {
    if (isNull (findDisplay 7800)) then {
        createDialog "life_character_select";
    };
    uiSleep 0.25;
};

life_character_gate_active = false;
cutText ["","BLACK FADED"];
0 cutFadeOut 9999999;
true;
