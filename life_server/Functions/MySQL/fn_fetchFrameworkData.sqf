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

private _leoRows = [];
private _leoDbRows = [format ["SELECT department_key, rank_key, primary_subdivision, subdivisions, role_permissions, status FROM leo_memberships WHERE pid='%1' AND status='active'",_uid],2,true] call DB_fnc_asyncCall;
if (_leoDbRows isEqualType []) then {
    {
        _leoRows pushBack [
            _x select 0,
            _x select 1,
            _x select 2,
            [(_x select 3)] call _readArray,
            [(_x select 4)] call _readArray,
            _x select 5
        ];
    } forEach _leoDbRows;
};

private _trainingDocs = ["SELECT id, department_key, title, body, created_by_pid, DATE_FORMAT(insert_time,'%Y-%m-%d %H:%i') FROM leo_training_documents WHERE active='1' ORDER BY id DESC LIMIT 30",2,true] call DB_fnc_asyncCall;
if !(_trainingDocs isEqualType []) then {_trainingDocs = [];};

private _commandDocs = ["SELECT id, department_key, title, body, created_by_pid, DATE_FORMAT(insert_time,'%Y-%m-%d %H:%i') FROM leo_command_documents WHERE active='1' ORDER BY id DESC LIMIT 40",2,true] call DB_fnc_asyncCall;
if !(_commandDocs isEqualType []) then {_commandDocs = [];};

private _trainingRoster = ["SELECT trainee_pid, trainee_character_uid, department_key, phase, trainer_pid, notes FROM leo_training_roster WHERE active='1' ORDER BY updated_at DESC LIMIT 60",2,true] call DB_fnc_asyncCall;
if !(_trainingRoster isEqualType []) then {_trainingRoster = [];};

[_permissions,_citations,_warrants,_leoRows,_trainingDocs,_trainingRoster,_commandDocs] remoteExecCall ["life_fnc_frameworkDataReceived",_owner];
