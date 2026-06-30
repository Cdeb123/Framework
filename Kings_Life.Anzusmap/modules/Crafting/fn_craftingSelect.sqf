#include "..\..\script_macros.hpp"
/*
    File: fn_craftingSelect.sqf
*/
disableSerialization;
private _display = findDisplay 9300;
if (isNull _display) exitWith {};

private _scope = [missionNamespace getVariable ["life_crafting_scope",""]] call life_fnc_craftingScope;
private _scopeCfg = [_scope] call life_fnc_craftingScopeConfig;
private _tab = missionNamespace getVariable ["life_crafting_tab","craft"];
private _left = _display displayCtrl 9322;
private _right = _display displayCtrl 9323;
private _details = _display displayCtrl 9324;
private _quantity = _display displayCtrl 9325;

if (_tab in ["craft","vehicles"]) then {
    lbClear _right;
    if ((lbCurSel _left) < 0) exitWith {_details ctrlSetStructuredText parseText "";};

    private _recipeName = _left lbData (lbCurSel _left);
    missionNamespace setVariable ["life_crafting_selected",_recipeName];
    private _recipe = _scopeCfg >> "Recipes" >> _recipeName;
    if !(isClass _recipe) exitWith {};

    private _outType = toLower getText (_recipe >> "outputType");
    private _outClass = getText (_recipe >> "outputClass");
    private _title = getText (_recipe >> "title");
    if (_title isEqualTo "") then {_title = [_outClass,_outType] call life_fnc_craftingItemTitle;};

    private _allowQty = (getNumber (_recipe >> "allowQuantity")) isEqualTo 1;
    _quantity ctrlEnable _allowQty;
    if (!_allowQty) then {_quantity ctrlSetText "1";};
    private _qtyText = ctrlText _quantity;
    private _qty = if ([_qtyText] call TON_fnc_isnumber) then {(parseNumber _qtyText) max 1} else {1};
    if (!_allowQty) then {_qty = 1;};
    private _maxQty = getNumber (_recipe >> "maxQuantity");
    if (_maxQty <= 0) then {_maxQty = getNumber (missionConfigFile >> "Life_Crafting" >> "maxMagazineQuantity");};
    if (_allowQty) then {_qty = _qty min _maxQty;};

    private _workbench = ["workbench",_scope] call life_fnc_craftingGetStorage;
    {
        private _item = _x param [0,"",[""]];
        private _need = (_x param [1,0,[0]]) * _qty;
        private _have = 0;
        private _index = _workbench findIf {(_x param [0,"",[""]]) isEqualTo _item};
        if (_index >= 0) then {_have = (_workbench select _index) param [1,0,[0]];};
        private _name = [_item,"virtual"] call life_fnc_craftingItemTitle;
        private _row = _right lbAdd format ["%1/%2 - %3",_have,_need,_name];
        _right lbSetData [_row,_item];
        _right lbSetValue [_row,_need];
    } forEach getArray (_recipe >> "materials");

    private _requiredLevel = getNumber (_recipe >> "requiredLevel");
    if (_requiredLevel < 1) then {_requiredLevel = 1;};
    private _craftTime = getNumber (_recipe >> "craftTime");
    private _timeMult = getNumber (_scopeCfg >> "timeMultiplier");
    if (_timeMult <= 0) then {_timeMult = 1;};
    private _focus = ["crafting_focus"] call life_fnc_perkModifier;
    if (_focus <= 0) then {_focus = 1;};
    private _totalTime = round ((_craftTime * _qty * _timeMult) / _focus);
    private _cashCost = (getNumber (_recipe >> "cashCost")) * _qty;
    private _xp = (getNumber (_recipe >> "craftingXP")) * _qty;
    private _allowed = [_recipe,_scope,false] call life_fnc_craftingRecipeAllowed;
    private _status = if (_allowed) then {"Ready"} else {"Locked"};
    private _rank = getText (_recipe >> "rank");
    private _rankText = if (_rank isEqualTo "") then {""} else {format ["<br/><t color='#8fa4aa'>Rank: %1</t>",_rank]};
    private _typeText = switch (_outType) do {
        case "vehicle": {"Vehicle to Garage"};
        case "virtual": {"Virtual Item Storage"};
        default {"Gear Vault"};
    };
    _details ctrlSetStructuredText parseText format [
        "<t size='1.12' color='#effbff'>%1</t><br/><t color='#8fe7ff'>%2</t><br/><br/>%3<br/><br/><t color='#8fa4aa'>Level: %4 | Time: %5s | XP: %6</t><br/><t color='#8fa4aa'>Cash: $%7 | Qty: %8</t>%9<br/><br/><t color='#9edb5a'>%10</t>",
        _title,
        _typeText,
        getText (_recipe >> "text"),
        _requiredLevel,
        _totalTime,
        _xp,
        [_cashCost] call life_fnc_numberText,
        _qty,
        _rankText,
        _status
    ];
} else {
    private _mode = switch (_tab) do {
        case "workbench": {"workbench"};
        case "gear": {"gear"};
        default {"items"};
    };
    private _capacity = [_mode,_scope] call life_fnc_craftingStorageCapacity;
    _capacity params ["_level","_cap","_nextCost","_nextCap","_used"];
    private _nextText = if (_nextCost < 0) then {"Max storage level reached."} else {format ["Next: %1 capacity for $%2.",_nextCap,[_nextCost] call life_fnc_numberText]};
    private _selected = "";
    if ((lbCurSel _left) >= 0) then {
        private _className = _left lbData (lbCurSel _left);
        private _itemType = if (_mode isEqualTo "gear") then {"gear"} else {"virtual"};
        _selected = format ["<br/><br/><t color='#effbff'>Selected:</t><br/>%1",[_className,_itemType] call life_fnc_craftingItemTitle];
    };
    _details ctrlSetStructuredText parseText format [
        "<t size='1.10' color='#effbff'>Storage Level %1</t><br/><t color='#8fa4aa'>Used: %2 / %3</t><br/><br/>%4%5",
        _level,
        _used,
        _cap,
        _nextText,
        _selected
    ];
};
