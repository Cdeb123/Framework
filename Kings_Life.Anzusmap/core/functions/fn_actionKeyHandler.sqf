/*
    Legacy action-key compatibility.

    Framework interactions now resolve through the contextual F1 wheel. This
    entry point remains so old key presets and scripts open the same system.
*/
if (dialog && {isNull (findDisplay 9200)}) exitWith {};
[] call life_fnc_openRadialMenu;
