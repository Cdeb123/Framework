#include "..\..\script_macros.hpp"
/*
    File: fn_craftingCraft.sqf
*/
disableSerialization;
private _display = findDisplay 9300;
if (isNull _display) exitWith {};
if (life_action_inUse || {missionNamespace getVariable ["life_crafting_active",false]}) exitWith {hint "You are already crafting something.";};

private _tab = missionNamespace getVariable ["life_crafting_tab","craft"];
if !(_tab in ["craft","vehicles"]) exitWith {};

private _left = _display displayCtrl 9322;
if ((lbCurSel _left) < 0) exitWith {hint localize "STR_Global_NoSelection";};

private _scope = [missionNamespace getVariable ["life_crafting_scope",""]] call life_fnc_craftingScope;
private _scopeCfg = [_scope] call life_fnc_craftingScopeConfig;
private _recipeName = _left lbData (lbCurSel _left);
private _recipe = _scopeCfg >> "Recipes" >> _recipeName;
if !(isClass _recipe) exitWith {};
if !([_recipe,_scope,true] call life_fnc_craftingRecipeAllowed) exitWith {};

private _outType = toLower getText (_recipe >> "outputType");
private _outClass = getText (_recipe >> "outputClass");
private _outAmount = (getNumber (_recipe >> "outputAmount")) max 1;
private _title = getText (_recipe >> "title");
if (_title isEqualTo "") then {_title = [_outClass,_outType] call life_fnc_craftingItemTitle;};

private _allowQty = (getNumber (_recipe >> "allowQuantity")) isEqualTo 1;
private _qtyText = ctrlText (_display displayCtrl 9325);
if !([_qtyText] call TON_fnc_isnumber) exitWith {hint localize "STR_MISC_WrongNumFormat";};
private _qty = (parseNumber _qtyText) max 1;
_qty = floor _qty;
if (!_allowQty) then {_qty = 1;};
private _maxQty = getNumber (_recipe >> "maxQuantity");
if (_maxQty <= 0) then {_maxQty = getNumber (missionConfigFile >> "Life_Crafting" >> "maxMagazineQuantity");};
if (_allowQty) then {_qty = _qty min _maxQty;};

private _totalOut = _outAmount * _qty;
private _cashCost = (getNumber (_recipe >> "cashCost")) * _qty;
private _materials = getArray (_recipe >> "materials");
private _workbench = ["workbench",_scope] call life_fnc_craftingGetStorage;

private _hasMaterials = {
    params ["_storage","_requirements","_multiplier"];
    private _ok = true;
    {
        private _item = _x param [0,"",[""]];
        private _need = (_x param [1,0,[0]]) * _multiplier;
        private _index = _storage findIf {(_x param [0,"",[""]]) isEqualTo _item};
        private _have = if (_index < 0) then {0} else {(_storage select _index) param [1,0,[0]]};
        if (_have < _need) exitWith {_ok = false;};
    } forEach _requirements;
    _ok
};

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
    params ["_storage","_requirements","_multiplier"];
    {
        private _item = _x param [0,"",[""]];
        private _need = (_x param [1,0,[0]]) * _multiplier;
        private _index = _storage findIf {(_x param [0,"",[""]]) isEqualTo _item};
        if (_index >= 0) then {
            private _row = _storage select _index;
            private _newAmount = (_row param [1,0,[0]]) - _need;
            if (_newAmount <= 0) then {
                _storage deleteAt _index;
            } else {
                _row set [1,_newAmount];
                _storage set [_index,_row];
            };
        };
    } forEach _requirements;
    _storage
};

if !([_workbench,_materials,_qty] call _hasMaterials) exitWith {hint "Your workbench does not have the required materials.";};
if (CASH < _cashCost) exitWith {hint format ["You need $%1 more cash to craft that.",[_cashCost - CASH] call life_fnc_numberText];};

private _outputBlocked = false;
if (_outType in ["virtual","gear"]) then {
    private _storageType = if (_outType isEqualTo "gear") then {"gear"} else {"items"};
    private _capacity = [_storageType,_scope] call life_fnc_craftingStorageCapacity;
    private _addUse = if (_storageType isEqualTo "gear") then {
        _totalOut
    } else {
        ([_outClass] call life_fnc_itemWeight) * _totalOut
    };
    if (((_capacity select 4) + _addUse) > (_capacity select 1)) then {
        hint "Your output storage is full. Upgrade it or withdraw some stored items first.";
        _outputBlocked = true;
    };
};
if (_outputBlocked) exitWith {};

private _baseTime = getNumber (_recipe >> "craftTime");
private _timeMult = getNumber (_scopeCfg >> "timeMultiplier");
if (_timeMult <= 0) then {_timeMult = 1;};
private _focus = ["crafting_focus"] call life_fnc_perkModifier;
if (_focus <= 0) then {_focus = 1;};
private _craftTime = (((_baseTime max 1) * _qty * _timeMult) / _focus) max 1;
private _minDistance = getNumber (missionConfigFile >> "Life_Crafting" >> "minCraftDistance");
if (_minDistance <= 0) then {_minDistance = 7;};
private _source = missionNamespace getVariable ["life_crafting_source",objNull];

life_action_inUse = true;
missionNamespace setVariable ["life_crafting_active",true];

"progressBar" cutRsc ["life_progress","PLAIN"];
private _ui = uiNamespace getVariable ["life_progress",displayNull];
private _overlayProgress = if (isNull _ui) then {controlNull} else {_ui displayCtrl 38201};
private _overlayText = if (isNull _ui) then {controlNull} else {_ui displayCtrl 38202};
private _dialogProgress = _display displayCtrl 9329;
private _dialogText = _display displayCtrl 9330;
private _start = time;
private _cancelled = false;

while {((time - _start) < _craftTime) && {!_cancelled}} do {
    private _progress = ((time - _start) / _craftTime) min 1;
    private _percent = round (_progress * 100);
    private _text = format ["Crafting %1 (%2%3)",_title,_percent,"%"];
    if (!isNull _overlayProgress) then {_overlayProgress progressSetPosition _progress;};
    if (!isNull _overlayText) then {_overlayText ctrlSetText _text;};
    if (!isNull _dialogProgress) then {_dialogProgress progressSetPosition _progress;};
    if (!isNull _dialogText) then {_dialogText ctrlSetText _text;};
    if (!alive player || {player getVariable ["restrained",false]}) then {_cancelled = true;};
    if (!isNull _source && {player distance _source > _minDistance}) then {_cancelled = true;};
    uiSleep 0.25;
};

if (_cancelled) exitWith {
    "progressBar" cutText ["","PLAIN"];
    life_action_inUse = false;
    missionNamespace setVariable ["life_crafting_active",false];
    hint "Crafting cancelled. Stay near the bench until the job is complete.";
    if (!isNull (findDisplay 9300)) then {[] call life_fnc_craftingLoad;};
};

_workbench = ["workbench",_scope] call life_fnc_craftingGetStorage;
if !([_workbench,_materials,_qty] call _hasMaterials) exitWith {
    "progressBar" cutText ["","PLAIN"];
    life_action_inUse = false;
    missionNamespace setVariable ["life_crafting_active",false];
    hint "Crafting failed because the workbench materials changed.";
    if (!isNull (findDisplay 9300)) then {[] call life_fnc_craftingLoad;};
};
if (CASH < _cashCost) exitWith {
    "progressBar" cutText ["","PLAIN"];
    life_action_inUse = false;
    missionNamespace setVariable ["life_crafting_active",false];
    hint "Crafting failed because you no longer have enough cash.";
    if (!isNull (findDisplay 9300)) then {[] call life_fnc_craftingLoad;};
};

_outputBlocked = false;
if (_outType in ["virtual","gear"]) then {
    private _storageType = if (_outType isEqualTo "gear") then {"gear"} else {"items"};
    private _capacity = [_storageType,_scope] call life_fnc_craftingStorageCapacity;
    private _addUse = if (_storageType isEqualTo "gear") then {
        _totalOut
    } else {
        ([_outClass] call life_fnc_itemWeight) * _totalOut
    };
    if (((_capacity select 4) + _addUse) > (_capacity select 1)) then {
        _outputBlocked = true;
    };
};
if (_outputBlocked) exitWith {
    "progressBar" cutText ["","PLAIN"];
    life_action_inUse = false;
    missionNamespace setVariable ["life_crafting_active",false];
    hint "Crafting failed because the output storage filled up.";
    if (!isNull (findDisplay 9300)) then {[] call life_fnc_craftingLoad;};
};

CASH = CASH - _cashCost;
[0] call SOCK_fnc_updatePartial;

_workbench = [_workbench,_materials,_qty] call _removeFromStorage;
["workbench",_workbench,_scope] call life_fnc_craftingSetStorage;

switch (_outType) do {
    case "virtual": {
        private _items = ["items",_scope] call life_fnc_craftingGetStorage;
        _items = [_items,_outClass,_totalOut] call _addToStorage;
        ["items",_items,_scope] call life_fnc_craftingSetStorage;
    };
    case "vehicle": {
        private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
        private _color = getNumber (missionConfigFile >> "Life_Crafting" >> "vehicleColorIndex");
        if (life_HC_isActive) then {
            [player,playerSide,_outClass,_color,_charUID,_scope] remoteExecCall ["HC_fnc_craftingVehicleCreate",HC_Life];
        } else {
            [player,playerSide,_outClass,_color,_charUID,_scope] remoteExecCall ["TON_fnc_craftingVehicleCreate",RSERV];
        };
    };
    default {
        private _gear = ["gear",_scope] call life_fnc_craftingGetStorage;
        _gear = [_gear,_outClass,_totalOut] call _addToStorage;
        ["gear",_gear,_scope] call life_fnc_craftingSetStorage;
    };
};

private _xp = (getNumber (_recipe >> "craftingXP")) * _qty;
private _charXP = (getNumber (_recipe >> "characterXP")) * _qty;
if (_xp > 0) then {
    ["crafting",_xp,format ["Crafted %1",_title]] call life_fnc_addXP;
};
if (_charXP > 0) then {
    ["character",_charXP,format ["Crafted %1",_title],false] call life_fnc_addXP;
};

"progressBar" cutText ["","PLAIN"];
life_action_inUse = false;
missionNamespace setVariable ["life_crafting_active",false];

private _destination = switch (_outType) do {
    case "vehicle": {"garage"};
    case "virtual": {"item storage"};
    default {"gear vault"};
};
hint format ["Crafted %1 x%2. Output sent to %3.",_title,_totalOut,_destination];

if (!isNull (findDisplay 9300)) then {
    [] call life_fnc_craftingLoad;
};
