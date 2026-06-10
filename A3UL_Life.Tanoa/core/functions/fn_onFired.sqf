#include "..\..\script_macros.hpp"
/*
    File: fn_onFired.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles various different ammo types being fired.
*/
private ["_ammoType","_projectile"];
_ammoType = _this select 4;
_projectile = _this select 6;

private _mode = missionNamespace getVariable ["life_fireMode","SEMI"];
if (_mode isEqualTo "SAFE") exitWith {
    if (!isNull _projectile) then {deleteVehicle _projectile;};
    titleText ["Fire mode: SAFE","PLAIN"];
};

if (_mode isEqualTo "SEMI") then {
    private _lastShot = missionNamespace getVariable ["life_lastShotTime",0];
    if ((time - _lastShot) < 0.18) exitWith {
        if (!isNull _projectile) then {deleteVehicle _projectile;};
    };
    life_lastShotTime = time;
};

if (_ammoType isEqualTo "GrenadeHand_stone") then {
    _projectile spawn {
        private "_position";
        while {!isNull _this} do {
            _position = ASLtoATL (visiblePositionASL _this);
            sleep 0.1;
        };
        [_position] remoteExec ["life_fnc_flashbang",RCLIENT];
    };
};
