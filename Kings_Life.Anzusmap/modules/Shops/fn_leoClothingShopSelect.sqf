#include "..\..\script_macros.hpp"
/*
    File: fn_leoClothingShopSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8950;
if (isNull _display) exitWith {};
if ((lbCurSel 8954) < 0) exitWith {};

private _shop = missionNamespace getVariable ["life_leo_clothing_shop_type","cop"];
private _shopCfg = missionConfigFile >> "Life_Shops" >> "LEOClothingShops" >> _shop;
private _department = getText (_shopCfg >> "department");
if (_department isEqualTo "") then {_department = "kcso";};

private _data = call compile (lbData [8954,lbCurSel 8954]);
_data params [
    ["_itemType","",[""]],
    ["_className","",[""]],
    ["_displayName","",[""]],
    ["_price",0,[0]],
    ["_condition","",[""]],
    ["_rank","",[""]],
    ["_subdivisions",[],[[]]],
    ["_rolePermissions",[],[[]]],
    ["_text","",[""]],
    ["_categoryTitle","",[""]],
    ["_picture","",[""]]
];

private _picturePath = _picture;
private _details = "";
if (!(_className isEqualTo "NONE")) then {
    private _info = [_className] call life_fnc_fetchCfgDetails;
    if !(_info isEqualTo []) then {
        if (_displayName isEqualTo "") then {_displayName = _info select 1;};
        if (_picturePath isEqualTo "") then {_picturePath = _info select 2;};
        _details = _info select 9;
    };
};
if (_displayName isEqualTo "") then {_displayName = _className;};
if (_text isEqualTo "") then {_text = _details;};
if (_text isEqualTo "") then {_text = "No description is available for this clothing item.";};
if (_picturePath isEqualTo "") then {_picturePath = "\A3\ui_f\data\map\markers\military\dot_CA.paa";};

private _slotLabel = switch (_itemType) do {
    case "uniform": {"Uniform"};
    case "headgear": {"Headgear"};
    case "goggles": {"Glasses"};
    case "vest": {"Vest"};
    case "backpack": {"Backpack"};
    default {"Gear"};
};

private _rankName = "Any rank";
if !(_rank isEqualTo "") then {
    _rankName = getText (missionConfigFile >> "Life_LEO" >> "Departments" >> _department >> "Ranks" >> _rank >> "displayName");
    if (_rankName isEqualTo "") then {_rankName = _rank;};
    _rankName = format ["%1 or higher",_rankName];
};

private _subdivisionNames = [];
{
    private _subName = getText (missionConfigFile >> "Life_LEO" >> "Departments" >> _department >> "Subdivisions" >> _x >> "displayName");
    if (_subName isEqualTo "") then {_subName = _x;};
    _subdivisionNames pushBack _subName;
} forEach _subdivisions;
private _subdivisionText = if ((count _subdivisionNames) isEqualTo 0) then {"Any subdivision"} else {_subdivisionNames joinString " or "};
private _roleText = if ((count _rolePermissions) isEqualTo 0) then {"No role permission required"} else {_rolePermissions joinString ", "};

private _accessData = [_condition,_rank,_department,_subdivisions,_rolePermissions] call life_fnc_leoClothingShopAccess;
_accessData params ["_access","_reason"];

private _taxData = [_price,"clothing",_className,false] call life_fnc_applyTax;
_taxData params ["_base","_tax","_total","_rate"];

(_display displayCtrl 8956) ctrlSetText _picturePath;
(_display displayCtrl 8955) ctrlSetStructuredText parseText format [
    "<t size='1.2' color='#f2fbfb'>%1</t><br/><t color='#7dcbd0'>Slot</t><br/>%2<br/><t color='#7dcbd0'>Category</t><br/>%3<br/><br/><t color='#7dcbd0'>Price</t><br/>$%4 <t color='#8fdde4'>(tax $%5)</t><br/><br/><t color='#7dcbd0'>Access</t><br/>%6<br/><br/><t color='#7dcbd0'>Requirements</t><br/>Rank: %7<br/>Subdivision: %8<br/>Role: %9<br/><br/><t color='#7dcbd0'>Details</t><br/>%10",
    _displayName,
    _slotLabel,
    _categoryTitle,
    [_total] call life_fnc_numberText,
    [_tax] call life_fnc_numberText,
    ["Locked: " + _reason,"Available"] select _access,
    _rankName,
    _subdivisionText,
    _roleText,
    _text
];

(_display displayCtrl 8957) ctrlSetText (["Remove","Purchase"] select (!(_className isEqualTo "NONE")));
(_display displayCtrl 8957) ctrlEnable _access;
