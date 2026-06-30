#include "..\..\script_macros.hpp"
/*
    File: fn_openLicenseShop.sqf
*/
private _shop = "DMV";
if (_this isEqualType "") then {
    _shop = _this;
};
if (_this isEqualType []) then {
    if ((count _this) > 3) then {
        _shop = _this param [3,"DMV",[""]];
    } else {
        _shop = _this param [0,"DMV",[""]];
    };
};
if ((toLower _shop) isEqualTo "dmv") then {_shop = "DMV";};

if (dialog) exitWith {};
if !(isClass (missionConfigFile >> "Life_Shops" >> "LicenseShops" >> _shop) || {(toLower _shop) isEqualTo "dmv"}) exitWith {};

life_license_shop_type = _shop;
createDialog "life_license_shop";
[] spawn {
    disableSerialization;
    uiSleep 0.05;
    [missionNamespace getVariable ["life_license_shop_type","DMV"]] call life_fnc_licenseShopLoad;
};
