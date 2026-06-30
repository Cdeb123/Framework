#include "..\..\script_macros.hpp"
/*
    File: fn_doorAccessFor.sqf

    Returns the access profile for a building door.
*/
params [
    ["_building",objNull,[objNull]],
    ["_door",0,[0]]
];

private _default = ["public","Public Access",false,[],[],[],[]];
if (isNull _building || {_door <= 0}) exitWith {_default};

private _type = typeOf _building;
private _matched = configNull;

{
    private _classes = getArray (_x >> "classnames");
    private _doors = getArray (_x >> "doors");
    private _classMatch = (count _classes) isEqualTo 0;
    private _doorMatch = (count _doors) isEqualTo 0 || {_door in _doors};

    if (!_classMatch) then {
        {
            if (_type isEqualTo _x || {_building isKindOf _x}) exitWith {
                _classMatch = true;
            };
        } forEach _classes;
    };

    if (_classMatch && {_doorMatch}) exitWith {
        _matched = _x;
    };
} forEach ("true" configClasses (missionConfigFile >> "Life_DoorAccess" >> "Doors"));

private _accessKey = "public";
if !(isNull _matched) then {
    _accessKey = getText (_matched >> "access");
    if (_accessKey isEqualTo "") then {_accessKey = "public";};
};

private _objectAccess = _building getVariable [format ["life_door_access_%1",_door],_building getVariable ["life_door_access",""]];
if !(_objectAccess isEqualTo "") then {
    _accessKey = _objectAccess;
};

private _accessCfg = missionConfigFile >> "Life_DoorAccess" >> "Access" >> _accessKey;
private _mode = if (isClass _accessCfg) then {getText (_accessCfg >> "mode")} else {_accessKey};
if (_mode isEqualTo "") then {_mode = "public";};

private _label = if (isClass _accessCfg) then {getText (_accessCfg >> "label")} else {"Door Access"};
private _keypad = if (isClass _accessCfg) then {(getNumber (_accessCfg >> "keypad")) isEqualTo 1} else {false};
private _codes = if (isClass _accessCfg) then {getArray (_accessCfg >> "codes")} else {[]};
private _keycards = if (isClass _accessCfg) then {getArray (_accessCfg >> "keycards")} else {[]};
private _permissions = if (isClass _accessCfg) then {getArray (_accessCfg >> "permissions")} else {[]};
private _sides = if (isClass _accessCfg) then {getArray (_accessCfg >> "sides")} else {[]};

if !(isNull _matched) then {
    private _ruleLabel = getText (_matched >> "label");
    if !(_ruleLabel isEqualTo "") then {_label = _ruleLabel;};

    if (!isNull (_matched >> "keypad")) then {
        _keypad = (getNumber (_matched >> "keypad")) isEqualTo 1;
    };

    {
        _codes pushBackUnique _x;
    } forEach getArray (_matched >> "codes");

    {
        _keycards pushBackUnique _x;
    } forEach getArray (_matched >> "keycards");

    {
        _permissions pushBackUnique _x;
    } forEach getArray (_matched >> "permissions");

    {
        _sides pushBackUnique _x;
    } forEach getArray (_matched >> "sides");
};

private _objectLabel = _building getVariable [format ["life_door_label_%1",_door],_building getVariable ["life_door_label",""]];
if !(_objectLabel isEqualTo "") then {_label = _objectLabel;};

private _objectKeypad = _building getVariable [format ["life_door_keypad_%1",_door],_building getVariable ["life_door_keypad",-1]];
if (_objectKeypad isEqualType true) then {
    _keypad = _objectKeypad;
} else {
    if (_objectKeypad >= 0) then {_keypad = _objectKeypad isEqualTo 1;};
};

{
    _codes pushBackUnique _x;
} forEach (_building getVariable [format ["life_door_codes_%1",_door],_building getVariable ["life_door_codes",[]]]);

{
    _keycards pushBackUnique _x;
} forEach (_building getVariable [format ["life_door_keycards_%1",_door],_building getVariable ["life_door_keycards",[]]]);

{
    _permissions pushBackUnique _x;
} forEach (_building getVariable [format ["life_door_permissions_%1",_door],_building getVariable ["life_door_permissions",[]]]);

{
    _sides pushBackUnique _x;
} forEach (_building getVariable [format ["life_door_sides_%1",_door],_building getVariable ["life_door_sides",[]]]);

[_mode,_label,_keypad,_codes,_keycards,_permissions,_sides]
