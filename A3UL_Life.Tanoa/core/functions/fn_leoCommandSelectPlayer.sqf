#include "..\..\script_macros.hpp"
/*
    File: fn_leoCommandSelectPlayer.sqf
*/
disableSerialization;
private _display = findDisplay 8100;
if (isNull _display || {(lbCurSel 8101) < 0}) exitWith {};

private _data = call compile (lbData [8101,lbCurSel 8101]);
_data params [
    ["_uid","",[""]],
    ["_name","",[""]],
    ["_charUid","",[""]]
];

ctrlSetText [8113,_uid];
ctrlSetText [8114,_charUid];
(_display displayCtrl 8117) ctrlSetStructuredText parseText format [
    "<t color='#40E0F0' size='1.1'>Selected Member</t><br/>%1<br/>Steam: %2<br/>Character: %3",
    _name,
    _uid,
    _charUid
];
