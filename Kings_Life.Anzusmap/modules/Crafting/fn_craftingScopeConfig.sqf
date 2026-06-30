#include "..\..\script_macros.hpp"
/*
    File: fn_craftingScopeConfig.sqf
*/
params [
    ["_scope","",[""]]
];

_scope = [_scope] call life_fnc_craftingScope;
private _className = switch (_scope) do {
    case "leo": {"LawEnforcement"};
    case "rebel": {"Rebel"};
    default {"Civilian"};
};

missionConfigFile >> "Life_Crafting" >> _className
