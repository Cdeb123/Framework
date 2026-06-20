/* Toggles detected vehicle door animation sources. */
params [
    ["_vehicle",objNull,[objNull]],
    ["_mode","driver",[""]]
];
if (isNull _vehicle || {!alive _vehicle}) exitWith {hint "No usable vehicle selected.";};
if !(_vehicle isKindOf "LandVehicle") exitWith {hint "Door controls are only available on land vehicles.";};
if (vehicle player != _vehicle && {player distance _vehicle > 7}) exitWith {hint "Move closer to the vehicle.";};
if (locked _vehicle isEqualTo 2 && {!(_vehicle in life_vehicles)}) exitWith {hint "That vehicle is locked.";};

private _containsAny = {
    params [["_value","",[""]],["_terms",[],[[]]]];
    (_terms findIf {[_x,_value] call BIS_fnc_inString}) >= 0
};
private _sources = [];
{
    private _source = configName _x;
    private _lower = toLower _source;
    if ([_lower,["door","hood","bonnet","boot","trunk"]] call _containsAny) then {
        _sources pushBackUnique _source;
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AnimationSources"));

{
    _sources pushBackUnique _x;
} forEach ["door_back_R","door_back_L","door_R","door_L","Door_L_source","Door_rear","Door_rear_source","Door_1_source","Door_2_source","Door_3_source","Door_LF","Door_RF","Door_LB","Door_RB","DoorL_Front_Open","DoorR_Front_Open","DoorL_Back_Open","DoorR_Back_Open"];

private _selected = switch (_mode) do {
    case "all": {_sources select {private _n = toLower _x; !([_n,["hood","bonnet","boot","trunk"]] call _containsAny)}};
    case "hood": {_sources select {private _n = toLower _x; [_n,["hood","bonnet"]] call _containsAny}};
    case "trunk": {_sources select {private _n = toLower _x; [_n,["boot","trunk"]] call _containsAny}};
    default {
        private _driver = _sources select {
            private _n = toLower _x;
            [_n,["driver","door_l","doorlf","left_front","front_left"]] call _containsAny
        };
        if (_driver isEqualTo [] && {!(_sources isEqualTo [])}) then {_driver = [_sources select 0];};
        _driver
    };
};

if (_selected isEqualTo []) exitWith {hint "This vehicle does not expose that door animation.";};
private _open = (_selected findIf {(_vehicle animationSourcePhase _x) < 0.5}) >= 0;
private _phase = [0,1] select _open;
{
    _vehicle animateDoor [_x,_phase];
    _vehicle animateSource [_x,_phase,true];
} forEach _selected;
titleText [format ["%1 %2",["Closed","Opened"] select _open,if (_mode isEqualTo "all") then {"vehicle doors"} else {"vehicle door"}],"PLAIN DOWN"];
