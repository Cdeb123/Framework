#include "..\..\script_macros.hpp"
/*
    File: fn_craftingSave.sqf
*/
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _key = format ["life_crafting_%1",_charUID];
private _data = [
    missionNamespace getVariable ["life_crafting_workbench_civilian",[]],
    missionNamespace getVariable ["life_crafting_workbench_rebel",[]],
    missionNamespace getVariable ["life_crafting_workbench_leo",[]],
    missionNamespace getVariable ["life_crafting_personal_items",[]],
    missionNamespace getVariable ["life_crafting_personal_gear",[]],
    missionNamespace getVariable ["life_crafting_workbench_levels",[["civilian",1],["rebel",1],["leo",1]]],
    missionNamespace getVariable ["life_crafting_item_storage_level",1],
    missionNamespace getVariable ["life_crafting_gear_storage_level",1]
];

profileNamespace setVariable [_key,_data];
saveProfileNamespace;
