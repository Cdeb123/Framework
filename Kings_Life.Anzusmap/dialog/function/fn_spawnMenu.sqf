/*
    File: fn_spawnMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Initializes the spawn point selection menu.
*/
private ["_spCfg","_sp","_ctrl"];
disableSerialization;

if (life_is_arrested) exitWith {
    [] call life_fnc_respawned;
};

if (life_respawned) then {
    [] call life_fnc_respawned;
};
cutText["","BLACK FADED"];
0 cutFadeOut 9999999;
if (!(createDialog "life_spawn_selection")) exitWith {[] call life_fnc_spawnMenu;};
(findDisplay 38500) displaySetEventHandler ["keyDown","_this call life_fnc_displayHandler"];

_spCfg = [playerSide] call life_fnc_spawnPointCfg;
if (_spCfg isEqualTo []) exitWith {
    closeDialog 0;
    hint "No spawn points are available for your faction.";
};

_ctrl = ((findDisplay 38500) displayCtrl 38510);
{
    _x params [
        ["_marker","",[""]],
        ["_name","Spawn",[""]],
        ["_icon","",[""]],
        ["_type","Town Center",[""]]
    ];

    _ctrl lnbAddRow["",_name,_type];
    _ctrl lnbSetPicture[[_ForEachIndex,0],_icon];
    _ctrl lnbSetData[[_ForEachIndex,0],_marker];
} forEach _spCfg;

_sp = _spCfg select 0; //First option is set by default

life_spawn_point = _sp;

ctrlSetText[38505,format ["%1 AVAILABLE",count _spCfg]];
_ctrl lnbSetCurSelRow 0;
[_ctrl,0] call life_fnc_spawnPointSelected;
