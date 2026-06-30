#include "..\..\script_macros.hpp"
/*
    File: fn_actionMenuFilter.sqf

    Description:
    Blocks default action-menu weapon switching while leaving mission
    addActions available for the native scroll wheel.
*/
private _blockedActions = [
    "switchweapon",
    "switchweapongroup",
    "switchprimary",
    "switchsecondary",
    "switchhandgun",
    "switchlauncher",
    "switchmagazine"
];

private _actionName = "";
{
    if (_x isEqualType "") then {
        private _candidate = toLower _x;
        if (_candidate in _blockedActions) exitWith {_actionName = _candidate;};
    };
} forEach _this;

if (_actionName isEqualTo "") exitWith {false};

private _scrollState = player getVariable ["life_scroll_weapon_state",[]];
if !(_scrollState isEqualTo []) then {
    _scrollState params [
        ["_weapon","",[""]],
        ["_muzzle","",[""]]
    ];

    if (_weapon isEqualTo "") then {
        player action ["SwitchWeapon",player,player,100];
    } else {
        if (_weapon in weapons player) then {
            player selectWeapon ([_muzzle,_weapon] select (_muzzle isEqualTo ""));
        };
    };
};

true
