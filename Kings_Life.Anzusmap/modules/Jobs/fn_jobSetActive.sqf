#include "..\..\script_macros.hpp"
/*
    File: fn_jobSetActive.sqf
*/
params [
    ["_job","",[""]]
];

if (_job isEqualTo "") exitWith {false};

if ((count (missionNamespace getVariable ["life_jobs",[]])) isEqualTo 0) then {
    [] call life_fnc_jobInit;
};

private _known = false;
{
    if ((_x select 0) isEqualTo _job) exitWith {_known = true;};
} forEach life_jobs;

if (!_known) exitWith {
    hint "You do not have access to that job.";
    false
};

life_active_job = _job;
player setVariable ["activeJob",life_active_job,true];
[] call life_fnc_hudUpdate;
true;
