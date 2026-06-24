/* Central client-side HUD preference handler. Add future HUD options here. */
params [
    ["_option","",[""]],
    ["_value",0,[0,true,""]]
];

private _cfg = missionConfigFile >> "Life_WeaponHUD";
switch (_option) do {
    case "weapon": {
        profileNamespace setVariable ["life_hud_weapon_enabled",_value isEqualTo 1];
    };
    case "stamina": {
        profileNamespace setVariable ["life_hud_stamina_enabled",_value isEqualTo 1];
    };
    case "ballistics": {
        profileNamespace setVariable ["life_hud_ballistics_enabled",_value isEqualTo 1];
    };
    case "theme": {
        if (isClass (_cfg >> "Themes" >> _value)) then {
            profileNamespace setVariable ["life_hud_theme",_value];
        };
    };
    case "scale": {
        private _scale = ((_value / 100) max 0.80) min 1.25;
        profileNamespace setVariable ["life_hud_scale",_scale];
        if (!isNull (findDisplay 2900)) then {ctrlSetText [2985,format ["%1%2",round (_scale * 100),"%"]];};
    };
    case "opacity": {
        private _opacity = ((_value / 100) max 0.45) min 1;
        profileNamespace setVariable ["life_hud_opacity",_opacity];
        if (!isNull (findDisplay 2900)) then {ctrlSetText [2987,format ["%1%2",round (_opacity * 100),"%"]];};
    };
    case "reset": {
        profileNamespace setVariable ["life_hud_weapon_enabled",(getNumber (_cfg >> "defaultWeaponHUD")) isEqualTo 1];
        profileNamespace setVariable ["life_hud_stamina_enabled",(getNumber (_cfg >> "defaultStaminaHUD")) isEqualTo 1];
        profileNamespace setVariable ["life_hud_ballistics_enabled",(getNumber (_cfg >> "defaultBallistics")) isEqualTo 1];
        profileNamespace setVariable ["life_vehicle_hud_enabled",(getNumber (missionConfigFile >> "Life_VehicleHUD" >> "defaultVehicleHUD")) isEqualTo 1];
        profileNamespace setVariable ["life_vehicle_gps_enabled",(getNumber (missionConfigFile >> "Life_VehicleHUD" >> "defaultGPS")) isEqualTo 1];
        profileNamespace setVariable ["life_hud_theme",getText (_cfg >> "defaultTheme")];
        profileNamespace setVariable ["life_hud_scale",getNumber (_cfg >> "defaultScale")];
        profileNamespace setVariable ["life_hud_opacity",getNumber (_cfg >> "defaultOpacity")];
        [] call life_fnc_settingsMenu;
    };
};

saveProfileNamespace;
[] call life_fnc_hudUpdate;
