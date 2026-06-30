#include "..\..\script_macros.hpp"
/*
    File: fn_resetSpawnState.sqf

    Description:
    Clears bad spawn/exit animation state and keeps the player's weapon holstered.
*/
params [
    ["_rememberWeapon",true,[true]],
    ["_forceStand",true,[true]]
];

private _applyState = {
    params [
        ["_remember",true,[true]],
        ["_stand",true,[true]]
    ];

    if (!alive player) exitWith {};

    if (_stand && {isNull objectParent player}) then {
        player setUnitPos "UP";
        player switchMove "";
        player playMoveNow "AmovPercMstpSnonWnonDnon";
    };

    if (_remember) then {
        private _weapon = currentWeapon player;
        if (_weapon isEqualTo "") then {_weapon = primaryWeapon player;};
        if (_weapon isEqualTo "") then {_weapon = handgunWeapon player;};
        if (_weapon isEqualTo "") then {_weapon = secondaryWeapon player;};
        life_curWep_h = _weapon;
    };

    player action ["SwitchWeapon",player,player,100];
    player switchCamera cameraView;
};

[_rememberWeapon,_forceStand] call _applyState;

[_rememberWeapon,_forceStand,_applyState] spawn {
    params [
        ["_remember",true,[true]],
        ["_stand",true,[true]],
        ["_stateFn",{},[{}]]
    ];

    sleep 0.1;
    [_remember,_stand] call _stateFn;

    sleep 0.35;
    [_remember,_stand] call _stateFn;

    if (_stand && {alive player} && {isNull objectParent player}) then {
        player setUnitPos "AUTO";
        player action ["SwitchWeapon",player,player,100];
    };
};
