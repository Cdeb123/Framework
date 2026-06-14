#include "..\..\script_macros.hpp"
/*
    File: fn_licenseShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8400;
if (isNull _display) exitWith {};
if ((lbCurSel 8401) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_license_shop_type","DMV"];
private _data = call compile (lbData [8401,lbCurSel 8401]);
_data params [
    ["_license","",[""]],
    ["_variable","",[""]],
    ["_displayName","",[""]],
    ["_price",0,[0]],
    ["_side","civ",[""]],
    ["_desc","",[""]]
];

if (_variable isEqualTo "") then {_variable = _license;};
if (_side isEqualTo "") then {_side = "civ";};
private _owned = missionNamespace getVariable [format ["license_%1_%2",_side,_variable],false];
if (_desc isEqualTo "" && {(toLower _shop) isEqualTo "dmv"}) then {
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
    localize _displayName,
    [_price] call life_fnc_numberText,
    ["Available","Already owned"] select _owned,
    _desc
];

(_display displayCtrl 8403) ctrlEnable (!_owned && {playerSide isEqualTo civilian});
