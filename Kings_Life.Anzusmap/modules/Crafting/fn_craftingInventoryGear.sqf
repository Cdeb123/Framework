#include "..\..\script_macros.hpp"
/*
    File: fn_craftingInventoryGear.sqf
*/
private _gear = [];
private _add = {
    params [["_className","",[""]]];
    if (_className isEqualTo "" || {_className in ["Throw","Put"]}) exitWith {};
    private _index = _gear findIf {(_x param [0,"",[""]]) isEqualTo _className};
    if (_index < 0) then {
        _gear pushBack [_className,1];
    } else {
        private _row = _gear select _index;
        _row set [1,(_row param [1,0,[0]]) + 1];
        _gear set [_index,_row];
    };
};

{[_x] call _add;} forEach (weapons player);
{[_x] call _add;} forEach (magazines player);
{[_x] call _add;} forEach (items player);
{[_x] call _add;} forEach (assignedItems player);
{[_x] call _add;} forEach [(uniform player),(vest player),(backpack player),(headgear player),(goggles player)];

_gear
