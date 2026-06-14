#include "\life_server\script_macros.hpp"
/*
    File: fn_updateLEOTraining.sqf

    Server-side write endpoint for the TCSD Training Terminal.
*/
params [
    ["_requesterUid","",[""]],
    ["_mode","",[""]],
    ["_data",[],[[]]]
];

if (_requesterUid isEqualTo "" || {_mode isEqualTo ""}) exitWith {};

private _readArray = {
    params [["_raw","",[""]]];
    private _value = [_raw] call DB_fnc_mresToArray;
    if (_value isEqualType "") then {_value = call compile format ["%1",_value];};
    if !(_value isEqualType []) then {_value = [];};
    _value;
};

private _canEdit = {
    params [["_uid","",[""]]];
    if (_uid in ["76561198810688206"]) exitWith {true};

    private _permissions = [];
    private _rows = [format ["SELECT permissions FROM steam_whitelist WHERE pid='%1' AND active='1'",_uid],2,true] call DB_fnc_asyncCall;
    if (_rows isEqualType []) then {
        {
            { _permissions pushBackUnique _x; } forEach ([(_x select 0)] call _readArray);
        } forEach _rows;
    };

    private _leoRows = [format ["SELECT rank_key, primary_subdivision, subdivisions, role_permissions FROM leo_memberships WHERE pid='%1' AND status='active'",_uid],2,true] call DB_fnc_asyncCall;
    if (_leoRows isEqualType []) then {
        {
            _permissions pushBackUnique format ["rank:%1",_x select 0];
            _permissions pushBackUnique format ["sub:%1",_x select 1];
            { _permissions pushBackUnique format ["sub:%1",_x]; } forEach ([(_x select 2)] call _readArray);
            { _permissions pushBackUnique _x; } forEach ([(_x select 3)] call _readArray);
        } forEach _leoRows;
    };

    ("leo.training.edit" in _permissions)
    || {"leo.training.roster" in _permissions}
    || {"leo.training.fto" in _permissions}
    || {"leo.command.terminal" in _permissions}
    || {"leo.department.oversight" in _permissions}
    || {"owner.access" in _permissions}
    || {"owner.community" in _permissions}
    || {"staff.permissions" in _permissions}
    || {"sub:academy" in _permissions}
    || {"rank:sergeant" in _permissions}
    || {"rank:lieutenant" in _permissions}
    || {"rank:captain" in _permissions}
    || {"rank:assistant_sheriff" in _permissions}
    || {"rank:undersheriff" in _permissions}
    || {"rank:sheriff" in _permissions}
};

private _rankOrder = {
    params [["_rank","",[""]]];
    private _ranks = ["cadet","deputy","senior_deputy","corporal","detective","sergeant","lieutenant","captain","assistant_sheriff","undersheriff","sheriff"];
    _ranks find _rank;
};

if !([_requesterUid] call _canEdit) exitWith {
    diag_log format ["[LEO] Rejected training terminal write from %1",_requesterUid];
};

switch (_mode) do {
    case "document": {
        _data params [
            ["_department","tcsd",[""]],
            ["_title","",[""]],
            ["_body","",[""]]
        ];
        if (_title isEqualTo "" || {_body isEqualTo ""}) exitWith {};

        private _query = format [
            "INSERT INTO leo_training_documents (department_key, title, body, created_by_pid, active) VALUES ('%1','%2','%3','%4','1')",
            [_department] call DB_fnc_mresString,
            [_title] call DB_fnc_mresString,
            [_body] call DB_fnc_mresString,
            [_requesterUid] call DB_fnc_mresString
        ];
        [_query,2] call DB_fnc_asyncCall;
    };

    case "roster": {
        _data params [
            ["_traineePid","",[""]],
            ["_characterUid","",[""]],
            ["_department","tcsd",[""]],
            ["_phase","Cadet",[""]],
            ["_ftoPid","",[""]],
            ["_notes","",[""]]
        ];
        if (_traineePid isEqualTo "") exitWith {};
        if (_characterUid isEqualTo "") then {_characterUid = _traineePid;};

        private _requesterBestOrder = -1;
        private _requesterOversight = _requesterUid in ["76561198810688206"];
        private _requesterRows = [format ["SELECT rank_key, role_permissions FROM leo_memberships WHERE pid='%1' AND status='active'",_requesterUid],2,true] call DB_fnc_asyncCall;
        if (_requesterRows isEqualType []) then {
            {
                private _rankOrderValue = [_x select 0] call _rankOrder;
                if (_rankOrderValue > _requesterBestOrder) then {_requesterBestOrder = _rankOrderValue;};
                private _rolePerms = [(_x select 1)] call _readArray;
                if (
                    ((_x select 0) in ["sheriff","undersheriff","assistant_sheriff"])
                    || {"leo.department.oversight" in _rolePerms}
                    || {"leo.command.owner" in _rolePerms}
                    || {"staff.permissions" in _rolePerms}
                ) then {
                    _requesterOversight = true;
                };
            } forEach _requesterRows;
        };

        private _traineeBestOrder = -1;
        private _traineeRows = [format ["SELECT rank_key FROM leo_memberships WHERE pid='%1' AND status='active'",_traineePid],2,true] call DB_fnc_asyncCall;
        if (_traineeRows isEqualType []) then {
            {
                private _rankOrderValue = [_x select 0] call _rankOrder;
                if (_rankOrderValue > _traineeBestOrder) then {_traineeBestOrder = _rankOrderValue;};
            } forEach _traineeRows;
        };

        if (!_requesterOversight && {_traineeBestOrder > 0} && {_requesterBestOrder >= 0} && {_traineeBestOrder >= _requesterBestOrder}) exitWith {
            diag_log format ["[LEO] Rejected training roster write from %1 for same-or-higher ranked trainee %2",_requesterUid,_traineePid];
        };

        private _query = format [
            "INSERT INTO leo_training_roster (trainee_pid, trainee_character_uid, department_key, phase, fto_pid, notes, updated_by_pid, active) VALUES ('%1','%2','%3','%4','%5','%6','%7','1') ON DUPLICATE KEY UPDATE phase='%4', fto_pid='%5', notes='%6', updated_by_pid='%7', active='1', updated_at=CURRENT_TIMESTAMP",
            [_traineePid] call DB_fnc_mresString,
            [_characterUid] call DB_fnc_mresString,
            [_department] call DB_fnc_mresString,
            [_phase] call DB_fnc_mresString,
            [_ftoPid] call DB_fnc_mresString,
            [_notes] call DB_fnc_mresString,
            [_requesterUid] call DB_fnc_mresString
        ];
        [_query,2] call DB_fnc_asyncCall;
    };
};

{
    if ((getPlayerUID _x) isEqualTo _requesterUid) then {
        [] remoteExecCall ["life_fnc_frameworkDataQuery",owner _x];
    };
} forEach allPlayers;
