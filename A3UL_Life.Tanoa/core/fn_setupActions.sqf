/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Framework interactions are exposed through the F1 radial menu. Nearby
    mission addActions are migrated at runtime so legacy map vendors continue
    to work without populating the scroll wheel.
*/

life_actions = [];
[] spawn life_fnc_interactionSanitizer;
