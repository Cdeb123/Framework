#include "..\..\script_macros.hpp"
/*
*    File: fn_keyHandler.sqf
*    Author: Bryan "Tonic" Boardwine
*
*    Description:
*    Main key handler for event 'keyDown'.
*/

params [
    "_ctrl",
    "_code",
    "_shift",
    "_ctrlKey",
    "_alt"
];

private _speed = speed cursorObject;
private _handled = false;
private _interruptionKeys = [17, 30, 31, 32]; //A,S,W,D

// F1 (or the configured custom action) owns framework interactions.
private _radialKey = LIFE_SETTINGS(getNumber,"radial_menu_key");
private _radialCustom = LIFE_SETTINGS(getText,"radial_menu_customAction");
private _radialCustomKeys = if (_radialCustom isEqualTo "") then {[]} else {actionKeys _radialCustom};
if ((_code isEqualTo _radialKey || {_code in _radialCustomKeys}) && {!_shift} && {!_ctrlKey} && {!_alt}) exitWith {
    if (!dialog || {!isNull (findDisplay 9200)}) then {[] call life_fnc_openRadialMenu;};
    true
};

private _vehicleControlsEnabled = (getNumber (missionConfigFile >> "Life_VehicleControls" >> "enabled")) isEqualTo 1;

private _isDriver = !(vehicle player isEqualTo player) && {driver (vehicle player) isEqualTo player};
private _vehicleHudEnabled = (getNumber (missionConfigFile >> "Life_VehicleHUD" >> "defaultVehicleHUD")) isEqualTo 1;
if (_vehicleHudEnabled && {!(vehicle player isEqualTo player)} && {_code isEqualTo (getNumber (missionConfigFile >> "Life_VehicleHUD" >> "gpsToggleKey"))} && {_ctrlKey} && {!_shift} && {!_alt}) exitWith {
    [] call life_fnc_vehicleHUDToggleGPS;
    true
};
if (_vehicleControlsEnabled && {_isDriver} && {_code isEqualTo (getNumber (missionConfigFile >> "Life_VehicleControls" >> "backupCameraKey"))} && {_ctrlKey} && {!_alt}) exitWith {
    [vehicle player] call life_fnc_vehicleBackupCamera;
    true
};

//Vault handling...
if ((_code in (actionKeys "GetOver") || _code in (actionKeys "salute") || _code in (actionKeys "SitDown") || _code in (actionKeys "Throw") || _code in (actionKeys "GetIn") || _code in (actionKeys "GetOut") || _code in (actionKeys "Fire") || _code in (actionKeys "ReloadMagazine") || _code in [16,18]) && ((player getVariable ["restrained",false]) || (player getVariable ["playerSurrender",false]) || life_isknocked || life_istazed)) exitWith {
    true;
};

if (_code in (actionKeys "GetOut") && {missionNamespace getVariable ["life_seatbelt",false]} && {!(vehicle player isEqualTo player)}) exitWith {
    hint "Unbuckle your seatbelt first.";
    true;
};

private _isVehicleHornKey = (_code in (actionKeys "Fire")) || {_code in (actionKeys "CarHorn")};
if (_isVehicleHornKey
    && {!(vehicle player isEqualTo player)}
    && {driver (vehicle player) isEqualTo player}
    && {(getNumber (missionConfigFile >> "Life_ELS" >> "enabled")) isEqualTo 1}
    && {!((getNumber (missionConfigFile >> "Life_ELS" >> "policeOnly")) isEqualTo 1 && {!(playerSide isEqualTo west)})}
    && {[vehicle player] call life_fnc_elsIsConfigured}) exitWith {
    [vehicle player] call life_fnc_elsAirhorn;
    true;
};

if (life_action_inUse) exitWith {
    if (!life_interrupted && _code in _interruptionKeys) then {life_interrupted = true};
    _handled;
};

if (life_container_active) exitwith {
    //ignore movement actions
    private _allowedMoves = [
        "MoveForward",
        "MoveBack",
        "TurnLeft",
        "TurnRight",
        "MoveFastForward",
        "MoveSlowForward",
        "turbo",
        "TurboToggle",
        "MoveLeft",
        "MoveRight",
        "WalkRunTemp",
        "WalkRunToggle",
        "AdjustUp",
        "AdjustDown",
        "AdjustLeft",
        "AdjustRight",
        "Stand",
        "Crouch",
        "Prone",
        "MoveUp",
        "MoveDown",
        "LeanLeft",
        "LeanLeftToggle",
        "LeanRight",
        "LeanRightToggle"
    ];
    if (({_code in (actionKeys _x)} count _allowedMoves) > 0) exitwith {
        false;
    };
    //handle other keys
    if (_code isEqualTo 57) then {//space key -> place
        life_storagePlacing = 0 spawn life_fnc_placestorage;
    } else { //other keys -> abort
        if (!isNull life_storagePlacing) exitWith {}; //already placing down a box
        if (!isNull life_container_activeObj) then {
            deleteVehicle life_container_activeObj;
            titleText [localize "STR_NOTF_PlaceContainerAbort", "PLAIN"];
        };
        life_container_active = false;
    };
    true;
};

if ([_code] call life_fnc_elsKey) exitWith {true;};

switch (_code) do {
    // -- Disable commander/tactical view
    if (LIFE_SETTINGS(getNumber,"disableCommanderView") isEqualTo 1) then {
        private _CommandMode = actionKeys "tacticalView";

        if (_code in _CommandMode) then {
            hint localize "STR_NOTF_CommanderView";
            _handled = true;
        };
    };

    //Space key for Jumping
    case 57: {
        if (isNil "jumpActionTime") then {jumpActionTime = 0;};
        if (_shift && {!(animationState player isEqualTo "AovrPercMrunSrasWrflDf")} && {isTouchingGround player} && {stance player isEqualTo "STAND"} && {speed player > 2} && {!life_is_arrested} && {((velocity player) select 2) < 2.5} && {time - jumpActionTime > 1.5}) then {
            jumpActionTime = time; //Update the time.
            [player] remoteExec ["life_fnc_jumpFnc",RANY]; //Global execution
            _handled = true;
        };
    };

    //Surrender (Shift + B) / Seatbelt (Ctrl + B)
    case 48: {
        if (_ctrlKey && {!_shift} && {!(vehicle player isEqualTo player)}) then {
            [] call life_fnc_seatbeltToggle;
            _handled = true;
        };

        if (_shift) then {
            if (player getVariable ["playerSurrender",false]) then {
                player setVariable ["playerSurrender",false,true];
            } else {
                [] spawn life_fnc_surrender;
            };
            _handled = true;
        };
    };

    //Holster / recall weapon. (Shift + H / Ctrl + H)
    case 35: {
        if (_shift && !_ctrlKey && !(currentWeapon player isEqualTo "")) then {
            [true,false] call life_fnc_resetSpawnState;
            _handled = true;
        };

        if (!_shift && _ctrlKey && !isNil "life_curWep_h" && {!(life_curWep_h isEqualTo "")}) then {
            if (life_curWep_h in [primaryWeapon player,secondaryWeapon player,handgunWeapon player]) then {
                player selectWeapon life_curWep_h;
                _handled = true;
            };
        };
    };

    //Restraining (Shift + R soft, Ctrl + Shift + R hard)
    case 19: {
        if (_shift) then {_handled = true};
        if (_shift && playerSide isEqualTo west && {!isNull cursorObject} && {cursorObject isKindOf "CAManBase"} && {(isPlayer cursorObject)} && {(side cursorObject in [civilian,independent])} && {alive cursorObject} && {cursorObject distance player < 3.8} && {!(cursorObject getVariable "Escorting")} && {!(cursorObject getVariable "restrained")} && {speed cursorObject < 4}) then {
            [_ctrlKey] call life_fnc_restrainAction;
        };
    };

    //Knock out, this is experimental and yeah... (Shift + G)
    case 34: {
        if (_shift) then {_handled = true};
        if (_shift && playerSide isEqualTo civilian && !isNull cursorObject && cursorObject isKindOf "CAManBase" && isPlayer cursorObject && alive cursorObject && cursorObject distance player < 4 && speed cursorObject < 1) then {
            if ((animationState cursorObject) != "Incapacitated" && (currentWeapon player == primaryWeapon player || currentWeapon player == handgunWeapon player) && currentWeapon player != "" && !life_knockout && !(player getVariable ["restrained",false]) && !life_istazed && !life_isknocked) then {
                [cursorObject] spawn life_fnc_knockoutAction;
            };
        };
    };

    //T Key (Trunk)
    case 20: {
        if (_ctrlKey && _shift && {!_alt} && {!dialog}) exitWith {
            [] call life_fnc_openLEOTrainingTerminal;
            _handled = true;
        };

        if (!_alt && {!_ctrlKey} && {!dialog} && {!life_action_inUse} && {!(player getVariable ["playerSurrender",false])} && {!(player getVariable ["restrained",false])} && {!life_isknocked} && {!life_istazed}) then {
            if (!(isNull objectParent player) && alive vehicle player) then {
                if ((vehicle player) in life_vehicles) then {
                    [vehicle player] spawn life_fnc_openInventory;
                };
            } else {
                private "_list";
                _list = ((ASLtoATL (getPosASL player)) nearEntities [["Box_IND_Grenades_F","B_supplyCrate_F"], 2.5]) select 0;
                if (!(isNil "_list")) then {
                    _house = nearestObject [(ASLtoATL (getPosASL _list)), "House"];
                    if (_house getVariable ["locked", false]) then {
                        hint localize "STR_House_ContainerDeny";
                    } else {
                        [_list] spawn life_fnc_openInventory;
                    };
                } else {
                    _list = ["landVehicle","Air","Ship"];
                    if (KINDOF_ARRAY(cursorObject,_list) && {player distance cursorObject < 7} && {isNull objectParent player} && {alive cursorObject} && {!life_action_inUse}) then {
                        if (cursorObject in life_vehicles || {locked cursorObject isEqualTo 0}) then {
                            [cursorObject] spawn life_fnc_openInventory;
                        };
                    };
                };
            };
        };
    };

    //L Key?
    case 38: {
        if (_ctrlKey && _shift && {!_alt} && {!dialog}) exitWith {
            [] call life_fnc_openLEOCommandTerminal;
            _handled = true;
        };

        if (!_alt && !_ctrlKey) then { [] call life_fnc_radar; };
    };

    //Y Player Menu
    case 21: {
        if (!_alt && !_ctrlKey && !dialog && !(player getVariable ["restrained",false]) && {!life_action_inUse}) then {
            [] call life_fnc_p_openMenu;
        };
    };

    //I ID Card
    case 23: {
        if (_ctrlKey && {!_alt} && {!dialog}) then {
            if (!isNull cursorObject && {isPlayer cursorObject} && {player distance cursorObject < 5}) then {
                [cursorObject] call life_fnc_showID;
            } else {
                [] call life_fnc_openID;
            };
            _handled = true;
        };
    };

    //P Character Menu
    case 25: {
        if (_ctrlKey && {!_alt} && {!dialog}) then {
            createDialog "life_character_select";
            _handled = true;
        };
    };

    //F Key
    case 33: {
        if (!_shift && {!_ctrlKey} && {!_alt} && {!dialog}) then {
            private _gatherInteraction = [] call life_fnc_gatherInteraction;
            if !(_gatherInteraction isEqualTo []) exitWith {
                _gatherInteraction params [
                    ["_kind","",[""]],
                    ["_title","",[""]],
                    ["_subtitle","",[""]],
                    ["_functionName","",[""]]
                ];

                private _function = missionNamespace getVariable [format ["life_fnc_%1",_functionName],{}];
                [] spawn _function;
                _handled = true;
            };
        };

        if ((playerSide in [west,independent]) && {vehicle player != player} && {((driver vehicle player) == player)}) then {_handled = true;};
    };

    //O Key
    case 24: {
        if (_shift) then {
            if !(soundVolume isEqualTo 1) then {
                1 fadeSound 1;
                systemChat localize "STR_MISC_soundnormal";
            } else {
                1 fadeSound 0.1;
                systemChat localize "STR_MISC_soundfade";
            };
        };
    };

    //U Key - owned house/vehicle lock shortcut
    case 22: {
        if (!_alt && !_ctrlKey) then {
            private _veh = if (isNull objectParent player) then {
                cursorObject;
            } else {
                vehicle player;
            };

            if (_veh isKindOf "House_F") then {
                [_veh,0] call life_fnc_radialHouseDoorLock;
            } else {
                [_veh] call life_fnc_radialVehicleLock;
            };
            _handled = true;
        };
    };
};

_handled;
