#include "\life_server\script_macros.hpp"
/*
    File: fn_fetchFrameworkData.sqf

    Description:
    Fetches optional framework extension data without changing the legacy
    player query packet.
*/
params [
    ["_uid","",[""]],
    ["_returnToSender",objNull,[objNull]]
];

if (_uid isEqualTo "" || {isNull _returnToSender}) exitWith {};

private _owner = owner _returnToSender;
private _readArray = {
    params [["_raw","",[""]]];
    private _value = [_raw] call DB_fnc_mresToArray;
    if (_value isEqualType "") then {_value = call compile format ["%1",_value];};
    if !(_value isEqualType []) then {_value = [];};
    _value;
};

private _permissions = [];
private _whitelistRows = [format ["SELECT permissions FROM steam_whitelist WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
if (_whitelistRows isEqualType []) then {
    {
        { _permissions pushBackUnique _x; } forEach ([(_x select 0)] call _readArray);
    } forEach _whitelistRows;
};

private _discordRows = [format ["SELECT permissions FROM discord_permissions WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
if (_discordRows isEqualType []) then {
    {
        { _permissions pushBackUnique _x; } forEach ([(_x select 0)] call _readArray);
    } forEach _discordRows;
};

private _citations = [format ["SELECT id, amount, reason FROM citations WHERE pid='%1' AND status='pending'",_uid],2,true] call DB_fnc_asyncCall;
if !(_citations isEqualType []) then {_citations = [];};

private _warrants = [format ["SELECT id, severity, reason FROM warrants WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
if !(_warrants isEqualType []) then {_warrants = [];};

[_permissions,_citations,_warrants] remoteExecCall ["life_fnc_frameworkDataReceived",_owner];
