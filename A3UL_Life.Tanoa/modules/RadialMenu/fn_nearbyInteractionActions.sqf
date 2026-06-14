#include "..\..\script_macros.hpp"
/*
    File: fn_nearbyInteractionActions.sqf

    Builds usable interaction actions from real addActions on nearby objects,
    plus core framework actions that do not live on a vendor object.
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
                    _allowed = player call (compile _condition);
                    if !(_allowed isEqualType true) then {_allowed = false;};
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

if (([] call life_fnc_nearATM) && {!dialog}) then {
    ["ATM","Open bank account and cash controls","code","[] call life_fnc_atmMenu","Banking",30] call _addAction;
};

private _door = [] call life_fnc_nearestBuildingDoor;
if (!(_door isEqualTo []) && {!dialog} && {isNull objectParent player}) then {
    ["Door Access","Open, close, keypad, or keycard access","code","[] call life_fnc_doorInteraction","Nearby",25] call _addAction;
};

if (!dialog && {!(player getVariable ["restrained",false])}) then {
    ["Player Menu","Inventory, keys, phone, money, and settings","code","[] call life_fnc_p_openMenu","Personal",10] call _addAction;
    ["ID Card","Show or inspect identification","code","[] call life_fnc_openID","Personal",9] call _addAction;
};

if (playerSide isEqualTo west) then {
    ["TCSD Command Terminal","Ranks, divisions, documents, and oversight","code","[] call life_fnc_openLEOCommandTerminal","Law Enforcement",14] call _addAction;
    ["Training Academy","Cadets, FTO records, and academy documents","code","[] call life_fnc_openLEOTrainingTerminal","Law Enforcement",13] call _addAction;

    if (vehicle player != player) then {
        ["Mobile Data Terminal","In-vehicle TCSD command access","code","[] call life_fnc_openLEOCommandTerminal","Law Enforcement",18] call _addAction;
        ["Radar","Track target vehicle speed","code","[] call life_fnc_radar","Law Enforcement",17] call _addAction;
    };
};

if ((["staff.permissions"] call life_fnc_hasPermission) || {["owner.access"] call life_fnc_hasPermission} || {[] call life_fnc_isCommunityOwner}) then {
    ["Staff Menu","Server staff tools placeholder","code","hint 'Staff menu framework ready. Admin tools can be added here.'","Staff",11] call _addAction;
};

_actions
