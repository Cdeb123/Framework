#include "..\..\script_macros.hpp"
/*
    File: fn_atmLoad.sqf
*/
disableSerialization;
private _display = findDisplay 2700;
if (isNull _display) exitWith {};

private _limit = getNumber (missionConfigFile >> "Life_ATM" >> "dailyDepositLimit");
private _used = [] call life_fnc_atmDailyDeposit;
private _remaining = (_limit - _used) max 0;

(_display displayCtrl 2701) ctrlSetStructuredText parseText format [
    "<t color='#052b2f' size='1.05'>Checking Account</t><br/><t color='#061616'>Bank:</t> <t color='#00505a'>$%1</t>   <t color='#061616'>Cash:</t> <t color='#00505a'>$%2</t><br/><t color='#345253' size='0.82'>Daily cash deposit remaining: $%3</t>",
    [BANK] call life_fnc_numberText,
    [CASH] call life_fnc_numberText,
    [_remaining] call life_fnc_numberText
];

(_display displayCtrl 2706) ctrlSetStructuredText parseText "<t color='#345253' size='0.82'>Transfers draw from your bank balance. Player transfer tax is applied automatically.</t>";

private _players = _display displayCtrl 2703;
lbClear _players;
{
    if (alive _x && {isPlayer _x} && {!(_x isEqualTo player)}) then {
        private _name = _x getVariable ["realname",name _x];
        private _type = switch (side _x) do {
            case west: {"LEO"};
            case independent: {"EMS/FIRE"};
            case civilian: {"CIV"};
            default {"UNK"};
        };
        _players lbAdd format ["%1 (%2)",_name,_type];
        _players lbSetData [(lbSize _players) - 1,netId _x];
    };
} forEach playableUnits;
if ((lbSize _players) > 0) then {_players lbSetCurSel 0;};

private _gangs = _display displayCtrl 2704;
lbClear _gangs;
private _seen = [];
{
    private _group = group _x;
    private _gangName = _group getVariable ["gang_name",""];
    if (!(_gangName isEqualTo "") && {!(_group in _seen)} && {alive leader _group}) then {
        _seen pushBack _group;
        _gangs lbAdd format ["%1 ($%2)",_gangName,[(_group getVariable ["gang_bank",0])] call life_fnc_numberText];
        _gangs lbSetData [(lbSize _gangs) - 1,netId (leader _group)];
    };
} forEach playableUnits;
if ((lbSize _gangs) > 0) then {_gangs lbSetCurSel 0;};

private _factions = _display displayCtrl 2705;
lbClear _factions;

private _canDepositFaction = {
    params [["_cfg",configNull,[configNull]]];
    if ((getNumber (_cfg >> "canDeposit")) isEqualTo 0) exitWith {false};
    private _side = getText (_cfg >> "side");
    switch (_side) do {
        case "cop": {playerSide isEqualTo west && {["deputy"] call life_fnc_leoAtLeastRank}};
        case "med": {playerSide isEqualTo independent};
        case "civ": {playerSide isEqualTo civilian};
        default {true};
    };
};

private _canWithdrawFaction = {
    params [["_cfg",configNull,[configNull]]];
    if ((getNumber (_cfg >> "canWithdraw")) isEqualTo 0) exitWith {false};
    private _side = getText (_cfg >> "side");
    switch (_side) do {
        case "cop": {playerSide isEqualTo west && {[] call life_fnc_leoCanCommand}};
        default {false};
    };
};

{
    if (([_x] call _canDepositFaction) || {[_x] call _canWithdrawFaction}) then {
        private _bankClass = configName _x;
        private _varName = format ["life_faction_bank_%1",_bankClass];
        _factions lbAdd format ["%1 ($%2)",getText (_x >> "title"),[(missionNamespace getVariable [_varName,0])] call life_fnc_numberText];
        _factions lbSetData [(lbSize _factions) - 1,configName _x];
    };
} forEach ("true" configClasses (missionConfigFile >> "Life_ATM" >> "FactionBanks"));
if ((lbSize _factions) > 0) then {_factions lbSetCurSel 0;};
