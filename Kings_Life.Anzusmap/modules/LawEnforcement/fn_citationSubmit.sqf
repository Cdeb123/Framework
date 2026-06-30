#include "..\..\script_macros.hpp"
/*
    File: fn_citationSubmit.sqf
*/
disableSerialization;

private _target = missionNamespace getVariable ["life_citation_unit",objNull];
if !(playerSide isEqualTo west) exitWith {hint "Only law enforcement can issue citations.";};
if !(["police.ticket"] call life_fnc_hasPermission) exitWith {hint "You do not have citation permissions.";};
if (isNull _target || {!isPlayer _target}) exitWith {hint "The selected civilian is no longer available.";};
if (player distance _target > 8) exitWith {hint "Move closer to issue the citation.";};

private _limitText = {
    params [
        ["_text","",[""]],
        ["_max",64,[0]]
    ];
    if ((count _text) > _max) then {_text select [0,_max]} else {_text};
};

private _civilianName = [ctrlText 8353,64] call _limitText;
private _vehicleDescription = [ctrlText 8355,80] call _limitText;
private _plate = [ctrlText 8357,24] call _limitText;
private _offense = [ctrlText 8359,120] call _limitText;
private _amountText = ctrlText 8361;

if (_civilianName isEqualTo "") exitWith {hint "Enter the civilian name.";};
if (_offense isEqualTo "") exitWith {hint "Enter the offense.";};
if (!([_amountText] call TON_fnc_isnumber)) exitWith {hint "Enter a valid ticket amount.";};

private _amount = floor (parseNumber _amountText);
private _maxAmount = getNumber (missionConfigFile >> "Life_LEO" >> "Citations" >> "maxAmount");
if (_maxAmount <= 0) then {_maxAmount = 250000;};
if (_amount < 1) exitWith {hint "Ticket amount must be at least $1.";};
if (_amount > _maxAmount) exitWith {hint format ["Ticket amount cannot exceed $%1.",[_maxAmount] call life_fnc_numberText];};

private _issuerName = player getVariable ["realname",profileName];
private _badge = player getVariable ["leoBadgeNumber",""];
private _department = missionNamespace getVariable ["life_leo_department_display",missionNamespace getVariable ["life_leo_department",""]];
private _rank = missionNamespace getVariable ["life_leo_rank_display",missionNamespace getVariable ["life_leo_rank",""]];
private _citationId = format [
    "CIT-%1-%2-%3",
    getPlayerUID player,
    floor serverTime,
    floor random 10000
];

private _record = [
    _citationId,
    "pending",
    serverTime,
    date,
    getPlayerUID player,
    _issuerName,
    _badge,
    _department,
    _rank,
    getPlayerUID _target,
    _target getVariable ["characterUID",""],
    _civilianName,
    _vehicleDescription,
    _plate,
    _offense,
    _amount,
    -1,
    -1
];

[_record] call life_fnc_citationAddRecord;
[player,_record] remoteExec ["life_fnc_citationPrompt",_target];

hint format ["Citation %1 issued to %2 for $%3.",_citationId,_civilianName,[_amount] call life_fnc_numberText];
closeDialog 0;
