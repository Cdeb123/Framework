#include "..\..\script_macros.hpp"
/*
    File: fn_openLEOTrainingTerminal.sqf
*/
if !(playerSide isEqualTo west) exitWith {hint "The KCSO Admin Services Terminal is only available to Law Enforcement.";};
private _canOpen = (["leo.training.view"] call life_fnc_hasPermission)
    || {["leo.training.edit"] call life_fnc_hasPermission}
    || {["leo.training.roster"] call life_fnc_hasPermission}
    || {["leo.training.admin_services"] call life_fnc_hasPermission}
    || {["lieutenant","kcso"] call life_fnc_leoAtLeastRank};
if (!_canOpen) exitWith {hint "You do not have Admin Services terminal access.";};
if (dialog) exitWith {};

createDialog "life_leo_training_terminal";
