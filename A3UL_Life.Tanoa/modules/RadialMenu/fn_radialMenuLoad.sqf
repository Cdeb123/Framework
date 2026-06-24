#include "..\..\script_macros.hpp"
/*
    File: fn_radialMenuLoad.sqf

    Populates the eight positions of the native circular interaction wheel.
*/
disableSerialization;
private _display = findDisplay 9200;
if (isNull _display) exitWith {};

private _sourceActions = missionNamespace getVariable ["life_radial_source_actions",[]];
private _category = missionNamespace getVariable ["life_radial_category","quick"];
private _page = missionNamespace getVariable ["life_radial_page",0];
private _actions = [];
private _seenGroups = [];

private _categoryDetails = {
    params [["_group","",[""]]];
    switch (_group) do {
        case "Personal": {"ID, inventory, status, and quick self actions"};
        case "Vehicle": {"Locks, storage, GPS, camera, and repairs"};
        case "Door": {"Nearby building access, keycards, and keypads"};
        case "House": {"Owned doors, storage, garage, and improvements"};
        case "House Upgrades": {"Workbench, security, and home improvements"};
        case "Items": {"Ground items, containers, gathering, and equipment"};
        case "Civilian": {"Civilian roleplay and nearby player actions"};
        case "Law Enforcement": {"Field, vehicle, custody, and command tools"};
        case "EMS": {"Patient care, recovery, and medical response tools"};
        case "License Shop": {"Permits, vehicle licenses, and professional licenses"};
        case "Access Shop": {"Markets, clothing, weapons, and nearby vendors"};
        case "Garage": {"Retrieve, store, return, and manage vehicles"};
        case "Banking": {"ATM and account controls"};
        case "Service": {"Fuel, repair, hospital, and public counters"};
        case "Department of Justice": {"Citation review and justice records"};
        case "Staff": {"Authorized server staff tools"};
        default {"Context-sensitive interactions near your character"};
    };
};

private _iconFor = {
    params [
        ["_title","",[""]],
        ["_group","",[""]]
    ];
    private _lower = toLower format ["%1 %2",_title,_group];
    if (["back",_lower] call BIS_fnc_inString) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\navigate_ca.paa"};
    if ((["ems",_lower] call BIS_fnc_inString) || {["heal",_lower] call BIS_fnc_inString} || {["revive",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa"};
    if ((["law",_lower] call BIS_fnc_inString) || {["citation",_lower] call BIS_fnc_inString} || {["police",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\defend_ca.paa"};
    if (["gps",_lower] call BIS_fnc_inString) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\map_ca.paa"};
    if ((["vehicle",_lower] call BIS_fnc_inString) || {["trunk",_lower] call BIS_fnc_inString} || {["signal",_lower] call BIS_fnc_inString} || {["camera",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\map\vehicleicons\iconCar_ca.paa"};
    if ((["house",_lower] call BIS_fnc_inString) || {["door",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\interact_ca.paa"};
    if (["mine",_lower] call BIS_fnc_inString) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\mine_ca.paa"};
    if ((["gather",_lower] call BIS_fnc_inString) || {["harvest",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa"};
    if ((["bank",_lower] call BIS_fnc_inString) || {["atm",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\documents_ca.paa"};
    if ((["repair",_lower] call BIS_fnc_inString) || {["service",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa"};
    if ((["item",_lower] call BIS_fnc_inString) || {["storage",_lower] call BIS_fnc_inString} || {["pickup",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa"};
    if ((["personal",_lower] call BIS_fnc_inString) || {["civilian",_lower] call BIS_fnc_inString} || {[" id",_lower] call BIS_fnc_inString}) exitWith {"\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa"};
    "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa"
};

if (_category isEqualTo "quick") then {
    private _seenActions = [];
    private _quickCandidates = [];
    {
        private _title = _x param [0,"",[""]];
        private _type = _x param [2,"code",[""]];
        if !(_type isEqualTo "category" || {_title isEqualTo ""}) then {
            private _action = +_x;
            private _group = _action param [4,"Nearby",[""]];
            if (_group isEqualTo "House Upgrades") then {
                _action set [5,((_action param [5,0,[0]]) min 34)];
            };
            _quickCandidates pushBack _action;
        };
    } forEach _sourceActions;
    _quickCandidates = [_quickCandidates,[],{_x param [5,0,[0]]},"DESCEND"] call BIS_fnc_sortBy;
    {
        private _title = _x param [0,"",[""]];
        if !(_title in _seenActions) then {
            _seenActions pushBack _title;
            _actions pushBack _x;
        };
    } forEach _quickCandidates;
} else {
if (_category isEqualTo "main") then {
    {
        private _group = _x select 4;
        if !(_group in _seenGroups) then {_seenGroups pushBack _group;};
    } forEach _sourceActions;

    {
        if (_x in _seenGroups) then {
            _actions pushBack [_x,[_x] call _categoryDetails,"category",_x,_x,50,[_x,_x] call _iconFor];
        };
    } forEach ["Personal","Vehicle","Door","House","House Upgrades","Items","Civilian","Law Enforcement","EMS","License Shop","Access Shop","Garage","Banking","Service","Department of Justice","Staff","Nearby"];
} else {
    {
        if ((_x select 4) isEqualTo _category) then {_actions pushBack _x;};
    } forEach _sourceActions;
    _actions = [_actions,[],{_x param [5,0,[0]]},"DESCEND"] call BIS_fnc_sortBy;
};
};

if (_actions isEqualTo []) then {
    _actions pushBack ["No Actions","Move closer to a person, vehicle, door, vendor, or terminal","code","hint 'No nearby interactions are available right now.'","Nearby",0,"\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa"];
};

for "_i" from 0 to ((count _actions) - 1) do {
    private _action = _actions select _i;
    if ((count _action) < 7) then {
        _action pushBack ([_action param [0,"",[""]],_action param [4,"Nearby",[""]]] call _iconFor);
        _actions set [_i,_action];
    };
};
life_radial_actions = _actions;
private _pageSize = 8;
private _maxPage = floor ((((count _actions) - 1) max 0) / _pageSize);
if (_page > _maxPage) then {_page = _maxPage; life_radial_page = _page;};
if (_page < 0) then {_page = 0; life_radial_page = 0;};

for "_i" from 0 to 7 do {
    private _button = _display displayCtrl (9210 + _i);
    private _iconCtrl = _display displayCtrl (9230 + _i);
    private _labelCtrl = _display displayCtrl (9240 + _i);
    private _keyCtrl = _display displayCtrl (9250 + _i);
    private _backCtrl = _display displayCtrl (9260 + _i);
    private _edgeCtrl = _display displayCtrl (9270 + _i);
    private _actionIndex = (_page * _pageSize) + _i;

    if (_actionIndex < count _actions) then {
        private _action = _actions select _actionIndex;
        _action params [
            ["_title","",[""]],
            ["_subtitle","",[""]],
            ["_type","code",[""]],
            ["_payload",[],[[],objNull,""]],
            ["_group","Nearby",[""]]
        ];
        private _icon = _action param [6,[_title,_group] call _iconFor,[""]];
        private _wheelLabel = switch (_title) do {
            case "Lock / Unlock": {"LOCK /<br/>UNLOCK"};
            case "Lock / Unlock Door": {"DOOR<br/>LOCK"};
            case "Open Trunk": {"OPEN<br/>TRUNK"};
            case "Repair Vehicle": {"REPAIR<br/>VEHICLE"};
            case "GPS Display": {"GPS<br/>DISPLAY"};
            case "Backup Camera": {"REAR<br/>CAMERA"};
            case "Vehicle Registration": {"VEHICLE<br/>REG."};
            case "Search Vehicle": {"SEARCH<br/>VEHICLE"};
            case "Impound Vehicle": {"IMPOUND<br/>VEHICLE"};
            case "Assess Patient": {"ASSESS<br/>PATIENT"};
            case "Revive Patient": {"REVIVE<br/>PATIENT"};
            case "Law Enforcement": {"LEO"};
            case "Department of Justice": {"JUSTICE"};
            case "House Upgrades": {"HOUSE<br/>UPGRADES"};
            case "License Shop": {"LICENSES"};
            case "Access Shop": {"SHOPS"};
            default {
                private _words = (toUpper _title) splitString " ";
                if ((count _words) <= 1) then {
                    private _single = toUpper _title;
                    if ((count _single) > 14) then {_single = (_single select [0,12]) + ".";};
                    _single
                } else {
                    private _line1 = "";
                    private _line2 = "";
                    private _targetLength = ceil ((count _title) / 2);
                    {
                        private _candidate = _line1 + ([""," "] select !(_line1 isEqualTo "")) + _x;
                        if ((count _candidate) <= _targetLength || {_line1 isEqualTo ""}) then {
                            _line1 = _candidate;
                        } else {
                            _line2 = _line2 + ([""," "] select !(_line2 isEqualTo "")) + _x;
                        };
                    } forEach _words;
                    if ((count _line1) > 14) then {_line1 = (_line1 select [0,12]) + ".";};
                    if ((count _line2) > 14) then {_line2 = (_line2 select [0,12]) + ".";};
                    format ["%1<br/>%2",_line1,_line2]
                };
            };
        };
        _labelCtrl ctrlSetStructuredText parseText format ["<t align='center' color='#eefaff'>%1</t>",_wheelLabel];
        _iconCtrl ctrlSetText _icon;
        _button ctrlSetTooltip _subtitle;
        _button ctrlEnable true;
        _button ctrlSetEventHandler ["ButtonClick",format ["[%1] call life_fnc_radialMenuExecute",_actionIndex]];
        _iconCtrl ctrlSetFade 0;
        _labelCtrl ctrlSetFade 0;
        _keyCtrl ctrlSetFade 0;
        _backCtrl ctrlSetFade 0;
        _edgeCtrl ctrlSetFade 0;
        _backCtrl ctrlSetTextColor [0.018,0.038,0.049,0.96];
        _edgeCtrl ctrlSetTextColor [0.20,0.68,0.86,0.62];
    } else {
        _labelCtrl ctrlSetStructuredText parseText "";
        _iconCtrl ctrlSetText "";
        _button ctrlSetTooltip "";
        _button ctrlEnable false;
        _button ctrlSetEventHandler ["ButtonClick",""];
        _iconCtrl ctrlSetFade 1;
        _labelCtrl ctrlSetFade 1;
        _keyCtrl ctrlSetFade 1;
        _backCtrl ctrlSetFade 0.78;
        _edgeCtrl ctrlSetFade 1;
        _backCtrl ctrlSetTextColor [0.015,0.025,0.030,0.36];
    };
    {_x ctrlCommit 0;} forEach [_button,_iconCtrl,_labelCtrl,_keyCtrl,_backCtrl,_edgeCtrl];
};

(_display displayCtrl 9220) ctrlEnable (_page > 0);
(_display displayCtrl 9221) ctrlEnable (_page < _maxPage);
(_display displayCtrl 9204) ctrlSetText format ["PAGE %1 / %2  |  %3 ACTIONS",_page + 1,_maxPage + 1,count _actions];
life_radial_hover = 0;
if !(_actions isEqualTo []) then {
    [0] call life_fnc_radialMenuHover;
    ctrlSetFocus (_display displayCtrl 9210);
} else {
    [-1] call life_fnc_radialMenuHover;
};
