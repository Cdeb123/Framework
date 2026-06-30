/*
    File: fn_progressionLoad.sqf
*/
disableSerialization;
private _display = findDisplay 8600;
if (isNull _display) exitWith {};
if !(missionNamespace getVariable ["life_progression_loaded",false]) then {[] call life_fnc_progressionInit;};

private _tab = missionNamespace getVariable ["life_progression_tab","xp"];
private _selected = missionNamespace getVariable ["life_progression_selected",""];

private _charInfo = ["character"] call life_fnc_progressionLevelInfo;
private _roleCategory = switch (playerSide) do {case west: {"leo"}; case independent: {"ems"}; default {"gang"};};
private _roleInfo = [_roleCategory] call life_fnc_progressionLevelInfo;
private _craftInfo = ["crafting"] call life_fnc_progressionLevelInfo;

(_display displayCtrl 8602) ctrlSetStructuredText parseText format [
    "<t color='#dceff1'>Level %1</t><br/><t color='#8fa4aa'>Perk Points:</t> <t color='#9edb5a'>%2</t>",
    _charInfo select 0,
    missionNamespace getVariable ["life_perk_points",0]
];
(_display displayCtrl 8603) progressSetPosition (_charInfo select 4);
(_display displayCtrl 8604) progressSetPosition (_roleInfo select 4);
(_display displayCtrl 8605) progressSetPosition (_craftInfo select 4);
ctrlSetText [8606,format ["CHAR %1",_charInfo select 0]];
ctrlSetText [8607,format ["%1 %2",getText (missionConfigFile >> "Life_Progression" >> "Categories" >> _roleCategory >> "shortTitle"),_roleInfo select 0]];
ctrlSetText [8608,format ["CRAFT %1",_craftInfo select 0]];

private _list = _display displayCtrl 8610;
lbClear _list;

switch (_tab) do {
    case "perks": {
        {
            private _perk = configName _x;
            private _rank = [_perk] call life_fnc_perkLevel;
            private _maxRank = getNumber (_x >> "maxRank");
            _list lbAdd format ["%1  %2/%3",getText (_x >> "title"),_rank,_maxRank];
            _list lbSetData [(lbSize _list) - 1,_perk];
            _list lbSetPicture [(lbSize _list) - 1,getText (_x >> "icon")];
        } forEach ("true" configClasses (missionConfigFile >> "Life_Progression" >> "Perks"));
        ctrlShow [8612,true];
    };
    case "skills": {
        {
            private _category = configName _x;
            private _info = [_category] call life_fnc_progressionLevelInfo;
            _list lbAdd format ["%1  Level %2",getText (_x >> "title"),_info select 0];
            _list lbSetData [(lbSize _list) - 1,_category];
            _list lbSetPicture [(lbSize _list) - 1,getText (_x >> "icon")];
        } forEach ("true" configClasses (missionConfigFile >> "Life_Progression" >> "Categories"));
        ctrlShow [8612,false];
    };
    default {
        {
            private _category = configName _x;
            private _info = [_category] call life_fnc_progressionLevelInfo;
            _list lbAdd format ["%1  %2 XP",getText (_x >> "title"),[(_info select 3)] call life_fnc_numberText];
            _list lbSetData [(lbSize _list) - 1,_category];
            _list lbSetPicture [(lbSize _list) - 1,getText (_x >> "icon")];
        } forEach ("true" configClasses (missionConfigFile >> "Life_Progression" >> "Categories"));
        ctrlShow [8612,false];
    };
};

private _targetIndex = 0;
if !(_selected isEqualTo "") then {
    for "_i" from 0 to ((lbSize _list) - 1) do {
        if ((_list lbData _i) isEqualTo _selected) exitWith {_targetIndex = _i;};
    };
};
if ((lbSize _list) > 0) then {_list lbSetCurSel _targetIndex;};
[] call life_fnc_progressionSelect;
