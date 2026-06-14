#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_license_shop_type","dmv"],[""]]
];

private _display = findDisplay 8300;
if (isNull _display) exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "LicenseShops" >> _shop;
if !(isClass _shopCfg) exitWith {closeDialog 0;};
life_license_shop_type = _shop;

(_display displayCtrl 8304) ctrlSetText getText (_shopCfg >> "title");
(_display displayCtrl 8305) ctrlSetText getText (_shopCfg >> "subtitle");

lbClear 8301;
{
    private _license = _x;
    private _cfg = missionConfigFile >> "Licenses" >> _license;
    if (isClass _cfg) then {
        private _side = getText (_cfg >> "side");
        private _owned = LICENSE_VALUE(_license,_side);
        private _name = localize getText (_cfg >> "displayName");
        private _price = [getNumber (_cfg >> "price")] call life_fnc_numberText;
        private _idx = lbAdd [8301,format ["%1    $%2    %3",_name,_price,["Available","Owned"] select _owned]];
        lbSetData [8301,_idx,_license];
        lbSetValue [8301,_idx,getNumber (_cfg >> "price")];
        lbSetColor [8301,_idx,[[0.92,0.96,0.96,1],[0.42,0.88,0.58,1]] select _owned];
    };
} forEach getArray (_shopCfg >> "licenses");

if ((lbSize 8301) > 0) then {
    lbSetCurSel [8301,0];
} else {
    (_display displayCtrl 8302) ctrlSetStructuredText parseText "<t color='#dceaf0'>No licenses are configured for this shop.</t>";
    (_display displayCtrl 8303) ctrlEnable false;
};
