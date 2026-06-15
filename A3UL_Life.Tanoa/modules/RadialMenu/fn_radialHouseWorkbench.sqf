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

private _craftInfo = ["crafting"] call life_fnc_progressionLevelInfo;
hint parseText format [
    "<t size='1.15' color='#8FE7FF'>House Workbench</t><br/>Crafting level %1 is ready here.<br/><br/>Recipe categories can hook into this upgrade when the crafting module is expanded.",
    _craftInfo select 0
];

