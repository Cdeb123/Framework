/*
    File: fn_atmRecordDeposit.sqf
*/
params [
    ["_amount",0,[0]]
];

private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _now = systemTimeUTC;
private _dayKey = format ["%1-%2-%3",_now select 0,_now select 1,_now select 2];
private _key = format ["life_atm_daily_deposit_%1",_charUID];
private _used = [] call life_fnc_atmDailyDeposit;

profileNamespace setVariable [_key,[_dayKey,_used + _amount]];
saveProfileNamespace;
