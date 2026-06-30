/*
    File: fn_atmDailyDeposit.sqf
*/
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _now = systemTimeUTC;
private _dayKey = format ["%1-%2-%3",_now select 0,_now select 1,_now select 2];
private _key = format ["life_atm_daily_deposit_%1",_charUID];
private _data = profileNamespace getVariable [_key,[_dayKey,0]];

if !((_data select 0) isEqualTo _dayKey) then {
    _data = [_dayKey,0];
    profileNamespace setVariable [_key,_data];
    saveProfileNamespace;
};

_data select 1
