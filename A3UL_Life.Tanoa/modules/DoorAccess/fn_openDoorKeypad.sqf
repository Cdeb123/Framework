#include "..\..\script_macros.hpp"
/*
    File: fn_openDoorKeypad.sqf
*/
params [
    ["_building",objNull,[objNull]],
    ["_door",0,[0]],
    ["_access",[],[[]]]
];

if (isNull _building || {_door <= 0}) exitWith {false};

life_door_keypad_target = [_building,_door,_access];
life_door_keypad_lastCode = "";

if !(createDialog "life_door_keypad") exitWith {
    life_door_keypad_target = [];
    hint "Unable to open the door access terminal.";
    false
};

disableSerialization;
private _display = findDisplay 8300;
if (!isNull _display) then {
    _access params [
        ["_mode","",[""]],
        ["_label","Door Access",[""]]
    ];

    private _labelCtrl = _display displayCtrl 8302;
    private _editCtrl = _display displayCtrl 8301;
    private _statusCtrl = _display displayCtrl 8303;

    _labelCtrl ctrlSetText _label;
    _statusCtrl ctrlSetStructuredText parseText "<t color='#8FB4C1'>Enter the assigned 4-digit code.</t>";
    ctrlSetFocus _editCtrl;
};

true
