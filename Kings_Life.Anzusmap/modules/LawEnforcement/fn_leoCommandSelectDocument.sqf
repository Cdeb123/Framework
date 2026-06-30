#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandSelectDocument.sqf
*/
disableSerialization;
private _display = findDisplay 8100;
if (isNull _display || {(lbCurSel 8123) < 0}) exitWith {};

private _row = call compile (lbData [8123,lbCurSel 8123]);
_row params [
    ["_id",0,[0]],
    ["_department","",[""]],
    ["_title","",[""]],
    ["_body","",[""]],
    ["_createdBy","",[""]],
    ["_createdAt","",[""]]
];

(_display displayCtrl 8124) ctrlSetStructuredText parseText format [
    "<t color='#6EE7F9' size='1.08'>%1</t><br/><t color='#9FB4C8'>%2 | %3</t><br/><br/><t color='#EEF7FB'>%4</t>",
    _title,
    _department,
    _createdAt,
    _body
];
