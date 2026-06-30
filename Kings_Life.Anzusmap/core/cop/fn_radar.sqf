/*
    File: fn_radar.sqf
    Author: Silly Aussie kid named Jaydon

    Description:
    Looks like weird but radar?
*/
if !(playerSide isEqualTo west) exitWith {};
private ["_speed","_vehicle"];
_vehicle = cursorObject;

if (isNull _vehicle || {!(_vehicle isKindOf "LandVehicle")} || {_vehicle isEqualTo vehicle player}) then {
    private _origin = vehicle player;
    private _forward = vectorDir _origin;
    private _best = objNull;
    private _bestScore = 9999;

    {
        if (!(_x isEqualTo _origin) && {alive _x}) then {
            private _direction = (getPosASL _x) vectorDiff (getPosASL _origin);
            private _distance = _origin distance _x;
            private _dot = (vectorNormalized _direction) vectorDotProduct _forward;
            if (_dot > 0.35 && {_distance < 125}) then {
                private _score = _distance - (_dot * 45);
                if (_score < _bestScore) then {
                    _best = _x;
                    _bestScore = _score;
                };
            };
        };
    } forEach (nearestObjects [_origin,["LandVehicle"],125]);

    _vehicle = _best;
};

if (isNull _vehicle || {!(_vehicle isKindOf "LandVehicle")}) exitWith {
    hint "Radar: no vehicle target found.";
};

if ((vehicle player isEqualTo player) && {!((currentWeapon player) isEqualTo "hgun_P07_snds_F")}) exitWith {
    hint "Radar requires the patrol radar pistol while on foot.";
};

_speed = round (abs (speed _vehicle));

switch (true) do {
    case (_speed > 33 && _speed <= 80): {
        hint parseText format ["<t color='#ffffff'><t size='2'><t align='center'>" +(localize "STR_Cop_Radar")+ "<br/><t color='#33CC33'><t align='center'><t size='1'>" +(localize "STR_Cop_VehSpeed"),_speed];
    };

    case (_speed > 80): {
        hint parseText format ["<t color='#ffffff'><t size='2'><t align='center'>" +(localize "STR_Cop_Radar")+ "<br/><t color='#FF0000'><t align='center'><t size='1'>" +(localize "STR_Cop_VehSpeed"),_speed];
    };

    default {
        hint parseText format ["<t color='#ffffff'><t size='2'><t align='center'>" +(localize "STR_Cop_Radar")+ "<br/><t color='#9BD8FF'><t align='center'><t size='1'>" +(localize "STR_Cop_VehSpeed"),_speed];
    };
};
