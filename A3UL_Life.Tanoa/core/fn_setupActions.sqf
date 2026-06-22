/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Keeps native scroll-wheel interactions available and adds contextual door
    controls to the same action menu. Space activates the highlighted action.
*/

{player removeAction _x;} forEach (player getVariable ["life_context_actions",[]]);

private _doorCondition = "!dialog && {!life_action_inUse} && {!(player getVariable ['restrained',false])} && {!(isNull objectParent player) || {!(([] call life_fnc_nearestBuildingDoor) isEqualTo [])} || {!isNull cursorObject && {cursorObject isKindOf 'LandVehicle' || {cursorObject isKindOf 'Ship'} || {cursorObject isKindOf 'Air'}} && {player distance cursorObject < 7}}}";

private _contextDoorAction = player addAction [
    "Use Door",
    { [false] call life_fnc_vehicleContextDoor; },
    nil,
    6,
    true,
    true,
    "",
    _doorCondition,
    7
];

private _allVehicleDoorsAction = player addAction [
    "Open / Close All Vehicle Doors",
    { [true] call life_fnc_vehicleContextDoor; },
    nil,
    5,
    true,
    true,
    "",
    "!dialog && {!life_action_inUse} && {!(player getVariable ['restrained',false])} && {!(isNull objectParent player)}"
];

life_actions = [_contextDoorAction,_allVehicleDoorsAction];
player setVariable ["life_context_actions",life_actions,false];
player setVariable ["life_radial_ignore_actions",life_actions,false];
