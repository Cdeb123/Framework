#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopReturn.sqf
*/
private _nearVehicles = nearestObjects [getPosATL player,["Car","Air","Ship"],35];
private _vehicle = objNull;
{
    private _owners = _x getVariable ["vehicle_info_owners",[]];
    if ((count _owners) > 0 && {((_owners select 0) select 0) isEqualTo (getPlayerUID player)} && {_x getVariable ["life_vehicle_rental",false]}) exitWith {
        _vehicle = _x;
    };
} forEach _nearVehicles;

if (isNull _vehicle) exitWith {hint "No rental vehicle registered to you is close enough to return.";};
if !(alive _vehicle) exitWith {hint "That rental is destroyed and cannot be returned here.";};

life_vehicles = life_vehicles - [_vehicle];
deleteVehicle _vehicle;
hint "Rental returned.";
closeDialog 0;
