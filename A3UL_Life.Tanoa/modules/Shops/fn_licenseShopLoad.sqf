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

private _licenseClasses = if (isClass (_shopCfg >> "Licenses")) then {
    "true" configClasses (_shopCfg >> "Licenses")
} else {
    []
};

if (_licenseClasses isEqualTo [] && {_fallback}) then {
    _licenseClasses = [
        ["driver","driver","STR_License_Driver",500,"civ","Required to legally operate standard road vehicles."],
        ["boat","boat","STR_License_Boat",1000,"civ","Required to legally operate civilian watercraft."],
        ["pilot","pilot","STR_License_Pilot",25000,"civ","Required to legally operate civilian aircraft."],
        ["trucking","trucking","STR_License_Truck",20000,"civ","Required to legally operate commercial transport trucks."],
        ["dive","dive","STR_License_Diving",2000,"civ","Required for legal diving work and underwater equipment access."],
        ["home","home","STR_License_Home",75000,"civ","Required to purchase and register residential property."]
    ];
};

lbClear 8401;
{
    private _license = "";
    private _variable = "";
    private _displayName = "";
    private _priceValue = 0;
    private _side = "civ";
    private _description = "";

    if (_x isEqualType configNull) then {
        _license = configName _x;
        _variable = getText (_x >> "variable");
        _displayName = getText (_x >> "displayName");
        _priceValue = getNumber (_x >> "price");
        _side = getText (_x >> "side");
        _description = getText (_x >> "text");
    } else {
        _x params ["_class","_var","_name","_price","_licenseSide","_text"];
        _license = _class;
        _variable = _var;
        _displayName = _name;
        _priceValue = _price;
        _side = _licenseSide;
        _description = _text;
    };

    if (_variable isEqualTo "") then {_variable = _license;};
    if (_side isEqualTo "") then {_side = "civ";};
    private _varName = format ["license_%1_%2",_side,_variable];
    private _owned = missionNamespace getVariable [_varName,false];
    private _name = localize _displayName;
    private _price = [_priceValue] call life_fnc_numberText;
    private _idx = lbAdd [8401,format ["%1    $%2    %3",_name,_price,["Available","Owned"] select _owned]];
    lbSetData [8401,_idx,str [_license,_variable,_displayName,_priceValue,_side,_description]];
    lbSetValue [8401,_idx,_priceValue];
    lbSetColor [8401,_idx,[[0.92,0.96,0.96,1],[0.42,0.88,0.58,1]] select _owned];
} forEach _licenseClasses;

if ((lbSize 8401) > 0) then {
    lbSetCurSel [8401,0];
} else {
    (_display displayCtrl 8402) ctrlSetStructuredText parseText "<t color='#dceaf0'>No licenses are configured for this shop.</t>";
    (_display displayCtrl 8403) ctrlEnable false;
};
