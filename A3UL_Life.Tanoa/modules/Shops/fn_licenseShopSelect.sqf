#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8400;
if (isNull _display) exitWith {};
if ((lbCurSel 8401) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_license_shop_type","dmv"];
private _license = lbData [8401,lbCurSel 8401];
private _cfg = missionConfigFile >> "Licenses" >> _license;
if !(isClass _cfg) exitWith {};

private _side = getText (_cfg >> "side");
private _owned = LICENSE_VALUE(_license,_side);
private _price = getNumber (_cfg >> "price");
private _desc = getText (missionConfigFile >> "Life_Shops" >> "LicenseShops" >> _shop >> "Descriptions" >> _license >> "text");
if (_desc isEqualTo "" && {_shop isEqualTo "dmv"}) then {
    _desc = switch (_license) do {
        case "driver": {"Required to legally operate standard road vehicles."};
        case "boat": {"Required to legally operate civilian watercraft."};
        case "pilot": {"Required to legally operate civilian aircraft."};
        case "trucking": {"Required to legally operate commercial transport trucks."};
        case "dive": {"Required for legal diving work and underwater equipment access."};
        case "home": {"Required to purchase and register residential property."};
        default {""};
    };
};
if (_desc isEqualTo "") then {_desc = "No description is available for this license.";};

(_display displayCtrl 8402) ctrlSetStructuredText parseText format [
    "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Price</t><br/>$%2<br/><br/><t color='#7dcbd0'>Status</t><br/>%3<br/><br/><t color='#7dcbd0'>Description</t><br/>%4",
    localize getText (_cfg >> "displayName"),
    [_price] call life_fnc_numberText,
    ["Available","Already owned"] select _owned,
    _desc
];

(_display displayCtrl 8403) ctrlEnable (!_owned && {playerSide isEqualTo civilian});
