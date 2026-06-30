/*
    File: fn_applyTax.sqf
*/
params [
    ["_amount",0,[0]],
    ["_category","",[""]],
    ["_item","",[""]],
    ["_collect",false,[false]]
];

private _rate = [_category,_item] call life_fnc_taxRate;
private _tax = round (_amount * _rate);
private _total = _amount + _tax;

if (_collect && {_tax > 0}) then {
    [_tax] call life_fnc_governmentAddRevenue;
};

[_amount,_tax,_total,_rate]
