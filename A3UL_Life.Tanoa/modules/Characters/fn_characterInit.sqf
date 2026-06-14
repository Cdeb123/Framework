#include "..\..\script_macros.hpp"
/*
    File: fn_characterInit.sqf

    Description:
    Loads profile-local character slots and opens creation/selection when needed.
*/
private _key = format ["life_characters_%1_%2",getPlayerUID player,profileName];
life_characters = profileNamespace getVariable [_key,[]];
if !(life_characters isEqualType []) then {life_characters = [];};

private _lastSlot = profileNamespace getVariable [format ["%1_selected",_key],-1];
private _match = [];
{
    if ((_x select 0) isEqualTo _lastSlot) exitWith {_match = _x;};
} forEach life_characters;

if ((count _match) > 0) then {
    [_match] call life_fnc_characterApply;
} else {
    createDialog "life_character_select";
};
