#include "..\..\script_macros.hpp"
/*
    File: fn_frameworkDataQuery.sqf
*/
if (LIFE_SETTINGS(getNumber,"framework_extensionData") isEqualTo 0) exitWith {
    life_framework_data_loaded = true;
};
[getPlayerUID player,player] remoteExecCall ["DB_fnc_fetchFrameworkData",RSERV];
