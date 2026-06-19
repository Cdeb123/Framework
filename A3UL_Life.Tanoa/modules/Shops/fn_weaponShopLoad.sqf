#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_weapon_shop_type","gun"],[""]]
];

private _display = findDisplay 8700;
if (isNull _display) exitWith {};

private _group = missionNamespace getVariable ["life_weapon_shop_group",switch (playerSide) do {
    case west: {"LawEnforcement"};
    case civilian: {"Civilian"};
    default {""};
}];
if (_shop isEqualTo "cop_basic") then {_shop = "tcsd_armory";};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};

life_weapon_shop_type = _shop;
life_weapon_shop_group = _group;
life_weapon_shop_items = [];

(_display displayCtrl 8701) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 8702) ctrlSetText getText (_shopCfg >> "subtitle");
(_display displayCtrl 8705) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a category to begin.</t>";
(_display displayCtrl 8706) ctrlSetText "";
(_display displayCtrl 8707) ctrlEnable false;
(_display displayCtrl 8708) ctrlSetText "1";
ctrlShow [8708,false];
ctrlShow [8709,false];
ctrlShow [8710,false];

lbClear 8703;
lbClear 8704;

if (isClass (_shopCfg >> "License")) then {
    private _idx = lbAdd [8703,"License"];
    lbSetData [8703,_idx,str ["license",""]];
    lbSetColor [8703,_idx,[0.42,0.88,0.58,1]];
};

{
    private _idx = lbAdd [8703,getText (_x >> "title")];
    lbSetData [8703,_idx,str ["category",configName _x]];
} forEach ("true" configClasses (_shopCfg >> "Categories"));

if ((lbSize 8703) > 0) then {
    lbSetCurSel [8703,0];
} else {
    (_display displayCtrl 8705) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No categories are configured for this shop.</t><br/><br/>Path checked:<br/>Life_Shops >> WeaponShops >> %1 >> %2 >> Categories",
        _group,
        _shop
    ];
};
