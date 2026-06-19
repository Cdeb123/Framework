#include "..\..\script_macros.hpp"
/*
    File: fn_openCitation.sqf
*/
params [
    ["_unit",objNull,[objNull]]
];

if !(playerSide isEqualTo west) exitWith {hint "Only law enforcement can issue citations.";};
if !(["police.ticket"] call life_fnc_hasPermission) exitWith {hint "You do not have citation permissions.";};
if (isNull _unit || {!isPlayer _unit} || {_unit isEqualTo player}) exitWith {hint "Select a nearby civilian first.";};
if (player distance _unit > 6) exitWith {hint "Move closer to issue a citation.";};

life_citation_unit = _unit;
if (!(createDialog "life_citation_issue")) exitWith {hint "Citation terminal failed to open.";};
