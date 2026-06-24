#include "..\..\script_macros.hpp"
/*
    File: fn_craftingSetTab.sqf
*/
params [
    ["_tab","craft",[""]]
];

if !(_tab in ["craft","vehicles","workbench","storage","gear"]) then {_tab = "craft";};
missionNamespace setVariable ["life_crafting_tab",_tab];
missionNamespace setVariable ["life_crafting_selected",""];
[] call life_fnc_craftingLoad;
