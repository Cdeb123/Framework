/*
    File: fn_perkModifier.sqf
*/
params [
    ["_perk","",[""]]
];

if !(isClass (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk)) exitWith {1};
if !(missionNamespace getVariable ["life_progression_loaded",false]) then {
    [] call life_fnc_progressionInit;
};

private _rank = [_perk] call life_fnc_perkLevel;
private _modifier = getNumber (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk >> "modifier");
private _minMultiplier = getNumber (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk >> "minMultiplier");
if (_minMultiplier <= 0) then {_minMultiplier = 0.2;};

(_minMultiplier max (1 + (_rank * _modifier)))
