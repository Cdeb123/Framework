/*
    File: fn_taxRate.sqf
*/
params [
    ["_category","",[""]],
    ["_item","",[""]]
];

private _resolved = _category;
if (_resolved isEqualTo "" && {!(_item isEqualTo "")}) then {
    private _taxCategories = missionConfigFile >> "Life_Government" >> "TaxCategories";
    if (_item in getArray (_taxCategories >> "foodItems")) then {_resolved = "food";};
    if (_item in getArray (_taxCategories >> "fuelItems")) then {_resolved = "fuel";};
    if (_item in getArray (_taxCategories >> "weedItems")) then {_resolved = "weed";};
    if (_item in getArray (_taxCategories >> "illegalDrugItems")) then {_resolved = "illegal_drugs";};
};

if (_resolved isEqualTo "") exitWith {0};

private _override = missionNamespace getVariable [format ["life_tax_%1",_resolved],-1];
if (_override >= 0) exitWith {_override};

getNumber (missionConfigFile >> "Life_Government" >> "Taxes" >> _resolved >> "rate")
