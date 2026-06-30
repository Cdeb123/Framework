#include "..\..\script_macros.hpp"
/*
    File: fn_atmAction.sqf
*/
params [
    ["_mode","",[""]]
];
disableSerialization;

private _display = findDisplay 2700;
if (isNull _display) exitWith {};
if ((time - life_action_delay) < 0.5) exitWith {hint localize "STR_NOTF_ActionDelay";};

private _raw = ctrlText 2702;
if (!([_raw] call TON_fnc_isnumber)) exitWith {hint localize "STR_ATM_notnumeric";};
private _value = floor (parseNumber _raw);
private _maxTransaction = getNumber (missionConfigFile >> "Life_ATM" >> "maxTransaction");
if (_value < 1) exitWith {};
if (_value > _maxTransaction) exitWith {hint format ["The maximum transaction is $%1.",[_maxTransaction] call life_fnc_numberText];};

switch (_mode) do {
    case "deposit": {
        private _limit = getNumber (missionConfigFile >> "Life_ATM" >> "dailyDepositLimit");
        private _used = [] call life_fnc_atmDailyDeposit;
        if (_value > CASH) exitWith {hint localize "STR_ATM_NotEnoughCash";};
        if ((_used + _value) > _limit) exitWith {
            hint format ["Daily cash deposit limit reached. Remaining today: $%1.",[(_limit - _used) max 0] call life_fnc_numberText];
        };

        CASH = CASH - _value;
        BANK = BANK + _value;
        [_value] call life_fnc_atmRecordDeposit;
        [6] call SOCK_fnc_updatePartial;
        hint format [localize "STR_ATM_DepositSuccess",[_value] call life_fnc_numberText];
    };

    case "withdraw": {
        if (_value > BANK) exitWith {hint localize "STR_ATM_NotEnoughFunds";};
        if (_value < 100 && {BANK > 20000000}) exitWith {hint localize "STR_ATM_WithdrawMin";};

        CASH = CASH + _value;
        BANK = BANK - _value;
        [6] call SOCK_fnc_updatePartial;
        hint format [localize "STR_ATM_WithdrawSuccess",[_value] call life_fnc_numberText];
    };

    case "player": {
        if ((lbCurSel 2703) isEqualTo -1) exitWith {hint localize "STR_ATM_NoneSelected";};
        private _unit = objectFromNetId (lbData [2703,lbCurSel 2703]);
        if (isNull _unit || {!alive _unit} || {!isPlayer _unit}) exitWith {hint localize "STR_ATM_DoesntExist";};

        private _tax = _value * (getNumber (missionConfigFile >> "Life_ATM" >> "playerTransferTax"));
        if ((_value + _tax) > BANK) exitWith {hint format [localize "STR_ATM_SentMoneyFail",_value,_tax];};

        BANK = BANK - (_value + _tax);
        [_value,profileName] remoteExecCall ["life_fnc_wireTransfer",_unit];
        [1] call SOCK_fnc_updatePartial;
        hint format [localize "STR_ATM_SentMoneySuccess",[_value] call life_fnc_numberText,_unit getVariable ["realname",name _unit],[_tax] call life_fnc_numberText];
    };

    case "gang": {
        if ((lbCurSel 2704) isEqualTo -1) exitWith {hint "Select an online gang first.";};
        private _leader = objectFromNetId (lbData [2704,lbCurSel 2704]);
        if (isNull _leader || {!alive _leader}) exitWith {hint "That gang is no longer online.";};
        private _group = group _leader;
        private _gangName = _group getVariable ["gang_name",""];
        if (_gangName isEqualTo "") exitWith {hint localize "STR_ATM_NotInGang";};
        if (_value > BANK) exitWith {hint localize "STR_ATM_NotEnoughFunds";};

        BANK = BANK - _value;
        _group setVariable ["gang_bank",(_group getVariable ["gang_bank",0]) + _value,true];
        if (life_HC_isActive) then {
            [0,_group] remoteExecCall ["HC_fnc_updateGang",HC_Life];
        } else {
            [0,_group] remoteExecCall ["TON_fnc_updateGang",RSERV];
        };
        [1] call SOCK_fnc_updatePartial;
        hint format ["Transferred $%1 to %2.",[_value] call life_fnc_numberText,_gangName];
    };

    case "faction": {
        if ((lbCurSel 2705) isEqualTo -1) exitWith {hint "Select a faction bank first.";};
        private _bankClass = lbData [2705,lbCurSel 2705];
        private _bankCfg = missionConfigFile >> "Life_ATM" >> "FactionBanks" >> _bankClass;
        private _bankTitle = getText (_bankCfg >> "title");
        private _bankSide = getText (_bankCfg >> "side");
        if ((getNumber (_bankCfg >> "canDeposit")) isEqualTo 0) exitWith {hint "This faction bank does not accept deposits.";};
        if (_bankSide isEqualTo "cop" && {!(playerSide isEqualTo west && {["deputy"] call life_fnc_leoAtLeastRank})}) exitWith {
            hint "Only Deputy+ can deposit to the law enforcement faction bank.";
        };
        if (_bankSide isEqualTo "med" && {!(playerSide isEqualTo independent)}) exitWith {hint "Only EMS can deposit to this faction bank.";};
        if (_bankSide isEqualTo "civ" && {!(playerSide isEqualTo civilian)}) exitWith {hint "Only civilians can deposit to this faction bank.";};
        if (_value > BANK) exitWith {hint localize "STR_ATM_NotEnoughFunds";};

        private _varName = format ["life_faction_bank_%1",_bankClass];
        missionNamespace setVariable [_varName,(missionNamespace getVariable [_varName,0]) + _value,true];
        publicVariable _varName;
        BANK = BANK - _value;
        [1] call SOCK_fnc_updatePartial;
        hint format ["Transferred $%1 to %2.",[_value] call life_fnc_numberText,_bankTitle];
    };

    case "factionWithdraw": {
        if ((lbCurSel 2705) isEqualTo -1) exitWith {hint "Select a faction bank first.";};
        private _bankClass = lbData [2705,lbCurSel 2705];
        private _bankCfg = missionConfigFile >> "Life_ATM" >> "FactionBanks" >> _bankClass;
        private _bankTitle = getText (_bankCfg >> "title");
        private _bankSide = getText (_bankCfg >> "side");
        if ((getNumber (_bankCfg >> "canWithdraw")) isEqualTo 0) exitWith {hint "This faction bank does not allow withdrawals.";};
        if !(_bankSide isEqualTo "cop" && {playerSide isEqualTo west} && {[] call life_fnc_leoCanCommand}) exitWith {
            hint "Only law enforcement command can withdraw from faction banks.";
        };

        private _varName = format ["life_faction_bank_%1",_bankClass];
        private _funds = missionNamespace getVariable [_varName,0];
        if (_value > _funds) exitWith {hint "That faction bank does not have enough funds.";};

        missionNamespace setVariable [_varName,_funds - _value,true];
        publicVariable _varName;
        BANK = BANK + _value;
        [1] call SOCK_fnc_updatePartial;
        hint format ["Withdrew $%1 from %2.",[_value] call life_fnc_numberText,_bankTitle];
    };
};

life_action_delay = time;
[] call life_fnc_atmLoad;
