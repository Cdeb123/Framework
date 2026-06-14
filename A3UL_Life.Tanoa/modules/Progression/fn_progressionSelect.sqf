/*
    File: fn_progressionSelect.sqf
*/
disableSerialization;
private _display = findDisplay 8600;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 8610;
if ((lbCurSel _list) < 0) exitWith {};
private _data = _list lbData (lbCurSel _list);
private _tab = missionNamespace getVariable ["life_progression_tab","xp"];
missionNamespace setVariable ["life_progression_selected",_data];

private _detail = "";
switch (_tab) do {
    case "perks": {
        private _cfg = missionConfigFile >> "Life_Progression" >> "Perks" >> _data;
        private _rank = [_data] call life_fnc_perkLevel;
        private _maxRank = getNumber (_cfg >> "maxRank");
        private _cost = getNumber (_cfg >> "cost");
        private _points = missionNamespace getVariable ["life_perk_points",0];
        ctrlEnable [8612,(_rank < _maxRank && {_points >= _cost})];
        _detail = format [
            "<img image='%1' size='3'/><br/><t color='#00c7eb' size='1.25'>%2</t><br/><t color='#8fa4aa'>%3</t><br/><br/>Rank: <t color='#9edb5a'>%4/%5</t><br/>Cost: <t color='#9edb5a'>%6 point(s)</t><br/>Available: <t color='#9edb5a'>%7</t><br/><br/>%8",
            getText (_cfg >> "icon"),
            getText (_cfg >> "title"),
            getText (_cfg >> "group"),
            _rank,
            _maxRank,
            _cost,
            _points,
            getText (_cfg >> "description")
        ];
    };
    default {
        private _cfg = missionConfigFile >> "Life_Progression" >> "Categories" >> _data;
        private _info = [_data] call life_fnc_progressionLevelInfo;
        private _unlock = [_data] call life_fnc_progressionNextUnlock;
        private _percent = round ((_info select 4) * 100);
        ctrlEnable [8612,false];
        _detail = format [
            "<img image='%1' size='3'/><br/><t color='#00c7eb' size='1.25'>%2</t><br/><br/>Level <t color='#9edb5a'>%3</t><br/>XP: <t color='#dceff1'>%4</t><br/>Next level: <t color='#dceff1'>%5 / %6</t> (%7%8)<br/><br/><t color='#8fa4aa'>Next unlock</t><br/>%9 - %10<br/><br/>%11",
            getText (_cfg >> "icon"),
            getText (_cfg >> "title"),
            _info select 0,
            [(_info select 3)] call life_fnc_numberText,
            [(_info select 1)] call life_fnc_numberText,
            [(_info select 2)] call life_fnc_numberText,
            _percent,
            "%",
            _unlock select 0,
            _unlock select 1,
            getText (_cfg >> "description")
        ];
    };
};

(_display displayCtrl 8611) ctrlSetStructuredText parseText _detail;
