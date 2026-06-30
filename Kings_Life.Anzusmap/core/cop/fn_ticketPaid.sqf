#include "..\..\script_macros.hpp"
/*
    File: fn_ticketPaid.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Verifies that the ticket was paid.
*/
params [
    ["_value",5,[0]],
    ["_unit",objNull,[objNull]],
    ["_cop",objNull,[objNull]]
];
if (isNull _unit || {!(_unit isEqualTo life_ticket_unit)}) exitWith {}; //NO
if (isNull _cop || {!(_cop isEqualTo player)}) exitWith {}; //Double NO

private _bankClass = getText (missionConfigFile >> "Life_LEO" >> "Citations" >> "factionBank");
if (_bankClass isEqualTo "") then {_bankClass = "law_enforcement";};
private _varName = format ["life_faction_bank_%1",_bankClass];
missionNamespace setVariable [_varName,(missionNamespace getVariable [_varName,0]) + _value,true];
publicVariable _varName;
["leo",getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> "ticketPaid"),"Paid ticket"] call life_fnc_addXP;
