#include "..\script_macros.hpp"
/*
    File: fn_initMedic.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the medic..
*/
waitUntil {!(isNull (findDisplay 46))};
private _isOwner = [] call life_fnc_isCommunityOwner;

if (!_isOwner && {(FETCH_CONST(life_medicLevel)) < 1 && (FETCH_CONST(life_adminlevel) isEqualTo 0)}) exitWith {
    ["Notwhitelisted",false,true] call BIS_fnc_endMission;
    sleep 35;
};

player setVariable ["rank",([FETCH_CONST(life_medicLevel),getNumber (missionConfigFile >> "Life_CommunityOwnerGrant" >> "medicRank")] select _isOwner),true];
[] call life_fnc_characterGate;
[] call life_fnc_spawnMenu;
waitUntil{!isNull (findDisplay 38500)}; //Wait for the spawn selection to be open.
waitUntil{isNull (findDisplay 38500)}; //Wait for the spawn selection to be done.
