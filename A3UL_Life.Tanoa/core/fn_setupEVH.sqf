/*
    File: fn_setupEVH.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Master eventhandler file
*/
player addEventHandler ["Killed", {_this call life_fnc_onPlayerKilled}];
player addEventHandler ["HandleDamage", {_this call life_fnc_handleDamage}];
player addEventHandler ["Respawn", {_this call life_fnc_onPlayerRespawn}];
player addEventHandler ["GetOutMan", {
    [] spawn {
        sleep 0.05;
        [true,false] call life_fnc_resetSpawnState;
    };
}];
player addEventHandler ["Take", {_this call life_fnc_onTakeItem}];
player addEventHandler ["Fired", {_this call life_fnc_onFired}];
player addEventHandler ["InventoryClosed", {_this call life_fnc_inventoryClosed}];
player addEventHandler ["InventoryOpened", {_this call life_fnc_inventoryOpened}];
player addEventHandler ["HandleRating", {0}];

addMissionEventHandler ["Map", {_this call life_fnc_checkMap}];

(findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display","_button"];
    if !(_button isEqualTo 0) exitWith {false};
    if ((getNumber (missionConfigFile >> "Life_ELS" >> "enabled")) isEqualTo 0) exitWith {false};
    if ((getNumber (missionConfigFile >> "Life_ELS" >> "policeOnly")) isEqualTo 1 && {!(playerSide isEqualTo west)}) exitWith {false};
    if (vehicle player isEqualTo player) exitWith {false};

    private _vehicle = vehicle player;
    if !(driver _vehicle isEqualTo player) exitWith {false};
    if !([_vehicle] call life_fnc_elsIsConfigured) exitWith {false};

    [_vehicle] call life_fnc_elsAirhorn;
    true;
}];
