#include "..\..\script_macros.hpp"
/*
    File: fn_craftingStorageUsed.sqf
*/
params [
    ["_type","workbench",[""]],
    ["_scope","",[""]]
];

private _storage = [_type,_scope] call life_fnc_craftingGetStorage;
private _used = 0;

if ((toLower _type) isEqualTo "gear") then {
    {
        _used = _used + (_x param [1,0,[0]]);
    } forEach _storage;
} else {
    {
        private _item = _x param [0,"",[""]];
        private _amount = _x param [1,0,[0]];
        _used = _used + (([_item] call life_fnc_itemWeight) * _amount);
    } forEach _storage;
};

_used
