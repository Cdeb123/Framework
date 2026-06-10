class life_leo_command_terminal {
    idd = 8100;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_leoCommandLoad";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.022,0.028,0.95};
            x = 0.12 * safezoneW + safezoneX;
            y = 0.12 * safezoneH + safezoneY;
            w = 0.76 * safezoneW;
            h = 0.76 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.78,0.92,1};
            x = 0.12 * safezoneW + safezoneX;
            y = 0.12 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.76 * safezoneH;
        };
        class Title: Life_RscText {
            idc = -1;
            text = "TCSD Command Terminal";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.04;
            x = 0.145 * safezoneW + safezoneX;
            y = 0.145 * safezoneH + safezoneY;
            w = 0.36 * safezoneW;
            h = 0.045 * safezoneH;
        };
    };

    class controls {
        class PlayerList: Life_RscListBox {
            idc = 8101;
            x = 0.145 * safezoneW + safezoneX;
            y = 0.215 * safezoneH + safezoneY;
            w = 0.265 * safezoneW;
            h = 0.405 * safezoneH;
            sizeEx = 0.030;
            onLBSelChanged = "[] call life_fnc_leoCommandSelectPlayer";
        };

        class SelectedInfo: Life_RscStructuredText {
            idc = 8117;
            x = 0.145 * safezoneW + safezoneX;
            y = 0.635 * safezoneH + safezoneY;
            w = 0.265 * safezoneW;
            h = 0.105 * safezoneH;
        };

        class DepartmentCombo: Life_RscCombo {
            idc = 8102;
            x = 0.445 * safezoneW + safezoneX;
            y = 0.215 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.038 * safezoneH;
            onLBSelChanged = "[] call life_fnc_leoCommandLoadDepartment";
        };

        class RankCombo: Life_RscCombo {
            idc = 8103;
            x = 0.650 * safezoneW + safezoneX;
            y = 0.215 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class SubdivisionCombo: Life_RscCombo {
            idc = 8104;
            x = 0.445 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class SteamEdit: Life_RscEdit {
            idc = 8113;
            text = "";
            x = 0.650 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class CharacterEdit: Life_RscEdit {
            idc = 8114;
            text = "";
            x = 0.445 * safezoneW + safezoneX;
            y = 0.335 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class SubdivisionEdit: Life_RscEdit {
            idc = 8115;
            text = "";
            x = 0.445 * safezoneW + safezoneX;
            y = 0.395 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class PermissionEdit: Life_RscEdit {
            idc = 8116;
            text = "";
            x = 0.445 * safezoneW + safezoneX;
            y = 0.455 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.080 * safezoneH;
        };

        class HireButton: Life_RscButtonMenu {
            idc = -1;
            text = "Hire / Update";
            onButtonClick = "[] call life_fnc_leoCommandApply";
            x = 0.445 * safezoneW + safezoneX;
            y = 0.565 * safezoneH + safezoneY;
            w = 0.120 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class FireButton: Life_RscButtonMenu {
            idc = -1;
            text = "Fire";
            onButtonClick = "[] call life_fnc_leoCommandFire";
            x = 0.585 * safezoneW + safezoneX;
            y = 0.565 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.695 * safezoneW + safezoneX;
            y = 0.565 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class FieldHelp: Life_RscStructuredText {
            idc = -1;
            x = 0.445 * safezoneW + safezoneX;
            y = 0.635 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.105 * safezoneH;
            text = "<t color='#40E0F0'>Fields</t><br/>Extra subdivisions and permissions are comma-separated keys. Primary subdivision is assigned from the dropdown.";
        };
    };
};

class life_leo_training_terminal {
    idd = 8200;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_leoTrainingLoad";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.022,0.028,0.95};
            x = 0.10 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.80 * safezoneW;
            h = 0.80 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.78,0.92,1};
            x = 0.10 * safezoneW + safezoneX;
            y = 0.10 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.80 * safezoneH;
        };
        class Title: Life_RscText {
            idc = -1;
            text = "TCSD Training Terminal";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.04;
            x = 0.125 * safezoneW + safezoneX;
            y = 0.125 * safezoneH + safezoneY;
            w = 0.36 * safezoneW;
            h = 0.045 * safezoneH;
        };
    };

    class controls {
        class DocumentList: Life_RscListBox {
            idc = 8201;
            x = 0.125 * safezoneW + safezoneX;
            y = 0.195 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.255 * safezoneH;
            sizeEx = 0.030;
            onLBSelChanged = "[] call life_fnc_leoTrainingSelectDocument";
        };

        class DocumentBody: Life_RscStructuredText {
            idc = 8202;
            x = 0.395 * safezoneW + safezoneX;
            y = 0.195 * safezoneH + safezoneY;
            w = 0.470 * safezoneW;
            h = 0.255 * safezoneH;
        };

        class DocTitleEdit: Life_RscEdit {
            idc = 8203;
            text = "";
            x = 0.125 * safezoneW + safezoneX;
            y = 0.485 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class DocBodyEdit: Life_RscEdit {
            idc = 8204;
            text = "";
            x = 0.395 * safezoneW + safezoneX;
            y = 0.485 * safezoneH + safezoneY;
            w = 0.470 * safezoneW;
            h = 0.070 * safezoneH;
        };

        class RosterList: Life_RscListBox {
            idc = 8205;
            x = 0.125 * safezoneW + safezoneX;
            y = 0.580 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.195 * safezoneH;
            sizeEx = 0.030;
        };

        class TraineeCombo: Life_RscCombo {
            idc = 8206;
            x = 0.395 * safezoneW + safezoneX;
            y = 0.580 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class PhaseCombo: Life_RscCombo {
            idc = 8207;
            x = 0.635 * safezoneW + safezoneX;
            y = 0.580 * safezoneH + safezoneY;
            w = 0.230 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class NotesEdit: Life_RscEdit {
            idc = 8208;
            text = "";
            x = 0.395 * safezoneW + safezoneX;
            y = 0.635 * safezoneH + safezoneY;
            w = 0.470 * safezoneW;
            h = 0.070 * safezoneH;
        };

        class PostDocButton: Life_RscButtonMenu {
            idc = 8211;
            text = "Post Document";
            onButtonClick = "[] call life_fnc_leoTrainingPostDocument";
            x = 0.395 * safezoneW + safezoneX;
            y = 0.735 * safezoneH + safezoneY;
            w = 0.130 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class RosterButton: Life_RscButtonMenu {
            idc = 8212;
            text = "Update Roster";
            onButtonClick = "[] call life_fnc_leoTrainingRosterUpdate";
            x = 0.545 * safezoneW + safezoneX;
            y = 0.735 * safezoneH + safezoneY;
            w = 0.130 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.695 * safezoneW + safezoneX;
            y = 0.735 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.044 * safezoneH;
        };
    };
};
