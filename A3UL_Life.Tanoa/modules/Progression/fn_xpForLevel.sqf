/*
    File: fn_xpForLevel.sqf
*/
params [
    ["_level",1,[0]]
];

private _maxLevel = getNumber (missionConfigFile >> "Life_Progression" >> "maxCharacterLevel");
if (_level >= _maxLevel) exitWith {0};

private _base = getNumber (missionConfigFile >> "Life_Progression" >> "baseLevelXP");
private _growth = getNumber (missionConfigFile >> "Life_Progression" >> "levelGrowth");
private _linear = getNumber (missionConfigFile >> "Life_Progression" >> "levelLinearBonus");

round (_base * ((_level max 1) ^ _growth) + (_linear * _level))
