/*
    File: fn_progressionDutyLoop.sqf
*/
if (missionNamespace getVariable ["life_progression_duty_loop",false]) exitWith {};
missionNamespace setVariable ["life_progression_duty_loop",true];

private _tick = getNumber (missionConfigFile >> "Life_Progression" >> "dutyTickSeconds");
if (_tick < 60) then {_tick = 60;};

for "_i" from 0 to 1 step 0 do {
    uiSleep _tick;
    if (alive player) then {
        switch (playerSide) do {
            case west: {
                ["leo",getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> "leoDuty"),"Time on duty",false] call life_fnc_addXP;
            };
            case independent: {
                ["ems",getNumber (missionConfigFile >> "Life_Progression" >> "XPEvents" >> "emsDuty"),"Time on duty",false] call life_fnc_addXP;
            };
        };
    };
};
