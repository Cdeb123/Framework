#include "..\..\script_macros.hpp"
/*
    File: fn_characterCreate.sqf
*/
disableSerialization;
private _display = findDisplay 7800;
if (isNull _display) exitWith {};

private _key = format ["life_characters_%1_%2",getPlayerUID player,profileName];
life_characters = profileNamespace getVariable [_key,[]];
if !(life_characters isEqualType []) then {life_characters = [];};
if ((count life_characters) >= 3) exitWith {hint "You can only have three characters on this Arma profile.";};

private _name = ctrlText (_display displayCtrl 7803);
private _dob = ctrlText (_display displayCtrl 7804);
private _political = ctrlText (_display displayCtrl 7805);
private _background = ctrlText (_display displayCtrl 7806);
private _face = lbData [7807,lbCurSel 7807];
private _uniform = lbData [7808,lbCurSel 7808];
private _cleanText = {
    params [["_value","",[""]]];
    (_value splitString "<>") joinString ""
};

_name = [_name] call _cleanText;
_dob = [_dob] call _cleanText;
_political = [_political] call _cleanText;
_background = [_background] call _cleanText;

if (_name isEqualTo "") exitWith {hint "Enter a character name.";};
if (_dob isEqualTo "") then {_dob = "01/01/1995";};
if (_political isEqualTo "") then {_political = "Resident";};
if (_background isEqualTo "") then {_background = "No background set.";};
if (_face isEqualTo "") then {_face = "WhiteHead_01";};
if (_uniform isEqualTo "") then {_uniform = "U_C_Poloshirt_blue";};

private _usedSlots = life_characters apply {_x select 0};
private _slot = 0;
for "_i" from 0 to 2 do {
    if !(_i in _usedSlots) exitWith {_slot = _i;};
};

private _characterUID = format ["%1-%2-%3",getPlayerUID player,profileName,_slot + 1];
private _character = [_slot,_characterUID,_name,_dob,_political,_background,_face,_uniform,[],[],[],[]];
life_characters pushBack _character;
profileNamespace setVariable [_key,life_characters];
profileNamespace setVariable [format ["%1_selected",_key],_slot];
saveProfileNamespace;

[_character] call life_fnc_characterApply;
closeDialog 0;
