#include "..\..\script_macros.hpp"
/*
    File: fn_craftingScope.sqf
*/
params [
    ["_scope","",[""]]
];

_scope = toLower _scope;
if (_scope isEqualTo "") exitWith {
    if (playerSide isEqualTo west) exitWith {"leo"};
    if (playerSide isEqualTo civilian && {missionNamespace getVariable ["license_civ_rebel",false]}) exitWith {"rebel"};
    "civilian"
};

switch (_scope) do {
    case "civ": {"civilian"};
    case "cop": {"leo"};
    case "police": {"leo"};
    case "lawenforcement": {"leo"};
    case "law_enforcement": {"leo"};
    default {_scope};
};
