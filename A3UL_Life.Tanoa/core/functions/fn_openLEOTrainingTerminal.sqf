#include "..\..\script_macros.hpp"
/*
    File: fn_openLEOTrainingTerminal.sqf
*/
if !(playerSide isEqualTo west) exitWith {hint "The TCSD Training Terminal is only available to Law Enforcement.";};
private _canOpen = (["leo.training.view"] call life_fnc_hasPermission)
    || {["leo.training.edit"] call life_fnc_hasPermission}
    || {["leo.training.roster"] call life_fnc_hasPermission}
    || {["leo.training.fto"] call life_fnc_hasPermission}
    || {["lieutenant","tcsd"] call life_fnc_leoAtLeastRank};
if (!_canOpen) exitWith {hint "You do not have training terminal access.";};
if (dialog) exitWith {};

createDialog "life_leo_training_terminal";
