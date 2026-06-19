/*
    File: fn_vehicleCreate.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Answers the query request to create the vehicle in the database.
*/
private ["_uid","_side","_type","_classname","_color","_plate"];
_uid = [_this,0,"",[""]] call BIS_fnc_param;
_side = [_this,1,sideUnknown,[west]] call BIS_fnc_param;
_vehicle = [_this,2,objNull,[objNull]] call BIS_fnc_param;
_color = [_this,3,-1,[0]] call BIS_fnc_param;
_characterUid = [_this,4,_uid,[""]] call BIS_fnc_param;
private _characterUidPublic = _characterUid;

//Error checks
if (_uid isEqualTo "" || _side isEqualTo sideUnknown || isNull _vehicle) exitWith {};
if (!alive _vehicle) exitWith {};
_className = typeOf _vehicle;
_type = switch (true) do {
    case (_vehicle isKindOf "Car"): {"Car"};
    case (_vehicle isKindOf "Air"): {"Air"};
    case (_vehicle isKindOf "Ship"): {"Ship"};
};

_side = switch (_side) do {
    case west:{"cop"};
    case civilian: {"civ"};
    case independent: {"med"};
    default {"Error"};
};

_characterUid = [_characterUid] call DB_fnc_mresString;
if (_characterUid isEqualTo "") then {_characterUid = _uid;};

_plate = round(random(1000000));
[_uid,_side,_type,_classname,_color,_plate,_characterUid] call DB_fnc_insertVehicle;

_vehicle setVariable ["dbInfo",[_uid,_plate,_characterUid,_side],true];
_vehicle setVariable ["characterUID",_characterUidPublic,true];
_vehicle setVariable ["vehicleSide",_side,true];
