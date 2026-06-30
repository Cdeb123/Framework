/* Draws the client-only weapon and stamina panels in the top-left corner. */
disableSerialization;
params [["_display",displayNull,[displayNull]]];
if (isNull _display) exitWith {};

private _cfg = missionConfigFile >> "Life_WeaponHUD";
private _weaponEnabled = profileNamespace getVariable ["life_hud_weapon_enabled",(getNumber (_cfg >> "defaultWeaponHUD")) isEqualTo 1];
private _staminaEnabled = profileNamespace getVariable ["life_hud_stamina_enabled",(getNumber (_cfg >> "defaultStaminaHUD")) isEqualTo 1];
private _ballisticsEnabled = profileNamespace getVariable ["life_hud_ballistics_enabled",(getNumber (_cfg >> "defaultBallistics")) isEqualTo 1];
private _scale = (profileNamespace getVariable ["life_hud_scale",getNumber (_cfg >> "defaultScale")]) max 0.80 min 1.25;
private _opacity = (profileNamespace getVariable ["life_hud_opacity",getNumber (_cfg >> "defaultOpacity")]) max 0.45 min 1;
private _themeName = profileNamespace getVariable ["life_hud_theme",getText (_cfg >> "defaultTheme")];
private _themeCfg = _cfg >> "Themes" >> _themeName;
if !(isClass _themeCfg) then {_themeCfg = _cfg >> "Themes" >> getText (_cfg >> "defaultTheme");};

private _accent = getArray (_themeCfg >> "accent");
private _panel = getArray (_themeCfg >> "panel");
private _panelAlt = getArray (_themeCfg >> "panelAlt");
private _text = getArray (_themeCfg >> "text");
private _muted = getArray (_themeCfg >> "muted");
private _withAlpha = {
    params ["_color","_alpha"];
    [_color param [0,1],_color param [1,1],_color param [2,1],_alpha]
};

private _weapon = currentWeapon player;
private _muzzle = currentMuzzle player;
private _weaponVisible = _weaponEnabled && {alive player} && {!(_weapon isEqualTo "")} && {!(_weapon in ["Throw","Put","Binocular","Rangefinder","Laserdesignator"])};
private _staminaVisible = _staminaEnabled && {alive player} && {isNull objectParent player};
private _weaponControls = [2400,2401,2402,2403,2404,2405,2406,1400,1401,1402,1403,1404,1405,1406];
private _staminaControls = [2420,2421,2422,2423,2424,1420,1421];
{(_display displayCtrl _x) ctrlShow _weaponVisible;} forEach _weaponControls;
{(_display displayCtrl _x) ctrlShow _staminaVisible;} forEach _staminaControls;
if (!_weaponVisible && {!_staminaVisible}) exitWith {};

private _unitW = safezoneW * _scale;
private _unitH = safezoneH * _scale;
private _x = safezoneX + (0.014 * safezoneW);
private _y = safezoneY + (0.038 * safezoneH);
private _w = 0.226 * _unitW;
private _h = 0.142 * _unitH;

if (_weaponVisible) then {
    private _magazine = currentMagazine player;
    private _capacity = getNumber (configFile >> "CfgMagazines" >> _magazine >> "count");
    private _loaded = if (_muzzle isEqualTo "") then {0} else {player ammo _muzzle};
    private _reserve = 0;
    {
        if ((_x param [0,"",[""]]) isEqualTo _magazine && {!(_x param [2,false,[false]])}) then {
            _reserve = _reserve + (_x param [1,0,[0]]);
        };
    } forEach magazinesAmmoFull player;
    private _total = _loaded + _reserve;
    private _magRatio = if (_capacity <= 0) then {0} else {(_loaded / _capacity) max 0 min 1};
    ([_weapon,_magazine] call life_fnc_weaponHUDData) params ["_weaponName","_icon","_ammoLabel","_magazineName","_penetration","_band"];

    (_display displayCtrl 2400) ctrlSetPosition [_x + 0.003 * _unitW,_y + 0.004 * _unitH,_w,_h];
    (_display displayCtrl 2401) ctrlSetPosition [_x,_y,_w,_h];
    (_display displayCtrl 2402) ctrlSetPosition [_x,_y,0.004 * _unitW,_h];
    (_display displayCtrl 2403) ctrlSetPosition [_x + 0.176 * _unitW,_y + 0.014 * _unitH,0.038 * _unitW,0.043 * _unitH];
    (_display displayCtrl 2406) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.061 * _unitH,0.202 * _unitW,0.001 * _unitH];
    (_display displayCtrl 1400) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.010 * _unitH,0.158 * _unitW,0.023 * _unitH];
    (_display displayCtrl 1401) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.034 * _unitH,0.158 * _unitW,0.019 * _unitH];
    (_display displayCtrl 1402) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.067 * _unitH,0.045 * _unitW,0.036 * _unitH];
    (_display displayCtrl 1403) ctrlSetPosition [_x + 0.059 * _unitW,_y + 0.068 * _unitH,0.078 * _unitW,0.018 * _unitH];
    (_display displayCtrl 1404) ctrlSetPosition [_x + 0.059 * _unitW,_y + 0.087 * _unitH,0.078 * _unitW,0.017 * _unitH];
    (_display displayCtrl 1405) ctrlSetPosition [_x + 0.142 * _unitW,_y + 0.068 * _unitH,0.072 * _unitW,0.036 * _unitH];
    (_display displayCtrl 2404) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.111 * _unitH,0.202 * _unitW,0.007 * _unitH];
    (_display displayCtrl 2405) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.111 * _unitH,(0.202 * _magRatio) * _unitW,0.007 * _unitH];
    (_display displayCtrl 1406) ctrlSetPosition [_x + 0.012 * _unitW,_y + 0.121 * _unitH,0.202 * _unitW,0.015 * _unitH];

    (_display displayCtrl 1400) ctrlSetFontHeight (0.019 * _unitH);
    (_display displayCtrl 1401) ctrlSetFontHeight (0.014 * _unitH);
    (_display displayCtrl 1402) ctrlSetFontHeight (0.035 * _unitH);
    {(_display displayCtrl _x) ctrlSetFontHeight (0.013 * _unitH);} forEach [1403,1404,1406];
    (_display displayCtrl 1405) ctrlSetFontHeight (0.012 * _unitH);

    (_display displayCtrl 2400) ctrlSetBackgroundColor ([[_panel param [0,0],_panel param [1,0],_panel param [2,0],1],0.38 * _opacity] call _withAlpha);
    (_display displayCtrl 2401) ctrlSetBackgroundColor ([_panel,0.94 * _opacity] call _withAlpha);
    (_display displayCtrl 2402) ctrlSetBackgroundColor ([_accent,0.95 * _opacity] call _withAlpha);
    (_display displayCtrl 2403) ctrlSetTextColor ([_text,0.90] call _withAlpha);
    (_display displayCtrl 2406) ctrlSetBackgroundColor ([_muted,0.25 * _opacity] call _withAlpha);
    (_display displayCtrl 2404) ctrlSetBackgroundColor ([_panelAlt,0.95 * _opacity] call _withAlpha);
    private _ammoColor = switch (true) do {
        case (_magRatio <= 0.15): {[1.00,0.25,0.18,0.98]};
        case (_magRatio <= 0.35): {[1.00,0.68,0.20,0.96]};
        default {_accent};
    };
    (_display displayCtrl 2405) ctrlSetBackgroundColor ([_ammoColor,0.96] call _withAlpha);
    (_display displayCtrl 1400) ctrlSetTextColor ([_text,0.98] call _withAlpha);
    (_display displayCtrl 1401) ctrlSetTextColor ([_accent,0.94] call _withAlpha);
    (_display displayCtrl 1402) ctrlSetTextColor ([_ammoColor,1] call _withAlpha);
    {(_display displayCtrl _x) ctrlSetTextColor ([_muted,0.94] call _withAlpha);} forEach [1403,1404,1406];
    (_display displayCtrl 1405) ctrlSetTextColor ([_text,0.90] call _withAlpha);

    (_display displayCtrl 2403) ctrlSetText _icon;
    (_display displayCtrl 1400) ctrlSetText (toUpper _weaponName);
    (_display displayCtrl 1401) ctrlSetText (toUpper _ammoLabel);
    (_display displayCtrl 1402) ctrlSetText str _loaded;
    (_display displayCtrl 1403) ctrlSetText format ["/ %1  MAG",_capacity];
    (_display displayCtrl 1404) ctrlSetText format ["%1  RESERVE",_reserve];
    (_display displayCtrl 1405) ctrlSetText (if (_ballisticsEnabled) then {format ["PEN %1 / 100  •  %2",_penetration,_band]} else {""});
    (_display displayCtrl 1405) ctrlShow _ballisticsEnabled;
    (_display displayCtrl 1406) ctrlSetText format ["%1 ROUNDS TOTAL   •   %2",_total,toUpper _magazineName];
    {(_display displayCtrl _x) ctrlCommit 0;} forEach _weaponControls;
};

if (_staminaVisible) then {
    private _staminaY = if (_weaponVisible) then {_y + 0.150 * _unitH} else {_y};
    private _stamina = ((getStamina player) / 60) max 0 min 1;
    private _staminaColor = switch (true) do {
        case (_stamina <= 0.20): {[1.00,0.25,0.18,0.98]};
        case (_stamina <= 0.45): {[1.00,0.68,0.20,0.96]};
        default {_accent};
    };

    (_display displayCtrl 2420) ctrlSetPosition [_x + 0.003 * _unitW,_staminaY + 0.003 * _unitH,_w,0.044 * _unitH];
    (_display displayCtrl 2421) ctrlSetPosition [_x,_staminaY,_w,0.044 * _unitH];
    (_display displayCtrl 2422) ctrlSetPosition [_x,_staminaY,0.004 * _unitW,0.044 * _unitH];
    (_display displayCtrl 1420) ctrlSetPosition [_x + 0.012 * _unitW,_staminaY + 0.007 * _unitH,0.145 * _unitW,0.016 * _unitH];
    (_display displayCtrl 1421) ctrlSetPosition [_x + 0.167 * _unitW,_staminaY + 0.007 * _unitH,0.047 * _unitW,0.016 * _unitH];
    (_display displayCtrl 2423) ctrlSetPosition [_x + 0.012 * _unitW,_staminaY + 0.029 * _unitH,0.202 * _unitW,0.006 * _unitH];
    (_display displayCtrl 2424) ctrlSetPosition [_x + 0.012 * _unitW,_staminaY + 0.029 * _unitH,(0.202 * _stamina) * _unitW,0.006 * _unitH];

    (_display displayCtrl 2420) ctrlSetBackgroundColor ([_panel,0.38 * _opacity] call _withAlpha);
    (_display displayCtrl 2421) ctrlSetBackgroundColor ([_panel,0.94 * _opacity] call _withAlpha);
    (_display displayCtrl 2422) ctrlSetBackgroundColor ([_staminaColor,0.95] call _withAlpha);
    (_display displayCtrl 2423) ctrlSetBackgroundColor ([_panelAlt,0.95 * _opacity] call _withAlpha);
    (_display displayCtrl 2424) ctrlSetBackgroundColor ([_staminaColor,0.96] call _withAlpha);
    (_display displayCtrl 1420) ctrlSetFontHeight (0.013 * _unitH);
    (_display displayCtrl 1421) ctrlSetFontHeight (0.013 * _unitH);
    (_display displayCtrl 1420) ctrlSetTextColor ([_muted,0.94] call _withAlpha);
    (_display displayCtrl 1421) ctrlSetTextColor ([_staminaColor,1] call _withAlpha);
    (_display displayCtrl 1420) ctrlSetText "STAMINA";
    (_display displayCtrl 1421) ctrlSetText format ["%1%2",round (_stamina * 100),"%"];
    {(_display displayCtrl _x) ctrlCommit 0;} forEach _staminaControls;
};
