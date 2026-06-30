#include "..\..\script_macros.hpp"
/*
    File: fn_craftingStorageCapacity.sqf

    Returns [level, capacity, nextCost, nextCapacity, used].
*/
params [
    ["_type","workbench",[""]],
    ["_scope","",[""]]
];

_type = toLower _type;
_scope = [_scope] call life_fnc_craftingScope;

private _level = switch (_type) do {
    case "workbench": {
        private _found = 1;
        {
            if ((_x param [0,"",[""]]) isEqualTo _scope) exitWith {
                _found = _x param [1,1,[0]];
            };
        } forEach (missionNamespace getVariable ["life_crafting_workbench_levels",[["civilian",1],["rebel",1],["leo",1]]]);
        _found
    };
    case "gear": {missionNamespace getVariable ["life_crafting_gear_storage_level",1]};
    default {missionNamespace getVariable ["life_crafting_item_storage_level",1]};
};

private _arrayName = switch (_type) do {
    case "workbench": {"workbenchLevels"};
    case "gear": {"gearStorageLevels"};
    default {"itemStorageLevels"};
};

private _levels = getArray (missionConfigFile >> "Life_Crafting" >> "Storage" >> _arrayName);
private _current = [];
private _next = [];
{
    private _rowLevel = _x param [0,0,[0]];
    if (_rowLevel isEqualTo _level) then {_current = _x;};
    if (_rowLevel isEqualTo (_level + 1)) then {_next = _x;};
} forEach _levels;

if (_current isEqualTo [] && {!(_levels isEqualTo [])}) then {
    _current = _levels select 0;
};

private _capacity = _current param [1,0,[0]];
private _nextCost = if (_next isEqualTo []) then {-1} else {_next param [2,-1,[0]]};
private _nextCapacity = if (_next isEqualTo []) then {-1} else {_next param [1,-1,[0]]};
private _used = [_type,_scope] call life_fnc_craftingStorageUsed;

[_level,_capacity,_nextCost,_nextCapacity,_used]
