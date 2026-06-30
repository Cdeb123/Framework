#include "..\..\script_macros.hpp"
/*
    File: fn_openLEOVehicleShop.sqf
*/
private _input = _this;
private _args = _input;
if (_input isEqualType [] && {(count _input) > 3} && {(_input select 3) isEqualType []}) then {
    _args = _input select 3;
};

private _shop = "cop_car";
private _spawnPoints = "";
private _shopFlag = "cop";
private _disableBuy = false;
private _wrongSide = false;

if (_args isEqualType "") then {
    _shop = _args;
} else {
    _args params [
        ["_argShop","",[""]],
        ["_sideCheck",sideUnknown,[civilian]],
        ["_argSpawnPoints","",["",[]]],
        ["_argShopFlag","cop",[""]],
        ["_shopTitle","",[""]],
        ["_argDisableBuy",false,[true]]
    ];
    _shop = _argShop;
    _spawnPoints = _argSpawnPoints;
    _shopFlag = _argShopFlag;
    _disableBuy = _argDisableBuy;
    _wrongSide = !(_sideCheck isEqualTo sideUnknown) && {!(playerSide isEqualTo _sideCheck)};
};

if (_wrongSide) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};
if !(playerSide isEqualTo west) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};
if (_shop isEqualTo "") exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "VehicleShops" >> "LawEnforcement" >> _shop;
if !(isClass _shopCfg) exitWith {};

private _condition = getText (_shopCfg >> "condition");
if !([_condition] call life_fnc_levelCheck) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

private _cert = getText (_shopCfg >> "requiredCertification");
private _missingCert = false;
if !(_cert isEqualTo "") then {
    _missingCert = !(missionNamespace getVariable [format ["license_cop_%1",_cert],false]);
};
if (_missingCert) exitWith {hint "You need the required TCSD certification before using this shop.";};

if (dialog) exitWith {};
life_vehicle_shop_type = _shop;
life_vehicle_shop_context = [_shop,_spawnPoints,_shopFlag,_disableBuy];
createDialog "life_leo_vehicle_shop";
[] spawn {
    disableSerialization;
    uiSleep 0.05;
    [missionNamespace getVariable ["life_vehicle_shop_type","cop_car"]] call life_fnc_leoVehicleShopLoad;
};
