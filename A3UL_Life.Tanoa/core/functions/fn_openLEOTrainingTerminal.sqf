#include "..\..\script_macros.hpp"
/*
    File: fn_openLEOTrainingTerminal.sqf
*/
if !(playerSide isEqualTo west) exitWith {hint "The TCSD Training Terminal is only available to Law Enforcement.";};
if (!(["leo.training.view"] call life_fnc_hasPermission) && {!((["leo.training.edit"] call life_fnc_hasPermission))}) exitWith {hint "You do not have training terminal access.";};
if (dialog) exitWith {};

createDialog "life_leo_training_terminal";
