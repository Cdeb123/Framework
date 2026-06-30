/* Safely tears down the rear camera and overlay. */
private _loop = missionNamespace getVariable ["life_backup_camera_loop",scriptNull];
if (!isNull _loop && {!scriptDone _loop}) then {terminate _loop;};
private _camera = missionNamespace getVariable ["life_backup_camera",objNull];
if (!isNull _camera) then {
    _camera cameraEffect ["TERMINATE","BACK"];
    camDestroy _camera;
};
"life_backup_camera_layer" cutText ["","PLAIN"];
life_backup_camera = objNull;
life_backup_camera_vehicle = objNull;
life_backup_camera_loop = scriptNull;
