#include "..\..\script_macros.hpp"
/*
    File: fn_characterMenuLoad.sqf
*/
disableSerialization;
params [
    ["_display",displayNull,[displayNull]]
];

if (isNull _display) then {_display = findDisplay 7800;};
if (isNull _display) exitWith {};

private _key = format ["life_characters_%1_%2",getPlayerUID player,profileName];
life_characters = profileNamespace getVariable [_key,[]];
if !(life_characters isEqualType []) then {life_characters = [];};
private _lastSlot = profileNamespace getVariable [format ["%1_selected",_key],-1];
private _lastIndex = -1;

lbClear 7801;
if ((count life_characters) < 3) then {
    private _newIdx = lbAdd [7801,"Create New Character"];
    lbSetData [7801,_newIdx,"__new"];
};

{
    private _slot = _x select 0;
    private _name = _x select 2;
    private _dob = _x select 3;
    private _idx = lbAdd [7801,format ["Slot %1  |  %2",_slot + 1,_name]];
    lbSetData [7801,_idx,str _x];
    lbSetTooltip [7801,_idx,format ["DOB: %1",_dob]];
    if (_slot isEqualTo _lastSlot) then {_lastIndex = _idx;};
} forEach life_characters;

if (_lastIndex >= 0) then {
    lbSetCurSel [7801,_lastIndex];
} else {
    if ((lbCurSel 7801) < 0 && {(lbSize 7801) > 0}) then {
        lbSetCurSel [7801,0];
    };
};

private _faces = [
    ["WhiteHead_01","Face 01"],
    ["WhiteHead_02","Face 02"],
    ["WhiteHead_03","Face 03"],
    ["AfricanHead_01","Face 04"],
    ["AsianHead_A3_01","Face 05"]
];

lbClear 7807;
{
    private _idx = lbAdd [7807,_x select 1];
    lbSetData [7807,_idx,_x select 0];
} forEach _faces;
lbSetCurSel [7807,0];

private _uniforms = [
    ["U_C_Poloshirt_blue","Blue Polo"],
    ["U_C_Poloshirt_burgundy","Burgundy Polo"],
    ["U_C_Poloshirt_stripped","Striped Polo"],
    ["U_C_Poloshirt_tricolour","Tricolor Polo"],
    ["U_C_Man_casual_1_F","Casual 1"],
    ["U_C_Man_casual_2_F","Casual 2"]
];

lbClear 7808;
{
    private _idx = lbAdd [7808,_x select 1];
    lbSetData [7808,_idx,_x select 0];
} forEach _uniforms;
lbSetCurSel [7808,0];

private _remaining = 3 - (count life_characters);
(_display displayCtrl 7802) ctrlSetStructuredText parseText format [
    "<t color='#00c7eb' size='1.1'>%1 slots available</t><br/><t color='#dceaf0'>Steam ID:</t> %2<br/><t color='#dceaf0'>Profile:</t> %3",
    _remaining max 0,
    getPlayerUID player,
    profileName
];

if (missionNamespace getVariable ["life_character_gate_active",false]) then {
    (_display displayCtrl 7803) ctrlSetTooltip "Required";
    (_display displayCtrl 7804) ctrlSetTooltip "Required";
    (_display displayCtrl 7805) ctrlSetTooltip "Required";
    (_display displayCtrl 7806) ctrlSetTooltip "Required";
};

[_display] call life_fnc_characterPreviewStart;
