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
private _uniform = _character select 7;

player setVariable ["realname",_name,true];
player setVariable ["characterUID",life_character_uid,true];
player setFace _face;

if ((uniform player) isEqualTo "" && {!(_uniform isEqualTo "")}) then {
    player forceAddUniform _uniform;
};

[] call life_fnc_hudUpdate;
