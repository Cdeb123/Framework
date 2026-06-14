#include "..\..\script_macros.hpp"
/*
    File: fn_openRadialMenu.sqf
*/
params [
    ["_category","main",[""]]
];

if (dialog && {isNull (findDisplay 9200)}) exitWith {};

if (!isNull (findDisplay 9200)) exitWith {
    closeDialog 0;
};

life_radial_source_actions = [] call life_fnc_nearbyInteractionActions;

private _resolvedCategory = _category;
if (_category isEqualTo "main") then {
    {
        private _group = _x;
        if (({(_x select 4) isEqualTo _group && {(_x select 5) >= 20}} count life_radial_source_actions) > 0) exitWith {
            _resolvedCategory = _group;
        };
    } forEach ["License Shop","Access Shop","Garage","Banking","Service","Nearby"];
};

life_radial_category = _resolvedCategory;
life_radial_page = 0;

createDialog "life_radial_menu";
