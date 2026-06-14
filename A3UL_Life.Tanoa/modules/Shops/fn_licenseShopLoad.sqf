#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopLoad.sqf
*/
disableSerialization;
params [
    ["_shop",missionNamespace getVariable ["life_license_shop_type","dmv"],[""]]
];

private _display = findDisplay 8400;
if (isNull _display) exitWith {};

private _shopCfg = missionConfigFile >> "Life_Shops" >> "LicenseShops" >> _shop;
private _fallback = _shop isEqualTo "dmv";
if !(isClass _shopCfg || {_fallback}) exitWith {closeDialog 0;};
life_license_shop_type = _shop;

(_display displayCtrl 8404) ctrlSetText (["Department of Motor Vehicles",getText (_shopCfg >> "title")] select (isClass _shopCfg));
(_display displayCtrl 8405) ctrlSetText (["Civil permits and transportation licenses",getText (_shopCfg >> "subtitle")] select (isClass _shopCfg));

private _licenses = if (isClass _shopCfg) then {
    getArray (_shopCfg >> "licenses")
} else {
    []
};
if (_licenses isEqualTo [] && {_fallback}) then {
    _licenses = ["driver","boat","pilot","trucking","dive","home"];
};

lbClear 8401;
{
    private _license = _x;
    private _cfg = missionConfigFile >> "Licenses" >> _license;
    if (isClass _cfg) then {
        private _side = getText (_cfg >> "side");
        private _owned = LICENSE_VALUE(_license,_side);
        private _name = localize getText (_cfg >> "displayName");
        private _price = [getNumber (_cfg >> "price")] call life_fnc_numberText;
        private _idx = lbAdd [8401,format ["%1    $%2    %3",_name,_price,["Available","Owned"] select _owned]];
        lbSetData [8401,_idx,_license];
        lbSetValue [8401,_idx,getNumber (_cfg >> "price")];
        lbSetColor [8401,_idx,[[0.92,0.96,0.96,1],[0.42,0.88,0.58,1]] select _owned];
    };
} forEach _licenses;

if ((lbSize 8401) > 0) then {
    lbSetCurSel [8401,0];
} else {
    (_display displayCtrl 8402) ctrlSetStructuredText parseText "<t color='#dceaf0'>No licenses are configured for this shop.</t>";
    (_display displayCtrl 8403) ctrlEnable false;
};
