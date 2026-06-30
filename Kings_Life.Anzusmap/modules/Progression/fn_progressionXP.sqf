/*
    File: fn_progressionXP.sqf
*/
params [
    ["_category","character",[""]]
];

missionNamespace getVariable [format ["life_progression_xp_%1",_category],0]
