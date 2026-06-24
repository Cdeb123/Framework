/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Keeps native scroll-wheel interactions available for building doors.
    Space activates the highlighted action.
*/

{player removeAction _x;} forEach (player getVariable ["life_context_actions",[]]);

private _doorCondition = "!dialog && {!life_action_inUse} && {!(player getVariable ['restrained',false])} && {isNull objectParent player} && {!(([] call life_fnc_nearestBuildingDoor) isEqualTo [])}";

private _contextDoorAction = player addAction [
    "Use Door",
    {
        private _door = [] call life_fnc_nearestBuildingDoor;
        if !(_door isEqualTo []) then {_door call life_fnc_doorInteraction;};
    },
    nil,
    6,
    true,
    true,
    "",
    _doorCondition,
    7
];

life_actions = [_contextDoorAction];
player setVariable ["life_context_actions",life_actions,false];
player setVariable ["life_radial_ignore_actions",life_actions,false];
