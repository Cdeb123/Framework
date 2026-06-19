#include "..\..\script_macros.hpp"
/*
    File: fn_citationRecords.sqf

    Returns citation records for LEO tooling and the upcoming MDT.
*/
params [
    ["_nameFilter","",[""]]
];

private _records = +(missionNamespace getVariable ["life_citation_records",[]]);
private _filter = toLower _nameFilter;

if !(_filter isEqualTo "") then {
    _records = _records select {
        private _targetName = toLower (_x param [11,"",[""]]);
        private _plate = toLower (_x param [13,"",[""]]);
        private _offense = toLower (_x param [14,"",[""]]);
        ([_filter,_targetName] call BIS_fnc_inString)
        || {[_filter,_plate] call BIS_fnc_inString}
        || {[_filter,_offense] call BIS_fnc_inString}
    };
};

reverse _records;
_records;
