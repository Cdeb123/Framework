#include "..\..\script_macros.hpp"
/*
    File: fn_craftingRecipeAllowed.sqf
*/
params [
    ["_recipe",configNull,[configNull]],
    ["_scope","",[""]],
    ["_notify",false,[false]]
];

if (isNull _recipe) exitWith {false};
_scope = [_scope] call life_fnc_craftingScope;
private _scopeCfg = [_scope] call life_fnc_craftingScopeConfig;
if !(isClass _scopeCfg) exitWith {false};

private _allowed = true;
private _message = "";

private _scopeCondition = getText (_scopeCfg >> "condition");
if !([_scopeCondition] call life_fnc_levelCheck) then {
    _allowed = false;
    _message = "This crafting bench is not available to your current role.";
};

private _condition = getText (_recipe >> "condition");
if (_allowed && {!([_condition] call life_fnc_levelCheck)}) then {
    _allowed = false;
    _message = "You do not meet this recipe's license or condition requirement.";
};

private _requiredLevel = getNumber (_recipe >> "requiredLevel");
if (_requiredLevel < 1) then {
    private _group = getText (_recipe >> "craftingGroup");
    if !(_group isEqualTo "") then {
        _requiredLevel = getNumber (missionConfigFile >> "Life_Progression" >> "CraftingRequirements" >> _group >> "requiredLevel");
    };
};
if (_requiredLevel < 1) then {_requiredLevel = 1;};

private _craftLevel = (["crafting"] call life_fnc_progressionLevelInfo) param [0,1,[0]];
if (_allowed && {_craftLevel < _requiredLevel}) then {
    _allowed = false;
    _message = format ["Crafting level %1 is required.",_requiredLevel];
};

if (_allowed && {_scope isEqualTo "leo"}) then {
    private _department = getText (_scopeCfg >> "department");
    private _rank = getText (_recipe >> "rank");
    if (!(_rank isEqualTo "") && {!([_rank,_department] call life_fnc_leoAtLeastRank)}) then {
        _allowed = false;
        _message = format ["LEO rank '%1' is required.",_rank];
    };

    private _subdivisions = getArray (_recipe >> "subdivisions");
    if (_allowed && {!(_subdivisions isEqualTo [])}) then {
        private _subOk = false;
        {
            if ([_x,_department] call life_fnc_leoHasSubdivision) exitWith {_subOk = true;};
        } forEach _subdivisions;
        if (!_subOk) then {
            _allowed = false;
            _message = "This recipe is restricted to a different LEO role or subdivision.";
        };
    };

    private _permissions = getArray (_recipe >> "rolePermissions");
    if (_allowed && {!(_permissions isEqualTo [])}) then {
        private _permOk = false;
        {
            if ([_x] call life_fnc_hasPermission) exitWith {_permOk = true;};
        } forEach _permissions;
        if (!_permOk) then {
            _allowed = false;
            _message = "This recipe requires a department role permission.";
        };
    };
};

if (!_allowed && {_notify}) then {hint _message;};
_allowed
