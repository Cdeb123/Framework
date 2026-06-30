#include "..\..\script_macros.hpp"
/*
    File: fn_citationRecordsLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8390;
if (isNull _display) exitWith {};

private _filter = ctrlText 8392;
private _records = [_filter] call life_fnc_citationRecords;
private _list = _display displayCtrl 8391;
lbClear _list;

{
    private _amount = _x param [15,0,[0]];
    private _label = format [
        "%1 | %2 | %3 | $%4",
        toUpper (_x param [1,"pending",[""]]),
        _x param [11,"Unknown",[""]],
        _x param [14,"Offense",[""]],
        [_amount] call life_fnc_numberText
    ];
    _list lbAdd _label;
    _list lbSetData [(lbSize _list) - 1,_x param [0,""]];
} forEach _records;

if ((lbSize _list) > 0) then {
    _list lbSetCurSel 0;
    [] call life_fnc_citationRecordsSelect;
} else {
    (_display displayCtrl 8393) ctrlSetStructuredText parseText "<t color='#7ea6b3'>No citations match this search.</t>";
};

ctrlSetText [8394,format ["%1 citation records",count _records]];
