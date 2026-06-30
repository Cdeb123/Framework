#include "..\..\script_macros.hpp"
/*
    File: fn_craftingSetStorage.sqf
*/
params [
    ["_type","workbench",[""]],
    ["_data",[],[[]]],
    ["_scope","",[""]]
];

_scope = [_scope] call life_fnc_craftingScope;
switch (toLower _type) do {
    case "workbench": {
        missionNamespace setVariable [format ["life_crafting_workbench_%1",_scope],+_data];
    };
    case "items": {
        missionNamespace setVariable ["life_crafting_personal_items",+_data];
    };
    case "gear": {
        missionNamespace setVariable ["life_crafting_personal_gear",+_data];
    };
};

[] call life_fnc_craftingSave;
true
