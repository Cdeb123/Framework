#include "\life_server\script_macros.hpp"
/*
    File: fn_updateLEOMembership.sqf

    Server-side write endpoint for the KCSO/LEO Command Terminal.
*/
params [
    ["_requesterUid","",[""]],
    ["_targetUid","",[""]],
    ["_targetName","",[""]],
    ["_characterUid","",[""]],
    ["_department","kcso",[""]],
    ["_rank","probationary_deputy",[""]],
    ["_primarySubdivision","admin_services",[""]],
    ["_subdivisions",[],[[]]],
    ["_rolePermissions",[],[[]]],
    ["_status","active",[""]]
];

if (_requesterUid isEqualTo "" || {_targetUid isEqualTo ""}) exitWith {};
if !(_status in ["active","fired","suspended"]) then {_status = "active";};
if (_characterUid isEqualTo "") then {_characterUid = _targetUid;};
if !(_primarySubdivision in _subdivisions) then {_subdivisions pushBack _primarySubdivision;};

private _readArray = {
    params [["_raw","",[""]]];
    private _value = [_raw] call DB_fnc_mresToArray;
    if (_value isEqualType "") then {_value = call compile format ["%1",_value];};
    if !(_value isEqualType []) then {_value = [];};
    _value;
};

private _canCommand = {
    params [["_uid","",[""]]];

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

    ("leo.command.terminal" in _permissions)
    || {"leo.command.hire" in _permissions}
    || {"leo.command.fire" in _permissions}
    || {"leo.command.permissions" in _permissions}
    || {"leo.command.ranks" in _permissions}
    || {"leo.command.divisions" in _permissions}
    || {"leo.command.roles" in _permissions}
    || {"leo.command.documents" in _permissions}
    || {"leo.command.executive" in _permissions}
    || {"leo.department.oversight" in _permissions}
    || {"staff.permissions" in _permissions}
    || {"rank:lieutenant" in _permissions}
    || {"rank:captain" in _permissions}
    || {"rank:major" in _permissions}
    || {"rank:undersheriff" in _permissions}
    || {"rank:sheriff" in _permissions}
    || {"rank:commissioner" in _permissions}
};

if !([_requesterUid] call _canCommand) exitWith {
    diag_log format ["[LEO] Rejected command terminal write from %1 for %2",_requesterUid,_targetUid];
};

private _safeTarget = [_targetUid] call DB_fnc_mresString;
private _safeName = [_targetName] call DB_fnc_mresString;
private _safeCharacter = [_characterUid] call DB_fnc_mresString;
private _safeDepartment = [_department] call DB_fnc_mresString;
private _safeRank = [_rank] call DB_fnc_mresString;
private _safePrimary = [_primarySubdivision] call DB_fnc_mresString;
private _safeStatus = [_status] call DB_fnc_mresString;
private _safeRequester = [_requesterUid] call DB_fnc_mresString;
private _safeSubdivisions = [_subdivisions] call DB_fnc_mresArray;
private _safePermissions = [_rolePermissions] call DB_fnc_mresArray;

private _query = format [
    "INSERT INTO leo_memberships (pid, character_uid, department_key, rank_key, primary_subdivision, subdivisions, role_permissions, status, hired_by_pid, updated_by_pid, notes) VALUES ('%1','%2','%3','%4','%5','%6','%7','%8','%9','%9','%10') ON DUPLICATE KEY UPDATE rank_key='%4', primary_subdivision='%5', subdivisions='%6', role_permissions='%7', status='%8', updated_by_pid='%9', notes='%10', updated_at=CURRENT_TIMESTAMP",
    _safeTarget,
    _safeCharacter,
    _safeDepartment,
    _safeRank,
    _safePrimary,
    _safeSubdivisions,
    _safePermissions,
    _safeStatus,
    _safeRequester,
    _safeName
];
[_query,2] call DB_fnc_asyncCall;

{
    if ((getPlayerUID _x) in [_targetUid,_requesterUid]) then {
        [] remoteExecCall ["life_fnc_frameworkDataQuery",owner _x];
    };
} forEach allPlayers;
