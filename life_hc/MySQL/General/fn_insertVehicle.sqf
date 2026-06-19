/*
    File: fn_insertVehicle.sqf
    Author: Bryan "Tonic" Boardwine

    This file is for Nanou's HeadlessClient.

    Description:
    Inserts the vehicle into the database
*/
private ["_query","_sql"];
params [
    "_uid",
    "_side",
    "_type",
    "_className",
    ["_color",-1,[0]],
    ["_plate",-1,[0]],
    ["_characterUid","",[""]]
];

//Stop bad data being passed.
if (_uid isEqualTo "" || _side isEqualTo "" || _type isEqualTo "" || _className isEqualTo "" || _color isEqualTo -1 || _plate isEqualTo -1 || _characterUid isEqualTo "") exitWith {};

_query = format ["INSERT INTO vehicles (side, classname, type, pid, character_uid, alive, active, inventory, color, plate, gear, damage) VALUES ('%1', '%2', '%3', '%4', '%7', '1','1','""[[],0]""', '%5', '%6','""[]""','""[]""')",_side,_className,_type,_uid,_color,_plate,_characterUid];

[_query,1] call HC_fnc_asyncCall;
