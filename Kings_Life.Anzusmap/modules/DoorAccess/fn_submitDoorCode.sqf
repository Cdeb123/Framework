#include "..\..\script_macros.hpp"
/*
    File: fn_submitDoorCode.sqf
*/
disableSerialization;

private _display = findDisplay 8300;
if (isNull _display) exitWith {false};

private _code = ctrlText (_display displayCtrl 8301);
_code = (_code splitString " ") joinString "";
life_door_keypad_lastCode = _code;

private _chars = toArray _code;
private _valid = (count _chars) isEqualTo 4;
{
    if (_x < 48 || {_x > 57}) exitWith {
        _valid = false;
    };
} forEach _chars;

private _statusCtrl = _display displayCtrl 8303;
if (!_valid) exitWith {
    _statusCtrl ctrlSetStructuredText parseText "<t color='#FFB85C'>Code must be exactly 4 digits.</t>";
    false
};

if ((missionNamespace getVariable ["life_door_keypad_target",[]]) isEqualTo []) exitWith {
    _statusCtrl ctrlSetStructuredText parseText "<t color='#FF6B6B'>No door is linked to this terminal.</t>";
    false
};

life_door_keypad_target params [
    ["_building",objNull,[objNull]],
    ["_door",0,[0]],
    ["_access",[],[[]]]
];

if (isNull _building || {_door <= 0}) exitWith {
    _statusCtrl ctrlSetStructuredText parseText "<t color='#FF6B6B'>The linked door is no longer nearby.</t>";
    false
};

if (player distance _building > 8) exitWith {
    _statusCtrl ctrlSetStructuredText parseText "<t color='#FF6B6B'>Move closer to the access terminal.</t>";
    false
};

if (!([_access,_code] call life_fnc_canUseDoor)) exitWith {
    _statusCtrl ctrlSetStructuredText parseText "<t color='#FF6B6B'>Access denied. Invalid code or missing clearance.</t>";
    false
};

closeDialog 0;
[_building,_door] call life_fnc_toggleBuildingDoor;
true
