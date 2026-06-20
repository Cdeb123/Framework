/* Sets or toggles the current vehicle indicator state. */
params [
    ["_vehicle",objNull,[objNull]],
    ["_requested","off",[""]]
];
if (isNull _vehicle || {!alive _vehicle} || {!(_vehicle isKindOf "LandVehicle")}) exitWith {false};
if !(driver _vehicle isEqualTo player) exitWith {hint "Only the driver can control the indicators."; false};

private _current = _vehicle getVariable ["life_signal_state","off"];
private _next = ["off",_requested] select !(_current isEqualTo _requested);
_vehicle setVariable ["life_signal_state",_next,true];
[_vehicle,_next] remoteExecCall ["life_fnc_vehicleSignalApply",RCLIENT];

private _label = switch (_next) do {
    case "left": {"Left indicator"};
    case "right": {"Right indicator"};
    case "hazard": {"Hazard lights"};
    default {"Indicators off"};
};
titleText [_label,"PLAIN DOWN"];
true
