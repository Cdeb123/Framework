/*
    File: fn_spendPerk.sqf
*/
disableSerialization;
private _display = findDisplay 8600;
private _perk = missionNamespace getVariable ["life_progression_selected",""];
if (!isNull _display && {(lbCurSel 8610) >= 0}) then {
    _perk = lbData [8610,lbCurSel 8610];
};
if (_perk isEqualTo "" || {!(isClass (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk))}) exitWith {};

private _points = missionNamespace getVariable ["life_perk_points",0];
private _cost = getNumber (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk >> "cost");
private _maxRank = getNumber (missionConfigFile >> "Life_Progression" >> "Perks" >> _perk >> "maxRank");
private _rank = [_perk] call life_fnc_perkLevel;

if (_rank >= _maxRank) exitWith {hint "That perk is already maxed.";};
if (_points < _cost) exitWith {hint "You do not have enough perk points.";};

private _perks = missionNamespace getVariable ["life_progression_perks",[]];
private _index = [_perk,_perks] call TON_fnc_index;
if (_index < 0) then {
    _perks pushBack [_perk,1];
} else {
    _perks set [_index,[_perk,_rank + 1]];
};

missionNamespace setVariable ["life_progression_perks",_perks];
missionNamespace setVariable ["life_perk_points",_points - _cost];
[] call life_fnc_progressionSave;
[] call life_fnc_progressionLoad;
