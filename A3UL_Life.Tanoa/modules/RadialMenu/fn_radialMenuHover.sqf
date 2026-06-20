#include "..\..\script_macros.hpp"
/* Updates the wheel hub and the highlighted segment. */
disableSerialization;
params [["_slot",-1,[0]]];
private _display = findDisplay 9200;
if (isNull _display) exitWith {};

private _page = missionNamespace getVariable ["life_radial_page",0];
private _actions = missionNamespace getVariable ["life_radial_actions",[]];
private _category = missionNamespace getVariable ["life_radial_category","main"];
private _actionIndex = (_page * 8) + _slot;

for "_i" from 0 to 7 do {
    private _back = _display displayCtrl (9260 + _i);
    _back ctrlSetTextColor [0.018,0.038,0.049,0.96];
};

private _title = if (_category isEqualTo "main") then {"F1 INTERACT"} else {toUpper _category};
private _detail = if (_category isEqualTo "main") then {
    "Choose a context. The wheel only shows actions you can use here."
} else {
    "Select an action, or click the center to return."
};
private _icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";

if (_slot >= 0 && {_actionIndex < count _actions}) then {
    private _action = _actions select _actionIndex;
    _title = toUpper (_action param [0,"INTERACT",[""]]);
    _detail = _action param [1,"",[""]];
    _icon = _action param [6,"\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa",[""]];
    (_display displayCtrl (9260 + _slot)) ctrlSetTextColor [0.10,0.55,0.72,0.98];
};

(_display displayCtrl 9201) ctrlSetText _icon;
private _titleCtrl = _display displayCtrl 9202;
_titleCtrl ctrlSetFontHeight ([0.027,0.021] select ((count _title) > 18));
_titleCtrl ctrlSetText _title;
(_display displayCtrl 9203) ctrlSetStructuredText parseText format ["<t align='center' color='#9bb3bf'>%1</t>",_detail];
life_radial_hover = _slot;
