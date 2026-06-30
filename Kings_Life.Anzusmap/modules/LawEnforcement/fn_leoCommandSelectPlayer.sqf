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

private _unit = objNull;
{
    if ((getPlayerUID _x) isEqualTo _uid) exitWith {_unit = _x;};
} forEach allPlayers;

if !(isNull _unit) then {
    private _dept = _unit getVariable ["leoDepartment",""];
    private _rank = _unit getVariable ["leoRank",""];
    private _subs = _unit getVariable ["leoSubdivisions",[]];
    private _primary = _unit getVariable ["leoPrimarySubdivision",if ((count _subs) > 0) then {_subs select 0} else {""}];

    if !(_dept isEqualTo "") then {
        for "_i" from 0 to ((lbSize 8102) - 1) do {
            if ((lbData [8102,_i]) isEqualTo _dept) exitWith {lbSetCurSel [8102,_i];};
        };
        [] call life_fnc_leoCommandLoadDepartment;
    };

    if !(_rank isEqualTo "") then {
        for "_i" from 0 to ((lbSize 8103) - 1) do {
            if ((lbData [8103,_i]) isEqualTo _rank) exitWith {lbSetCurSel [8103,_i];};
        };
    };

    if !(_primary isEqualTo "") then {
        for "_i" from 0 to ((lbSize 8104) - 1) do {
            if ((lbData [8104,_i]) isEqualTo _primary) exitWith {lbSetCurSel [8104,_i];};
        };
    };

    private _extra = _subs select {!(_x isEqualTo _primary)};
    ctrlSetText [8115,_extra joinString ","];
};

(_display displayCtrl 8117) ctrlSetStructuredText parseText format [
    "<t color='#6EE7F9' size='1.08'>Selected Unit</t><br/><t color='#EEF7FB'>%1</t><br/><t color='#9FB4C8'>Steam: %2<br/>Character: %3</t>",
    _name,
    _uid,
    _charUid
];
