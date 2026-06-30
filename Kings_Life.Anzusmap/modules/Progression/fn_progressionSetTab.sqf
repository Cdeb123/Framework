/*
    File: fn_progressionSetTab.sqf
*/
params [
    ["_tab","xp",[""]]
];

missionNamespace setVariable ["life_progression_tab",_tab];
missionNamespace setVariable ["life_progression_selected",""];
[] call life_fnc_progressionLoad;
