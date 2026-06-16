#include "..\..\script_macros.hpp"
/*
    File: fn_nearbyInteractionActions.sqf

    Builds usable interaction actions from real addActions on nearby objects,
    plus compact F1 shortcuts for common framework interactions.
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

private _candidates = [];
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
    {
        private _id = _x;
        private _params = actionParams [_targetObject,_id];
        if !(_params isEqualTo []) then {
            private _title = _params param [0,"Interact",[""]];
            private _condition = _params param [7,"true",[""]];
            private _actionRadius = _params param [8,_radius,[0]];
            if (_actionRadius <= 0) then {_actionRadius = _radius;};

            if (player distance _targetObject <= (_actionRadius max _radius)) then {
                private _allowed = true;
                if !(_condition isEqualTo "") then {
                    private _target = _targetObject;
                    private _originalTarget = _targetObject;
                    private _actionId = _id;
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
                    [_title,_vendor,"userAction",[_targetObject,_id],_group,20] call _addAction;
                };
            };
        };
    } forEach (actionIDs _targetObject);
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

if (!isNull _storageCrate) then {
    ["Open Storage","Open the nearby house storage crate","spawnFunction",["radialHouseStorage",[objNull,"open",_storageCrate]],"Items",35] call _addAction;
    ["Storage Menu","Open the normal storage interaction menu","function",["containerMenu",[_storageCrate]],"Items",20] call _addAction;
};

if (!isNull _groundItem) then {
    ["Pick Up","Pick up the nearby item or cash","function",["radialPickupObject",[_groundItem]],"Items",30] call _addAction;
};

if (!isNull _vehicleTarget) then {
    if (_vehicleTarget in life_vehicles) then {
        ["Lock / Unlock","Toggle this vehicle's locks","function",["radialVehicleLock",[_vehicleTarget]],"Vehicle",45] call _addAction;
    };

    if (_vehicleTarget in life_vehicles || {locked _vehicleTarget isEqualTo 0}) then {
        ["Open Trunk","Open vehicle storage","spawnFunction",["radialVehicleTrunk",[_vehicleTarget]],"Vehicle",44] call _addAction;
    };

    if (isNull objectParent player) then {
        ["Vehicle Menu","Open the normal vehicle interaction menu","function",["vInteractionMenu",[_vehicleTarget]],"Vehicle",20] call _addAction;
    };

    if (playerSide isEqualTo west) then {
        if !((crew _vehicleTarget) isEqualTo []) then {
            ["Eject Occupants","Remove non-LEO occupants from this vehicle","function",["radialPulloutVehicle",[_vehicleTarget]],"Vehicle",38] call _addAction;
            ["Eject Occupants","Remove non-LEO occupants from this vehicle","function",["radialPulloutVehicle",[_vehicleTarget]],"Law Enforcement",24] call _addAction;
        };
    };
};

if (playerSide isEqualTo west) then {
    ["TCSD Command","Ranks, divisions, documents, and oversight","code","[] call life_fnc_openLEOCommandTerminal","Law Enforcement",18] call _addAction;
    ["Training Academy","Cadets, FTO records, and academy documents","code","[] call life_fnc_openLEOTrainingTerminal","Law Enforcement",17] call _addAction;

    if (vehicle player != player) then {
        ["Radar","Track target vehicle speed","code","[] call life_fnc_radar","Law Enforcement",16] call _addAction;
    };

    private _escorted = player getVariable ["escortingPlayer",objNull];
    if (!isNull _escorted) then {
        ["Put In Back Seat","Load the escorted player into a nearby vehicle","function",["radialPutInVehicle",[_escorted]],"Law Enforcement",30] call _addAction;
    };

    if (!isNull _targetPlayer && {_targetPlayer getVariable ["restrained",false]}) then {
        ["Player Interaction","Open the normal LEO player interaction menu","function",["copInteractionMenu",[_targetPlayer]],"Law Enforcement",20] call _addAction;
    };
};

if (playerSide isEqualTo independent) then {
    if (!isNull _targetPlayer && {!alive _targetPlayer} && {life_inv_defibrillator > 0}) then {
        ["Revive","Start revive on the nearby patient","spawnFunction",["revivePlayer",[_targetPlayer]],"EMS",35] call _addAction;
    };
};

if ((["staff.permissions"] call life_fnc_hasPermission) || {["owner.access"] call life_fnc_hasPermission} || {[] call life_fnc_isCommunityOwner}) then {
    ["Staff Menu","Server staff tools placeholder","code","hint 'Staff menu framework ready. Admin tools can be added here.'","Staff",11] call _addAction;
};

_actions
