#include "..\..\script_macros.hpp"
/*
    File: fn_citationRecordsSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8390;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 8391;
if ((lbCurSel _list) < 0) exitWith {};

private _id = _list lbData (lbCurSel _list);
private _records = missionNamespace getVariable ["life_citation_records",[]];
private _record = [];
{
    if ((_x param [0,""]) isEqualTo _id) exitWith {_record = _x;};
} forEach _records;
if (_record isEqualTo []) exitWith {};

private _amount = _record param [15,0,[0]];
private _status = toUpper (_record param [1,"pending",[""]]);
private _paidAt = _record param [16,-1,[0]];
private _declinedAt = _record param [17,-1,[0]];
private _resolution = switch (_record param [1,"pending",[""]]) do {
    case "paid": {format ["Paid at mission time %1",round _paidAt]};
    case "declined": {format ["Declined at mission time %1",round _declinedAt]};
    default {"Pending response"};
};

private _text = format [
    "<t color='#eaf7fb' size='1.05'>%1</t><br/><t color='#7ea6b3'>Status:</t> %2<br/><t color='#7ea6b3'>Issued By:</t> %3 #%4, %5<br/><t color='#7ea6b3'>Civilian:</t> %6<br/><t color='#7ea6b3'>Vehicle:</t> %7<br/><t color='#7ea6b3'>Plate:</t> %8<br/><t color='#7ea6b3'>Offense:</t> %9<br/><t color='#7ea6b3'>Amount:</t> $%10<br/><t color='#7ea6b3'>Resolution:</t> %11",
    _record param [0,""],
    _status,
    _record param [5,""],
    _record param [6,""],
    _record param [8,""],
    _record param [11,""],
    _record param [12,""],
    _record param [13,""],
    _record param [14,""],
    [_amount] call life_fnc_numberText,
    _resolution
];

(_display displayCtrl 8393) ctrlSetStructuredText parseText _text;
