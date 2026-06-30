#include "..\..\script_macros.hpp"
/*
    File: fn_seatbeltToggle.sqf

    Description:
    Toggles the local seatbelt state for the current vehicle and publishes it
    for HUD/status consumers.
*/
if (vehicle player isEqualTo player) exitWith {
    life_seatbelt = false;
    player setVariable ["seatbelt",false,true];
    [] call life_fnc_hudUpdate;
};

life_seatbelt = !(missionNamespace getVariable ["life_seatbelt",false]);
player setVariable ["seatbelt",life_seatbelt,true];

private _sound = if (life_seatbelt) then {"seatbeltOnSound"} else {"seatbeltOffSound"};
[player,_sound,18,1] remoteExecCall ["life_fnc_say3D",RCLIENT];

titleText [(["Seatbelt off","Seatbelt on"] select life_seatbelt),"PLAIN"];
[] call life_fnc_hudUpdate;
