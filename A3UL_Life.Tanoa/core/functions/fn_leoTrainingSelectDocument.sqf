#include "..\..\script_macros.hpp"
/*
    File: fn_leoTrainingSelectDocument.sqf
*/
disableSerialization;
private _display = findDisplay 8200;
if (isNull _display || {(lbCurSel 8201) < 0}) exitWith {};

private _row = call compile (lbData [8201,lbCurSel 8201]);
_row params [
    ["_id",0,[0]],
    ["_department","",[""]],
    ["_title","",[""]],
    ["_body","",[""]],
    ["_createdBy","",[""]],
    ["_createdAt","",[""]]
];

(_display displayCtrl 8202) ctrlSetStructuredText parseText format [
    "<t color='#F4B95A' size='1.1'>%1</t><br/><t color='#C9B38C'>%2 | %3</t><br/><br/><t color='#FFF8EA'>%4</t>",
    _title,
    _department,
    _createdAt,
    _body
];
