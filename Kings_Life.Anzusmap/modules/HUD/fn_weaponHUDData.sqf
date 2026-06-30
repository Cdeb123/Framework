/*
    Resolves readable weapon/ammunition details and a penetration rating.
    Returns: weapon name, icon, ammo label, magazine name, rating, rating band.
*/
params [
    ["_weapon","",[""]],
    ["_magazine","",[""]]
];

private _weaponCfg = configFile >> "CfgWeapons" >> _weapon;
private _magazineCfg = configFile >> "CfgMagazines" >> _magazine;
private _ammoClass = getText (_magazineCfg >> "ammo");
private _ammoCfg = configFile >> "CfgAmmo" >> _ammoClass;

private _weaponName = getText (_weaponCfg >> "displayName");
if (_weaponName isEqualTo "") then {_weaponName = "Weapon";};
private _icon = getText (_weaponCfg >> "picture");

private _magazineName = getText (_magazineCfg >> "displayNameShort");
if (_magazineName isEqualTo "") then {_magazineName = getText (_magazineCfg >> "displayName");};
if (_magazineName isEqualTo "") then {_magazineName = "No magazine";};

private _ammoLabel = _magazineName;
private _penetration = 0;
private _hudCfg = missionConfigFile >> "Life_WeaponHUD";

{
    if ((_x param [0,"",[""]]) isEqualTo _magazine) exitWith {
        _ammoLabel = _x param [1,_ammoLabel,[""]];
        _penetration = _x param [2,0,[0]];
    };
} forEach getArray (_hudCfg >> "ammoProfiles");

{
    if ((_x param [0,"",[""]]) isEqualTo _weapon) exitWith {
        _penetration = _x param [1,_penetration,[0]];
        private _override = _x param [2,"",[""]];
        if !(_override isEqualTo "") then {_ammoLabel = _override;};
    };
} forEach getArray (_hudCfg >> "weaponProfiles");

if (_penetration <= 0) then {
    private _caliber = getNumber (_ammoCfg >> "caliber");
    private _speed = getNumber (_ammoCfg >> "typicalSpeed");
    _penetration = round (((_caliber * 16) + (_speed / 35)) max 1 min 100);
};

private _band = switch (true) do {
    case (_penetration >= 70): {"VERY HIGH"};
    case (_penetration >= 50): {"HIGH"};
    case (_penetration >= 30): {"MEDIUM"};
    case (_penetration >= 12): {"LOW"};
    default {"MINIMAL"};
};

[_weaponName,_icon,_ammoLabel,_magazineName,_penetration,_band]
