/* Left-Windows context interaction for building and vehicle doors. */
params [["_allDoors",false,[false]]];
if (dialog || {player getVariable ["restrained",false]} || {life_action_inUse}) exitWith {};

if !(isNull objectParent player) exitWith {
    [vehicle player,["driver","all"] select _allDoors] call life_fnc_vehicleDoorControl;
};

private _nearDoor = [] call life_fnc_nearestBuildingDoor;
if !(_nearDoor isEqualTo []) exitWith {
    _nearDoor call life_fnc_doorInteraction;
};

private _vehicle = objNull;
if (!isNull cursorObject && {(cursorObject isKindOf "LandVehicle") || {cursorObject isKindOf "Ship"} || {cursorObject isKindOf "Air"}} && {player distance cursorObject < 7}) then {
    _vehicle = cursorObject;
} else {
    private _near = nearestObjects [player,["LandVehicle","Ship","Air"],5];
    if !(_near isEqualTo []) then {_vehicle = _near select 0;};
};

if (isNull _vehicle) exitWith {hint "No usable door is close enough.";};
[_vehicle,["driver","all"] select _allDoors] call life_fnc_vehicleDoorControl;
