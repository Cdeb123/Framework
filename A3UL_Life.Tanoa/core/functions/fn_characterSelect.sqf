#include "..\..\script_macros.hpp"
/*
    File: fn_characterSelect.sqf
*/
disableSerialization;
if ((lbCurSel 7801) < 0) exitWith {hint "Select a character.";};

private _character = call compile (lbData [7801,lbCurSel 7801]);
if !(_character isEqualType []) exitWith {hint "Character data is invalid.";};

private _key = format ["life_characters_%1_%2",getPlayerUID player,profileName];
profileNamespace setVariable [format ["%1_selected",_key],_character select 0];
saveProfileNamespace;

[_character] call life_fnc_characterApply;
closeDialog 0;
