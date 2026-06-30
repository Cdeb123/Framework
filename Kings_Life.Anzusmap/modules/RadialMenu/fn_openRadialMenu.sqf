#include "..\..\script_macros.hpp"
/*
    File: fn_openRadialMenu.sqf
*/
params [
    ["_category","quick",[""]]
];

if (dialog && {isNull (findDisplay 9200)}) exitWith {};

if (!isNull (findDisplay 9200)) exitWith {
    closeDialog 0;
};

life_radial_source_actions = [] call life_fnc_nearbyInteractionActions;
life_radial_category = _category;
life_radial_page = 0;

createDialog "life_radial_menu";
