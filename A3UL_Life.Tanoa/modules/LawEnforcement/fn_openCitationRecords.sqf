#include "..\..\script_macros.hpp"
/*
    File: fn_openCitationRecords.sqf
*/
private _canView = (playerSide isEqualTo west)
    || {["leo.records.view"] call life_fnc_hasPermission}
    || {["doj.citation_review"] call life_fnc_hasPermission}
    || {["doj.records"] call life_fnc_hasPermission}
    || {[] call life_fnc_isCommunityOwner};

if (!_canView) exitWith {hint "You do not have citation record access.";};
createDialog "life_citation_records";
