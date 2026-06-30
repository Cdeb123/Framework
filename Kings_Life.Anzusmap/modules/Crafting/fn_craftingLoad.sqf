#include "..\..\script_macros.hpp"
/*
    File: fn_craftingLoad.sqf
*/
disableSerialization;
private _display = findDisplay 9300;
if (isNull _display) exitWith {};

if !(missionNamespace getVariable ["life_crafting_loaded",false]) then {
    [] call life_fnc_craftingInit;
};

private _scope = [missionNamespace getVariable ["life_crafting_scope",""]] call life_fnc_craftingScope;
private _scopeCfg = [_scope] call life_fnc_craftingScopeConfig;
private _themeName = getText (_scopeCfg >> "theme");
private _themeCfg = missionConfigFile >> "Life_Crafting" >> "Themes" >> _themeName;
private _accent = getArray (_themeCfg >> "accent");
private _header = getArray (_themeCfg >> "header");
private _back = getArray (_themeCfg >> "back");
private _text = getArray (_themeCfg >> "text");
private _muted = getArray (_themeCfg >> "muted");
if (_accent isEqualTo []) then {_accent = [0.0,0.68,0.74,1];};
if (_header isEqualTo []) then {_header = [0.035,0.050,0.052,1];};
if (_back isEqualTo []) then {_back = [0.018,0.024,0.026,0.96];};
if (_text isEqualTo []) then {_text = [0.92,0.98,0.98,1];};
if (_muted isEqualTo []) then {_muted = [0.62,0.78,0.78,1];};

(_display displayCtrl 9301) ctrlSetBackgroundColor _accent;
(_display displayCtrl 9302) ctrlSetBackgroundColor _header;
(_display displayCtrl 9303) ctrlSetTextColor _text;
(_display displayCtrl 9304) ctrlSetTextColor _muted;
(_display displayCtrl 9303) ctrlSetText (getText (_themeCfg >> "title"));
(_display displayCtrl 9304) ctrlSetText (getText (_themeCfg >> "subtitle"));

private _tab = missionNamespace getVariable ["life_crafting_tab","craft"];
private _left = _display displayCtrl 9322;
private _right = _display displayCtrl 9323;
private _leftTitle = _display displayCtrl 9320;
private _rightTitle = _display displayCtrl 9321;
private _details = _display displayCtrl 9324;
private _quantity = _display displayCtrl 9325;
private _primary = _display displayCtrl 9326;
private _secondary = _display displayCtrl 9327;
private _upgrade = _display displayCtrl 9328;
private _progress = _display displayCtrl 9329;
private _progressText = _display displayCtrl 9330;

lbClear _left;
lbClear _right;
_details ctrlSetStructuredText parseText "";
_quantity ctrlSetText "1";
_progress progressSetPosition 0;
_progressText ctrlSetText "";

{
    private _ctrl = _display displayCtrl _x;
    _ctrl ctrlSetBackgroundColor [0.035,0.055,0.070,0.96];
} forEach [9310,9311,9312,9313,9314];

private _activeTabIDC = switch (_tab) do {
    case "vehicles": {9311};
    case "workbench": {9312};
    case "storage": {9313};
    case "gear": {9314};
    default {9310};
};
(_display displayCtrl _activeTabIDC) ctrlSetBackgroundColor _accent;

private _setButton = {
    params ["_ctrl","_textValue","_action","_enabled"];
    _ctrl ctrlSetText _textValue;
    _ctrl ctrlEnable _enabled;
    _ctrl ctrlSetEventHandler ["ButtonClick",_action];
};

if (_tab in ["craft","vehicles"]) then {
    private _recipeTitle = if (_tab isEqualTo "vehicles") then {"Vehicle Recipes"} else {"Recipes"};
    _leftTitle ctrlSetText _recipeTitle;
    _rightTitle ctrlSetText "Materials";
    [_primary,"Craft","[] spawn life_fnc_craftingCraft",true] call _setButton;
    [_secondary,"Refresh","[] call life_fnc_craftingLoad",true] call _setButton;
    _upgrade ctrlSetText "Upgrade Workbench";
    _upgrade ctrlSetEventHandler ["ButtonClick","['workbench'] call life_fnc_craftingUpgrade"];
    _upgrade ctrlEnable true;

    private _selected = missionNamespace getVariable ["life_crafting_selected",""];
    private _selectIndex = -1;
    {
        private _outType = toLower getText (_x >> "outputType");
        private _isVehicle = _outType isEqualTo "vehicle";
        if ((_tab isEqualTo "vehicles") isEqualTo _isVehicle) then {
            private _allowed = [_x,_scope,false] call life_fnc_craftingRecipeAllowed;
            private _title = getText (_x >> "title");
            if (_title isEqualTo "") then {
                _title = [getText (_x >> "outputClass"),_outType] call life_fnc_craftingItemTitle;
            };
            private _prefix = if (_allowed) then {""} else {"[LOCKED] "};
            private _index = _left lbAdd (_prefix + _title);
            _left lbSetData [_index,configName _x];
            _left lbSetValue [_index,if (_allowed) then {1} else {0}];
            if ((configName _x) isEqualTo _selected) then {_selectIndex = _index;};
        };
    } forEach ("true" configClasses (_scopeCfg >> "Recipes"));

    if ((lbSize _left) > 0) then {
        if (_selectIndex < 0) then {_selectIndex = 0;};
        _left lbSetCurSel _selectIndex;
    };
} else {
    private _mode = switch (_tab) do {
        case "workbench": {"workbench"};
        case "gear": {"gear"};
        default {"items"};
    };
    private _storage = [_mode,_scope] call life_fnc_craftingGetStorage;
    private _capacity = [_mode,_scope] call life_fnc_craftingStorageCapacity;
    _capacity params ["_level","_cap","_nextCost","_nextCap","_used"];

    switch (_tab) do {
        case "workbench": {
            _leftTitle ctrlSetText format ["Workbench Materials  %1/%2",_used,_cap];
            _rightTitle ctrlSetText "Player Materials";
            [_primary,"Withdraw","['withdrawWorkbench'] call life_fnc_craftingTransfer",true] call _setButton;
            [_secondary,"Deposit","['depositWorkbench'] call life_fnc_craftingTransfer",true] call _setButton;
            _upgrade ctrlSetText "Upgrade Workbench Storage";
            _upgrade ctrlSetEventHandler ["ButtonClick","['workbench'] call life_fnc_craftingUpgrade"];
            _upgrade ctrlEnable (_nextCost >= 0);
        };
        case "gear": {
            _leftTitle ctrlSetText format ["Gear Vault  %1/%2",_used,_cap];
            _rightTitle ctrlSetText "Player Gear";
            [_primary,"Take Gear","['withdrawGear'] call life_fnc_craftingTransfer",true] call _setButton;
            [_secondary,"Store Gear","['depositGear'] call life_fnc_craftingTransfer",true] call _setButton;
            _upgrade ctrlSetText "Upgrade Gear Storage";
            _upgrade ctrlSetEventHandler ["ButtonClick","['gear'] call life_fnc_craftingUpgrade"];
            _upgrade ctrlEnable (_nextCost >= 0);
        };
        default {
            _leftTitle ctrlSetText format ["Personal Items  %1/%2",_used,_cap];
            _rightTitle ctrlSetText "Player Items";
            [_primary,"Withdraw","['withdrawItems'] call life_fnc_craftingTransfer",true] call _setButton;
            [_secondary,"Deposit","['depositItems'] call life_fnc_craftingTransfer",true] call _setButton;
            _upgrade ctrlSetText "Upgrade Item Storage";
            _upgrade ctrlSetEventHandler ["ButtonClick","['items'] call life_fnc_craftingUpgrade"];
            _upgrade ctrlEnable (_nextCost >= 0);
        };
    };

    {
        private _className = _x param [0,"",[""]];
        private _amount = _x param [1,0,[0]];
        if (_amount > 0) then {
            private _itemType = if (_mode isEqualTo "gear") then {"gear"} else {"virtual"};
            private _title = [_className,_itemType] call life_fnc_craftingItemTitle;
            private _index = _left lbAdd format ["[%1] - %2",_amount,_title];
            _left lbSetData [_index,_className];
        };
    } forEach _storage;

    if (_mode isEqualTo "gear") then {
        {
            private _className = _x param [0,"",[""]];
            private _amount = _x param [1,0,[0]];
            private _title = [_className,"gear"] call life_fnc_craftingItemTitle;
            private _index = _right lbAdd format ["[%1] - %2",_amount,_title];
            _right lbSetData [_index,_className];
        } forEach ([] call life_fnc_craftingInventoryGear);
    } else {
        private _allowedWorkbench = getArray (missionConfigFile >> "Life_Crafting" >> "Storage" >> "workbenchItems");
        {
            private _item = configName _x;
            private _amount = ITEM_VALUE(_item);
            private _include = _amount > 0;
            if (_mode isEqualTo "workbench") then {_include = _include && {_item in _allowedWorkbench};};
            if (_include) then {
                private _title = [_item,"virtual"] call life_fnc_craftingItemTitle;
                private _index = _right lbAdd format ["[%1] - %2",_amount,_title];
                _right lbSetData [_index,_item];
            };
        } forEach ("true" configClasses (missionConfigFile >> "VirtualItems"));
    };

    if ((lbSize _left) > 0) then {_left lbSetCurSel 0;};
};

[] call life_fnc_craftingSelect;
