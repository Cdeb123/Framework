#include "..\..\script_macros.hpp"
/*
    File: fn_craftingUpgrade.sqf
*/
params [
    ["_type","",[""]]
];

private _scope = [missionNamespace getVariable ["life_crafting_scope",""]] call life_fnc_craftingScope;
if (_type isEqualTo "") then {
    private _tab = missionNamespace getVariable ["life_crafting_tab","storage"];
    _type = switch (_tab) do {
        case "workbench": {"workbench"};
        case "gear": {"gear"};
        default {"items"};
    };
};

private _capacity = [_type,_scope] call life_fnc_craftingStorageCapacity;
_capacity params ["_level","_cap","_nextCost","_nextCap","_used"];
if (_nextCost < 0) exitWith {hint "That storage is already fully upgraded.";};
if (BANK < _nextCost) exitWith {
    hint format ["You need $%1 more in your bank for that upgrade.",[_nextCost - BANK] call life_fnc_numberText];
};

BANK = BANK - _nextCost;
[1] call SOCK_fnc_updatePartial;

switch (toLower _type) do {
    case "workbench": {
        private _levels = missionNamespace getVariable ["life_crafting_workbench_levels",[["civilian",1],["rebel",1],["leo",1]]];
        private _index = _levels findIf {(_x param [0,"",[""]]) isEqualTo _scope};
        if (_index < 0) then {
            _levels pushBack [_scope,_level + 1];
        } else {
            private _row = _levels select _index;
            _row set [1,_level + 1];
            _levels set [_index,_row];
        };
        missionNamespace setVariable ["life_crafting_workbench_levels",_levels];
    };
    case "gear": {
        missionNamespace setVariable ["life_crafting_gear_storage_level",_level + 1];
    };
    default {
        missionNamespace setVariable ["life_crafting_item_storage_level",_level + 1];
    };
};

[] call life_fnc_craftingSave;
hint format ["Storage upgraded to level %1.",_level + 1];
[] call life_fnc_craftingLoad;
