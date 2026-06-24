/*
    File: fn_craftingVehicleCreate.sqf

    Description:
    Inserts a crafted vehicle into the player's garage without spawning it.
*/
params [
    ["_unit",objNull,[objNull]],
    ["_side",sideUnknown,[west]],
    ["_className","",[""]],
    ["_color",-1,[0]],
    ["_characterUid","",[""]],
    ["_scope","civilian",[""]]
];

if (isNull _unit || {!isPlayer _unit}) exitWith {};
private _uid = getPlayerUID _unit;
if (_uid isEqualTo "" || {_className isEqualTo ""} || {_color < 0}) exitWith {};
if (_characterUid isEqualTo "") then {_characterUid = _uid;};

private _sideString = switch (_side) do {
    case west: {"cop"};
    case civilian: {"civ"};
    case independent: {"med"};
    default {"Error"};
};
if (_sideString isEqualTo "Error") exitWith {};

private _scopeKey = toLower _scope;
_scopeKey = switch (_scopeKey) do {
    case "civ": {"civilian"};
    case "cop": {"leo"};
    case "police": {"leo"};
    case "lawenforcement": {"leo"};
    case "law_enforcement": {"leo"};
    default {_scopeKey};
};
if !(_scopeKey in ["civilian","rebel","leo"]) exitWith {};

private _scopeClass = switch (_scopeKey) do {
    case "leo": {"LawEnforcement"};
    case "rebel": {"Rebel"};
    default {"Civilian"};
};
private _scopeCfg = missionConfigFile >> "Life_Crafting" >> _scopeClass;
if !(isClass _scopeCfg) exitWith {};
if !((getText (_scopeCfg >> "side")) isEqualTo _sideString) exitWith {};

private _recipeIndex = ("true" configClasses (_scopeCfg >> "Recipes")) findIf {
    (toLower getText (_x >> "outputType")) isEqualTo "vehicle" && {(getText (_x >> "outputClass")) isEqualTo _className}
};
if (_recipeIndex < 0) exitWith {};

private _vehicleCfg = configFile >> "CfgVehicles" >> _className;
if !(isClass _vehicleCfg) exitWith {};

private _inheritsFrom = {
    params ["_cfg","_baseClass"];
    private _current = _cfg;
    private _found = false;
    while {isClass _current && {!_found}} do {
        if ((configName _current) isEqualTo _baseClass) exitWith {_found = true;};
        _current = inheritsFrom _current;
    };
    _found
};

private _type = switch (true) do {
    case ([_vehicleCfg,"Car"] call _inheritsFrom): {"Car"};
    case ([_vehicleCfg,"Air"] call _inheritsFrom): {"Air"};
    case ([_vehicleCfg,"Ship"] call _inheritsFrom): {"Ship"};
    default {""};
};
if (_type isEqualTo "") exitWith {};

private _garageSide = getText (_scopeCfg >> "vehicleGarageSide");
if (_garageSide isEqualTo "") then {_garageSide = _sideString;};

private _plate = round (random 1000000);
private _displayName = getText (_vehicleCfg >> "displayName");
if (_displayName isEqualTo "") then {_displayName = _className;};

private _garageSideSql = [_garageSide] call DB_fnc_mresString;
private _classSql = [_className] call DB_fnc_mresString;
private _typeSql = [_type] call DB_fnc_mresString;
private _uidSql = [_uid] call DB_fnc_mresString;
private _characterSql = [_characterUid] call DB_fnc_mresString;

private _query = format [
    "INSERT INTO vehicles (side, classname, type, pid, character_uid, alive, active, inventory, color, plate, gear, damage) VALUES ('%1', '%2', '%3', '%4', '%5', '1', '0', '""[[],0]""', '%6', '%7', '""[]""', '""[]""')",
    _garageSideSql,
    _classSql,
    _typeSql,
    _uidSql,
    _characterSql,
    _color,
    _plate
];
[_query,1] call DB_fnc_asyncCall;

private _ownerId = if (remoteExecutedOwner > 0) then {remoteExecutedOwner} else {owner _unit};
[1,format ["Your crafted %1 is now available in your garage.",_displayName]] remoteExecCall ["life_fnc_broadcast",_ownerId];
