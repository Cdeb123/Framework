#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopBuySell.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles legacy weapon-shop purchases and sales, including magazine quantities.
*/
disableSerialization;
if ((lbCurSel 38403) isEqualTo -1) exitWith {hint localize "STR_Shop_Weapon_NoSelect";};

private _price = lbValue [38403,lbCurSel 38403];
if (isNil "_price") then {_price = 0;};
private _item = lbData [38403,lbCurSel 38403];
private _itemInfo = [_item] call life_fnc_fetchCfgDetails;
private _isSelling = (uiNamespace getVariable ["Weapon_Shop_Filter",0]) isEqualTo 1;
private _isMagazineClass = !(_itemInfo isEqualTo []) && {(_itemInfo select 6) isEqualTo "CfgMagazines"};
private _isMagazine = !_isSelling && {_isMagazineClass};
private _magazineCapacity = if (_isMagazine) then {getNumber (configFile >> "CfgMagazines" >> _item >> "count")} else {0};
if (_isMagazine && {_magazineCapacity < 1}) then {_magazineCapacity = 1;};

private _quantity = 1;
if (_isMagazine) then {
    private _quantityText = ctrlText 38408;
    if !([_quantityText] call TON_fnc_isnumber) exitWith {_quantity = 0;};
    _quantity = floor (parseNumber _quantityText);
};
if (_quantity < 1 || {_quantity > 100}) exitWith {hint "Enter a magazine quantity from 1 to 100.";};

if (!_isSelling && {!(_itemInfo isEqualTo [])} && {(_itemInfo select 6) != "CfgVehicles"}) then {
    if ((_itemInfo select 4) in [4096,131072] && {!(player canAdd _item)}) exitWith {_quantity = 0;};
};
if (_isMagazine && {!(player canAdd _item)}) then {_quantity = 0;};
if (_quantity isEqualTo 0) exitWith {hint localize "STR_NOTF_NoRoom";};

if (_isMagazine) then {
    private _magazineMass = getNumber (configFile >> "CfgMagazines" >> _item >> "mass");
    if (_magazineMass > 0 && {(loadAbs player) + (_magazineMass * _quantity) > (maxLoad player)}) exitWith {
        _quantity = 0;
    };
};
if (_quantity isEqualTo 0) exitWith {hint "You do not have room for that many magazines.";};

private _totalPrice = _price * _quantity;
private _displayName = if (_itemInfo isEqualTo []) then {_item} else {_itemInfo select 1};
private _purchaseName = format ["%1%2",["",format ["%1x ",_quantity]] select (_quantity > 1),_displayName];
private _givePurchase = {
    if (_isMagazine) then {
        for "_i" from 1 to _quantity do {player addMagazine [_item,_magazineCapacity];};
    } else {
        [_item,true] call life_fnc_handleItem;
    };
};

if (_isSelling) then {
    // Magazine sale prices are class-based: remaining rounds never reduce the configured payout.
    private _removed = true;
    if (_isMagazineClass) then {
        _removed = false;
        private _entries = (magazinesAmmoFull player) select {
            !(_x param [2,false,[false]]) && {(_x param [0,"",[""]]) isEqualTo _item}
        };

        if !(_entries isEqualTo []) then {
            private _sellIndex = 0;
            private _lowestRounds = (_entries select 0) param [1,0,[0]];
            {
                private _rounds = _x param [1,0,[0]];
                if (_rounds < _lowestRounds) then {
                    _lowestRounds = _rounds;
                    _sellIndex = _forEachIndex;
                };
            } forEach _entries;

            for "_i" from 1 to (count _entries) do {player removeMagazine _item;};
            _entries deleteAt _sellIndex;
            {
                player addMagazine [_item,_x param [1,0,[0]]];
            } forEach _entries;
            _removed = true;
        };
    } else {
        [_item,false] call life_fnc_handleItem;
    };

    if (!_removed) then {
        hint "That magazine is loaded or is no longer in your inventory.";
    } else {
        CASH = CASH + _price;
        hint parseText format [localize "STR_Shop_Weapon_Sold",_displayName,[_price] call life_fnc_numberText];
        [nil,(uiNamespace getVariable ["Weapon_Shop_Filter",0])] call life_fnc_weaponShopFilter;
    };
} else {
    private _altisArray = ["Land_u_Barracks_V2_F","Land_i_Barracks_V2_F"];
    private _tanoaArray = ["Land_School_01_F","Land_Warehouse_03_F","Land_House_Small_02_F"];
    private _hideoutObjs = [[["Altis",_altisArray],["Tanoa",_tanoaArray]]] call TON_fnc_terrainSort;
    private _nearHideouts = nearestObjects [getPosATL player,_hideoutObjs,25];
    private _hideout = if (_nearHideouts isEqualTo []) then {objNull} else {_nearHideouts select 0};

    if (!isNull _hideout && {!isNil {group player getVariable "gang_bank"}} && {(group player getVariable "gang_bank") >= _totalPrice}) then {
        private _action = [
            format [
                (localize "STR_Shop_Virt_Gang_FundsMSG") + "<br/><br/>" + (localize "STR_Shop_Virt_Gang_Funds") + " <t color='#8cff9b'>$%1</t><br/>" + (localize "STR_Shop_Virt_YourFunds") + " <t color='#8cff9b'>$%2</t>",
                [(group player getVariable "gang_bank")] call life_fnc_numberText,
                [CASH] call life_fnc_numberText
            ],
            localize "STR_Shop_Virt_YourorGang",
            localize "STR_Shop_Virt_UI_GangFunds",
            localize "STR_Shop_Virt_UI_YourCash"
        ] call BIS_fnc_guiMessage;

        if (_action) then {
            private _funds = group player getVariable "gang_bank";
            group player setVariable ["gang_bank",_funds - _totalPrice,true];
            call _givePurchase;
            hint parseText format [localize "STR_Shop_Weapon_BoughtGang",_purchaseName,[_totalPrice] call life_fnc_numberText];

            if (life_HC_isActive) then {
                [1,group player] remoteExecCall ["HC_fnc_updateGang",HC_Life];
            } else {
                [1,group player] remoteExecCall ["TON_fnc_updateGang",RSERV];
            };
        } else {
            if (_totalPrice > CASH) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};
            CASH = CASH - _totalPrice;
            call _givePurchase;
            hint parseText format [localize "STR_Shop_Weapon_BoughtItem",_purchaseName,[_totalPrice] call life_fnc_numberText];
        };
    } else {
        if (_totalPrice > CASH) exitWith {hint localize "STR_NOTF_NotEnoughMoney";};
        CASH = CASH - _totalPrice;
        call _givePurchase;
        hint parseText format [localize "STR_Shop_Weapon_BoughtItem",_purchaseName,[_totalPrice] call life_fnc_numberText];
    };
};

[0] call SOCK_fnc_updatePartial;
[3] call SOCK_fnc_updatePartial;
