/*
    File: fn_governmentAddRevenue.sqf
*/
params [
    ["_amount",0,[0]]
];

if (_amount <= 0) exitWith {};
private _balance = missionNamespace getVariable [
    "life_government_balance",
    getNumber (missionConfigFile >> "Life_Government" >> "startingBalance")
];

missionNamespace setVariable ["life_government_balance",_balance + _amount,true];
publicVariable "life_government_balance";
