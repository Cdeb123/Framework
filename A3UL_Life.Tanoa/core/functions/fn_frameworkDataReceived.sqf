#include "..\..\script_macros.hpp"
/*
    File: fn_frameworkDataReceived.sqf
*/
params [
    ["_permissions",[],[[]]],
    ["_citations",[],[[]]],
    ["_warrants",[],[[]]]
];

life_discord_permissions = _permissions;
life_pending_citations = _citations;
life_pending_warrants = _warrants;

[] call life_fnc_jobInit;
[] call life_fnc_hudUpdate;
