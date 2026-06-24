/*
    File: fn_spawnPointSelected.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Sorts out the spawn point selected and does a map zoom.
*/
disableSerialization;
private ["_control","_selection","_spCfg","_sp"];
_control = [_this,0,controlNull,[controlNull]] call BIS_fnc_param;
_selection = [_this,1,0,[0]] call BIS_fnc_param;
if (_selection < 0) exitWith {};

_spCfg = [playerSide] call life_fnc_spawnPointCfg;
if (_spCfg isEqualTo [] || {_selection >= count _spCfg}) exitWith {};

_sp = _spCfg select _selection;
life_spawn_point = _sp;

private _display = findDisplay 38500;
if (isNull _display) exitWith {};

_sp params [
    ["_marker","",[""]],
    ["_name","Spawn",[""]],
    ["_icon","",[""]],
    ["_type","Town Center",[""]],
    ["_description","",[""]],
    ["_position",[],[[]]]
];

if (_position isEqualTo [] && {!(_marker isEqualTo "")}) then {
    _position = getMarkerPos _marker;
};

[(_display displayCtrl 38502),0.45,0.075,_position] call life_fnc_setMapPosition;
(_display displayCtrl 38501) ctrlSetText _name;
(_display displayCtrl 38504) ctrlSetText toUpper _type;
(_display displayCtrl 38503) ctrlSetStructuredText parseText format [
    "<t color='#8EE7F0' size='0.95'>%1</t><br/><t color='#EAF7F8' size='0.88'>%2</t>",
    _type,
    _description
];
