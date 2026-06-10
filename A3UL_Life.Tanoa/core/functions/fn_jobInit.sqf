#include "..\..\script_macros.hpp"
/*
    File: fn_jobInit.sqf

    Description:
    Builds local job and permission state from rank, side, config, and future
    server/Discord grants.
*/
life_jobs = [];
life_permissions = [];

{
    life_permissions pushBackUnique _x;
} forEach (missionNamespace getVariable ["life_discord_permissions",[]]);

{
    private _jobKey = configName _x;
    private _conditions = getText (_x >> "conditions");
    private _allowed = if (_conditions isEqualTo "") then {true} else {call compile _conditions};

    if (_allowed) then {
        private _displayName = getText (_x >> "displayName");
        private _permissions = getArray (_x >> "permissions");
        life_jobs pushBackUnique [_jobKey,_displayName,_permissions];
        {life_permissions pushBackUnique _x;} forEach _permissions;
    };
} forEach ("true" configClasses (missionConfigFile >> "Life_Jobs"));

if ((missionNamespace getVariable ["life_active_job","unemployed"]) isEqualTo "") then {
    life_active_job = "unemployed";
};

player setVariable ["activeJob",life_active_job,true];
player setVariable ["permissions",life_permissions,true];
