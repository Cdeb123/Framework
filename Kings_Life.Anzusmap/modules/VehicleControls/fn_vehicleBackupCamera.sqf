/* Toggles a non-blocking rear-view render target for configured vehicles. */
params [["_vehicle",objNull,[objNull]]];
if (!isNull (missionNamespace getVariable ["life_backup_camera",objNull])) exitWith {
    [] call life_fnc_vehicleBackupCameraStop;
};
if (isNull _vehicle) then {_vehicle = vehicle player;};
if (isNull _vehicle || {_vehicle isEqualTo player} || {!alive _vehicle}) exitWith {hint "Enter a supported vehicle first.";};
if !(driver _vehicle isEqualTo player) exitWith {hint "The backup camera is available to the driver.";};

private _allowedClasses = getArray (missionConfigFile >> "Life_VehicleControls" >> "backupCameraVehicles");
if !((typeOf _vehicle) in _allowedClasses || {_vehicle getVariable ["life_backup_camera",false]}) exitWith {
    hint "This vehicle is not fitted with a backup camera.";
};

"life_backup_camera_layer" cutRsc ["life_backup_camera_display","PLAIN",0.15,false];
private _camera = "camera" camCreate getPosATL _vehicle;
_camera cameraEffect ["Internal","Back","lifebackuprender"];
_camera camSetFOV 0.82;
_camera camCommit 0;
life_backup_camera = _camera;
life_backup_camera_vehicle = _vehicle;

life_backup_camera_loop = [_camera,_vehicle] spawn {
    params ["_cam","_veh"];
    private _box = boundingBoxReal _veh;
    private _min = _box select 0;
    private _rearY = (_min select 1) - 0.20;
    private _height = ((_min select 2) + 1.05) max 0.75;
    while {!isNull _cam && {alive player} && {alive _veh} && {driver _veh isEqualTo player} && {vehicle player isEqualTo _veh}} do {
        _cam setPosASL (AGLToASL (_veh modelToWorld [0,_rearY,_height]));
        _cam camSetTarget (_veh modelToWorld [0,_rearY - 12,0.55]);
        _cam camCommit 0;
        uiSleep 0.03;
    };
    life_backup_camera_loop = scriptNull;
    [] call life_fnc_vehicleBackupCameraStop;
};
