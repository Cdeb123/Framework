#include "..\..\script_macros.hpp"
/*
    File: fn_restrainAction.sqf

    Description:
    Restrains the target. Soft cuff is the normal controlled cuff.
    Hard cuff adds a short takedown/tackle moment before restraint.
*/
params [
    ["_hardCuff",false,[false]]
];

private _unit = cursorObject;
if (isNull _unit) exitWith {};
if (player distance _unit > 3.8) exitWith {};
if (_unit getVariable ["restrained",false]) exitWith {};
if (side _unit isEqualTo west) exitWith {};
if (player isEqualTo _unit) exitWith {};
if (!isPlayer _unit) exitWith {};
if (_hardCuff && {speed _unit > 6}) exitWith {hint "The target is moving too fast to hard cuff.";};

life_action_inUse = true;

if (_hardCuff) then {
    player playActionNow "PutDown";
    [_unit,"cuffHardSound",35,1] remoteExecCall ["life_fnc_say3D",RCLIENT];
    uiSleep 0.8;
} else {
    player playActionNow "Medic";
    [_unit,"cuffSoftSound",25,1] remoteExecCall ["life_fnc_say3D",RCLIENT];
    uiSleep 0.45;
};

_unit setVariable ["playerSurrender",false,true];
_unit setVariable ["restrained",true,true];
_unit setVariable ["restrainMode",(["soft","hard"] select _hardCuff),true];
[player,_hardCuff] remoteExec ["life_fnc_restrain",_unit];
[0,"STR_NOTF_Restrained",true,[_unit getVariable ["realname", name _unit], profileName]] remoteExecCall ["life_fnc_broadcast",west];

life_action_inUse = false;
