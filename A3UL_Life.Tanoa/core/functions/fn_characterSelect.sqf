#include "..\..\script_macros.hpp"
/*
    File: fn_characterSelect.sqf
*/
disableSerialization;
if ((lbCurSel 7801) < 0) exitWith {hint "Select a character.";};

private _data = lbData [7801,lbCurSel 7801];
if (_data in ["","__new"]) exitWith {hint "Fill the form and press Create for a new character.";};

private _character = call compile _data;
if !(_character isEqualType []) exitWith {hint "Character data is invalid.";};

private _key = format ["life_characters_%1_%2",getPlayerUID player,profileName];
profileNamespace setVariable [format ["%1_selected",_key],_character select 0];
saveProfileNamespace;

[_character] call life_fnc_characterApply;
life_character_preview_committed = true;
life_character_completed = true;
closeDialog 0;
