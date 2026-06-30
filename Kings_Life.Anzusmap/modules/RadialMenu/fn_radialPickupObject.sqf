#include "..\..\script_macros.hpp"
/*
    File: fn_radialPickupObject.sqf

    F1 pickup shortcut for normal ground item and cash pickups.
*/
params [
    ["_object",objNull,[objNull]]
];

if (isNull _object) then {_object = cursorObject;};
if (isNull _object) exitWith {hint "No item selected.";};
if (player distance _object > 4) exitWith {hint "Move closer to pick that up.";};

private _miscItems = ["Land_BottlePlastic_V1_F","Land_TacticalBacon_F","Land_Can_V3_F","Land_CanisterFuel_F","Land_Suitcase_F"];
if ((typeOf _object) in _miscItems) exitWith {
    [_object,player,false] remoteExecCall ["TON_fnc_pickupAction",RSERV];
};

if ((typeOf _object) isEqualTo "Land_Money_F" && {!(_object getVariable ["inUse",false])}) exitWith {
    [_object,player,true] remoteExecCall ["TON_fnc_pickupAction",RSERV];
};

hint "That item cannot be picked up from the F1 menu.";
