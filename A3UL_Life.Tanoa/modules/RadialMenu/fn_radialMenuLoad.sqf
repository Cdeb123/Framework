#include "..\..\script_macros.hpp"
/*
    File: fn_radialMenuLoad.sqf
*/
disableSerialization;
private _display = findDisplay 9200;
if (isNull _display) exitWith {};

private _sourceActions = missionNamespace getVariable ["life_radial_source_actions",[]];
private _category = missionNamespace getVariable ["life_radial_category","main"];
private _page = missionNamespace getVariable ["life_radial_page",0];
private _actions = [];
private _seenGroups = [];

private _addMenuAction = {
    params [
        ["_title","",[""]],
        ["_subtitle","",[""]],
        ["_type","code",[""]],
        ["_payload",[],[[],objNull,""]],
        ["_group","Menu",[""]],
        ["_priority",0,[0]]
    ];
    if (_title isEqualTo "") exitWith {};
    _actions pushBack [_title,_subtitle,_type,_payload,_group,_priority];
};

if (_category isEqualTo "main") then {
    {
        private _group = _x select 4;
        if !(_group in _seenGroups) then {
            _seenGroups pushBack _group;
        };
    } forEach _sourceActions;

    {
        if (_x in _seenGroups) then {
            private _subtitle = switch (_x) do {
                case "License Shop": {"Permits, driver, boat, pilot, and job licenses"};
                case "Access Shop": {"Markets, clothing, weapons, and vendor access"};
                case "Garage": {"Retrieve, store, and manage vehicles"};
                case "Banking": {"ATM and bank controls"};
                case "Law Enforcement": {"TCSD field and command tools"};
                case "Staff": {"Server staff tools"};
                default {"Nearby context actions"};
            };
            [_x,_subtitle,"category",_x,_x,50] call _addMenuAction;
        };
    } forEach ["License Shop","Access Shop","Garage","Banking","Service","Law Enforcement","Personal","Staff","Nearby"];
} else {
    ["Back","Return to the main radial","category","main","Menu",100] call _addMenuAction;
    {
        if ((_x select 4) isEqualTo _category) then {
            _actions pushBack _x;
        };
    } forEach _sourceActions;
};

if (_actions isEqualTo []) then {
    ["No Actions","Move closer to a vendor, door, vehicle, or terminal","code","hint 'No nearby interactions are available right now.'","Menu",0] call _addMenuAction;
};

life_radial_actions = _actions;

private _pageSize = 8;
private _maxPage = (((count _actions) - 1) max 0) / _pageSize;
_maxPage = floor _maxPage;
if (_page > _maxPage) then {_page = _maxPage; life_radial_page = _page;};
if (_page < 0) then {_page = 0; life_radial_page = 0;};

ctrlSetText [9201,if (_category isEqualTo "main") then {"F1 Menu"} else {_category}];
ctrlSetText [9202,format ["%1 actions | Page %2/%3",count _actions,_page + 1,_maxPage + 1]];

for "_i" from 0 to 7 do {
    private _ctrl = _display displayCtrl (9210 + _i);
    private _actionIndex = (_page * _pageSize) + _i;
    if (_actionIndex < count _actions) then {
        private _action = _actions select _actionIndex;
        _action params [
            ["_title","",[""]],
            ["_subtitle","",[""]]
        ];
        _ctrl ctrlSetText _title;
        _ctrl ctrlSetTooltip _subtitle;
        _ctrl ctrlEnable true;
        _ctrl ctrlSetFade 0;
        _ctrl ctrlSetEventHandler ["ButtonClick",format ["[%1] call life_fnc_radialMenuExecute",_actionIndex]];
    } else {
        _ctrl ctrlSetText "";
        _ctrl ctrlEnable false;
        _ctrl ctrlSetFade 0.65;
        _ctrl ctrlSetEventHandler ["ButtonClick",""];
    };
    _ctrl ctrlCommit 0;
};

(_display displayCtrl 9220) ctrlEnable (_page > 0);
(_display displayCtrl 9221) ctrlEnable (_page < _maxPage);
