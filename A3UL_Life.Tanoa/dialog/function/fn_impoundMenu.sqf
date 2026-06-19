#include "..\..\script_macros.hpp"
/*
    File: fn_impoundMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Not actually a impound menu, may act as confusion to some but that is what I wanted.
    The purpose of this menu is it is now called a 'Garage' where vehicles are stored (persistent ones).
*/
disableSerialization;
private _vehicles = param [0,[],[[]]];

waitUntil {!isNull (findDisplay 2800)};
private _display = findDisplay 2800;
private _control = _display displayCtrl 2802;

private _typeLabel = switch (missionNamespace getVariable ["life_garage_type","Car"]) do {
    case "Air": {"Aircraft"};
    case "Ship": {"Watercraft"};
    default {"Ground Vehicles"};
};
private _roleLabel = switch (playerSide) do {
    case west: {"LEO"};
    case independent: {"EMS"};
    default {"Civilian"};
};
private _character = missionNamespace getVariable ["life_character_data",[]];
private _characterName = if ((count _character) > 2) then {_character select 2} else {profileName};

(_display displayCtrl 2801) ctrlSetText format ["%1 %2 Garage",_roleLabel,_typeLabel];
(_display displayCtrl 2805) ctrlSetText format ["%1 | Character vehicles only | Storage and retrieval are free",_characterName];
(_display displayCtrl 2803) ctrlSetStructuredText parseText "<t color='#7dcbd0'>Select a stored vehicle to view its details.</t>";
(_display displayCtrl 2804) ctrlSetText "";
lbClear _control;

if (count _vehicles isEqualTo 0) exitWith {
    ctrlShow [2810,false];
    ctrlShow [2811,false];
    (_display displayCtrl 2803) ctrlSetStructuredText parseText format [
        "<t size='1.12' color='#dceaf0'>No stored %1</t><br/><br/><t color='#7dcbd0'>This garage only shows %2 vehicles owned by %3.</t><br/><br/>Bring an owned vehicle nearby and use <t color='#8cff9b'>Store Nearby - $0</t>.",
        toLower _typeLabel,
        _roleLabel,
        _characterName
    ];
};

{
    private _vehicleInfo = [(_x select 2)] call life_fnc_fetchVehInfo;
    _control lbAdd (_vehicleInfo select 3);
    private _tmp = str [(_x select 2),(_x select 8)];
    _control lbSetData [(lbSize _control)-1,_tmp];
    _control lbSetPicture [(lbSize _control)-1,(_vehicleInfo select 2)];
    _control lbSetValue [(lbSize _control)-1,(_x select 0)];
} forEach _vehicles;

ctrlShow [2810,false];
ctrlShow [2811,false];
if ((lbSize _control) > 0) then {_control lbSetCurSel 0;};
