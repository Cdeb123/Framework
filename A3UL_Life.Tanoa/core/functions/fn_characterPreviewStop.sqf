#include "..\..\script_macros.hpp"
/*
    File: fn_characterPreviewStop.sqf
*/
disableSerialization;
private _gate = missionNamespace getVariable ["life_character_gate_active",false];
private _display = findDisplay 7800;

if (!isNil "life_character_preview_camera" && {!isNull life_character_preview_camera}) then {
    life_character_preview_camera cameraEffect ["TERMINATE","BACK"];
    camDestroy life_character_preview_camera;
};

if (!isNil "life_character_preview_evh_zoom" && {!isNull _display}) then {
    _display displayRemoveEventHandler ["MouseZChanged",life_character_preview_evh_zoom];
};

detach player;

if (!_gate && {!isNil "life_character_preview_oldPos"}) then {
    player allowDamage true;
    if !(missionNamespace getVariable ["life_character_preview_committed",false]) then {
        player setUnitLoadout life_character_preview_oldLoadout;
    };
    player setPosASL life_character_preview_oldPos;
    player setDir life_character_preview_oldDir;
    player setBehaviour life_character_preview_oldBehaviour;
} else {
    player allowDamage false;
    player setVelocity [0,0,0];
    player setPosATL [1000,1000,10000];
};

{
    deleteVehicle _x;
} forEach (missionNamespace getVariable ["life_character_preview_objects",[]]);

life_character_preview_camera = objNull;
life_character_preview_objects = [];
life_character_preview_evh_zoom = nil;
life_character_preview_fov = nil;
life_character_preview_committed = false;
