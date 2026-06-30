#include "..\..\script_macros.hpp"
/*
    File: fn_openCraftingMenu.sqf
*/
params [
    ["_scope","",[""]],
    ["_source",objNull,[objNull]]
];

if (dialog) exitWith {};
if !(missionNamespace getVariable ["life_crafting_loaded",false]) then {
    [] call life_fnc_craftingInit;
};

_scope = [_scope] call life_fnc_craftingScope;
private _scopeCfg = [_scope] call life_fnc_craftingScopeConfig;
if !(isClass _scopeCfg) exitWith {hint "Crafting is not configured for this role.";};

private _condition = getText (_scopeCfg >> "condition");
if !([_condition] call life_fnc_levelCheck) exitWith {
    hint "You cannot access this crafting bench with your current role or license.";
};

private _accessBlocked = false;
if (!isNull _source && {_source isKindOf "House_F"}) then {
    private _owner = _source getVariable ["house_owner",[]];
    private _owned = (_source in life_vehicles) && {((count _owner) isEqualTo 0) || {(_owner select 0) isEqualTo getPlayerUID player}};
    if (!_owned) then {
        hint localize "STR_Garage_NotOwner";
        _accessBlocked = true;
    };
    if (!_accessBlocked && {!("workbench" in (_source getVariable ["house_upgrades",[]]))}) then {
        hint "Install the workbench upgrade first.";
        _accessBlocked = true;
    };
};
if (_accessBlocked) exitWith {};

missionNamespace setVariable ["life_crafting_scope",_scope];
missionNamespace setVariable ["life_crafting_source",_source];
missionNamespace setVariable ["life_crafting_tab","craft"];
missionNamespace setVariable ["life_crafting_selected",""];

createDialog "life_crafting_menu";
