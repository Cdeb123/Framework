#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8700;
if (isNull _display) exitWith {};
if ((lbCurSel 8704) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_weapon_shop_type","gun"];
private _group = missionNamespace getVariable ["life_weapon_shop_group","Civilian"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "WeaponShops" >> _group >> _shop;
private _data = call compile (lbData [8704,lbCurSel 8704]);

if ((_data param [0,"",[""]]) isEqualTo "license") exitWith {
    private _licenseCfg = _shopCfg >> "License";
    private _variable = getText (_licenseCfg >> "variable");
    private _side = getText (_licenseCfg >> "side");
    if (_side isEqualTo "") then {_side = "civ";};
    private _displayName = getText (_licenseCfg >> "displayName");
    private _owned = missionNamespace getVariable [format ["license_%1_%2",_side,_variable],false];
    private _price = getNumber (_licenseCfg >> "price");
    private _name = if (_displayName isEqualTo "") then {_variable} else {localize _displayName};
    private _text = getText (_licenseCfg >> "text");
    if (_text isEqualTo "") then {_text = "No description is available for this license.";};

    (_display displayCtrl 8706) ctrlSetText "\A3\ui_f\data\map\markers\military\dot_CA.paa";
    (_display displayCtrl 8705) ctrlSetStructuredText parseText format [
        "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Price</t><br/>$%2<br/><br/><t color='#7dcbd0'>Status</t><br/>%3<br/><br/><t color='#7dcbd0'>Description</t><br/>%4",
        _name,
        [_price] call life_fnc_numberText,
        ["Available","Already owned"] select _owned,
        _text
    ];
    (_display displayCtrl 8707) ctrlSetText "Buy License";
    (_display displayCtrl 8707) ctrlEnable (!_owned && {playerSide isEqualTo civilian});
};

_data params [
    ["_className","",[""]],
    ["_nickname","",[""]],
    ["_price",0,[0]],
    ["_sellPrice",-1,[0]],
    ["_condition","",[""]],
    ["_text","",[""]],
    ["_category","",[""]],
    ["_categoryTitle","",[""]]
];

private _info = [_className] call life_fnc_fetchCfgDetails;
private _displayName = _nickname;
private _picture = "";
private _short = "";
private _cfgLocation = "";
if !(_info isEqualTo []) then {
    if (_displayName isEqualTo "") then {_displayName = _info select 1;};
    _picture = _info select 2;
    _short = _info select 9;
    _cfgLocation = _info select 6;
};
if (_displayName isEqualTo "") then {_displayName = _className;};
if ((_displayName find "STR_") isEqualTo 0) then {_displayName = localize _displayName;};
if (_text isEqualTo "") then {_text = _short;};
if (_text isEqualTo "") then {_text = "No description is available for this item.";};

private _requiredLicense = getText (_shopCfg >> "requiredLicense");
private _licenseSide = getText (_shopCfg >> "requiredLicenseSide");
if (_licenseSide isEqualTo "") then {_licenseSide = "civ";};
private _hasLicense = true;
if !(_requiredLicense isEqualTo "") then {
    _hasLicense = missionNamespace getVariable [format ["license_%1_%2",_licenseSide,_requiredLicense],false];
};
private _hasAccess = [_condition] call life_fnc_levelCheck;
private _taxData = [_price,"weapons",_className,false] call life_fnc_applyTax;
_taxData params ["_base","_tax","_total","_rate"];

(_display displayCtrl 8706) ctrlSetText _picture;
(_display displayCtrl 8705) ctrlSetStructuredText parseText format [
    "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Category</t><br/>%2<br/><br/><t color='#7dcbd0'>Price</t><br/>$%3 <t color='#8fdde4'>(tax $%4)</t><br/><br/><t color='#7dcbd0'>Access</t><br/>%5<br/><br/><t color='#7dcbd0'>Details</t><br/>%6",
    _displayName,
    _categoryTitle,
    [_total] call life_fnc_numberText,
    [_tax] call life_fnc_numberText,
    ["Locked",["License required","Available"] select _hasLicense] select _hasAccess,
    _text
];
(_display displayCtrl 8707) ctrlSetText "Purchase";
(_display displayCtrl 8707) ctrlEnable (_hasAccess && {_hasLicense});
