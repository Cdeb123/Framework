#include "craftingmenu.hpp"

exec_fnc_playerHideoutCrafting = {
    params ["_player", "_hideout"];

    private _craftingMenu = [_player, _hideout] call compile preprocessFileLineNumbers "A3UL_Life.Tanoa\modules\Crafting\craftingmenu.sqf";
    _craftingMenu call BIS_fnc_guiEffectTiles;
};

func playerHideoutCrafting {
    params ["_player", "_hideout"];

    [_player, _hideout] spawn exec_fnc_playerHideoutCrafting;
};

[
    "playerHideoutCrafting",
    "exec_fnc_playerHideoutCrafting",
    "A3UL_Life.Tanoa\modules\Crafting\fn_playerhideoutcrafting.sqf"
] call CBA_fnc_addClassToSystem;

if (isNil "A3UL_Life_Tanoa_Crafting") then {
    A3UL_Life_Tanoa_Crafting = [];
}; else {
    A3UL_Life_Tanoa_Crafting pushBack "playerHideoutCrafting";
};
openmenu = {
    params ["_player", "_hideout"];
    call playerHideoutCrafting;
};
    [_player, _hideout] call playerHideoutCrafting;
};
when_near_hideout = {
    params ["_player", "_hideout"];

    [_player, _hideout] call openmenu;
};

wait = 1.5 if menu_opened then { waitUntil { !menu_opened }; } else { sleep wait; };