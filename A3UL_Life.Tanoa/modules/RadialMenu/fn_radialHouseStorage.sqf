#include "..\..\script_macros.hpp"
/*
    File: fn_radialHouseStorage.sqf

    House storage shortcuts for the F1 menu.
*/
params [
    ["_house",objNull,[objNull]],
    ["_mode","open",[""]],
    ["_container",objNull,[objNull]]
];

private _ownHouse = {
    params [["_target",objNull,[objNull]]];
    if (isNull _target) exitWith {false};
    if !(_target in life_vehicles) exitWith {false};
    private _owner = _target getVariable ["house_owner",[]];
    (count _owner) isEqualTo 0 || {(_owner select 0) isEqualTo getPlayerUID player}
};

switch (_mode) do {
    case "open": {
        if (isNull _container) then {
            private _near = ((ASLtoATL (getPosASL player)) nearEntities [["Box_IND_Grenades_F","B_supplyCrate_F"],2.5]);
            if !(_near isEqualTo []) then {_container = _near select 0;};
        };

        if (isNull _container) exitWith {hint "No storage crate nearby.";};
        private _storageHouse = nearestObject [(ASLtoATL (getPosASL _container)),"House"];
        if (_storageHouse getVariable ["locked",false]) exitWith {hint localize "STR_House_ContainerDeny";};
        [_container] spawn life_fnc_openInventory;
    };

    case "lock": {
        if (isNull _house) exitWith {hint localize "STR_House_Door_NotNear";};
        if !([_house] call _ownHouse) exitWith {hint localize "STR_Garage_NotOwner";};
        [_house] call life_fnc_lockHouse;
    };

    case "small": {
        if (isNull _house) exitWith {hint localize "STR_ISTR_Box_NotinHouse";};
        if !([_house] call _ownHouse) exitWith {hint localize "STR_Garage_NotOwner";};
        if ((missionNamespace getVariable ["life_inv_storagesmall",0]) <= 0) exitWith {hint "You need a small storage crate.";};
        [false] call life_fnc_storageBox;
    };

    case "big": {
        if (isNull _house) exitWith {hint localize "STR_ISTR_Box_NotinHouse";};
        if !([_house] call _ownHouse) exitWith {hint localize "STR_Garage_NotOwner";};
        if ((missionNamespace getVariable ["life_inv_storagebig",0]) <= 0) exitWith {hint "You need a large storage crate.";};
        [true] call life_fnc_storageBox;
    };
};

