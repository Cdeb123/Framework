#include "..\..\script_macros.hpp"
/*
    File: fn_citationAddRecord.sqf

    Shared citation record upsert for field use, government review, and MDT.
    Record layout:
    [id,status,issuedAt,date,issuerUID,issuerName,badge,department,rank,targetUID,
     targetCharacterUID,targetName,vehicleDescription,plate,offense,amount,paidAt,declinedAt]
*/
params [
    ["_record",[],[[]]]
];

if (_record isEqualTo [] || {(count _record) < 18}) exitWith {false};

private _id = _record select 0;
private _records = missionNamespace getVariable ["life_citation_records",[]];
private _index = _records findIf {(_x param [0,""]) isEqualTo _id};

if (_index >= 0) then {
    _records set [_index,_record];
} else {
    _records pushBack _record;
};

missionNamespace setVariable ["life_citation_records",_records,true];
publicVariable "life_citation_records";
true;
