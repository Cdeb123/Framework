/*
    File: fn_receiveID.sqf
*/
params [
    ["_name","",[""]],
    ["_dob","Unknown",[""]],
    ["_charUID","",[""]],
    ["_licenses","None",[""]],
    ["_faction","",[""]],
    ["_faceTexture","",[""]]
];

missionNamespace setVariable ["life_shown_id_data",[
    _name,
    _dob,
    _charUID,
    _licenses,
    _faction,
    _faceTexture
]];

if (dialog) then {closeDialog 0;};
if (createDialog "life_shown_id_card") then {
    [] spawn {
        uiSleep 0.02;
        [] call life_fnc_refreshShownID;
    };
};
