#include "..\..\script_macros.hpp"
/*
    File: fn_radialMenuPage.sqf
*/
params [
    ["_direction",0,[0]]
];

life_radial_page = (missionNamespace getVariable ["life_radial_page",0]) + _direction;
[] call life_fnc_radialMenuLoad;
