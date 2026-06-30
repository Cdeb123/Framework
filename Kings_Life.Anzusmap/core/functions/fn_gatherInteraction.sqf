#include "..\..\script_macros.hpp"
/*
    File: fn_gatherInteraction.sqf

    Description:
    Resolves the resource action available at the player's current position.
    Returns [] when no mine/gather action is available, otherwise:
    [kind,title,subtitle,functionName,resource,requiredItem,zone,priority]
*/
if (!alive player) exitWith {[]};
if (life_action_inUse) exitWith {[]};
if !(isNull objectParent player) exitWith {[]};
if (player getVariable ["restrained",false]) exitWith {[]};
if (player getVariable ["playerSurrender",false]) exitWith {[]};
if (life_isknocked || {life_istazed}) exitWith {[]};

private _resourceName = {
    params [["_resource","",[""]]];
    if (_resource isEqualTo "") exitWith {"resource"};

    private _displayName = M_CONFIG(getText,"VirtualItems",_resource,"displayName");
    if (_displayName isEqualTo "") exitWith {_resource};
    localize _displayName
};

private _firstMinedResource = {
    params [["_config",configNull,[configNull]]];

    private _mined = getArray (_config >> "mined");
    if (_mined isEqualTo []) exitWith {configName _config};

    private _first = _mined select 0;
    if (_first isEqualType []) exitWith {_first param [0,configName _config,[""]]};
    _first
};

private _findZone = {
    params [
        ["_configRoot",configNull,[configNull]],
        ["_kind","gather",[""]]
    ];

    private _match = [];
    {
        private _zoneSize = getNumber (_x >> "zoneSize");
        if (_zoneSize <= 0) then {_zoneSize = 30;};

        private _matchedZone = "";
        {
            if ((player distance (getMarkerPos _x)) < _zoneSize) exitWith {
                _matchedZone = _x;
            };
        } forEach getArray (_x >> "zones");

        if !(_matchedZone isEqualTo "") exitWith {
            private _resource = configName _x;
            if (_kind isEqualTo "mine") then {
                _resource = [_x] call _firstMinedResource;
            };

            _match = [_kind,_resource,getText (_x >> "item"),_matchedZone];
        };
    } forEach ("true" configClasses _configRoot);

    _match
};

private _match = [missionConfigFile >> "CfgGather" >> "Minerals","mine"] call _findZone;
if (_match isEqualTo []) then {
    _match = [missionConfigFile >> "CfgGather" >> "Resources","gather"] call _findZone;
};
if (_match isEqualTo []) exitWith {[]};

_match params [
    ["_kind","",[""]],
    ["_resource","",[""]],
    ["_requiredItem","",[""]],
    ["_zone","",[""]]
];

private _isMine = _kind isEqualTo "mine";
private _functionName = if (_isMine) then {"mine"} else {"gather"};
private _title = if (_isMine) then {"Mine"} else {"Gather"};
private _resourceTitle = [_resource] call _resourceName;
private _xpKey = if (_isMine) then {"mine"} else {"gather"};
private _xp = getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> _xpKey);
private _perkKey = if (_isMine) then {"mining_speed"} else {"harvesting_speed"};
private _perkTitle = getText (missionConfigFile >> "Life_Progression" >> "Perks" >> _perkKey >> "title");
private _subtitle = format ["%1 %2 | +%3 Crafting XP | %4 applies",_title,_resourceTitle,_xp,_perkTitle];

if !(_requiredItem isEqualTo "") then {
    _subtitle = format ["%1 | Requires %2",_subtitle,[_requiredItem] call _resourceName];
};

[_kind,_title,_subtitle,_functionName,_resource,_requiredItem,_zone,38]
