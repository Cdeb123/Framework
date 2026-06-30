#include "..\..\script_macros.hpp"
/*
    File: fn_canUseDoor.sqf

    Returns true when the local player can use a configured door.
*/
params [
    ["_access",[],[[]]],
    ["_code","",[""]]
];

if (_access isEqualTo []) exitWith {true};

_access params [
    ["_mode","public",[""]],
    ["_label","Door Access",[""]],
    ["_keypad",false,[false]],
    ["_codes",[],[[]]],
    ["_keycards",[],[[]]],
    ["_permissions",[],[[]]],
    ["_sides",[],[[]]]
];

if (_mode isEqualTo "" || {_mode isEqualTo "public"}) exitWith {true};
if (["owner.access"] call life_fnc_hasPermission) exitWith {true};
if (["staff.permissions"] call life_fnc_hasPermission) exitWith {true};
if (["leo.department.oversight"] call life_fnc_hasPermission) exitWith {true};

private _sideKeys = switch (playerSide) do {
    case west: {["WEST","COP","POLICE"]};
    case independent: {["GUER","INDEPENDENT","MED","EMS","FIRE"]};
    case civilian: {["CIV","CIVILIAN"]};
    case east: {["EAST","OPFOR"]};
    default {[]};
};

if (({_x in _sides} count _sideKeys) > 0) exitWith {true};

if (({[_x] call life_fnc_hasPermission} count _permissions) > 0) exitWith {true};

private _localKeycards = missionNamespace getVariable ["life_door_keycards",[]];
private _playerKeycards = player getVariable ["doorKeycards",[]];
private _hasKeycard = false;
{
    private _card = _x;

    if (_card in _localKeycards || {_card in _playerKeycards}) exitWith {
        _hasKeycard = true;
    };

    private _itemCfg = missionConfigFile >> "VirtualItems" >> _card;
    if (isClass _itemCfg) then {
        private _itemVar = format ["life_inv_%1",getText (_itemCfg >> "variable")];
        if ((missionNamespace getVariable [_itemVar,0]) > 0) exitWith {
            _hasKeycard = true;
        };
    };

    if ((missionNamespace getVariable [format ["life_inv_%1",_card],0]) > 0) exitWith {
        _hasKeycard = true;
    };
} forEach _keycards;

if (_hasKeycard) exitWith {true};

if (_keypad && {!(_code isEqualTo "")} && {_code in _codes}) exitWith {true};

false
