#include "..\..\script_macros.hpp"
/*
    File: fn_unimpound.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Yeah... Gets the vehicle from the garage.
*/
disableSerialization;
if ((lbCurSel 2802) isEqualTo -1) exitWith {hint localize "STR_Global_NoSelection"};
_vehicle = lbData[2802,(lbCurSel 2802)];
_vehicle = (call compile format ["%1",_vehicle]) select 0;
_vehicleLife = _vehicle;
_vid = lbValue[2802,(lbCurSel 2802)];
_pid = getPlayerUID player;
_unit = player;
_spawntext = localize "STR_Garage_spawn_Success";
if (isNil "_vehicle") exitWith {hint localize "STR_Garage_Selection_Error"};
if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _vehicleLife)) then {
    _vehicleLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_vehicle];
};

private _price = 0;

private _garageSpawn = life_garage_sp;
if (_garageSpawn isEqualType [] && {(count _garageSpawn) > 0} && {(_garageSpawn select 0) isEqualType ""}) then {
    private _availableMarker = "";
    {
        if ((nearestObjects [getMarkerPos _x,["Car","Air","Ship"],10]) isEqualTo []) exitWith {_availableMarker = _x;};
    } forEach _garageSpawn;
    _garageSpawn = _availableMarker;
};
if (_garageSpawn isEqualType "" && {_garageSpawn isEqualTo ""}) exitWith {hint localize "STR_Garage_SpawnPointError";};

if (_garageSpawn isEqualType []) then {
    if (life_HC_isActive) then {
        [_vid,_pid,(_garageSpawn select 0),_unit,_price,(_garageSpawn select 1),_spawntext] remoteExec ["HC_fnc_spawnVehicle",HC_Life];
    } else {
        [_vid,_pid,(_garageSpawn select 0),_unit,_price,(_garageSpawn select 1),_spawntext] remoteExec ["TON_fnc_spawnVehicle",RSERV];
    };
} else {
    if (_garageSpawn in ["medic_spawn_1","medic_spawn_2","medic_spawn_3"]) then {
        if (life_HC_isActive) then {
            [_vid,_pid,_garageSpawn,_unit,_price,0,_spawntext] remoteExec ["HC_fnc_spawnVehicle",HC_Life];
        } else {
            [_vid,_pid,_garageSpawn,_unit,_price,0,_spawntext] remoteExec ["TON_fnc_spawnVehicle",RSERV];
        };
    } else {
        if (life_HC_isActive) then {
            [_vid,_pid,(getMarkerPos _garageSpawn),_unit,_price,markerDir _garageSpawn,_spawntext] remoteExec ["HC_fnc_spawnVehicle",HC_Life];
        } else {
            [_vid,_pid,(getMarkerPos _garageSpawn),_unit,_price,markerDir _garageSpawn,_spawntext] remoteExec ["TON_fnc_spawnVehicle",RSERV];
        };
    };
};

hint localize "STR_Garage_SpawningVeh";
closeDialog 0;
