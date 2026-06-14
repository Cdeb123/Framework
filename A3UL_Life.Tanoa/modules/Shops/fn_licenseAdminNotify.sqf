/*
    File: fn_licenseAdminNotify.sqf
*/
params [
    ["_targetName","",[""]],
    ["_licenseName","",[""]],
    ["_action","",[""]]
];

hint format ["%1: %2 %3.",_targetName,_licenseName,_action];
if (!isNull (findDisplay 8350)) then {
    [] call life_fnc_licenseAdminSelect;
};
