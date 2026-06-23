#include "..\..\script_macros.hpp"
/*
    File: fn_hudUpdate.sqf

    Description:
    Updates the modern framework HUD.
*/
disableSerialization;

private _display = LIFEdisplay;
if (isNull _display) exitWith {};
if (isNull (_display displayCtrl 2200)) exitWith {};

private _hunger = (life_hunger max 0) min 100;
private _thirst = (life_thirst max 0) min 100;
private _health = ((1 - (damage player)) * 100) max 0 min 100;

(_display displayCtrl 2200) progressSetPosition (_hunger / 100);
(_display displayCtrl 2201) progressSetPosition (_health / 100);
(_display displayCtrl 2202) progressSetPosition (_thirst / 100);
(_display displayCtrl 1200) ctrlSetText format ["%1%2",round _hunger,"%"];
(_display displayCtrl 1201) ctrlSetText format ["%1%2",round _health,"%"];
(_display displayCtrl 1202) ctrlSetText format ["%1%2",round _thirst,"%"];

private _foodColor = switch (true) do {
    case (_hunger <= 20): {[1.00,0.24,0.18,0.96]};
    case (_hunger <= 45): {[1.00,0.70,0.20,0.94]};
    default {[0.98,0.64,0.20,0.92]};
};
private _healthColor = switch (true) do {
    case (_health <= 20): {[1.00,0.24,0.18,0.96]};
    case (_health <= 45): {[1.00,0.70,0.20,0.94]};
    default {[0.13,0.85,0.54,0.92]};
};
private _waterColor = switch (true) do {
    case (_thirst <= 20): {[1.00,0.24,0.18,0.96]};
    case (_thirst <= 45): {[1.00,0.70,0.20,0.94]};
    default {[0.0,0.68,0.95,0.92]};
};

(_display displayCtrl 1203) ctrlSetTextColor _foodColor;
(_display displayCtrl 1204) ctrlSetTextColor _healthColor;
(_display displayCtrl 1205) ctrlSetTextColor _waterColor;
(_display displayCtrl 1200) ctrlSetTextColor _foodColor;
(_display displayCtrl 1201) ctrlSetTextColor _healthColor;
(_display displayCtrl 1202) ctrlSetTextColor _waterColor;
(_display displayCtrl 1210) ctrlSetTextColor _foodColor;
(_display displayCtrl 1211) ctrlSetTextColor _healthColor;
(_display displayCtrl 1212) ctrlSetTextColor _waterColor;

private _vehicle = vehicle player;
private _inVehicle = !(_vehicle isEqualTo player);

{
    private _ctrl = _display displayCtrl _x;
    _ctrl ctrlShow false;
    _ctrl ctrlSetFade 1;
    _ctrl ctrlCommit 0;
} forEach [2300,2301,2302,2303,2304,2305,2306,2307];

private _statusSlot = 0;
private _showIcon = {
    params ["_idc","_color"];
    private _ctrl = _display displayCtrl _idc;
    private _x = safezoneX + safezoneW - 0.034 * safezoneW;
    private _y = safezoneY + 0.390 * safezoneH + (_statusSlot * 0.032 * safezoneH);
    _ctrl ctrlSetPosition [_x,_y,0.018 * safezoneW,0.024 * safezoneH];
    _ctrl ctrlShow true;
    _ctrl ctrlSetTextColor _color;
    _ctrl ctrlSetFade 0;
    _ctrl ctrlCommit 0;
    _statusSlot = _statusSlot + 1;
};

if (_inVehicle) then {
    private _beltColor = if (missionNamespace getVariable ["life_seatbelt",false]) then {
        [0.13,0.85,0.54,0.95]
    } else {
        [0.95,0.28,0.24,0.95]
    };
    [2300,_beltColor] call _showIcon;
};

if (player getVariable ["restrained",false]) then {
    [2301,[0.0,0.78,0.92,0.95]] call _showIcon;
};

if (missionNamespace getVariable ["life_effect_poisoned",false]) then {
    [2302,[0.70,1.00,0.18,0.95]] call _showIcon;
};

if (missionNamespace getVariable ["life_effect_virus",false]) then {
    [2303,[0.68,0.55,1.00,0.95]] call _showIcon;
};

if (missionNamespace getVariable ["life_effect_drunk",false]) then {
    [2304,[1.00,0.62,0.20,0.95]] call _showIcon;
};

private _weightRatio = if (life_maxWeight <= 0) then {0} else {life_carryWeight / life_maxWeight};
if (_weightRatio >= 0.90) then {
    private _weightColor = switch (true) do {
        case (_weightRatio >= 1.25): {[1.00,0.12,0.10,0.98]};
        case (_weightRatio >= 1.00): {[1.00,0.55,0.12,0.96]};
        default {[1.00,0.90,0.20,0.92]};
    };
    [2305,_weightColor] call _showIcon;
};

if (count (missionNamespace getVariable ["life_pending_citations",[]]) > 0) then {
    [2306,[1.00,0.90,0.20,0.95]] call _showIcon;
};

if (count (missionNamespace getVariable ["life_pending_warrants",[]]) > 0) then {
    [2307,[1.00,0.24,0.18,0.95]] call _showIcon;
};

[_display] call life_fnc_weaponHUDUpdate;
