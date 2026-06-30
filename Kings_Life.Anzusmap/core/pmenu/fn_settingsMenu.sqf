#include "..\..\script_macros.hpp"
/*
    File: fn_settingsMenu
    Author: Bryan "Tonic" Boardwine

    Description:
    Setup the settings menu.
*/
if (isNull (findDisplay 2900)) then {
    if (!createDialog "SettingsMenu") exitWith {hint localize "STR_NOTF_menuWillNotOpen";};
};

disableSerialization;

ctrlSetText[2902, format ["%1", life_settings_viewDistanceFoot]];
ctrlSetText[2912, format ["%1", life_settings_viewDistanceCar]];
ctrlSetText[2922, format ["%1", life_settings_viewDistanceAir]];

/* Set up the sliders */
{
    slidersetRange [(_x select 0),100,8000];
    CONTROL(2900,(_x select 0)) sliderSetSpeed [100,100,100];
    sliderSetPosition [(_x select 0),(_x select 1)];
} forEach [[2901,life_settings_viewDistanceFoot],[2911,life_settings_viewDistanceCar],[2921,life_settings_viewDistanceAir]];


if (isNil "life_settings_revealObjects") then {
    life_settings_enableNewsBroadcast = profileNamespace setVariable ["life_enableNewsBroadcast",true];
    life_settings_enableSidechannel = profileNamespace setVariable ["life_enableSidechannel",true];
    life_settings_tagson = profileNamespace setVariable ["life_settings_tagson",true];
    life_settings_revealObjects = profileNamespace setVariable ["life_settings_revealObjects",true];
};

CONTROL(2900,2971) cbSetChecked life_settings_enableSidechannel;
CONTROL(2900,2973) cbSetChecked life_settings_enableNewsBroadcast;
CONTROL(2900,2970) cbSetChecked life_settings_tagson;
CONTROL(2900,2972) cbSetChecked life_settings_revealObjects;

/* Client-only HUD preferences */
private _hudCfg = missionConfigFile >> "Life_WeaponHUD";
private _weaponHUD = profileNamespace getVariable ["life_hud_weapon_enabled",(getNumber (_hudCfg >> "defaultWeaponHUD")) isEqualTo 1];
private _staminaHUD = profileNamespace getVariable ["life_hud_stamina_enabled",(getNumber (_hudCfg >> "defaultStaminaHUD")) isEqualTo 1];
private _ballisticsHUD = profileNamespace getVariable ["life_hud_ballistics_enabled",(getNumber (_hudCfg >> "defaultBallistics")) isEqualTo 1];
private _hudScale = profileNamespace getVariable ["life_hud_scale",getNumber (_hudCfg >> "defaultScale")];
private _hudOpacity = profileNamespace getVariable ["life_hud_opacity",getNumber (_hudCfg >> "defaultOpacity")];
private _hudTheme = profileNamespace getVariable ["life_hud_theme",getText (_hudCfg >> "defaultTheme")];

CONTROL(2900,2980) cbSetChecked _weaponHUD;
CONTROL(2900,2981) cbSetChecked _staminaHUD;
CONTROL(2900,2982) cbSetChecked _ballisticsHUD;

sliderSetRange [2984,80,125];
sliderSetSpeed [2984,5,5];
sliderSetPosition [2984,_hudScale * 100];
ctrlSetText [2985,format ["%1%2",round (_hudScale * 100),"%"]];

sliderSetRange [2986,45,100];
sliderSetSpeed [2986,5,5];
sliderSetPosition [2986,_hudOpacity * 100];
ctrlSetText [2987,format ["%1%2",round (_hudOpacity * 100),"%"]];

lbClear 2983;
private _selectedTheme = 0;
{
    private _index = lbAdd [2983,getText (_x >> "displayName")];
    private _className = configName _x;
    lbSetData [2983,_index,_className];
    if (_className isEqualTo _hudTheme) then {_selectedTheme = _index;};
} forEach ("true" configClasses (_hudCfg >> "Themes"));
lbSetCurSel [2983,_selectedTheme];
