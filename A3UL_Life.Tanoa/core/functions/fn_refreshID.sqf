#include "..\..\script_macros.hpp"
/*
    File: fn_refreshID.sqf
*/
disableSerialization;
private _display = findDisplay 7900;
if (isNull _display) exitWith {};

private _faceTexture = getText (configFile >> "CfgFaces" >> "Man_A3" >> (face player) >> "texture");
if !(_faceTexture isEqualTo "") then {
    (_display displayCtrl 7901) ctrlSetText _faceTexture;
};

private _char = missionNamespace getVariable ["life_character_data",[]];
private _name = player getVariable ["realname",name player];
private _dob = if ((count _char) > 3) then {_char select 3} else {"Unknown"};
private _political = if ((count _char) > 4) then {_char select 4} else {"Resident"};
private _background = if ((count _char) > 5) then {_char select 5} else {"No background set."};
private _charUID = missionNamespace getVariable ["life_character_uid",getPlayerUID player];

private _licenses = [];
private _flag = switch (playerSide) do {case west: {"cop"}; case civilian: {"civ"}; case independent: {"med"}; default {"civ"};};
{
    private _varName = LICENSE_VARNAME(configName _x,_flag);
    if (missionNamespace getVariable [_varName,false]) then {
        _licenses pushBack localize (getText (_x >> "displayName"));
    };
} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_flag] configClasses (missionConfigFile >> "Licenses"));

private _licenseText = if ((count _licenses) > 0) then {_licenses joinString ", "} else {"None"};
private _citations = count (missionNamespace getVariable ["life_pending_citations",[]]);
private _warrants = count (missionNamespace getVariable ["life_pending_warrants",[]]);
private _statuses = [];
if (player getVariable ["restrained",false]) then {_statuses pushBack "Cuffed";};
if (missionNamespace getVariable ["life_effect_poisoned",false]) then {_statuses pushBack "Poisoned";};
if (missionNamespace getVariable ["life_effect_virus",false]) then {_statuses pushBack "Virus Exposure";};
if (missionNamespace getVariable ["life_effect_drunk",false]) then {_statuses pushBack "Impaired";};
private _statusText = if ((count _statuses) > 0) then {_statuses joinString ", "} else {"Clear"};

(_display displayCtrl 7903) ctrlSetStructuredText parseText format [
    "<t color='#dceaf0'>Name</t><br/>%1<br/><br/><t color='#dceaf0'>DOB</t><br/>%2<br/><br/><t color='#dceaf0'>Character ID</t><br/>%3<br/><br/><t color='#dceaf0'>Political Status</t><br/>%4",
    _name,
    _dob,
    _charUID,
    _political
];

(_display displayCtrl 7904) ctrlSetStructuredText parseText format [
    "<t color='#00c7eb'>Licenses</t><br/>%1<br/><t color='#00c7eb'>Legal</t><br/>Citations: %2 | Warrants: %3<br/><t color='#00c7eb'>Special Status</t><br/>%4<br/><t color='#647780'>Background:</t> %5",
    _licenseText,
    _citations,
    _warrants,
    _statusText,
    _background
];
