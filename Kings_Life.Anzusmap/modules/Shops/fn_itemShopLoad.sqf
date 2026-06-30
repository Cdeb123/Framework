#include "..\..\script_macros.hpp"
/*
    File: fn_itemShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_item_shop_type","market"],[""]]
];

private _display = findDisplay 8900;
if (isNull _display) exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "ItemShops" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};

life_item_shop_type = _shop;
life_item_shop_items = [];

(_display displayCtrl 8901) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 8902) ctrlSetText getText (_shopCfg >> "subtitle");
(_display displayCtrl 8905) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a category to begin.</t>";
(_display displayCtrl 8906) ctrlSetText "";
(_display displayCtrl 8907) ctrlEnable false;
(_display displayCtrl 8908) ctrlSetText "1";
(_display displayCtrl 8908) ctrlEnable false;

lbClear 8903;
lbClear 8904;

if (isClass (_shopCfg >> "License")) then {
    private _idx = lbAdd [8903,"License"];
    lbSetData [8903,_idx,str ["license",""]];
    lbSetColor [8903,_idx,[0.42,0.88,0.58,1]];
};

{
    private _idx = lbAdd [8903,getText (_x >> "title")];
    lbSetData [8903,_idx,str ["category",configName _x]];
} forEach ("true" configClasses (_shopCfg >> "Categories"));

if ((lbSize 8903) > 0) then {
    lbSetCurSel [8903,0];
} else {
    (_display displayCtrl 8905) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No categories are configured for this shop.</t><br/><br/>Path checked:<br/>Life_Shops >> ItemShops >> %1 >> Categories",
        _shop
    ];
};
