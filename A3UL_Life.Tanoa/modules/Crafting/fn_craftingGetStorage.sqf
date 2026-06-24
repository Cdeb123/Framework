#include "..\..\script_macros.hpp"
/*
    File: fn_craftingGetStorage.sqf
*/
params [
    ["_type","workbench",[""]],
    ["_scope","",[""]]
];

if !(missionNamespace getVariable ["life_crafting_loaded",false]) then {
    [] call life_fnc_craftingInit;
};

_scope = [_scope] call life_fnc_craftingScope;
switch (toLower _type) do {
    case "workbench": {+(missionNamespace getVariable [format ["life_crafting_workbench_%1",_scope],[]])};
    case "items": {+(missionNamespace getVariable ["life_crafting_personal_items",[]])};
    case "gear": {+(missionNamespace getVariable ["life_crafting_personal_gear",[]])};
    default {[]};
};
