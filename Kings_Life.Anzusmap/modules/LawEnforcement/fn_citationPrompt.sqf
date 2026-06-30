#include "..\..\script_macros.hpp"
/*
    File: fn_citationPrompt.sqf
*/
params [
    ["_officer",objNull,[objNull]],
    ["_record",[],[[]]]
];

if (isNull _officer || {_record isEqualTo []}) exitWith {};
if (!isNull (findDisplay 8370)) exitWith {};

life_citation_active = _record;
life_citation_officer = _officer;
life_citation_decided = false;

if (!(createDialog "life_citation_pay")) exitWith {};
disableSerialization;
waitUntil {!isNull (findDisplay 8370)};

private _amount = _record param [15,0,[0]];
private _text = format [
    "<t color='#eaf7fb' size='1.04'>Citation %1</t><br/><br/><t color='#7ea6b3'>Officer:</t> %2 #%3<br/><t color='#7ea6b3'>Civilian:</t> %4<br/><t color='#7ea6b3'>Vehicle:</t> %5<br/><t color='#7ea6b3'>Plate:</t> %6<br/><t color='#7ea6b3'>Offense:</t> %7<br/><br/><t color='#7ee6a2' size='1.08'>Amount Due: $%8</t>",
    _record param [0,""],
    _record param [5,""],
    _record param [6,""],
    _record param [11,""],
    _record param [12,""],
    _record param [13,""],
    _record param [14,""],
    [_amount] call life_fnc_numberText
];

CONTROL(8370,8371) ctrlSetStructuredText parseText _text;

[] spawn {
    waitUntil {missionNamespace getVariable ["life_citation_decided",false] || {isNull (findDisplay 8370)}};
    if (isNull (findDisplay 8370) && {!(missionNamespace getVariable ["life_citation_decided",false])}) then {
        [] call life_fnc_citationDecline;
    };
};
