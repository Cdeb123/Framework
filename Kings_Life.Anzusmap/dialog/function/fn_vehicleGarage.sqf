#include "..\..\script_macros.hpp"
/*
    File: fn_vehicleGarage.sqf
    Author: Bryan "Tonic" Boardwine
    Updated to Housing/Garage Configs - BoGuu

    Description:
    Vehicle Garage, why did I spawn this in an action its self?
*/
params [
    ["_garageSource",objNull,[objNull,"",[]]],
    ["_type","Car",[""]]
];

private _validGarage = true;
if (_garageSource isEqualType objNull) then {
    if (isNull _garageSource) then {_validGarage = false;};

    if (_validGarage) then {
        private _className = typeOf _garageSource;
        private _houseConfig = missionConfigFile >> "Housing" >> worldName >> _className;
        private _garageConfig = missionConfigFile >> "Garages" >> worldName >> _className;
        private _configs = [_garageConfig,_houseConfig] select {isClass _x};

        if (_configs isEqualTo []) then {
            _validGarage = false;
        } else {
            private _config = _configs select 0;
            private _dir = getNumber (_config >> "garageSpawnDir");
            private _modelPos = getArray (_config >> "garageSpawnPos");

            life_garage_sp = [(_garageSource modelToWorld _modelPos),((getDir _garageSource) + _dir)];
        };
    };
} else {
    life_garage_sp = _garageSource;
};
if (!_validGarage) exitWith {};
life_garage_type = _type;

if (dialog) then {closeDialog 0;};
createDialog "Life_impound_menu";
disableSerialization;
ctrlSetText [2811,"Loading character vehicles..."];

if (life_HC_isActive) then {
    [getPlayerUID player,playerSide,_type,player] remoteExec ["HC_fnc_getVehicles",HC_Life];
} else {
    [getPlayerUID player,playerSide,_type,player] remoteExec ["TON_fnc_getVehicles",RSERV];
};
