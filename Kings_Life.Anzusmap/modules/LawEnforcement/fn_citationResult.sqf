#include "..\..\script_macros.hpp"
/*
    File: fn_citationResult.sqf
*/
params [
    ["_paid",false,[false]],
    ["_record",[],[[]]],
    ["_targetName","",[""]],
    ["_reason","",[""]]
];

if (_record isEqualTo []) exitWith {};

if (_paid) then {
    hint format ["%1 paid citation %2.",_targetName,_record param [0,""]];
    ["leo",getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> "ticketPaid"),"Paid citation"] call life_fnc_addXP;
} else {
    hint format ["%1 did not pay citation %2. %3",_targetName,_record param [0,""],_reason];
};
