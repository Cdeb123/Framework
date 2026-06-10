#include "..\..\script_macros.hpp"
/*
    File: fn_frameworkDataQuery.sqf
*/
if (LIFE_SETTINGS(getNumber,"framework_extensionData") isEqualTo 0) exitWith {};
[getPlayerUID player,player] remoteExecCall ["DB_fnc_fetchFrameworkData",RSERV];
