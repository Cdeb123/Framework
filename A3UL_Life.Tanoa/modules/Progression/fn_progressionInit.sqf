/*
    File: fn_progressionInit.sqf
*/
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _key = format ["life_progression_%1",_charUID];
private _data = profileNamespace getVariable [_key,[0,0,0,0,0,0,[]]];

if !(_data isEqualType []) then {_data = [0,0,0,0,0,0,[]];};
if ((count _data) < 7) then {_data resize 7;};

missionNamespace setVariable ["life_progression_xp_character",_data param [0,0,[0]]];
missionNamespace setVariable ["life_progression_xp_leo",_data param [1,0,[0]]];
missionNamespace setVariable ["life_progression_xp_ems",_data param [2,0,[0]]];
missionNamespace setVariable ["life_progression_xp_gang",_data param [3,0,[0]]];
missionNamespace setVariable ["life_progression_xp_crafting",_data param [4,0,[0]]];
missionNamespace setVariable ["life_perk_points",_data param [5,0,[0]]];
missionNamespace setVariable ["life_progression_perks",_data param [6,[],[[]]]];
missionNamespace setVariable ["life_progression_loaded",true];

[] call life_fnc_progressionSave;
