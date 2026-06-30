/* Small target-safe wrappers for former vehicle interaction-menu actions. */
params [
    ["_vehicle",objNull,[objNull]],
    ["_mode","",[""]]
];
if (isNull _vehicle || {player distance _vehicle > 10} || {!alive _vehicle}) exitWith {hint "No usable vehicle selected.";};

switch (_mode) do {
    case "push": {[_vehicle] spawn life_fnc_pushObject;};
    case "driver": {
        if (!((crew _vehicle) isEqualTo []) || {!canMove _vehicle} || {locked _vehicle != 0}) exitWith {hint "The driver seat is not available.";};
        player moveInDriver _vehicle;
    };
    case "unflip": {
        if !((crew _vehicle) isEqualTo []) exitWith {hint "The vehicle must be empty.";};
        _vehicle setVectorUp (surfaceNormal (getPosATL _vehicle));
        _vehicle setPosATL ((getPosATL _vehicle) vectorAdd [0,0,0.45]);
        hint "Vehicle righted.";
    };
    case "fuelStop": {
        _vehicle setVariable ["fuelTankWork",nil,true];
        hint "Fuel transfer stopped.";
    };
};
