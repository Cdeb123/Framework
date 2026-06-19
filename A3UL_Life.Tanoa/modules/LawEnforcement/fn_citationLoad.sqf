#include "..\..\script_macros.hpp"
/*
    File: fn_citationLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8350;
if (isNull _display) exitWith {};

private _target = missionNamespace getVariable ["life_citation_unit",objNull];
private _targetName = if (!isNull _target) then {_target getVariable ["realname",name _target]} else {""};

private _vehicle = objNull;
if (!isNull _target && {!(vehicle _target isEqualTo _target)}) then {
    _vehicle = vehicle _target;
} else {
    private _nearVehicles = nearestObjects [player,["LandVehicle","Ship","Air"],8];
    if !(_nearVehicles isEqualTo []) then {_vehicle = _nearVehicles select 0;};
};

private _vehicleDescription = "";
private _plate = "";
if (!isNull _vehicle) then {
    _vehicleDescription = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
    if (_vehicleDescription isEqualTo "") then {_vehicleDescription = typeOf _vehicle;};
    _plate = getPlateNumber _vehicle;
};

ctrlSetText [8351,format ["Issue Citation | %1",_targetName]];
ctrlSetText [8353,_targetName];
ctrlSetText [8355,_vehicleDescription];
ctrlSetText [8357,_plate];
ctrlSetText [8359,""];
ctrlSetText [8361,"500"];
(_display displayCtrl 8363) ctrlSetStructuredText parseText "<t color='#7ea6b3'>Complete each field, then submit the citation to the selected player for on-scene payment.</t>";
