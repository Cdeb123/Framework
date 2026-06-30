#include "..\..\script_macros.hpp"
/*
    File: fn_craftingInit.sqf
*/
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _key = format ["life_crafting_%1",_charUID];
private _defaultLevels = [["civilian",1],["rebel",1],["leo",1]];
private _data = profileNamespace getVariable [_key,[[],[],[],[],[],_defaultLevels,1,1]];

if !(_data isEqualType []) then {
    _data = [[],[],[],[],[],_defaultLevels,1,1];
};
if ((count _data) < 8) then {
    _data resize 8;
};

missionNamespace setVariable ["life_crafting_workbench_civilian",_data param [0,[],[[]]]];
missionNamespace setVariable ["life_crafting_workbench_rebel",_data param [1,[],[[]]]];
missionNamespace setVariable ["life_crafting_workbench_leo",_data param [2,[],[[]]]];
missionNamespace setVariable ["life_crafting_personal_items",_data param [3,[],[[]]]];
missionNamespace setVariable ["life_crafting_personal_gear",_data param [4,[],[[]]]];
missionNamespace setVariable ["life_crafting_workbench_levels",_data param [5,_defaultLevels,[[]]]];
missionNamespace setVariable ["life_crafting_item_storage_level",_data param [6,1,[0]]];
missionNamespace setVariable ["life_crafting_gear_storage_level",_data param [7,1,[0]]];
missionNamespace setVariable ["life_crafting_loaded",true];

[] call life_fnc_craftingSave;
