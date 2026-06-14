#include "..\..\script_macros.hpp"
/*
    File: fn_openLEOCommandTerminal.sqf
*/
if !(playerSide isEqualTo west) exitWith {hint "The TCSD Command Terminal is only available to Law Enforcement.";};
if !([] call life_fnc_leoCanCommand) exitWith {hint "You do not have command terminal permissions.";};
if (dialog) exitWith {};

createDialog "life_leo_command_terminal";
