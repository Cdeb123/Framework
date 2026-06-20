/*
    File: fn_interactionSanitizer.sqf

    Continuously migrates nearby framework actions away from the action menu.
    A short interval also catches actions added by pumps, placed equipment, and
    late-running mission initialization without doing a global object scan.
*/
if (missionNamespace getVariable ["life_interaction_sanitizer_running",false]) exitWith {};
life_interaction_sanitizer_running = true;

while {true} do {
    private _targets = [player];
    if (!isNull cursorObject && {player distance cursorObject < 24}) then {
        _targets pushBackUnique cursorObject;
    };
    {
        if (!isNull _x) then {_targets pushBackUnique _x;};
    } forEach (player nearObjects 18);

    {[_x] call life_fnc_captureInteractionActions;} forEach _targets;
    uiSleep 0.75;
};
