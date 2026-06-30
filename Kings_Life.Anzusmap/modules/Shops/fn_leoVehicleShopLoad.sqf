#include "..\..\script_macros.hpp"
/*
    File: fn_leoVehicleShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_vehicle_shop_type","cop_car"],[""]]
];

private _display = findDisplay 8800;
if (isNull _display) exitWith {};

if (_shop isEqualTo "cop_car") then {
    _shop = switch (missionNamespace getVariable ["life_leo_department","kcso"]) do {
        case "usms": {"usms_motor_pool"};
        case "dea": {"dea_motor_pool"};
        case "fbi": {"fbi_motor_pool"};
        default {"cop_car"};
    };
};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "LawEnforcement" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};

life_vehicle_shop_type = _shop;
life_vehicle_shop_items = [];

(_display displayCtrl 8801) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 8802) ctrlSetText getText (_shopCfg >> "subtitle");
(_display displayCtrl 8805) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a vehicle category to begin.</t>";
(_display displayCtrl 8806) ctrlSetText "";
(_display displayCtrl 8807) ctrlEnable false;

lbClear 8803;
lbClear 8804;
lbClear 8808;

{
    private _idx = lbAdd [8803,getText (_x >> "title")];
    lbSetData [8803,_idx,configName _x];
} forEach ("true" configClasses (_shopCfg >> "Categories"));

if ((lbSize 8803) > 0) then {
    lbSetCurSel [8803,0];
} else {
    (_display displayCtrl 8805) ctrlSetStructuredText parseText format [
        "<t color='#dceaf0'>No vehicle categories are configured.</t><br/><br/>Path checked:<br/>Life_Shops >> VehicleShops >> LawEnforcement >> %1 >> Categories",
        _shop
    ];
};
