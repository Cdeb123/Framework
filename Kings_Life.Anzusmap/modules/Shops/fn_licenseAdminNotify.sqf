/*
    File: fn_licenseAdminNotify.sqf
*/
params [
    ["_targetName","",[""]],
    ["_licenseName","",[""]],
    ["_action","",[""]]
];

hint format ["%1: %2 %3.",_targetName,_licenseName,_action];
["leo",getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> "licenseAdmin"),format ["License %1",_action]] call life_fnc_addXP;
if (!isNull (findDisplay 8350)) then {
    [] call life_fnc_licenseAdminSelect;
};
