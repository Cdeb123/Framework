#include "..\..\script_macros.hpp"
/*
    File: fn_openATM.sqf
*/
if (!life_use_atm) exitWith {
    hint format [localize "STR_Shop_ATMRobbed",(LIFE_SETTINGS(getNumber,"noatm_timer"))];
};

if (dialog) exitWith {};
if (createDialog "Life_atm_management") then {
    [] spawn {
        uiSleep 0.02;
        [] call life_fnc_atmLoad;
    };
};
