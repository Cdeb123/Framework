#include "..\..\script_macros.hpp"
/*
    File: fn_characterPreviewStart.sqf

    Description:
    Moves the local player into a black-box preview space and opens a camera.
*/
disableSerialization;
params [
    ["_display",displayNull,[displayNull]]
];

if (isNull _display) exitWith {};
if (!isNil "life_character_preview_camera" && {!isNull life_character_preview_camera}) exitWith {};

life_character_preview_gate = missionNamespace getVariable ["life_character_gate_active",false];
life_character_preview_oldPos = getPosASL player;
life_character_preview_oldDir = getDir player;
life_character_preview_oldBehaviour = behaviour player;
life_character_preview_oldLoadout = getUnitLoadout player;
life_character_preview_committed = false;
life_character_preview_pos = [1000,1000,10000];

private _logic = "Logic" createVehicleLocal life_character_preview_pos;
_logic setPosATL life_character_preview_pos;

private _ut1 = "UserTexture10m_F" createVehicleLocal (_logic modelToWorld [0,5,10]);
_ut1 attachTo [_logic,[0,5,5]];
_ut1 setDir 0;
private _ut2 = "UserTexture10m_F" createVehicleLocal (_logic modelToWorld [5,0,10]);
_ut2 attachTo [_logic,[5,0,5]];
_ut2 setDir 90;
private _ut3 = "UserTexture10m_F" createVehicleLocal (_logic modelToWorld [-5,0,10]);
_ut3 attachTo [_logic,[-5,0,5]];
_ut3 setDir -90;
private _ut4 = "UserTexture10m_F" createVehicleLocal (_logic modelToWorld [0,-5,10]);
_ut4 attachTo [_logic,[0,-5,5]];
_ut4 setDir 180;
private _floor = "UserTexture10m_F" createVehicleLocal (_logic modelToWorld [0,0,10]);
_floor attachTo [_logic,[0,0,0]];
_floor setObjectTexture [0,"a3\map_data\gdt_concrete_co.paa"];
detach _floor;
_floor setVectorDirAndUp [[0,0,-.33],[0,.33,0]];

{
    _x setObjectTexture [0,"#(argb,8,8,3)color(0,0,0,1)"];
} forEach [_ut1,_ut2,_ut3,_ut4];

private _light = "#lightpoint" createVehicleLocal life_character_preview_pos;
_light setLightBrightness 0.65;
_light setLightColor [1,1,1];
_light setLightAmbient [1,1,1];
_light lightAttachObject [_logic,[0,0,1.5]];

life_character_preview_objects = [_logic,_ut1,_ut2,_ut3,_ut4,_floor,_light];

player allowDamage false;
player setBehaviour "SAFE";
player attachTo [_logic,[0,0,0]];
player setDir 180;
player switchMove "";

life_character_preview_camera = "CAMERA" camCreate getPos player;
showCinemaBorder false;
life_character_preview_camera cameraEffect ["Internal","Back"];
life_character_preview_camera camSetTarget (player modelToWorld [0,0,1.25]);
life_character_preview_camera camSetPos (player modelToWorld [0,4.2,1.65]);
life_character_preview_camera camSetFOV 0.34;
life_character_preview_camera camSetFocus [50,0];
life_character_preview_camera camCommit 0;

life_character_preview_evh_zoom = _display displayAddEventHandler ["MouseZChanged", {
    params ["", "_scroll"];
    if (isNil "life_character_preview_camera" || {isNull life_character_preview_camera}) exitWith {};
    private _currentFov = missionNamespace getVariable ["life_character_preview_fov",0.34];
    private _nextFov = (_currentFov - (_scroll * 0.015)) max 0.22 min 0.48;
    life_character_preview_fov = _nextFov;
    life_character_preview_camera camSetFOV _nextFov;
    life_character_preview_camera camCommit 0.1;
}];

[] call life_fnc_characterPreviewUpdate;
