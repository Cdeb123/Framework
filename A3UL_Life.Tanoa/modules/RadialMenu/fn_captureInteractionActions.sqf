/*
    File: fn_captureInteractionActions.sqf

    Migrates framework addActions into local radial-menu metadata, then removes
    their scroll-wheel entries. The original statement, arguments, condition,
    and radius are retained so map-authored vendors keep working through F1.
*/
params [["_target",objNull,[objNull]]];
if (isNull _target) exitWith {[]};

private _stored = _target getVariable ["life_radial_legacy_actions",[]];
{
    private _id = _x;
    private _params = actionParams [_target,_id];
    if !(_params isEqualTo []) then {
        private _title = _params param [0,"Interact",[""]];
        private _statement = _params param [1,{},[{},""]];
        private _arguments = _params param [2,nil];
        private _priority = _params param [3,0,[0]];
        private _condition = _params param [7,"true",[""]];
        private _radius = _params param [8,6,[0]];
        private _signature = str [_title,_statement,_arguments,_condition,_radius];

        if ((_stored findIf {(_x param [6,"",[""]]) isEqualTo _signature}) < 0) then {
            _stored pushBack [_title,_statement,_arguments,_condition,_radius,_priority,_signature];
        };
        _target removeAction _id;
    };
} forEach (actionIDs _target);

_target setVariable ["life_radial_legacy_actions",_stored,false];
_stored
