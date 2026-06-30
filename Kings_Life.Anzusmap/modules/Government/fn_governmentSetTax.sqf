/*
    File: fn_governmentSetTax.sqf
*/
params [
    ["_category","",[""]],
    ["_rate",-1,[0]]
];

if (_category isEqualTo "" || {_rate < 0} || {_rate > 1}) exitWith {false};
if !(playerSide isEqualTo west) exitWith {false};

private _varName = format ["life_tax_%1",_category];
missionNamespace setVariable [_varName,_rate,true];
publicVariable _varName;
true
