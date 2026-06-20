/* Compact EMS patient readout used by the F1 wheel. */
params [["_patient",objNull,[objNull]]];
if !(playerSide isEqualTo independent) exitWith {};
if (isNull _patient || {!(_patient isKindOf "CAManBase")} || {player distance _patient > 5}) exitWith {hint "No patient is close enough.";};

private _name = _patient getVariable ["realname",name _patient];
private _damage = round ((damage _patient) * 100);
private _status = if (!alive _patient) then {"UNRESPONSIVE / REVIVABLE"} else {
    if (_damage >= 70) then {"CRITICAL"} else {if (_damage >= 35) then {"INJURED"} else {"STABLE"}}
};
hint parseText format [
    "<t size='1.18' color='#65d7ef'>PATIENT ASSESSMENT</t><br/><t color='#ffffff'>%1</t><br/><br/>Status: <t color='#a8e9f5'>%2</t><br/>Trauma: %3%%<br/>Distance: %4m",
    _name,_status,_damage,round (player distance _patient)
];
