/*
    File: fn_perkLevel.sqf
*/
params [
    ["_perk","",[""]]
];

private _perks = missionNamespace getVariable ["life_progression_perks",[]];
private _index = [_perk,_perks] call TON_fnc_index;
if (_index < 0) exitWith {0};
(_perks select _index) select 1
