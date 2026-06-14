/*
    File: fn_refreshShownID.sqf
*/
disableSerialization;
private _display = findDisplay 7910;
if (isNull _display) exitWith {};

private _data = missionNamespace getVariable ["life_shown_id_data",[]];
if ((count _data) < 6) exitWith {};

_data params [
    ["_name","",[""]],
    ["_dob","Unknown",[""]],
    ["_charUID","",[""]],
    ["_licenses","None",[""]],
    ["_faction","",[""]],
    ["_faceTexture","",[""]]
];

if !(_faceTexture isEqualTo "") then {
    (_display displayCtrl 7911) ctrlSetText _faceTexture;
};

(_display displayCtrl 7912) ctrlSetStructuredText parseText format [
    "<t color='#173039' size='0.92'>Name</t><br/><t color='#050505' size='1.02'>%1</t><br/><t color='#173039' size='0.92'>DOB</t> <t color='#050505'>%2</t><br/><t color='#173039' size='0.92'>ID</t> <t color='#050505'>%3</t>",
    _name,
    _dob,
    _charUID
];

private _factionText = if (_faction isEqualTo "") then {""} else {format [" | %1",_faction]};
(_display displayCtrl 7913) ctrlSetStructuredText parseText format [
    "<t color='#173039' size='0.82'>Licenses:</t> <t color='#050505' size='0.82'>%1%2</t>",
    _licenses,
    _factionText
];
