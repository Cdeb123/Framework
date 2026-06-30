#include "..\..\script_macros.hpp"
/*
    File: fn_radialHouseWorkbench.sqf

    Workbench entry point for owned houses.
*/
params [
    ["_house",objNull,[objNull]]
];

if (isNull _house) exitWith {hint localize "STR_House_Door_NotNear";};
if !("workbench" in (_house getVariable ["house_upgrades",[]])) exitWith {
    hint "Install the workbench upgrade first.";
};

private _scope = if (playerSide isEqualTo civilian && {missionNamespace getVariable ["license_civ_rebel",false]}) then {
    "rebel"
} else {
    "civilian"
};

[_scope,_house] call life_fnc_openCraftingMenu;
