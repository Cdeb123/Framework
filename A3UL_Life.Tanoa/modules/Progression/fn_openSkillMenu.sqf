/*
    File: fn_openSkillMenu.sqf
*/
params [
    ["_tab","xp",[""]]
];

if (!alive player) exitWith {};
if !(missionNamespace getVariable ["life_progression_loaded",false]) then {
    [] call life_fnc_progressionInit;
};

missionNamespace setVariable ["life_progression_tab",_tab];
if (dialog) exitWith {
    [_tab] spawn {
        params [["_nextTab","xp",[""]]];
        closeDialog 0;
        uiSleep 0.05;
        [_nextTab] call life_fnc_openSkillMenu;
    };
};
if (createDialog "life_progression_menu") then {
    [] spawn {
        uiSleep 0.02;
        [] call life_fnc_progressionLoad;
    };
};
