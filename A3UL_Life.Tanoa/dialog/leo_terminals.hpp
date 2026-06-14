class life_leo_command_terminal {
    idd = 8100;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn life_fnc_leoCommandLoad";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.010,0.014,0.020,0.96};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.84 * safezoneW;
            h = 0.84 * safezoneH;
        };
        class HeaderBar: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.030,0.040,0.98};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.84 * safezoneW;
            h = 0.092 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.72,0.92,1};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.84 * safezoneH;
        };
        class Logo: Life_RscPictureKeepAspect {
            idc = -1;
            text = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            colorText[] = {0.0,0.72,0.92,0.95};
            x = 0.105 * safezoneW + safezoneX;
            y = 0.102 * safezoneH + safezoneY;
            w = 0.035 * safezoneW;
            h = 0.050 * safezoneH;
        };
        class Title: Life_RscText {
            idc = -1;
            text = "TCSD Command Suite";
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.042;
            x = 0.148 * safezoneW + safezoneX;
            y = 0.097 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = -1;
            text = "Ranks, divisions, roles, and department documents";
            colorText[] = {0.56,0.70,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.150 * safezoneW + safezoneX;
            y = 0.137 * safezoneH + safezoneY;
            w = 0.360 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class RosterFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.40};
            x = 0.103 * safezoneW + safezoneX;
            y = 0.196 * safezoneH + safezoneY;
            w = 0.258 * safezoneW;
            h = 0.585 * safezoneH;
        };
        class AssignmentFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.38};
            x = 0.382 * safezoneW + safezoneX;
            y = 0.196 * safezoneH + safezoneY;
            w = 0.225 * safezoneW;
            h = 0.585 * safezoneH;
        };
        class DocumentFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.38};
            x = 0.628 * safezoneW + safezoneX;
            y = 0.196 * safezoneH + safezoneY;
            w = 0.249 * safezoneW;
            h = 0.585 * safezoneH;
        };
    };

    class controls {
        class RosterLabel: Life_RscText {
            idc = -1;
            text = "Online Roster";
            colorText[] = {0.62,0.88,0.96,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.207 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class PlayerList: Life_RscListBox {
            idc = 8101;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.242 * safezoneH + safezoneY;
            w = 0.238 * safezoneW;
            h = 0.405 * safezoneH;
            sizeEx = 0.027;
            onLBSelChanged = "[] call life_fnc_leoCommandSelectPlayer";
        };
        class SelectedInfo: Life_RscStructuredText {
            idc = 8117;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.662 * safezoneH + safezoneY;
            w = 0.238 * safezoneW;
            h = 0.102 * safezoneH;
            size = 0.026;
        };

        class AssignmentLabel: Life_RscText {
            idc = -1;
            text = "Assignment";
            colorText[] = {0.62,0.88,0.96,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.392 * safezoneW + safezoneX;
            y = 0.207 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class DepartmentLabel: Life_RscText {
            idc = -1;
            text = "Department";
            colorText[] = {0.66,0.76,0.82,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.392 * safezoneW + safezoneX;
            y = 0.244 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class DepartmentCombo: Life_RscCombo {
            idc = 8102;
            x = 0.392 * safezoneW + safezoneX;
            y = 0.270 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
            onLBSelChanged = "[] call life_fnc_leoCommandLoadDepartment";
        };
        class RankLabel: DepartmentLabel {
            text = "Rank";
            y = 0.312 * safezoneH + safezoneY;
        };
        class RankCombo: Life_RscCombo {
            idc = 8103;
            x = 0.392 * safezoneW + safezoneX;
            y = 0.338 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class SubdivisionLabel: DepartmentLabel {
            text = "Primary Division";
            y = 0.380 * safezoneH + safezoneY;
        };
        class SubdivisionCombo: Life_RscCombo {
            idc = 8104;
            x = 0.392 * safezoneW + safezoneX;
            y = 0.406 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class SteamLabel: DepartmentLabel {
            text = "Steam ID";
            y = 0.448 * safezoneH + safezoneY;
        };
        class SteamEdit: Life_RscEdit {
            idc = 8113;
            text = "";
            x = 0.392 * safezoneW + safezoneX;
            y = 0.474 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class CharacterLabel: DepartmentLabel {
            text = "Character UID";
            y = 0.516 * safezoneH + safezoneY;
        };
        class CharacterEdit: Life_RscEdit {
            idc = 8114;
            text = "";
            x = 0.392 * safezoneW + safezoneX;
            y = 0.542 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class DivisionKeysLabel: DepartmentLabel {
            text = "Extra Divisions";
            y = 0.584 * safezoneH + safezoneY;
        };
        class SubdivisionEdit: Life_RscEdit {
            idc = 8115;
            text = "";
            x = 0.392 * safezoneW + safezoneX;
            y = 0.610 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class RoleKeysLabel: DepartmentLabel {
            text = "Roles / Permissions";
            y = 0.652 * safezoneH + safezoneY;
        };
        class PermissionEdit: Life_RscEdit {
            idc = 8116;
            text = "";
            x = 0.392 * safezoneW + safezoneX;
            y = 0.678 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.050 * safezoneH;
        };
        class HireButton: Life_RscButtonMenu {
            idc = -1;
            text = "Save";
            onButtonClick = "[] call life_fnc_leoCommandApply";
            x = 0.392 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.067 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class FireButton: Life_RscButtonMenu {
            idc = -1;
            text = "Remove";
            onButtonClick = "[] call life_fnc_leoCommandFire";
            x = 0.469 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.067 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.546 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.067 * safezoneW;
            h = 0.040 * safezoneH;
        };

        class DocumentsLabel: Life_RscText {
            idc = -1;
            text = "Command Documents";
            colorText[] = {0.62,0.88,0.96,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.638 * safezoneW + safezoneX;
            y = 0.207 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class CommandDocList: Life_RscListBox {
            idc = 8123;
            x = 0.638 * safezoneW + safezoneX;
            y = 0.242 * safezoneH + safezoneY;
            w = 0.228 * safezoneW;
            h = 0.168 * safezoneH;
            sizeEx = 0.026;
            onLBSelChanged = "[] call life_fnc_leoCommandSelectDocument";
        };
        class CommandDocBody: Life_RscStructuredText {
            idc = 8124;
            x = 0.638 * safezoneW + safezoneX;
            y = 0.426 * safezoneH + safezoneY;
            w = 0.228 * safezoneW;
            h = 0.160 * safezoneH;
            size = 0.025;
        };
        class CommandDocTitleLabel: DepartmentLabel {
            text = "New Title";
            x = 0.638 * safezoneW + safezoneX;
            y = 0.604 * safezoneH + safezoneY;
        };
        class CommandDocTitleEdit: Life_RscEdit {
            idc = 8121;
            text = "";
            x = 0.638 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.228 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class CommandDocBodyLabel: CommandDocTitleLabel {
            text = "New Body";
            y = 0.672 * safezoneH + safezoneY;
        };
        class CommandDocBodyEdit: Life_RscEdit {
            idc = 8122;
            text = "";
            x = 0.638 * safezoneW + safezoneX;
            y = 0.698 * safezoneH + safezoneY;
            w = 0.228 * safezoneW;
            h = 0.050 * safezoneH;
        };
        class PostCommandDocButton: Life_RscButtonMenu {
            idc = 8125;
            text = "Post Document";
            onButtonClick = "[] call life_fnc_leoCommandPostDocument";
            x = 0.724 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.142 * safezoneW;
            h = 0.040 * safezoneH;
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
            colorBackground[] = {0.012,0.014,0.018,0.96};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.84 * safezoneW;
            h = 0.84 * safezoneH;
        };
        class HeaderBar: Life_RscText {
            idc = -1;
            colorBackground[] = {0.030,0.026,0.018,0.98};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.84 * safezoneW;
            h = 0.092 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.95,0.62,0.20,1};
            x = 0.08 * safezoneW + safezoneX;
            y = 0.08 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.84 * safezoneH;
        };
        class Logo: Life_RscPictureKeepAspect {
            idc = -1;
            text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\documents_ca.paa";
            colorText[] = {0.95,0.62,0.20,0.95};
            x = 0.105 * safezoneW + safezoneX;
            y = 0.102 * safezoneH + safezoneY;
            w = 0.035 * safezoneW;
            h = 0.050 * safezoneH;
        };
        class Title: Life_RscText {
            idc = -1;
            text = "TCSD Training Academy";
            colorText[] = {1.0,0.96,0.88,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.042;
            x = 0.148 * safezoneW + safezoneX;
            y = 0.097 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = -1;
            text = "FTO documents, academy phases, and trainee progress";
            colorText[] = {0.78,0.68,0.52,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.150 * safezoneW + safezoneX;
            y = 0.137 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class DocumentsFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.95,0.62,0.20,0.42};
            x = 0.103 * safezoneW + safezoneX;
            y = 0.196 * safezoneH + safezoneY;
            w = 0.774 * safezoneW;
            h = 0.290 * safezoneH;
        };
        class RosterFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.95,0.62,0.20,0.42};
            x = 0.103 * safezoneW + safezoneX;
            y = 0.520 * safezoneH + safezoneY;
            w = 0.774 * safezoneW;
            h = 0.265 * safezoneH;
        };
    };

    class controls {
        class DocumentLabel: Life_RscText {
            idc = -1;
            text = "Training Library";
            colorText[] = {1.0,0.78,0.42,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.207 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class DocumentList: Life_RscListBox {
            idc = 8201;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.242 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.182 * safezoneH;
            sizeEx = 0.027;
            onLBSelChanged = "[] call life_fnc_leoTrainingSelectDocument";
        };
        class DocumentBody: Life_RscStructuredText {
            idc = 8202;
            x = 0.382 * safezoneW + safezoneX;
            y = 0.242 * safezoneH + safezoneY;
            w = 0.482 * safezoneW;
            h = 0.182 * safezoneH;
            size = 0.025;
        };
        class DocTitleLabel: Life_RscText {
            idc = -1;
            text = "Document Title";
            colorText[] = {0.78,0.68,0.52,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.436 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class DocTitleEdit: Life_RscEdit {
            idc = 8203;
            text = "";
            x = 0.232 * safezoneW + safezoneX;
            y = 0.432 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class DocBodyLabel: DocTitleLabel {
            text = "Document Body";
            x = 0.462 * safezoneW + safezoneX;
        };
        class DocBodyEdit: Life_RscEdit {
            idc = 8204;
            text = "";
            x = 0.585 * safezoneW + safezoneX;
            y = 0.432 * safezoneH + safezoneY;
            w = 0.279 * safezoneW;
            h = 0.034 * safezoneH;
        };

        class RosterLabel: Life_RscText {
            idc = -1;
            text = "FTO Roster";
            colorText[] = {1.0,0.78,0.42,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.532 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class RosterList: Life_RscListBox {
            idc = 8205;
            x = 0.112 * safezoneW + safezoneX;
            y = 0.568 * safezoneH + safezoneY;
            w = 0.310 * safezoneW;
            h = 0.185 * safezoneH;
            sizeEx = 0.027;
        };
        class TraineeLabel: DocTitleLabel {
            text = "Trainee";
            x = 0.452 * safezoneW + safezoneX;
            y = 0.568 * safezoneH + safezoneY;
        };
        class TraineeCombo: Life_RscCombo {
            idc = 8206;
            x = 0.452 * safezoneW + safezoneX;
            y = 0.595 * safezoneH + safezoneY;
            w = 0.195 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class PhaseLabel: TraineeLabel {
            text = "Phase";
            x = 0.668 * safezoneW + safezoneX;
        };
        class PhaseCombo: Life_RscCombo {
            idc = 8207;
            x = 0.668 * safezoneW + safezoneX;
            y = 0.595 * safezoneH + safezoneY;
            w = 0.196 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class NotesLabel: TraineeLabel {
            text = "FTO Notes";
            y = 0.642 * safezoneH + safezoneY;
        };
        class NotesEdit: Life_RscEdit {
            idc = 8208;
            text = "";
            x = 0.452 * safezoneW + safezoneX;
            y = 0.669 * safezoneH + safezoneY;
            w = 0.412 * safezoneW;
            h = 0.046 * safezoneH;
        };
        class PostDocButton: Life_RscButtonMenu {
            idc = 8211;
            text = "Post Document";
            onButtonClick = "[] call life_fnc_leoTrainingPostDocument";
            x = 0.452 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.132 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class RosterButton: Life_RscButtonMenu {
            idc = 8212;
            text = "Update Roster";
            onButtonClick = "[] call life_fnc_leoTrainingRosterUpdate";
            x = 0.604 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.132 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.756 * safezoneW + safezoneX;
            y = 0.795 * safezoneH + safezoneY;
            w = 0.108 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
