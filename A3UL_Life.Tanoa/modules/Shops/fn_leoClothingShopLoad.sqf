#include "..\..\script_macros.hpp"
/*
    File: fn_leoClothingShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_leo_clothing_shop_type","cop"],[""]]
];

private _display = findDisplay 8950;
if (isNull _display) exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "LEOClothingShops" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};

life_leo_clothing_shop_type = _shop;
life_leo_clothing_shop_items = [];

(_display displayCtrl 8951) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 8952) ctrlSetText getText (_shopCfg >> "subtitle");
(_display displayCtrl 8955) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a clothing category to begin.</t>";
(_display displayCtrl 8956) ctrlSetText "";
(_display displayCtrl 8957) ctrlEnable false;

lbClear 8953;
lbClear 8954;

{
    private _idx = lbAdd [8953,getText (_x >> "title")];
    lbSetData [8953,_idx,configName _x];
} forEach ("true" configClasses (_shopCfg >> "Categories"));

if ((lbSize 8953) > 0) then {
    lbSetCurSel [8953,0];
} else {
    (_display displayCtrl 8955) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No LEO clothing categories are configured.</t><br/><br/>Path checked:<br/>Life_Shops >> LEOClothingShops >> %1 >> Categories",
        _shop
    ];
};
