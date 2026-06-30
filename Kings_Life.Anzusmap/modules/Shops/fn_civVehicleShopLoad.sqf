#include "..\..\script_macros.hpp"
/*
    File: fn_civVehicleShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_vehicle_shop_type","civ_car"],[""]]
];

private _display = findDisplay 9000;
if (isNull _display) exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "Civilian" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};

life_vehicle_shop_type = _shop;
life_vehicle_shop_items = [];

(_display displayCtrl 9001) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 9002) ctrlSetText getText (_shopCfg >> "subtitle");
(_display displayCtrl 9005) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a vehicle category to begin.</t>";
(_display displayCtrl 9006) ctrlSetText "";
(_display displayCtrl 9007) ctrlEnable false;
(_display displayCtrl 9009) ctrlEnable false;

lbClear 9003;
lbClear 9004;
lbClear 9008;

{
    private _idx = lbAdd [9003,getText (_x >> "title")];
    lbSetData [9003,_idx,configName _x];
} forEach ("true" configClasses (_shopCfg >> "Categories"));

if ((lbSize 9003) > 0) then {
    lbSetCurSel [9003,0];
} else {
    (_display displayCtrl 9005) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No vehicle categories are configured.</t><br/><br/>Path checked:<br/>Life_Shops >> VehicleShops >> Civilian >> %1 >> Categories",
        _shop
    ];
};
