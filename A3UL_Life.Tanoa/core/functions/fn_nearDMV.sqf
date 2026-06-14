/*
    File: fn_nearDMV.sqf

    Description:
    Checks whether the player is near a configured DMV license shop stand.
*/
params [
    ["_radius",5,[0]]
];

private _near = false;
private _shops = ["license_shop_1","license_shop_2","license_shop_3","license_shop_4"];

{
    private _shop = missionNamespace getVariable [_x,objNull];
    if (!isNull _shop && {typeOf _shop isEqualTo "Land_InfoStand_V1_F"} && {player distance _shop <= _radius}) exitWith {
        _near = true;
    };

    if ((getMarkerColor _x) != "" && {player distance2D (getMarkerPos _x) <= _radius}) exitWith {
        _near = true;
    };
} forEach _shops;

_near;
