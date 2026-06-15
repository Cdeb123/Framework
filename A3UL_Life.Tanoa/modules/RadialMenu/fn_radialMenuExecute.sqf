#include "..\..\script_macros.hpp"
/*
    File: fn_radialMenuExecute.sqf
*/
disableSerialization;
params [
    ["_index",-1,[0]]
];

private _actions = missionNamespace getVariable ["life_radial_actions",[]];
if (_index < 0 || {_index >= count _actions}) exitWith {};

private _action = _actions select _index;
_action params [
    ["_title","",[""]],
    ["_subtitle","",[""]],
    ["_type","code",[""]],
    ["_payload",[],[[],objNull,""]],
    ["_group","",[""]]
];

switch (_type) do {
    case "category": {
        life_radial_category = _payload;
        life_radial_page = 0;
        [] call life_fnc_radialMenuLoad;
    };

    case "userAction": {
        closeDialog 0;
        _payload params [
            ["_target",objNull,[objNull]],
            ["_id",-1,[0]]
        ];
        if (!isNull _target && {_id >= 0}) then {
            player action ["User",_target,_id];
        };
    };

    case "function": {
        closeDialog 0;
        if (_payload isEqualType []) then {
            _payload params [
                ["_functionName","",[""]],
                ["_arguments",[],[[]]]
            ];

            private _function = missionNamespace getVariable [format ["life_fnc_%1",_functionName],{}];
            _arguments call _function;
        };
    };

    case "spawnFunction": {
        closeDialog 0;
        if (_payload isEqualType []) then {
            _payload params [
                ["_functionName","",[""]],
                ["_arguments",[],[[]]]
            ];

            private _function = missionNamespace getVariable [format ["life_fnc_%1",_functionName],{}];
            _arguments spawn _function;
        };
    };

    default {
        closeDialog 0;
        if (_payload isEqualType "") then {
            call compile _payload;
        };
    };
};
