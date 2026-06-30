/*
    File: fn_progressionLevelInfo.sqf
*/
params [
    ["_category","character",[""]]
];

private _xp = [_category] call life_fnc_progressionXP;
private _maxLevel = getNumber (missionConfigFile >> "Life_Progression" >> "maxCharacterLevel");
private _level = 1;
private _remaining = _xp;
private _required = [_level] call life_fnc_xpForLevel;

while {_level < _maxLevel && {_required > 0} && {_remaining >= _required}} do {
    _remaining = _remaining - _required;
    _level = _level + 1;
    _required = [_level] call life_fnc_xpForLevel;
};

private _progress = if (_required <= 0) then {1} else {(_remaining / _required) min 1};
[_level,_remaining,_required,_xp,_progress]
