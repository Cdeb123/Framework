/*
    File: fn_vehicleHUDToggleGPS.sqf

    Description:
    Toggles the client-side GPS block in the vehicle HUD.
*/
private _cfg = missionConfigFile >> "Life_VehicleHUD";
private _defaultGPS = (getNumber (_cfg >> "defaultGPS")) isEqualTo 1;
private _enabled = !(profileNamespace getVariable ["life_vehicle_gps_enabled",_defaultGPS]);

profileNamespace setVariable ["life_vehicle_gps_enabled",_enabled];
saveProfileNamespace;

[] call life_fnc_hudUpdate;
_enabled
