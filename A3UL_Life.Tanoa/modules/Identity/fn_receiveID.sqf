/*
    File: fn_receiveID.sqf
*/
params [
    ["_name","",[""]],
    ["_dob","Unknown",[""]],
    ["_charUID","",[""]],
    ["_licenses","None",[""]],
    ["_faction","",[""]]
];

private _factionBlock = if (_faction isEqualTo "") then {""} else {format ["<br/><t color='#00c7eb'>Faction Credential</t><br/>%1",_faction]};
hint parseText format [
    "<t color='#00c7eb' size='1.35'>Identification</t><br/><t color='#dceaf0'>Name</t><br/>%1<br/><t color='#dceaf0'>DOB</t><br/>%2<br/><t color='#dceaf0'>Character ID</t><br/>%3<br/><t color='#00c7eb'>Licenses</t><br/>%4%5",
    _name,
    _dob,
    _charUID,
    _licenses,
    _factionBlock
];
