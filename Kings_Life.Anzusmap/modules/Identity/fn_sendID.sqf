#include "..\..\script_macros.hpp"
/*
    File: fn_sendID.sqf
*/
params [
    ["_viewer",objNull,[objNull]]
];
if (isNull _viewer || {!isPlayer _viewer}) exitWith {};

private _char = missionNamespace getVariable ["life_character_data",[]];
private _name = player getVariable ["realname",name player];
private _dob = if ((count _char) > 3) then {_char select 3} else {"Unknown"};
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];
private _faceTexture = getText (configFile >> "CfgFaces" >> "Man_A3" >> (face player) >> "texture");
private _flag = switch (playerSide) do {case west: {"cop"}; case civilian: {"civ"}; case independent: {"med"}; default {"civ"};};
private _licenses = [];
{
    private _license = configName _x;
    if (LICENSE_VALUE(_license,_flag)) then {
        _licenses pushBack localize getText (_x >> "displayName");
    };
} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_flag] configClasses (missionConfigFile >> "Licenses"));

private _badge = player getVariable ["leoBadgeNumber",""];
private _faction = "";
if (playerSide isEqualTo west) then {
    if (_badge isEqualTo "") then {
        _badge = str (10000 + floor random 90000);
        player setVariable ["leoBadgeNumber",_badge,true];
    };
    private _subs = player getVariable ["leoSubdivisions",[]];
    _faction = format [
        "%1 | %2 | %3 | Badge #%4 | Aviation: %5 | Maritime: %6",
        player getVariable ["leoDepartmentDisplay",missionNamespace getVariable ["life_leo_department_display","Law Enforcement"]],
        player getVariable ["leoRankDisplay",missionNamespace getVariable ["life_leo_rank_display","Officer"]],
        (player getVariable ["leoPrimarySubdivision",missionNamespace getVariable ["life_leo_primary_subdivision","Patrol"]]),
        _badge,
        ["No","Yes"] select LICENSE_VALUE("cAir","cop"),
        ["No","Yes"] select LICENSE_VALUE("cg","cop")
    ];
};

[
    _name,
    _dob,
    _charUID,
    if ((count _licenses) > 0) then {_licenses joinString ", "} else {"None"},
    _faction,
    _faceTexture
] remoteExecCall ["life_fnc_receiveID",_viewer];
