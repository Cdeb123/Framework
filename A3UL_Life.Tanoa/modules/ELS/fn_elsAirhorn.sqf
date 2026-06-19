#include "..\..\script_macros.hpp"
/*
    File: fn_elsAirhorn.sqf
*/
params [
    ["_vehicle",objNull,[objNull]]
];

if (isNull _vehicle || {_vehicle isEqualTo player}) exitWith {false};
if !(driver _vehicle isEqualTo player) exitWith {false};
if (missionNamespace getVariable ["life_els_airhorn_active",false]) exitWith {true};

private _configData = [_vehicle] call life_fnc_elsGetConfig;
_configData params [
    ["_vehicleCfg",configNull,[configNull]],
    ["_profile","",[""]]
];
if (_vehicleCfg isEqualTo configNull || {_profile isEqualTo ""}) exitWith {false};

private _profileCfg = missionConfigFile >> "Life_ELS" >> "Profiles" >> _profile;
private _cooldown = getNumber (_profileCfg >> "airhornCooldown");
if (_cooldown <= 0) then {_cooldown = 1;};

life_els_airhorn_active = true;
[_cooldown] spawn {
    params [["_delay",1,[0]]];
    sleep _delay;
    life_els_airhorn_active = false;
};

private _fallbackSound = getText (_profileCfg >> "fallbackAirhornSound");
if !(_fallbackSound isEqualTo "") exitWith {
    [
        _vehicle,
        _fallbackSound,
        getNumber (_profileCfg >> "fallbackAirhornDistance"),
        getNumber (_profileCfg >> "fallbackAirhornPitch")
    ] remoteExec ["life_fnc_say3D",RANY];
    true;
};

private _vehicleWeapons = weapons _vehicle;
if (_vehicleWeapons isEqualTo []) then {
    _vehicleWeapons = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "weapons");
};

private _wantedWeapons = getArray (_profileCfg >> "airhornWeapons");
private _weaponIndex = -1;
{
    private _index = _vehicleWeapons find _x;
    if (_index >= 0) exitWith {_weaponIndex = _index;};
} forEach _wantedWeapons;

if (_weaponIndex < 0) then {
    _weaponIndex = _vehicleWeapons findIf {
        private _weapon = toLower _x;
        (["horn",_weapon] call BIS_fnc_inString) || {["airhorn",_weapon] call BIS_fnc_inString}
    };
};

if (_weaponIndex >= 0) exitWith {
    player action ["UseWeapon",_vehicle,player,_weaponIndex];
    true;
};

true;
