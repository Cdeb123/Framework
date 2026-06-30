#include "..\..\script_macros.hpp"
/*
    File: fn_citationPay.sqf
*/
private _record = missionNamespace getVariable ["life_citation_active",[]];
private _officer = missionNamespace getVariable ["life_citation_officer",objNull];
if (_record isEqualTo []) exitWith {};

private _amount = _record param [15,0,[0]];
if (_amount <= 0) exitWith {};

if (CASH >= _amount) then {
    CASH = CASH - _amount;
    [0] call SOCK_fnc_updatePartial;
} else {
    if (BANK < _amount) exitWith {
        hint "You do not have enough cash or bank funds to pay this citation.";
    };
    BANK = BANK - _amount;
    [1] call SOCK_fnc_updatePartial;
};

life_citation_decided = true;
private _payerName = player getVariable ["realname",profileName];
_record set [1,"paid"];
_record set [16,serverTime];
[_record] call life_fnc_citationAddRecord;

private _bankClass = getText (missionConfigFile >> "Life_LEO" >> "Citations" >> "factionBank");
if (_bankClass isEqualTo "") then {_bankClass = "law_enforcement";};
private _varName = format ["life_faction_bank_%1",_bankClass];
missionNamespace setVariable [_varName,(missionNamespace getVariable [_varName,0]) + _amount,true];
publicVariable _varName;

hint format ["Paid citation %1 for $%2.",_record param [0,""],[_amount] call life_fnc_numberText];
[0,format ["%1 paid citation %2 for $%3.",_payerName,_record param [0,""],[_amount] call life_fnc_numberText]] remoteExecCall ["life_fnc_broadcast",west];
if (!isNull _officer) then {
    [true,_record,_payerName,"Paid"] remoteExec ["life_fnc_citationResult",_officer];
};

closeDialog 0;
