#include "..\..\script_macros.hpp"
/*
    File: fn_garageLBChange.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Can't be bothered to answer it.. Already deleted it by accident..
*/
disableSerialization;
_control = _this select 0;
_index = _this select 1;
if (_index < 0) exitWith {};

//Fetch some information.
_dataArr = CONTROL_DATAI(_control,_index);
_dataArr = call compile format ["%1",_dataArr];
_className = (_dataArr select 0);
_classNameLife = _className;

if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {
    _classNameLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
};

_vehicleColor = ((M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures") select (_dataArr select 1)) select 0);
if (isNil "_vehicleColor") then {_vehicleColor = "Default";};

_vehicleInfo = [_className] call life_fnc_fetchVehInfo;
_trunkSpace = [_className] call life_fnc_vehicleWeightCfg;

_price = M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price");
switch (playerSide) do {
    case civilian: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_CIVILIAN");
    };
    case west: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_COP");
    };
    case independent: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_MEDIC");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_MEDIC");
    };
    case east: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_OPFOR");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_OPFOR");
    };
};
_sellPrice = _purchasePrice * _sellMultiplier;

if (!(_sellPrice isEqualType 0) || _sellPrice < 1) then {_sellPrice = 500;};

ctrlSetText [2804,_vehicleInfo select 2];

(CONTROL(2800,2803)) ctrlSetStructuredText parseText format [
    "<t size='1.18' color='#dceaf0'>%1</t><br/><t color='#7dcbd0'>%2 vehicle</t><br/><br/>
    Retrieval <t color='#8cff9b'>$0</t><br/>
    Storage <t color='#8cff9b'>$0</t><br/>
    Sell value <t color='#8cff9b'>$%3</t><br/><br/>
    Color: %4<br/>
    Top speed: %5 km/h<br/>
    Horsepower: %6<br/>
    Passenger seats: %7<br/>
    Trunk capacity: %8<br/>
    Fuel capacity: %9
    ",
_vehicleInfo select 3,
switch (playerSide) do {case west: {"LEO"}; case independent: {"EMS"}; default {"Civilian"};},
[_sellPrice] call life_fnc_numberText,
_vehicleColor,
(_vehicleInfo select 8),
(_vehicleInfo select 11),
(_vehicleInfo select 10),
if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
(_vehicleInfo select 12)
];
