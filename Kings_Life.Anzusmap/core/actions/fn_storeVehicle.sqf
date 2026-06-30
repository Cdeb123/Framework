#include "..\..\script_macros.hpp"
/*
    File: fn_storeVehicle.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Stores the vehicle in the garage.
*/
private _source = param [0,player,[objNull]];
private _unit = param [1,player,[objNull]];
private _vehicle = objNull;
private _expectedType = missionNamespace getVariable ["life_garage_type",""];
private _expectedSide = switch (playerSide) do {
    case west: {"cop"};
    case independent: {"med"};
    case civilian: {"civ"};
    default {""};
};
private _characterUid = missionNamespace getVariable ["life_character_uid",getPlayerUID player];

if !(isNull objectParent player) then {
    _vehicle = vehicle player;
} else {
    private _nearVehicles = nearestObjects [getPos _source,["Car","Air","Ship"],35];
    if (count _nearVehicles > 0) then {
        {
            private _vehData = _x getVariable ["vehicle_info_owners",[]];
            if (count _vehData > 0) then {
                private _vehOwner = ((_vehData select 0) select 0);
                private _candidateType = switch (true) do {
                    case (_x isKindOf "Car"): {"Car"};
                    case (_x isKindOf "Air"): {"Air"};
                    case (_x isKindOf "Ship"): {"Ship"};
                    default {""};
                };
                private _candidateSide = _x getVariable ["vehicleSide",""];
                private _candidateCharacter = _x getVariable ["characterUID",""];
                if (
                    (getPlayerUID player) isEqualTo _vehOwner
                    && {_expectedType isEqualTo "" || {_candidateType isEqualTo _expectedType}}
                    && {_candidateSide isEqualTo "" || {_candidateSide isEqualTo _expectedSide}}
                    && {_candidateCharacter isEqualTo "" || {_candidateCharacter isEqualTo _characterUid}}
                ) exitWith {
                    _vehicle = _x;
                };
            };
        } forEach _nearVehicles;
    };
};

if (isNull _vehicle) exitWith {hint "No owned persistent vehicle is close enough to store.";};
if (!alive _vehicle) exitWith {hint localize "STR_Garage_SQLError_Destroyed"};

private _actualType = switch (true) do {
    case (_vehicle isKindOf "Car"): {"Car"};
    case (_vehicle isKindOf "Air"): {"Air"};
    case (_vehicle isKindOf "Ship"): {"Ship"};
    default {""};
};
if !(_expectedType isEqualTo "" || {_actualType isEqualTo _expectedType}) exitWith {
    hint format ["This garage accepts %1 vehicles, not %2 vehicles.",toLower _expectedType,toLower _actualType];
};

private _vehicleSide = _vehicle getVariable ["vehicleSide",""];
if !(_vehicleSide isEqualTo "" || {_vehicleSide isEqualTo _expectedSide}) exitWith {
    hint "That vehicle belongs to a different role garage.";
};

private _vehicleCharacter = _vehicle getVariable ["characterUID",""];
if !(_vehicleCharacter isEqualTo "" || {_vehicleCharacter isEqualTo _characterUid}) exitWith {
    hint "That vehicle belongs to a different character.";
};

private _storetext = localize "STR_Garage_Store_Success";

if (life_HC_isActive) then {
    [_vehicle,false,_unit,_storetext] remoteExec ["HC_fnc_vehicleStore",HC_Life];
} else {
    [_vehicle,false,_unit,_storetext] remoteExec ["TON_fnc_vehicleStore",RSERV];
};

hint localize "STR_Garage_Store_Server";
life_garage_store = true;
