#include "..\..\script_macros.hpp"
/*
    File: fn_citationDecline.sqf
*/
private _record = missionNamespace getVariable ["life_citation_active",[]];
private _officer = missionNamespace getVariable ["life_citation_officer",objNull];
if (_record isEqualTo []) exitWith {};

life_citation_decided = true;
private _targetName = player getVariable ["realname",profileName];
_record set [1,"declined"];
_record set [17,serverTime];
[_record] call life_fnc_citationAddRecord;

hint "Citation declined.";
[0,format ["%1 declined citation %2.",_targetName,_record param [0,""]]] remoteExecCall ["life_fnc_broadcast",west];
if (!isNull _officer) then {
    [false,_record,_targetName,"Declined"] remoteExec ["life_fnc_citationResult",_officer];
};

closeDialog 0;
