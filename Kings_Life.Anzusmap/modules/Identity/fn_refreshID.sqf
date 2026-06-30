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
private _factionText = "";
if (playerSide isEqualTo west) then {
    private _badge = player getVariable ["leoBadgeNumber",""];
    if (_badge isEqualTo "") then {
        _badge = str (10000 + floor random 90000);
        player setVariable ["leoBadgeNumber",_badge,true];
    };
    _factionText = format [
        "<br/><t color='#006776' size='0.72'>Faction:</t> <t color='#050505' size='0.68'>%1 | %2 | %3 | #%4 | Air %5 | Sea %6</t>",
        missionNamespace getVariable ["life_leo_department_display","Law Enforcement"],
        missionNamespace getVariable ["life_leo_rank_display","Officer"],
        missionNamespace getVariable ["life_leo_primary_subdivision","Patrol"],
        _badge,
        ["No","Yes"] select LICENSE_VALUE("cAir","cop"),
        ["No","Yes"] select LICENSE_VALUE("cg","cop")
    ];
};
private _citations = count (missionNamespace getVariable ["life_pending_citations",[]]);
private _warrants = count (missionNamespace getVariable ["life_pending_warrants",[]]);
private _statuses = [];
if ([] call life_fnc_isCommunityOwner) then {_statuses pushBack (missionNamespace getVariable ["life_owner_role","Community Manager"]);};
if (player getVariable ["restrained",false]) then {_statuses pushBack "Cuffed";};
if (missionNamespace getVariable ["life_effect_poisoned",false]) then {_statuses pushBack "Poisoned";};
if (missionNamespace getVariable ["life_effect_virus",false]) then {_statuses pushBack "Virus Exposure";};
if (missionNamespace getVariable ["life_effect_drunk",false]) then {_statuses pushBack "Impaired";};
private _statusText = if ((count _statuses) > 0) then {_statuses joinString ", "} else {"Clear"};

(_display displayCtrl 7903) ctrlSetStructuredText parseText format [
    "<t color='#173039' size='0.76'>NAME</t><br/><t color='#050505' size='0.94'>%1</t><br/><t color='#173039' size='0.76'>DOB</t> <t color='#050505' size='0.88'>%2</t><br/><t color='#173039' size='0.76'>ID</t> <t color='#050505' size='0.78'>%3</t><br/><t color='#173039' size='0.76'>STATUS</t> <t color='#050505' size='0.78'>%4</t>",
    _name,
    _dob,
    _charUID,
    _political
];

(_display displayCtrl 7904) ctrlSetStructuredText parseText format [
    "<t color='#173039' size='0.72'>Licenses:</t> <t color='#050505' size='0.66'>%1</t>%6<br/><t color='#173039' size='0.72'>Legal:</t> <t color='#050505' size='0.66'>Citations %2 | Warrants %3</t><br/><t color='#173039' size='0.72'>Status:</t> <t color='#050505' size='0.66'>%4</t><br/><t color='#173039' size='0.72'>Background:</t> <t color='#050505' size='0.62'>%5</t>",
    _licenseText,
    _citations,
    _warrants,
    _statusText,
    _background,
    _factionText
];
