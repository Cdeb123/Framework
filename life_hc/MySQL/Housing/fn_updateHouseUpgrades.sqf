#include "\life_hc\hc_macros.hpp"
/*
    File: fn_updateHouseUpgrades.sqf

    Persists owned-house upgrade keys - HC.
*/
params [
    ["_uid","",[""]],
    ["_house",objNull,[objNull]],
    ["_upgrades",[],[[]]]
];

if (_uid isEqualTo "" || {isNull _house}) exitWith {};

private _owner = _house getVariable ["house_owner",[]];
if ((count _owner) > 0 && {!((_owner select 0) isEqualTo _uid)}) exitWith {};

private _cleanUpgrades = [];
{
    if (_x isEqualType "") then {
        _cleanUpgrades pushBackUnique _x;
    };
} forEach _upgrades;

private _houseID = _house getVariable ["house_id",-1];
private _housePos = getPosATL _house;
private _upgradeData = [_cleanUpgrades] call HC_fnc_mresArray;
private "_query";

if (_houseID isEqualTo -1) then {
    _query = format ["UPDATE houses SET upgrades='%1' WHERE pid='%2' AND pos='%3' AND owned='1'",_upgradeData,_uid,_housePos];
} else {
    _query = format ["UPDATE houses SET upgrades='%1' WHERE id='%2' AND pid='%3' AND owned='1'",_upgradeData,_houseID,_uid];
};

if (EXTDB_SETTING(getNumber,"DebugMode") isEqualTo 1) then {
    diag_log format ["Query: %1",_query];
};

[_query,1] call HC_fnc_asyncCall;
_house setVariable ["house_upgrades",_cleanUpgrades,true];

