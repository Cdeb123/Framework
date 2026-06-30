#include "..\..\script_macros.hpp"
/*
    File: fn_craftingTransfer.sqf
*/
disableSerialization;
params [
    ["_mode","",[""]]
];

private _display = findDisplay 9300;
if (isNull _display) exitWith {};

private _scope = [missionNamespace getVariable ["life_crafting_scope",""]] call life_fnc_craftingScope;
private _left = _display displayCtrl 9322;
private _right = _display displayCtrl 9323;
private _amountText = ctrlText (_display displayCtrl 9325);
if !([_amountText] call TON_fnc_isnumber) exitWith {hint localize "STR_MISC_WrongNumFormat";};
private _amount = (parseNumber _amountText) max 1;
_amount = floor _amount;

private _addToStorage = {
    params ["_storage","_className","_amountToAdd"];
    private _index = _storage findIf {(_x param [0,"",[""]]) isEqualTo _className};
    if (_index < 0) then {
        _storage pushBack [_className,_amountToAdd];
    } else {
        private _row = _storage select _index;
        _row set [1,(_row param [1,0,[0]]) + _amountToAdd];
        _storage set [_index,_row];
    };
    _storage
};

private _removeFromStorage = {
    params ["_storage","_className","_amountToRemove"];
    private _index = _storage findIf {(_x param [0,"",[""]]) isEqualTo _className};
    if (_index < 0) exitWith {[false,_storage]};
    private _row = _storage select _index;
    private _stored = _row param [1,0,[0]];
    if (_stored < _amountToRemove) exitWith {[false,_storage]};
    if (_stored isEqualTo _amountToRemove) then {
        _storage deleteAt _index;
    } else {
        _row set [1,_stored - _amountToRemove];
        _storage set [_index,_row];
    };
    [true,_storage]
};

private _storageType = switch (_mode) do {
    case "depositWorkbench";
    case "withdrawWorkbench": {"workbench"};
    case "depositGear";
    case "withdrawGear": {"gear"};
    default {"items"};
};

private _isDeposit = _mode in ["depositWorkbench","depositItems","depositGear"];
private _list = if (_isDeposit) then {_right} else {_left};
if ((lbCurSel _list) < 0) exitWith {hint localize "STR_Global_NoSelection";};
private _className = _list lbData (lbCurSel _list);
if (_className isEqualTo "") exitWith {};

private _storage = [_storageType,_scope] call life_fnc_craftingGetStorage;

if (_storageType isEqualTo "gear") then {
    if (_isDeposit) then {
        private _gear = [] call life_fnc_craftingInventoryGear;
        private _gearIndex = _gear findIf {(_x param [0,"",[""]]) isEqualTo _className};
        private _owned = if (_gearIndex < 0) then {0} else {(_gear select _gearIndex) param [1,0,[0]]};
        if (_owned < _amount) exitWith {hint "You do not have enough of that gear item.";};

        private _capacity = ["gear",_scope] call life_fnc_craftingStorageCapacity;
        if (((_capacity select 4) + _amount) > (_capacity select 1)) exitWith {hint "Your gear storage is full.";};

        for "_i" from 1 to _amount do {
            [_className,false] call life_fnc_handleItem;
        };
        _storage = [_storage,_className,_amount] call _addToStorage;
        ["gear",_storage,_scope] call life_fnc_craftingSetStorage;
        hint "Gear stored.";
    } else {
        private _removed = [_storage,_className,_amount] call _removeFromStorage;
        if !(_removed select 0) exitWith {hint "There is not enough gear in storage.";};
        _storage = _removed select 1;
        for "_i" from 1 to _amount do {
            [_className,true,false,false,true] call life_fnc_handleItem;
        };
        ["gear",_storage,_scope] call life_fnc_craftingSetStorage;
        hint "Gear withdrawn.";
    };
} else {
    if (_isDeposit) then {
        if (_storageType isEqualTo "workbench") then {
            private _allowed = getArray (missionConfigFile >> "Life_Crafting" >> "Storage" >> "workbenchItems");
            if !(_className in _allowed) exitWith {hint "Only ores, metals, and crafting materials can be placed in the workbench.";};
        };
        if (ITEM_VALUE(_className) < _amount) exitWith {hint localize "STR_NOTF_NotEnoughItem";};
        private _capacity = [_storageType,_scope] call life_fnc_craftingStorageCapacity;
        private _weight = ([_className] call life_fnc_itemWeight) * _amount;
        if (((_capacity select 4) + _weight) > (_capacity select 1)) exitWith {hint "That storage does not have enough room.";};
        if (!([false,_className,_amount] call life_fnc_handleInv)) exitWith {hint localize "STR_CouldNotRemoveItemsToPutInVeh";};
        _storage = [_storage,_className,_amount] call _addToStorage;
        [_storageType,_storage,_scope] call life_fnc_craftingSetStorage;
        hint "Items deposited.";
    } else {
        private _removed = [_storage,_className,_amount] call _removeFromStorage;
        if !(_removed select 0) exitWith {hint "There is not enough of that item in storage.";};
        private _diff = [_className,_amount,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
        if (_diff < _amount) exitWith {hint localize "STR_NOTF_InvFull";};
        _storage = _removed select 1;
        if (!([true,_className,_amount] call life_fnc_handleInv)) exitWith {hint localize "STR_NOTF_CouldntAdd";};
        [_storageType,_storage,_scope] call life_fnc_craftingSetStorage;
        hint "Items withdrawn.";
    };
};

[] call life_fnc_craftingLoad;
