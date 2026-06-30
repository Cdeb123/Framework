/*
    File: fn_addXP.sqf
*/
params [
    ["_category","character",[""]],
    ["_amount",0,[0]],
    ["_reason","Experience",[""]],
    ["_notify",true,[false]]
];

if (_amount <= 0) exitWith {};
if !(missionNamespace getVariable ["life_progression_loaded",false]) then {
    [] call life_fnc_progressionInit;
};
if !(isClass (missionConfigFile >> "Life_Progression" >> "Categories" >> _category)) exitWith {};

private _applyXP = {
    params ["_cat","_xpAmount"];
    private _before = [_cat] call life_fnc_progressionLevelInfo;
    private _varName = format ["life_progression_xp_%1",_cat];
    missionNamespace setVariable [_varName,(missionNamespace getVariable [_varName,0]) + _xpAmount];
    private _after = [_cat] call life_fnc_progressionLevelInfo;
    [_before,_after]
};

private _result = [_category,_amount] call _applyXP;
private _characterResult = [];
if !(_category isEqualTo "character") then {
    _characterResult = ["character",_amount] call _applyXP;
};

private _characterLevelUps = 0;
if (_category isEqualTo "character") then {
    _characterLevelUps = ((_result select 1) select 0) - ((_result select 0) select 0);
} else {
    _characterLevelUps = ((_characterResult select 1) select 0) - ((_characterResult select 0) select 0);
};

if (_characterLevelUps > 0) then {
    private _points = getNumber (missionConfigFile >> "Life_Progression" >> "perkPointsPerLevel");
    missionNamespace setVariable ["life_perk_points",(missionNamespace getVariable ["life_perk_points",0]) + (_characterLevelUps * _points)];
};

[] call life_fnc_progressionSave;

if (_notify) then {
    private _categoryTitle = getText (missionConfigFile >> "Life_Progression" >> "Categories" >> _category >> "title");
    private _newLevel = ((_result select 1) select 0);
    private _levelText = if (((_result select 1) select 0) > ((_result select 0) select 0)) then {format ["<br/><t color='#9edb5a'>%1 level %2 reached.</t>",_categoryTitle,_newLevel]} else {""};
    private _perkText = if (_characterLevelUps > 0) then {format ["<br/><t color='#00c7eb'>+%1 perk point(s)</t>",_characterLevelUps]} else {""};
    hintSilent parseText format ["<t color='#00c7eb' size='1.05'>+%1 XP</t><br/>%2<br/><t color='#8fa4aa'>%3</t>%4%5",_amount,_categoryTitle,_reason,_levelText,_perkText];
};

if (!isNull (findDisplay 8600)) then {
    [] call life_fnc_progressionLoad;
};
