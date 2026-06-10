#include "..\..\script_macros.hpp"
/*
    File: fn_frameworkDataReceived.sqf
*/
params [
    ["_permissions",[],[[]]],
    ["_citations",[],[[]]],
    ["_warrants",[],[[]]],
    ["_leoRows",[],[[]]],
    ["_trainingDocs",[],[[]]],
    ["_trainingRoster",[],[[]]]
];

life_discord_permissions = _permissions;
life_pending_citations = _citations;
life_pending_warrants = _warrants;
life_leo_training_docs = _trainingDocs;
life_leo_training_roster = _trainingRoster;
[_leoRows] call life_fnc_leoSetLocalData;
life_framework_data_loaded = true;

[] call life_fnc_jobInit;
[] call life_fnc_hudUpdate;
