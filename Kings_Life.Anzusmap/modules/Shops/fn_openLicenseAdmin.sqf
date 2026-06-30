#include "..\..\script_macros.hpp"
/*
    File: fn_openLicenseAdmin.sqf
*/
params [
    ["_target",objNull,[objNull]]
];

if (playerSide != west) exitWith {hint "Only law enforcement can access license actions.";};
if (isNull _target || {!isPlayer _target}) exitWith {hint "No valid citizen selected.";};
if (player distance _target > 5) exitWith {hint "Move closer to the citizen.";};

life_license_admin_target = _target;
if !(dialog) then {
    createDialog "life_leo_license_admin";
} else {
    [] call life_fnc_licenseAdminLoad;
};
