/*
    File: fn_vehicleHUDUpdate.sqf

    Description:
    Draws the client-side vehicle HUD with fuel, speed, GPS, and damage data.
*/
disableSerialization;
params [["_display",displayNull,[displayNull]]];
if (isNull _display) exitWith {};

private _vehicleControls = [
    2500,2501,2502,2503,2504,2505,2506,2507,2508,2509,2510,2511,2512,2513,
    1500,1501,1502,1503,1504,1505,1506,1507,1508,1509,1510,1511,1512,1513,1514
];
{
    private _ctrl = _display displayCtrl _x;
    _ctrl ctrlShow false;
    _ctrl ctrlSetFade 1;
    _ctrl ctrlCommit 0;
} forEach _vehicleControls;

private _vehicle = vehicle player;
private _cfg = missionConfigFile >> "Life_VehicleHUD";
private _enabled = profileNamespace getVariable ["life_vehicle_hud_enabled",(getNumber (_cfg >> "defaultVehicleHUD")) isEqualTo 1];
private _show = _enabled && {!(_vehicle isEqualTo player)} && {alive _vehicle} && {(_vehicle isKindOf "LandVehicle") || {_vehicle isKindOf "Air"}};
if (!_show) exitWith {};

private _weaponCfg = missionConfigFile >> "Life_WeaponHUD";
private _scale = (profileNamespace getVariable ["life_hud_scale",getNumber (_weaponCfg >> "defaultScale")]) max 0.80 min 1.25;
private _opacity = (profileNamespace getVariable ["life_hud_opacity",getNumber (_weaponCfg >> "defaultOpacity")]) max 0.45 min 1;
private _themeName = profileNamespace getVariable ["life_hud_theme",getText (_weaponCfg >> "defaultTheme")];
private _themeCfg = _weaponCfg >> "Themes" >> _themeName;
if !(isClass _themeCfg) then {_themeCfg = _weaponCfg >> "Themes" >> getText (_weaponCfg >> "defaultTheme");};

private _accent = getArray (_themeCfg >> "accent");
private _panel = getArray (_themeCfg >> "panel");
private _panelAlt = getArray (_themeCfg >> "panelAlt");
private _text = getArray (_themeCfg >> "text");
private _muted = getArray (_themeCfg >> "muted");
private _withAlpha = {
    params ["_color","_alpha"];
    [_color param [0,1],_color param [1,1],_color param [2,1],_alpha]
};
private _damageColor = {
    params [["_value",0,[0]]];
    switch (true) do {
        case (_value >= 0.72): {[1.00,0.22,0.16,0.98]};
        case (_value >= 0.42): {[1.00,0.68,0.20,0.96]};
        default {[0.13,0.85,0.54,0.94]};
    }
};
private _fuelColor = {
    params [["_value",1,[0]]];
    switch (true) do {
        case (_value <= 0.15): {[1.00,0.22,0.16,0.98]};
        case (_value <= 0.35): {[1.00,0.68,0.20,0.96]};
        default {_accent};
    }
};
private _hitDamage = {
    params [["_terms",[],[[]]],["_fallback",0,[0]]];

    private _result = _fallback;
    private _hitpoints = getAllHitPointsDamage _vehicle;
    if ((count _hitpoints) >= 3) then {
        private _names = _hitpoints select 0;
        private _values = _hitpoints select 2;
        private _matches = [];
        for "_i" from 0 to ((count _names) - 1) do {
            private _name = toLower (_names select _i);
            if ((_terms findIf {[_x,_name] call BIS_fnc_inString}) >= 0) then {
                _matches pushBack (_values select _i);
            };
        };

        if !(_matches isEqualTo []) then {
            private _sum = 0;
            {_sum = _sum + _x;} forEach _matches;
            _result = _sum / (count _matches);
        };
    };

    _result max 0 min 1
};

private _defaultGPS = (getNumber (_cfg >> "defaultGPS")) isEqualTo 1;
private _gpsEnabled = profileNamespace getVariable ["life_vehicle_gps_enabled",_defaultGPS];
private _unitW = safezoneW * _scale;
private _unitH = safezoneH * _scale;
private _w = 0.250 * _unitW;
private _h = ([0.162,0.218] select _gpsEnabled) * _unitH;
private _hudX = safezoneX + safezoneW - _w - (0.018 * safezoneW);
private _hudY = safezoneY + safezoneH - _h - (0.030 * safezoneH);

private _baseControls = [2500,2501,2502,2503,2504,2505,2506,2507,2508,2509,2510,2511,2512,1500,1501,1502,1503,1504,1505,1506,1507,1508,1509,1510];
{(_display displayCtrl _x) ctrlShow true; (_display displayCtrl _x) ctrlSetFade 0;} forEach _baseControls;
if (_gpsEnabled) then {
    {(_display displayCtrl _x) ctrlShow true; (_display displayCtrl _x) ctrlSetFade 0;} forEach [2513,1511,1512,1513,1514];
};

(_display displayCtrl 2500) ctrlSetPosition [_hudX + 0.003 * _unitW,_hudY + 0.004 * _unitH,_w,_h];
(_display displayCtrl 2501) ctrlSetPosition [_hudX,_hudY,_w,_h];
(_display displayCtrl 2502) ctrlSetPosition [_hudX,_hudY,0.004 * _unitW,_h];
(_display displayCtrl 1500) ctrlSetPosition [_hudX + 0.012 * _unitW,_hudY + 0.008 * _unitH,0.150 * _unitW,0.018 * _unitH];
(_display displayCtrl 1501) ctrlSetPosition [_hudX + 0.012 * _unitW,_hudY + 0.032 * _unitH,0.070 * _unitW,0.043 * _unitH];
(_display displayCtrl 1502) ctrlSetPosition [_hudX + 0.082 * _unitW,_hudY + 0.049 * _unitH,0.038 * _unitW,0.017 * _unitH];
(_display displayCtrl 1503) ctrlSetPosition [_hudX + 0.124 * _unitW,_hudY + 0.033 * _unitH,0.106 * _unitW,0.017 * _unitH];
(_display displayCtrl 1504) ctrlSetPosition [_hudX + 0.124 * _unitW,_hudY + 0.054 * _unitH,0.060 * _unitW,0.016 * _unitH];
(_display displayCtrl 1505) ctrlSetPosition [_hudX + 0.185 * _unitW,_hudY + 0.054 * _unitH,0.045 * _unitW,0.016 * _unitH];
(_display displayCtrl 2503) ctrlSetPosition [_hudX + 0.124 * _unitW,_hudY + 0.076 * _unitH,0.106 * _unitW,0.007 * _unitH];
(_display displayCtrl 2504) ctrlSetPosition [_hudX + 0.124 * _unitW,_hudY + 0.076 * _unitH,0.106 * (fuel _vehicle) * _unitW,0.007 * _unitH];
(_display displayCtrl 1506) ctrlSetPosition [_hudX + 0.012 * _unitW,_hudY + 0.089 * _unitH,0.218 * _unitW,0.016 * _unitH];

private _rowY = [_hudY + 0.111 * _unitH,_hudY + 0.126 * _unitH,_hudY + 0.141 * _unitH,_hudY + 0.156 * _unitH];
private _barX = _hudX + 0.060 * _unitW;
private _barW = 0.170 * _unitW;
{
    _x params ["_labelIdc","_backIdc","_fillIdc","_row","_damage","_label"];
    (_display displayCtrl _labelIdc) ctrlSetPosition [_hudX + 0.012 * _unitW,_rowY select _row,0.045 * _unitW,0.012 * _unitH];
    (_display displayCtrl _backIdc) ctrlSetPosition [_barX,_rowY select _row, _barW,0.006 * _unitH];
    (_display displayCtrl _fillIdc) ctrlSetPosition [_barX,_rowY select _row, _barW * _damage,0.006 * _unitH];
    (_display displayCtrl _labelIdc) ctrlSetText format ["%1 %2%3",_label,round (_damage * 100),"%"];
    (_display displayCtrl _fillIdc) ctrlSetBackgroundColor ([_damage] call _damageColor);
} forEach [
    [1507,2505,2506,0,(damage _vehicle) max 0 min 1,"HULL"],
    [1508,2507,2508,1,[["engine","motor"],damage _vehicle] call _hitDamage,"ENG"],
    [1509,2509,2510,2,[["fuel","tank"],damage _vehicle] call _hitDamage,"FUEL"],
    [1510,2511,2512,3,if (_vehicle isKindOf "Air") then {[["rotor","avionics"],damage _vehicle] call _hitDamage} else {[["wheel","track","tire"],damage _vehicle] call _hitDamage},"MOB"]
];

if (_gpsEnabled) then {
    private _gpsY = _hudY + 0.174 * _unitH;
    (_display displayCtrl 2513) ctrlSetPosition [_hudX + 0.012 * _unitW,_gpsY,0.218 * _unitW,0.034 * _unitH];
    (_display displayCtrl 1511) ctrlSetPosition [_hudX + 0.018 * _unitW,_gpsY + 0.004 * _unitH,0.135 * _unitW,0.013 * _unitH];
    (_display displayCtrl 1512) ctrlSetPosition [_hudX + 0.018 * _unitW,_gpsY + 0.018 * _unitH,0.090 * _unitW,0.012 * _unitH];
    (_display displayCtrl 1513) ctrlSetPosition [_hudX + 0.110 * _unitW,_gpsY + 0.018 * _unitH,0.052 * _unitW,0.012 * _unitH];
    (_display displayCtrl 1514) ctrlSetPosition [_hudX + 0.164 * _unitW,_gpsY + 0.018 * _unitH,0.060 * _unitW,0.012 * _unitH];
};

private _speedMph = round ((abs speed _vehicle) * 0.621371);
private _fuel = fuel _vehicle;
private _vehicleName = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
if (_vehicleName isEqualTo "") then {_vehicleName = typeOf _vehicle;};
private _role = if (driver _vehicle isEqualTo player) then {"DRIVER"} else {"PASSENGER"};
private _class = if (_vehicle isKindOf "Air") then {"AIR"} else {"GROUND"};
private _fuelPct = round (_fuel * 100);

(_display displayCtrl 1500) ctrlSetText "VEHICLE STATUS";
(_display displayCtrl 1501) ctrlSetText str _speedMph;
(_display displayCtrl 1502) ctrlSetText "MPH";
(_display displayCtrl 1503) ctrlSetText format ["%1 / %2",_class,_role];
(_display displayCtrl 1504) ctrlSetText "FUEL";
(_display displayCtrl 1505) ctrlSetText format ["%1%2",_fuelPct,"%"];
(_display displayCtrl 1506) ctrlSetText toUpper _vehicleName;

if (_gpsEnabled) then {
    private _locations = nearestLocations [getPosATL player,["NameCityCapital","NameCity","NameVillage","NameLocal","Hill"],2500];
    private _locationName = if (_locations isEqualTo []) then {worldName} else {text (_locations select 0)};
    if (_locationName isEqualTo "") then {_locationName = worldName;};
    private _dir = getDir _vehicle;
    private _cardinals = ["N","NE","E","SE","S","SW","W","NW","N"];
    private _heading = _cardinals select (round (_dir / 45));

    (_display displayCtrl 1511) ctrlSetText format ["GPS: %1",toUpper _locationName];
    (_display displayCtrl 1512) ctrlSetText format ["GRID %1",mapGridPosition player];
    (_display displayCtrl 1513) ctrlSetText format ["HDG %1",round _dir];
    (_display displayCtrl 1514) ctrlSetText _heading;
};

(_display displayCtrl 2500) ctrlSetBackgroundColor ([_panel,0.38 * _opacity] call _withAlpha);
(_display displayCtrl 2501) ctrlSetBackgroundColor ([_panel,0.94 * _opacity] call _withAlpha);
(_display displayCtrl 2502) ctrlSetBackgroundColor ([_accent,0.95 * _opacity] call _withAlpha);
(_display displayCtrl 2503) ctrlSetBackgroundColor ([_panelAlt,0.95 * _opacity] call _withAlpha);
(_display displayCtrl 2504) ctrlSetBackgroundColor ([_fuel] call _fuelColor);
{(_display displayCtrl _x) ctrlSetBackgroundColor ([_panelAlt,0.88 * _opacity] call _withAlpha);} forEach [2505,2507,2509,2511];
(_display displayCtrl 2513) ctrlSetBackgroundColor ([_panelAlt,0.72 * _opacity] call _withAlpha);

(_display displayCtrl 1500) ctrlSetFontHeight (0.014 * _unitH);
(_display displayCtrl 1501) ctrlSetFontHeight (0.040 * _unitH);
{(_display displayCtrl _x) ctrlSetFontHeight (0.012 * _unitH);} forEach [1502,1503,1504,1505,1507,1508,1509,1510,1511,1512,1513,1514];
(_display displayCtrl 1506) ctrlSetFontHeight (0.011 * _unitH);

(_display displayCtrl 1500) ctrlSetTextColor ([_accent,0.96] call _withAlpha);
(_display displayCtrl 1501) ctrlSetTextColor ([_text,1] call _withAlpha);
(_display displayCtrl 1502) ctrlSetTextColor ([_muted,0.94] call _withAlpha);
(_display displayCtrl 1503) ctrlSetTextColor ([_muted,0.94] call _withAlpha);
(_display displayCtrl 1504) ctrlSetTextColor ([_muted,0.94] call _withAlpha);
(_display displayCtrl 1505) ctrlSetTextColor ([_fuel] call _fuelColor);
(_display displayCtrl 1506) ctrlSetTextColor ([_text,0.88] call _withAlpha);
{(_display displayCtrl _x) ctrlSetTextColor ([_muted,0.92] call _withAlpha);} forEach [1507,1508,1509,1510,1512,1513];
(_display displayCtrl 1511) ctrlSetTextColor ([_text,0.94] call _withAlpha);
(_display displayCtrl 1514) ctrlSetTextColor ([_accent,0.96] call _withAlpha);

{(_display displayCtrl _x) ctrlCommit 0;} forEach _vehicleControls;
