#include "..\..\script_macros.hpp"
/*
    File: fn_repackMagazines.sqf

    Description:
    Consolidates rounds from non-loaded inventory magazines without creating ammo.
    Produces full magazines plus, when necessary, one partial remainder.
*/
params [
    ["_requestedClass","",[""]]
];

if (!alive player) exitWith {};
if ((time - life_action_delay) < 0.2) exitWith {hint localize "STR_NOTF_ActionDelay";};

if (_requestedClass isEqualTo "") then {
    private _modernDisplay = findDisplay 8700;
    if (!isNull _modernDisplay && {(lbCurSel 8704) >= 0}) then {
        private _data = call compile (lbData [8704,lbCurSel 8704]);
        if (_data isEqualType [] && {(count _data) > 0}) then {
            _requestedClass = _data param [0,"",[""]];
        };
    };

    private _legacyDisplay = findDisplay 38400;
    if (_requestedClass isEqualTo "" && {!isNull _legacyDisplay} && {(lbCurSel 38403) >= 0}) then {
        _requestedClass = lbData [38403,lbCurSel 38403];
    };
};

private _inventoryMagazines = (magazinesAmmoFull player) select {
    !(_x param [2,false,[false]])
};
private _classes = [];
{
    private _className = _x param [0,"",[""]];
    if (
        !(_className isEqualTo "")
        && {_requestedClass isEqualTo "" || {_className isEqualTo _requestedClass}}
        && {getNumber (configFile >> "CfgMagazines" >> _className >> "count") > 1}
    ) then {
        _classes pushBackUnique _className;
    };
} forEach _inventoryMagazines;

private _repackedTypes = 0;
private _oldMagazineCount = 0;
private _newMagazineCount = 0;
private _roundsPreserved = 0;

{
    private _className = _x;
    private _capacity = getNumber (configFile >> "CfgMagazines" >> _className >> "count");
    private _entries = _inventoryMagazines select {(_x param [0,"",[""]]) isEqualTo _className};
    private _totalRounds = 0;
    private _partialCount = 0;

    {
        private _rounds = ((_x param [1,0,[0]]) max 0) min _capacity;
        _totalRounds = _totalRounds + _rounds;
        if (_rounds < _capacity) then {_partialCount = _partialCount + 1;};
    } forEach _entries;

    private _fullCount = floor (_totalRounds / _capacity);
    private _remainder = _totalRounds mod _capacity;
    private _packedCount = _fullCount + ([0,1] select (_remainder > 0));
    private _shouldRepack = (_partialCount > 1) || {_packedCount < (count _entries)};

    if (_shouldRepack) then {
        private _entryCount = count _entries;
        for "_i" from 1 to _entryCount do {player removeMagazine _className;};
        for "_i" from 1 to _fullCount do {player addMagazine [_className,_capacity];};
        if (_remainder > 0) then {player addMagazine [_className,_remainder];};

        _repackedTypes = _repackedTypes + 1;
        _oldMagazineCount = _oldMagazineCount + _entryCount;
        _newMagazineCount = _newMagazineCount + _packedCount;
        _roundsPreserved = _roundsPreserved + _totalRounds;
    };
} forEach _classes;

if (_repackedTypes isEqualTo 0) exitWith {
    hint "No selected magazines can be consolidated. Repacking needs at least two partial or empty magazines of the same type.";
};

life_action_delay = time;
hint format [
    "Repacked %1 magazine type(s): %2 magazines became %3. All %4 rounds were preserved.",
    _repackedTypes,
    _oldMagazineCount,
    _newMagazineCount,
    _roundsPreserved
];
