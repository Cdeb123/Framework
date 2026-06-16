#include "..\..\script_macros.hpp"
/*
    File: fn_characterApply.sqf
*/
params [
    ["_character",[],[[]]]
];
if ((count _character) < 8) exitWith {};

life_character_slot = _character select 0;
life_character_uid = _character select 1;
life_character_data = _character;

private _name = _character select 2;
private _face = _character select 6;

player setVariable ["realname",_name,true];
player setVariable ["characterUID",life_character_uid,true];
player setFace _face;

[] call life_fnc_hudUpdate;
