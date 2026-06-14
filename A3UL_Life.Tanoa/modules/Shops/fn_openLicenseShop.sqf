#include "..\..\script_macros.hpp"
/*
    File: fn_openLicenseShop.sqf
*/
params [
    ["_shop","dmv",[""]]
];

if (dialog) exitWith {};
if !(isClass (missionConfigFile >> "Life_Shops" >> "LicenseShops" >> _shop)) exitWith {};

life_license_shop_type = _shop;
createDialog "life_license_shop";
