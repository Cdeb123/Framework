#include "..\..\script_macros.hpp"
/*
    File: fn_radialHouseUpgrade.sqf

    Purchases and persists owned-house upgrades.
*/
params [
    ["_house",objNull,[objNull]],
    ["_upgrade","",[""]]
];

if (isNull _house) exitWith {hint localize "STR_House_Door_NotNear";};
if !(_house in life_vehicles) exitWith {hint localize "STR_Garage_NotOwner";};

private _owner = _house getVariable ["house_owner",[]];
if ((count _owner) > 0 && {!((_owner select 0) isEqualTo getPlayerUID player)}) exitWith {
    hint localize "STR_Garage_NotOwner";
};

private _cfg = missionConfigFile >> "Life_HouseUpgrades" >> _upgrade;
if (!isClass _cfg) exitWith {hint "That upgrade is not configured.";};

private _installed = _house getVariable ["house_upgrades",[]];
if (_upgrade in _installed) exitWith {hint "That house upgrade is already installed.";};

private _title = getText (_cfg >> "title");
private _description = getText (_cfg >> "description");
private _price = getNumber (_cfg >> "price");
if (_title isEqualTo "") then {_title = _upgrade;};

private _confirmed = [
    format ["Install %1 for $%2?<br/><br/>%3",_title,[_price] call life_fnc_numberText,_description],
    "House Upgrade",
    localize "STR_Global_Buy",
    localize "STR_Global_Cancel"
] call BIS_fnc_guiMessage;

if (!_confirmed) exitWith {};
if (BANK < _price) exitWith {hint localize "STR_House_NotEnough";};

BANK = BANK - _price;
[1] call SOCK_fnc_updatePartial;

_installed pushBackUnique _upgrade;
_house setVariable ["house_upgrades",_installed,true];

if (life_HC_isActive) then {
    [getPlayerUID player,_house,_installed] remoteExecCall ["HC_fnc_updateHouseUpgrades",HC_Life];
} else {
    [getPlayerUID player,_house,_installed] remoteExecCall ["TON_fnc_updateHouseUpgrades",RSERV];
};

hint format ["%1 installed.",_title];

