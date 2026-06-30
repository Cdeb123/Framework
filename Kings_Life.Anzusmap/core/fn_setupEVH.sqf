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
    params ["_unit","_role","_vehicle"];
    [] call life_fnc_vehicleBackupCameraStop;
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

inGameUISetEventHandler ["Action","_this call life_fnc_actionMenuFilter"];

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

// Keep the wheel dedicated to action-menu navigation instead of weapon cycling.
(findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    params ["_display","_scroll"];
    if (dialog || {_scroll isEqualTo 0} || {!alive player}) exitWith {false};

    private _weapon = currentWeapon player;
    private _muzzle = currentMuzzle player;
    player setVariable ["life_scroll_weapon_time",diag_tickTime,false];

    if ((player getVariable ["life_scroll_weapon_state",[]]) isEqualTo []) then {
        player setVariable ["life_scroll_weapon_state",[_weapon,_muzzle],false];
        [] spawn {
            waitUntil {
                uiSleep 0.01;
                (diag_tickTime - (player getVariable ["life_scroll_weapon_time",0])) > 0.03
            };

            (player getVariable ["life_scroll_weapon_state",[]]) params [
                ["_weapon","",[""]],
                ["_muzzle","",[""]]
            ];
            player setVariable ["life_scroll_weapon_state",nil,false];
            player setVariable ["life_scroll_weapon_time",nil,false];
            if (!alive player) exitWith {};

            for "_i" from 0 to 5 do {
                uiSleep 0.03;
                if (_weapon isEqualTo "") then {
                    if !(currentWeapon player isEqualTo "") then {
                        player action ["SwitchWeapon",player,player,100];
                    };
                } else {
                    if (_weapon in weapons player && {!(currentWeapon player isEqualTo _weapon)}) then {
                        player selectWeapon ([_muzzle,_weapon] select (_muzzle isEqualTo ""));
                    };
                };
            };
        };
    };
    false
}];
