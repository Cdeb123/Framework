#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopStore.sqf
*/
private _shop = missionNamespace getVariable ["life_vehicle_shop_type","civ_car"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "Civilian" >> _shop;
if ((getNumber (_shopCfg >> "allowStore")) isEqualTo 0) exitWith {hint "Vehicle storage is not available at this shop.";};

private _nearVehicles = nearestObjects [getPosATL player,["Car","Air","Ship"],35];
private _vehicle = objNull;
{
    private _owners = _x getVariable ["vehicle_info_owners",[]];
    if ((count _owners) > 0 && {((_owners select 0) select 0) isEqualTo (getPlayerUID player)} && {!(_x getVariable ["life_vehicle_rental",false])}) exitWith {
        _vehicle = _x;
    };
} forEach _nearVehicles;

if (isNull _vehicle) exitWith {hint "No owned persistent vehicle is close enough to store.";};
if !(alive _vehicle) exitWith {hint localize "STR_Garage_SQLError_Destroyed";};

closeDialog 0;
if (life_HC_isActive) then {
    [_vehicle,false,player,localize "STR_Garage_Store_Success"] remoteExec ["HC_fnc_vehicleStore",HC_Life];
} else {
    [_vehicle,false,player,localize "STR_Garage_Store_Success"] remoteExec ["TON_fnc_vehicleStore",RSERV];
};
hint localize "STR_Garage_Store_Server";
life_garage_store = true;
