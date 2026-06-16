#include "..\..\script_macros.hpp"
/*
    File: fn_characterPreviewUpdate.sqf

    Description:
    Applies selected/edited face to the preview player.
*/
disableSerialization;
private _display = findDisplay 7800;
if (isNull _display) exitWith {};

private _face = "";
private _selected = lbCurSel 7801;

if (_selected >= 0) then {
    private _data = lbData [7801,_selected];
    if !(_data in ["","__new"]) then {
        private _character = call compile _data;
        if (_character isEqualType [] && {(count _character) >= 8}) then {
            _face = _character select 6;
            (_display displayCtrl 7803) ctrlSetText (_character select 2);
            (_display displayCtrl 7804) ctrlSetText (_character select 3);
            (_display displayCtrl 7805) ctrlSetText (_character select 4);
            (_display displayCtrl 7806) ctrlSetText (_character select 5);
        };
    } else {
        if (_data isEqualTo "__new" && {missionNamespace getVariable ["life_character_selectedChanged",false]}) then {
            (_display displayCtrl 7803) ctrlSetText "";
            (_display displayCtrl 7804) ctrlSetText "";
            (_display displayCtrl 7805) ctrlSetText "";
            (_display displayCtrl 7806) ctrlSetText "";
        };
    };
};

life_character_selectedChanged = false;

if (_face isEqualTo "") then {_face = lbData [7807,lbCurSel 7807];};

if !(_face isEqualTo "") then {player setFace _face;};

if (!isNil "life_character_preview_camera" && {!isNull life_character_preview_camera}) then {
    life_character_preview_camera camSetTarget (player modelToWorld [0,0,1.25]);
    life_character_preview_camera camSetPos (player modelToWorld [0,4.2,1.65]);
    life_character_preview_camera camCommit 0.15;
};
