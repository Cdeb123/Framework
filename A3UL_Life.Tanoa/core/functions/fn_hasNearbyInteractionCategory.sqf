#include "..\..\script_macros.hpp"
/*
    File: fn_hasNearbyInteractionCategory.sqf
*/
params [
    ["_category","",[""]]
];

if (_category isEqualTo "") exitWith {
    !(([] call life_fnc_nearbyInteractionActions) isEqualTo [])
};

private _found = false;
{
    if ((_x select 4) isEqualTo _category) exitWith {_found = true;};
} forEach ([_category] call life_fnc_nearbyInteractionActions);

_found
