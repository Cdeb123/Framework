#include "..\..\script_macros.hpp"
/*
    File: fn_openID.sqf
*/
if (dialog) exitWith {};
if (createDialog "life_id_card") then {
    [] spawn {
        uiSleep 0.02;
        [] call life_fnc_refreshID;
    };
};
