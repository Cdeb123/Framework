#include "..\..\script_macros.hpp"
/*
    File: fn_scrollInteractionProxy.sqf

    Description:
    Mirrors the closest nearby sign/vendor addActions onto the player so the
    native scroll wheel does not require pixel-perfect sign targeting.
*/
if (!hasInterface || {isNull player}) exitWith {};

private _baseIgnored = player getVariable ["life_radial_base_ignore_actions",[]];
private _clearProxy = {
    {
        player removeAction _x;
    } forEach (player getVariable ["life_scroll_proxy_actions",[]]);

    player setVariable ["life_scroll_proxy_actions",[],false];
    player setVariable ["life_scroll_proxy_signature","",false];
    player setVariable ["life_scroll_proxy_target",objNull,false];
    player setVariable ["life_radial_ignore_actions",_baseIgnored,false];
};

if (!alive player || {dialog} || {!(isNull objectParent player)} || {life_action_inUse} || {player getVariable ["restrained",false]}) exitWith {
    call _clearProxy;
};

private _radius = LIFE_SETTINGS(getNumber,"radial_menu_radius");
if (_radius <= 0) then {_radius = 6;};
private _searchRadius = _radius + 2;
private _candidates = [];

private _pushCandidate = {
    params [["_target",objNull,[objNull]]];
    if (isNull _target) exitWith {};
    if (_target isEqualTo player) exitWith {};
    if (isPlayer _target) exitWith {};
    if (KINDOF_ARRAY(_target,["LandVehicle","Ship","Air"])) exitWith {};
    if (_target isKindOf "House_F") exitWith {};
    if (player distance _target > _searchRadius) exitWith {};
    if ((count (actionIDs _target)) <= 0) exitWith {};
    _candidates pushBackUnique _target;
};

[cursorObject] call _pushCandidate;
{
    [_x] call _pushCandidate;
} forEach (player nearObjects _searchRadius);

if (_candidates isEqualTo []) exitWith {
    call _clearProxy;
};

private _actionsForTarget = {
    params [["_targetObject",objNull,[objNull]]];

    private _available = [];
    {
        _x params [
            ["_title","Interact",[""]],
            ["_statement",{},[{},""]],
            ["_arguments",nil],
            ["_condition","true",[""]],
            ["_actionRadius",_radius,[0]],
            ["_priority",0,[0]],
            ["_signature","",[""]]
        ];

        if (_actionRadius <= 0) then {_actionRadius = _radius;};
        if (player distance _targetObject > (_actionRadius max _radius)) exitWith {};

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
            _available pushBack [_title,_statement,_arguments,_condition,_actionRadius,_priority,_signature];
        };
    } forEach ([_targetObject] call life_fnc_captureInteractionActions);

    _available
};

private _bestTarget = objNull;
private _bestActions = [];
private _bestScore = 9999;
{
    private _targetObject = _x;
    private _available = [_targetObject] call _actionsForTarget;
    if !(_available isEqualTo []) then {
        private _score = player distance _targetObject;
        if (_targetObject isEqualTo cursorObject) then {_score = -1;};

        private _type = toLower (typeOf _targetObject);
        if (
            (["infostand",_type] call BIS_fnc_inString)
            || {["sign",_type] call BIS_fnc_inString}
            || {["billboard",_type] call BIS_fnc_inString}
            || {["atm",_type] call BIS_fnc_inString}
        ) then {
            _score = _score - 0.35;
        };

        if (_score < _bestScore) then {
            _bestScore = _score;
            _bestTarget = _targetObject;
            _bestActions = _available;
        };
    };
} forEach _candidates;

if (isNull _bestTarget || {_bestActions isEqualTo []}) exitWith {
    call _clearProxy;
};

_bestActions = [_bestActions,[],{_x param [5,0,[0]]},"DESCEND"] call BIS_fnc_sortBy;
if ((count _bestActions) > 6) then {_bestActions resize 6;};

private _signature = str [_bestTarget,(_bestActions apply {_x param [6,"",[""]]})];
if (_signature isEqualTo (player getVariable ["life_scroll_proxy_signature",""])) exitWith {};

call _clearProxy;

private _proxyCondition = "!dialog && {alive player} && {isNull objectParent player} && {!life_action_inUse} && {!((player getVariable ['restrained',false]))} && {!(cursorObject isEqualTo (player getVariable ['life_scroll_proxy_target',objNull]))}";
private _proxyIds = [];
{
    _x params [
        ["_title","Interact",[""]],
        ["_statement",{},[{},""]],
        ["_arguments",nil],
        ["_condition","true",[""]],
        ["_actionRadius",_radius,[0]],
        ["_priority",0,[0]]
    ];

    private _proxyId = player addAction [
        _title,
        {
            params ["_proxyTarget","_caller","_actionId","_payload"];
            _payload params [
                ["_targetObject",objNull,[objNull]],
                ["_statement",{},[{},""]],
                ["_arguments",nil],
                ["_condition","true",[""]],
                ["_actionRadius",6,[0]]
            ];

            if (isNull _targetObject) exitWith {};
            if (_caller distance _targetObject > _actionRadius) exitWith {};

            private _allowed = true;
            if !(_condition isEqualTo "") then {
                private _target = _targetObject;
                private _originalTarget = _targetObject;
                private _conditionResult = false;
                private _conditionFailed = isNil {
                    private _result = _caller call (compile _condition);
                    if (_result isEqualType true) then {_conditionResult = _result;};
                    _conditionResult
                };
                _allowed = (!_conditionFailed) && {_conditionResult};
            };
            if (!_allowed) exitWith {};

            private _actionArguments = [_targetObject,_caller,-1,_arguments];
            if (_statement isEqualType {}) then {
                _actionArguments call _statement;
            } else {
                _actionArguments call compile _statement;
            };
        },
        [_bestTarget,_statement,_arguments,_condition,(_actionRadius max _radius)],
        _priority,
        true,
        true,
        "",
        _proxyCondition,
        (_actionRadius max _radius)
    ];

    _proxyIds pushBack _proxyId;
} forEach _bestActions;

player setVariable ["life_scroll_proxy_actions",_proxyIds,false];
player setVariable ["life_scroll_proxy_signature",_signature,false];
player setVariable ["life_scroll_proxy_target",_bestTarget,false];
player setVariable ["life_radial_ignore_actions",_baseIgnored + _proxyIds,false];
