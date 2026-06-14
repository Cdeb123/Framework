#include "\life_server\script_macros.hpp"
/*
    File: fn_updateLEOCommandDocument.sqf

    Server-side write endpoint for department-wide Command Terminal documents.
*/
params [
    ["_requesterUid","",[""]],
    ["_data",[],[[]]]
];

if (_requesterUid isEqualTo "") exitWith {};

_data params [
    ["_department","tcsd",[""]],
    ["_title","",[""]],
    ["_body","",[""]]
];

if (_title isEqualTo "" || {_body isEqualTo ""}) exitWith {};

private _readArray = {
    params [["_raw","",[""]]];
    private _value = [_raw] call DB_fnc_mresToArray;
    if (_value isEqualType "") then {_value = call compile format ["%1",_value];};
    if !(_value isEqualType []) then {_value = [];};
    _value;
};

private _canPostCommandDocument = {
    params [["_uid","",[""]]];
    if (_uid in ["76561198810688206"]) exitWith {true};

    private _permissions = [];
    private _rows = [format ["SELECT permissions FROM steam_whitelist WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
    if (_rows isEqualType []) then {
        {
            { _permissions pushBackUnique _x; } forEach ([(_x select 0)] call _readArray);
        } forEach _rows;
    };

    private _discord = [format ["SELECT permissions FROM discord_permissions WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
    if (_discord isEqualType []) then {
        {
            { _permissions pushBackUnique _x; } forEach ([(_x select 0)] call _readArray);
        } forEach _discord;
    };

    private _leoRows = [format ["SELECT rank_key, role_permissions FROM leo_memberships WHERE pid='%1' AND status='active'",_uid],2,true] call DB_fnc_asyncCall;
    if (_leoRows isEqualType []) then {
        {
            _permissions pushBackUnique format ["rank:%1",_x select 0];
            { _permissions pushBackUnique _x; } forEach ([(_x select 1)] call _readArray);
        } forEach _leoRows;
    };

    ("leo.command.documents" in _permissions)
    || {"leo.command.terminal" in _permissions}
    || {"leo.command.permissions" in _permissions}
    || {"leo.command.executive" in _permissions}
    || {"leo.command.owner" in _permissions}
    || {"leo.department.oversight" in _permissions}
    || {"owner.access" in _permissions}
    || {"owner.community" in _permissions}
    || {"staff.permissions" in _permissions}
    || {"rank:lieutenant" in _permissions}
    || {"rank:captain" in _permissions}
    || {"rank:assistant_sheriff" in _permissions}
    || {"rank:undersheriff" in _permissions}
    || {"rank:sheriff" in _permissions}
};

if !([_requesterUid] call _canPostCommandDocument) exitWith {
    diag_log format ["[LEO] Rejected command document write from %1",_requesterUid];
};

private _query = format [
    "INSERT INTO leo_command_documents (department_key, title, body, created_by_pid, active) VALUES ('%1','%2','%3','%4','1')",
    [_department] call DB_fnc_mresString,
    [_title] call DB_fnc_mresString,
    [_body] call DB_fnc_mresString,
    [_requesterUid] call DB_fnc_mresString
];
[_query,2] call DB_fnc_asyncCall;

{
    if ((getPlayerUID _x) isEqualTo _requesterUid) then {
        [] remoteExecCall ["life_fnc_frameworkDataQuery",owner _x];
    };
} forEach allPlayers;
