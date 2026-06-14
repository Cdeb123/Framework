/*
    File: fn_progressionSave.sqf
*/
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _key = format ["life_progression_%1",_charUID];
private _data = [
    missionNamespace getVariable ["life_progression_xp_character",0],
    missionNamespace getVariable ["life_progression_xp_leo",0],
    missionNamespace getVariable ["life_progression_xp_ems",0],
    missionNamespace getVariable ["life_progression_xp_gang",0],
    missionNamespace getVariable ["life_progression_xp_crafting",0],
    missionNamespace getVariable ["life_perk_points",0],
    missionNamespace getVariable ["life_progression_perks",[]]
];

profileNamespace setVariable [_key,_data];
saveProfileNamespace;
