#include "..\..\script_macros.hpp"
/*
    File: fn_nearbyInteractionActions.sqf

    Builds usable radial interactions from migrated legacy addActions plus
    direct framework actions for players, vehicles, houses, LEO, and EMS.
*/
params [
    ["_category","",[""]]
];

private _actions = [];
private _radius = LIFE_SETTINGS(getNumber,"radial_menu_radius");
if (_radius <= 0) then {_radius = 6;};

private _addAction = {
    params [
        ["_title","Interact",[""]],
        ["_subtitle","",[""]],
        ["_type","code",[""]],
        ["_payload",[],[[],objNull,""]],
        ["_group","General",[""]],
        ["_priority",0,[0]]
    ];

    if (_title isEqualTo "") exitWith {};
    if (_category isEqualTo "" || {_group isEqualTo _category}) then {
        _actions pushBack [_title,_subtitle,_type,_payload,_group,_priority];
    };
};

private _actionGroup = {
    params [["_title","",[""]]];
    private _lower = toLower _title;
    if ((["license",_lower] call BIS_fnc_inString) || {["permit",_lower] call BIS_fnc_inString}) exitWith {"License Shop"};
    if ((["garage",_lower] call BIS_fnc_inString) || {["store vehicle",_lower] call BIS_fnc_inString}) exitWith {"Garage"};
    if ((["atm",_lower] call BIS_fnc_inString) || {["bank",_lower] call BIS_fnc_inString}) exitWith {"Banking"};
    if ((["medical",_lower] call BIS_fnc_inString) || {["hospital",_lower] call BIS_fnc_inString} || {["service",_lower] call BIS_fnc_inString}) exitWith {"Service"};
    if ((["ems",_lower] call BIS_fnc_inString) || {["fire",_lower] call BIS_fnc_inString}) exitWith {"EMS"};
    if ((["cop",_lower] call BIS_fnc_inString) || {["police",_lower] call BIS_fnc_inString} || {["apd",_lower] call BIS_fnc_inString} || {["tpd",_lower] call BIS_fnc_inString}) exitWith {"Law Enforcement"};
    if (
        (["shop",_lower] call BIS_fnc_inString)
        || {["store",_lower] call BIS_fnc_inString}
        || {["market",_lower] call BIS_fnc_inString}
        || {["armament",_lower] call BIS_fnc_inString}
        || {["weapon",_lower] call BIS_fnc_inString}
        || {["firearm",_lower] call BIS_fnc_inString}
        || {["clothing",_lower] call BIS_fnc_inString}
        || {["vehicle",_lower] call BIS_fnc_inString}
        || {["helicopter",_lower] call BIS_fnc_inString}
        || {["boat",_lower] call BIS_fnc_inString}
        || {["car",_lower] call BIS_fnc_inString}
        || {["food",_lower] call BIS_fnc_inString}
        || {["cart",_lower] call BIS_fnc_inString}
        || {["coffee",_lower] call BIS_fnc_inString}
        || {["dealer",_lower] call BIS_fnc_inString}
        || {["trader",_lower] call BIS_fnc_inString}
        || {["buyer",_lower] call BIS_fnc_inString}
        || {["item",_lower] call BIS_fnc_inString}
    ) exitWith {"Access Shop"};
    "Nearby"
};

private _vendorName = {
    params [["_target",objNull,[objNull]]];
    private _name = _target getVariable ["realname",""];
    if (_name isEqualTo "") then {
        _name = getText (configFile >> "CfgVehicles" >> typeOf _target >> "displayName");
    };
    if (_name isEqualTo "") then {_name = "Nearby"};
    _name
};

private _isVehicle = {
    params [["_target",objNull,[objNull]]];
    private _filters = ["LandVehicle","Ship","Air"];
    !isNull _target && {KINDOF_ARRAY(_target,_filters)}
};

private _candidates = [player];
if (!isNull cursorObject && {player distance cursorObject <= (_radius + 2)}) then {
    _candidates pushBackUnique cursorObject;
};

{
    if (!(_x isEqualTo player)) then {
        _candidates pushBackUnique _x;
    };
} forEach (player nearObjects (_radius + 2));

{
    if (!(_x isEqualTo player)) then {
        _candidates pushBackUnique _x;
    };
} forEach (nearestObjects [player,["CAManBase","LandVehicle","Ship","Air","ReammoBox_F","House_F","Land_Atm_01_F","Land_Atm_02_F","Land_InfoStand_V1_F","Land_InfoStand_V2_F","Land_InfoStand_V3_F"],_radius + 2]);

{
    private _targetObject = _x;
    private _legacyActions = [_targetObject] call life_fnc_captureInteractionActions;
    {
        _x params [
            ["_title","Interact",[""]],
            ["_statement",{},[{},""]],
            ["_arguments",nil],
            ["_condition","true",[""]],
            ["_actionRadius",_radius,[0]],
            ["_priority",0,[0]]
        ];
        if (_actionRadius <= 0) then {_actionRadius = _radius;};
        if (player distance _targetObject <= (_actionRadius max _radius)) then {
            private _allowed = true;
            if !(_condition isEqualTo "") then {
                private _target = _targetObject;
                private _originalTarget = _targetObject;
                private _conditionResult = false;
                private _conditionFailed = isNil {
                    private _result = player call (compile _condition);
                    if (_result isEqualType true) then {_conditionResult = _result;};
                    _conditionResult
                };
                _allowed = (!_conditionFailed) && {_conditionResult};
            };
            if (_allowed) then {
                private _group = [_title] call _actionGroup;
                private _vendor = [_targetObject] call _vendorName;
                [_title,_vendor,"legacyAction",[_targetObject,_statement,_arguments],_group,20 + _priority] call _addAction;
            };
        };
    } forEach _legacyActions;
} forEach _candidates;

private _leoCraftingAdded = false;
private _rebelCraftingAdded = false;
{
    private _targetObject = _x;
    if (player distance _targetObject <= (_radius + 2)) then {
        private _legacyActions = _targetObject getVariable ["life_radial_legacy_actions",[]];
        private _legacyText = "";
        {
            _legacyText = _legacyText + " " + toLower (_x param [0,"",[""]]);
        } forEach _legacyActions;

        if (
            !_leoCraftingAdded
            && {playerSide isEqualTo west}
            && {
                (["cop",_legacyText] call BIS_fnc_inString)
                || {["police",_legacyText] call BIS_fnc_inString}
                || {["tcsd",_legacyText] call BIS_fnc_inString}
            }
            && {
                (["weapon",_legacyText] call BIS_fnc_inString)
                || {["item",_legacyText] call BIS_fnc_inString}
                || {["clothing",_legacyText] call BIS_fnc_inString}
                || {["armory",_legacyText] call BIS_fnc_inString}
            }
        ) then {
            ["LEO Crafting","Craft rank and role-gated duty gear at this station","function",["openCraftingMenu",["leo",_targetObject]],"Law Enforcement",28] call _addAction;
            _leoCraftingAdded = true;
        };

        if (
            !_rebelCraftingAdded
            && {playerSide isEqualTo civilian}
            && {missionNamespace getVariable ["license_civ_rebel",false]}
            && {
                (["rebel",_legacyText] call BIS_fnc_inString)
                || {["gang armament",_legacyText] call BIS_fnc_inString}
            }
        ) then {
            ["Rebel Crafting","Craft restricted rebel gear and vehicles","function",["openCraftingMenu",["rebel",_targetObject]],"Access Shop",29] call _addAction;
            _rebelCraftingAdded = true;
        };
    };
} forEach _candidates;

private _targetPlayer = objNull;
if (!isNull cursorObject && {isPlayer cursorObject} && {player distance cursorObject <= 5}) then {
    _targetPlayer = cursorObject;
} else {
    {
        if (_x != player && {player distance _x <= 5}) exitWith {
            _targetPlayer = _x;
        };
    } forEach playableUnits;
    if (isNull _targetPlayer) then {
        {
            if (_x != player && {isPlayer _x}) exitWith {_targetPlayer = _x;};
        } forEach (nearestObjects [player,["CAManBase"],5]);
    };
};

private _vehicleTarget = objNull;
if (!(isNull objectParent player)) then {
    _vehicleTarget = vehicle player;
} else {
    if ([cursorObject] call _isVehicle && {player distance cursorObject <= 10}) then {
        _vehicleTarget = cursorObject;
    } else {
        private _nearVehicles = nearestObjects [player,["LandVehicle","Ship","Air"],7];
        if !(_nearVehicles isEqualTo []) then {_vehicleTarget = _nearVehicles select 0;};
    };
};

private _door = [] call life_fnc_nearestBuildingDoor;
private _doorBuilding = objNull;
private _doorNumber = 0;
private _doorAccess = [];
if (!(_door isEqualTo [])) then {
    _doorBuilding = _door select 0;
    _doorNumber = _door select 1;
    _doorAccess = [_doorBuilding,_doorNumber] call life_fnc_doorAccessFor;
};

private _houseTarget = objNull;
if (!isNull _doorBuilding && {_doorBuilding isKindOf "House_F"}) then {
    _houseTarget = _doorBuilding;
} else {
    if (!isNull cursorObject && {cursorObject isKindOf "House_F"} && {player distance cursorObject <= 12}) then {
        _houseTarget = cursorObject;
    };
};

private _houseOwner = if (!isNull _houseTarget) then {_houseTarget getVariable ["house_owner",[]]} else {[]};
private _isOwnedHouse = (
    !isNull _houseTarget
    && {_houseTarget in life_vehicles}
    && {((count _houseOwner) isEqualTo 0) || {(_houseOwner select 0) isEqualTo getPlayerUID player}}
);

private _storageCrate = objNull;
private _nearStorage = ((ASLtoATL (getPosASL player)) nearEntities [["Box_IND_Grenades_F","B_supplyCrate_F"],2.5]);
if !(_nearStorage isEqualTo []) then {_storageCrate = _nearStorage select 0;};

private _groundItem = objNull;
private _miscItems = ["Land_BottlePlastic_V1_F","Land_TacticalBacon_F","Land_Can_V3_F","Land_CanisterFuel_F","Land_Suitcase_F","Land_Money_F"];
if (!isNull cursorObject && {(typeOf cursorObject) in _miscItems} && {player distance cursorObject <= 4}) then {
    _groundItem = cursorObject;
} else {
    private _nearItems = nearestObjects [player,_miscItems,4];
    if !(_nearItems isEqualTo []) then {_groundItem = _nearItems select 0;};
};

if (([] call life_fnc_nearATM) && {!dialog}) then {
    ["ATM","Open bank account and cash controls","code","[] call life_fnc_atmMenu","Banking",30] call _addAction;
};

if (!dialog && {!(player getVariable ["restrained",false])}) then {
    ["Player Menu","Inventory, keys, phone, money, and settings","code","[] call life_fnc_p_openMenu","Personal",10] call _addAction;
    ["My ID","Open your identification card","function",["openID",[]],"Personal",9] call _addAction;

    private _hasPartialMagazine = (magazinesAmmoFull player) findIf {
        private _className = _x param [0,"",[""]];
        private _rounds = _x param [1,0,[0]];
        private _loaded = _x param [2,false,[false]];
        private _capacity = getNumber (configFile >> "CfgMagazines" >> _className >> "count");
        !_loaded && {_capacity > 1} && {_rounds < _capacity}
    };
    if (_hasPartialMagazine >= 0) then {
        ["Repack Magazines","Consolidate partial inventory magazines without creating rounds","function",["repackMagazines",[]],"Personal",11] call _addAction;
    };

    if (!isNull _targetPlayer) then {
        ["Show ID","Show your ID to the nearby player","function",["showID",[_targetPlayer]],"Personal",12] call _addAction;
    };
};

if (!(_door isEqualTo []) && {!dialog} && {isNull objectParent player}) then {
    ["Use Door","Open, close, keypad, or keycard access","function",["doorInteraction",[_doorBuilding,_doorNumber]],"Door",35] call _addAction;

    _doorAccess params [
        ["_mode","public",[""]],
        ["_label","Door Access",[""]],
        ["_keypad",false,[false]]
    ];

    if (_keypad) then {
        ["Keypad","Enter the assigned door code","function",["openDoorKeypad",[_doorBuilding,_doorNumber,_doorAccess]],"Door",34] call _addAction;
    };
};

if (_isOwnedHouse) then {
    ["Lock / Unlock Door","Toggle the door nearest to you","function",["radialHouseDoorLock",[_houseTarget,_doorNumber]],"House",55] call _addAction;
    ["Storage Lock","Lock or unlock placed house storage","function",["radialHouseStorage",[_houseTarget,"lock",objNull]],"House",45] call _addAction;
    ["House Upgrades","Open installed and available upgrades","category","House Upgrades","House",42] call _addAction;

    if ((missionNamespace getVariable ["life_inv_storagesmall",0]) > 0) then {
        ["Pull Small Storage","Place a small storage crate in this house","function",["radialHouseStorage",[_houseTarget,"small",objNull]],"House",40] call _addAction;
    };

    if ((missionNamespace getVariable ["life_inv_storagebig",0]) > 0) then {
        ["Pull Large Storage","Place a large storage crate in this house","function",["radialHouseStorage",[_houseTarget,"big",objNull]],"House",39] call _addAction;
    };

    private _installedUpgrades = _houseTarget getVariable ["house_upgrades",[]];
    if ("workbench" in _installedUpgrades) then {
        ["Use Workbench","Crafting workbench installed in this house","spawnFunction",["radialHouseWorkbench",[_houseTarget]],"House",38] call _addAction;
        ["Use Workbench","Crafting workbench installed in this house","spawnFunction",["radialHouseWorkbench",[_houseTarget]],"House Upgrades",60] call _addAction;
    };

    ["Sell Property","Sell this owned house or garage","spawnFunction",["sellHouse",[_houseTarget]],"House",25] call _addAction;
    ["House Lights","Toggle the interior house lights","function",["lightHouseAction",[_houseTarget]],"House",37] call _addAction;

    private _canGarage = getNumber (missionConfigFile >> "Housing" >> worldName >> typeOf _houseTarget >> "canGarage") isEqualTo 1;
    if (_canGarage && {!(_houseTarget getVariable ["blacklistedGarage",false])}) then {
        if (_houseTarget getVariable ["garageBought",false]) then {
            ["Access House Garage","Retrieve a stored road vehicle","spawnFunction",["vehicleGarage",[_houseTarget,"Car"]],"House",36] call _addAction;
            ["Store In House Garage","Store the nearest eligible vehicle","spawnFunction",["storeVehicle",[_houseTarget,player]],"House",35] call _addAction;
            ["Sell Garage Upgrade","Remove this house's garage access","spawnFunction",["sellHouseGarage",[_houseTarget]],"House Upgrades",32] call _addAction;
        } else {
            ["Buy Garage Upgrade","Add vehicle storage to this property","spawnFunction",["buyHouseGarage",[_houseTarget]],"House Upgrades",34] call _addAction;
        };
    };

    {
        private _upgradeKey = configName _x;
        private _upgradeTitle = getText (_x >> "title");
        private _upgradeDescription = getText (_x >> "description");
        private _upgradePrice = getNumber (_x >> "price");
        if (_upgradeTitle isEqualTo "") then {_upgradeTitle = _upgradeKey;};

        if !(_upgradeKey in _installedUpgrades) then {
            [
                format ["Buy %1",_upgradeTitle],
                format ["$%1 | %2",[_upgradePrice] call life_fnc_numberText,_upgradeDescription],
                "spawnFunction",
                ["radialHouseUpgrade",[_houseTarget,_upgradeKey]],
                "House Upgrades",
                50
            ] call _addAction;
        };
    } forEach ("true" configClasses (missionConfigFile >> "Life_HouseUpgrades"));
};

if (!isNull _houseTarget && {!_isOwnedHouse} && {playerSide isEqualTo civilian} && {isNil {_houseTarget getVariable "house_owner"}}) then {
    private _houseCfg = [typeOf _houseTarget] call life_fnc_houseConfig;
    if !(_houseCfg isEqualTo []) then {
        ["Buy Property","Purchase this available house or garage","spawnFunction",["buyHouse",[_houseTarget]],"House",45] call _addAction;
    };
};

if (!isNull _houseTarget && {playerSide isEqualTo west} && {!isNil {_houseTarget getVariable "house_owner"}}) then {
    ["Property Owner","Identify the registered property owner","function",["copHouseOwner",[_houseTarget]],"Law Enforcement",27] call _addAction;
    ["Breach Door","Break the nearest locked property door","spawnFunction",["copBreakDoor",[_houseTarget]],"Law Enforcement",26] call _addAction;
    if (player distance _houseTarget <= 3.6) then {
        ["Search Property","Search containers inside the raided property","spawnFunction",["raidHouse",[_houseTarget]],"Law Enforcement",25] call _addAction;
    };
    ["Secure Property","Close and lock every property door","spawnFunction",["lockupHouse",[_houseTarget]],"Law Enforcement",24] call _addAction;
};

if (!isNull _storageCrate) then {
    ["Open Storage","Open the nearby house storage crate","spawnFunction",["radialHouseStorage",[objNull,"open",_storageCrate]],"Items",35] call _addAction;
    if (playerSide isEqualTo west) then {
        ["Search Storage","Search this container for contraband","spawnFunction",["containerInvSearch",[_storageCrate]],"Law Enforcement",23] call _addAction;
    } else {
        ["Remove Storage","Pack up this placed storage container","spawnFunction",["removeContainer",[_storageCrate]],"House",23] call _addAction;
    };
};

if (!isNull _groundItem) then {
    ["Pick Up","Pick up the nearby item or cash","function",["radialPickupObject",[_groundItem]],"Items",30] call _addAction;
};

private _gatherInteraction = [] call life_fnc_gatherInteraction;
if !(_gatherInteraction isEqualTo []) then {
    _gatherInteraction params [
        ["_kind","",[""]],
        ["_title","",[""]],
        ["_subtitle","",[""]],
        ["_functionName","",[""]],
        ["_resource","",[""]],
        ["_requiredItem","",[""]],
        ["_zone","",[""]],
        ["_priority",38,[0]]
    ];

    [_title,_subtitle,"spawnFunction",[_functionName,[]],"Items",_priority] call _addAction;
};

if (!isNull _vehicleTarget) then {
    if (_vehicleTarget in life_vehicles) then {
        ["Lock / Unlock","Toggle this vehicle's locks","function",["radialVehicleLock",[_vehicleTarget]],"Vehicle",45] call _addAction;
    };

    if (_vehicleTarget in life_vehicles || {locked _vehicleTarget isEqualTo 0}) then {
        ["Open Trunk","Open vehicle storage","spawnFunction",["radialVehicleTrunk",[_vehicleTarget]],"Vehicle",44] call _addAction;
    };

    if (isNull objectParent player && {life_inv_toolkit > 0} && {[_vehicleTarget] call life_fnc_isDamaged}) then {
        ["Repair Vehicle","Use a toolkit to repair the selected vehicle","spawnFunction",["repairTruck",[_vehicleTarget]],"Vehicle",41] call _addAction;
    };

    if (vehicle player isEqualTo _vehicleTarget) then {
        private _gpsOn = profileNamespace getVariable ["life_vehicle_gps_enabled",(getNumber (missionConfigFile >> "Life_VehicleHUD" >> "defaultGPS")) isEqualTo 1];
        ["GPS Display",format ["%1 vehicle GPS | Ctrl+G",["Show","Hide"] select _gpsOn],"function",["vehicleHUDToggleGPS",[]],"Vehicle",46] call _addAction;
    };

    if (vehicle player isEqualTo _vehicleTarget && {driver _vehicleTarget isEqualTo player}) then {
        ["Seatbelt","Buckle or unbuckle | Ctrl+B","function",["seatbeltToggle",[]],"Vehicle",40] call _addAction;

        private _cameraClasses = getArray (missionConfigFile >> "Life_VehicleControls" >> "backupCameraVehicles");
        if ((typeOf _vehicleTarget) in _cameraClasses || {_vehicleTarget getVariable ["life_backup_camera",false]}) then {
            ["Backup Camera","Toggle the rear camera | Ctrl+R","function",["vehicleBackupCamera",[_vehicleTarget]],"Vehicle",47] call _addAction;
        };
    };

    if (playerSide isEqualTo west) then {
        ["Vehicle Registration","Read registered vehicle ownership","spawnFunction",["searchVehAction",[_vehicleTarget]],"Law Enforcement",34] call _addAction;
        ["Search Vehicle","Search the trunk for illegal items","spawnFunction",["vehInvSearch",[_vehicleTarget]],"Law Enforcement",33] call _addAction;
        ["Impound Vehicle","Send an empty vehicle to the impound lot","spawnFunction",["impoundAction",[_vehicleTarget]],"Law Enforcement",31] call _addAction;
        if !((crew _vehicleTarget) isEqualTo []) then {
            ["Eject Occupants","Remove non-LEO occupants from this vehicle","function",["radialPulloutVehicle",[_vehicleTarget]],"Vehicle",38] call _addAction;
            ["Eject Occupants","Remove non-LEO occupants from this vehicle","function",["radialPulloutVehicle",[_vehicleTarget]],"Law Enforcement",24] call _addAction;
        };
    } else {
        if (_vehicleTarget isKindOf "Ship" && {isNull objectParent player} && {local _vehicleTarget} && {(crew _vehicleTarget) isEqualTo []}) then {
            ["Push Boat","Push the empty boat away from shore","spawnFunction",["radialVehicleUtility",[_vehicleTarget,"push"]],"Vehicle",28] call _addAction;
        };
        if (isNull objectParent player && {(crew _vehicleTarget) isEqualTo []} && {canMove _vehicleTarget} && {locked _vehicleTarget isEqualTo 0}) then {
            ["Enter Driver Seat","Enter this unlocked empty vehicle","function",["radialVehicleUtility",[_vehicleTarget,"driver"]],"Vehicle",27] call _addAction;
        };
        if (isNull objectParent player && {(crew _vehicleTarget) isEqualTo []} && {!canMove _vehicleTarget}) then {
            ["Right Vehicle","Place an overturned empty vehicle upright","function",["radialVehicleUtility",[_vehicleTarget,"unflip"]],"Vehicle",26] call _addAction;
        };
        if (typeOf _vehicleTarget isEqualTo "O_Truck_03_device_F" && {_vehicleTarget in life_vehicles}) then {
            ["Mining Device","Start the vehicle's automated mining device","spawnFunction",["deviceMine",[_vehicleTarget]],"Vehicle",25] call _addAction;
        };
    };
};

if (playerSide isEqualTo civilian) then {
    if (!isNull _targetPlayer && {animationState _targetPlayer isEqualTo "Incapacitated"} && {!(_targetPlayer getVariable ["robbed",false])}) then {
        ["Rob Person","Take available cash from the incapacitated person","function",["robAction",[_targetPlayer]],"Civilian",30] call _addAction;
    };
    if (vehicle player isKindOf "Ship" && {surfaceIsWater (getPos vehicle player)} && {life_carryWeight < life_maxWeight} && {abs speed (vehicle player) < 2} && {!life_net_dropped}) then {
        ["Drop Fishing Net","Collect nearby fish from the water","spawnFunction",["dropFishingNet",[]],"Civilian",24] call _addAction;
    };
};

if (playerSide isEqualTo west) then {
    ["TCSD Command","Ranks, divisions, documents, and oversight","code","[] call life_fnc_openLEOCommandTerminal","Law Enforcement",18] call _addAction;
    ["Training Academy","Cadets, FTO records, and academy documents","code","[] call life_fnc_openLEOTrainingTerminal","Law Enforcement",17] call _addAction;
    ["Citation Records","Search citation history by character name, plate, or offense","code","[] call life_fnc_openCitationRecords","Law Enforcement",16] call _addAction;

    if (vehicle player != player) then {
        ["Radar","Track target vehicle speed","code","[] call life_fnc_radar","Law Enforcement",16] call _addAction;
    };

    private _escorted = player getVariable ["escortingPlayer",objNull];
    if (!isNull _escorted) then {
        ["Put In Back Seat","Load the escorted player into a nearby vehicle","function",["radialPutInVehicle",[_escorted]],"Law Enforcement",30] call _addAction;
    };

    if (!isNull _targetPlayer && {_targetPlayer getVariable ["restrained",false]}) then {
        ["Unrestrain","Remove restraints from this person","function",["unrestrain",[_targetPlayer]],"Law Enforcement",40] call _addAction;
        ["Search Person","Search this person's inventory","spawnFunction",["searchAction",[_targetPlayer]],"Law Enforcement",39] call _addAction;
        ["License / ID","Review and administer licenses","function",["openLicenseAdmin",[_targetPlayer]],"Law Enforcement",38] call _addAction;
        if (player getVariable ["isEscorting",false]) then {
            ["Stop Escort","Release the currently escorted person","function",["stopEscorting",[]],"Law Enforcement",37] call _addAction;
        } else {
            ["Escort","Begin escorting this restrained person","function",["escortAction",[_targetPlayer]],"Law Enforcement",37] call _addAction;
        };
        ["Put In Vehicle","Place this person into a nearby vehicle","function",["putInCar",[_targetPlayer]],"Law Enforcement",35] call _addAction;
        if (["police.ticket"] call life_fnc_hasPermission) then {
            ["Issue Citation","Open the field citation form","function",["openCitation",[_targetPlayer]],"Law Enforcement",36] call _addAction;
        };
        if (({player distance (getMarkerPos _x) < 30} count LIFE_SETTINGS(getArray,"sendtoJail_locations")) > 0) then {
            ["Process Arrest","Book this person into the nearby jail","function",["arrestAction",[_targetPlayer]],"Law Enforcement",34] call _addAction;
        };
        if (["corporal"] call life_fnc_leoAtLeastRank || {FETCH_CONST(life_coplevel) >= LIFE_SETTINGS(getNumber,"seize_minimum_rank")}) then {
            ["Seize Weapons","Remove illegal weapons and equipment","spawnFunction",["seizePlayerAction",[_targetPlayer]],"Law Enforcement",33] call _addAction;
        };
    };
};

if (playerSide isEqualTo independent) then {
    if (!isNull _targetPlayer) then {
        ["Assess Patient","Read the patient's current condition","function",["radialPatientAssessment",[_targetPlayer]],"EMS",40] call _addAction;
        if (!alive _targetPlayer && {life_inv_defibrillator > 0}) then {
            ["Revive Patient","Use a defibrillator to begin revival","spawnFunction",["revivePlayer",[_targetPlayer]],"EMS",39] call _addAction;
        };
    };
};

if ((["doj.citation_review"] call life_fnc_hasPermission) || {["doj.records"] call life_fnc_hasPermission}) then {
    ["Citation Records","Review citation history by character name, plate, or offense","code","[] call life_fnc_openCitationRecords","Department of Justice",16] call _addAction;
};

if ((["staff.permissions"] call life_fnc_hasPermission) || {["owner.access"] call life_fnc_hasPermission} || {[] call life_fnc_isCommunityOwner}) then {
    ["Staff Menu","Server staff tools placeholder","code","hint 'Staff menu framework ready. Admin tools can be added here.'","Staff",11] call _addAction;
};

_actions
