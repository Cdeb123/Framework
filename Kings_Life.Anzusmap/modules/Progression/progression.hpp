#define PROG_IDD 8600
#define PROG_TITLE 8601
#define PROG_SUMMARY 8602
#define PROG_CHAR_BAR 8603
#define PROG_ROLE_BAR 8604
#define PROG_CRAFT_BAR 8605
#define PROG_CHAR_TEXT 8606
#define PROG_ROLE_TEXT 8607
#define PROG_CRAFT_TEXT 8608
#define PROG_LIST 8610
#define PROG_DETAIL 8611
#define PROG_SPEND 8612
#define PROG_TAB_XP 8613
#define PROG_TAB_SKILLS 8614
#define PROG_TAB_PERKS 8615

class life_progression_menu {
    idd = PROG_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_progressionLoad;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.020,0.026,0.030,0.96};
            x = 0.185 * safezoneW + safezoneX;
            y = 0.130 * safezoneH + safezoneY;
            w = 0.630 * safezoneW;
            h = 0.720 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.015,0.130,0.150,1};
            x = 0.185 * safezoneW + safezoneX;
            y = 0.130 * safezoneH + safezoneY;
            w = 0.630 * safezoneW;
            h = 0.092 * safezoneH;
        };
        class LeftPanel: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.047,0.052,0.92};
            x = 0.215 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.500 * safezoneH;
        };
        class DetailPanel: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.047,0.052,0.92};
            x = 0.485 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.500 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = PROG_TITLE;
            text = "Progression";
            colorText[] = {0.92,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.040;
            x = 0.215 * safezoneW + safezoneX;
            y = 0.150 * safezoneH + safezoneY;
            w = 0.230 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Summary: Life_RscStructuredText {
            idc = PROG_SUMMARY;
            text = "";
            x = 0.485 * safezoneW + safezoneX;
            y = 0.148 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.056 * safezoneH;
        };
        class TabXP: Life_RscButtonMenu {
            idc = PROG_TAB_XP;
            text = "XP";
            onButtonClick = "['xp'] call life_fnc_progressionSetTab";
            x = 0.215 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class TabSkills: Life_RscButtonMenu {
            idc = PROG_TAB_SKILLS;
            text = "Skills";
            onButtonClick = "['skills'] call life_fnc_progressionSetTab";
            x = 0.295 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class TabPerks: Life_RscButtonMenu {
            idc = PROG_TAB_PERKS;
            text = "Perks";
            onButtonClick = "['perks'] call life_fnc_progressionSetTab";
            x = 0.375 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class CharacterProgress: Life_RscProgress {
            idc = PROG_CHAR_BAR;
            x = 0.495 * safezoneW + safezoneX;
            y = 0.230 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.018 * safezoneH;
            colorBar[] = {0.00,0.72,0.84,0.95};
        };
        class RoleProgress: Life_RscProgress {
            idc = PROG_ROLE_BAR;
            x = 0.595 * safezoneW + safezoneX;
            y = 0.230 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.018 * safezoneH;
            colorBar[] = {0.65,0.86,0.36,0.95};
        };
        class CraftProgress: Life_RscProgress {
            idc = PROG_CRAFT_BAR;
            x = 0.695 * safezoneW + safezoneX;
            y = 0.230 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.018 * safezoneH;
            colorBar[] = {0.96,0.68,0.22,0.95};
        };
        class CharacterText: Life_RscText {
            idc = PROG_CHAR_TEXT;
            text = "";
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.020;
            x = 0.495 * safezoneW + safezoneX;
            y = 0.207 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.020 * safezoneH;
        };
        class RoleText: CharacterText {
            idc = PROG_ROLE_TEXT;
            x = 0.595 * safezoneW + safezoneX;
        };
        class CraftText: CharacterText {
            idc = PROG_CRAFT_TEXT;
            x = 0.695 * safezoneW + safezoneX;
        };
        class EntryList: Life_RscListBox {
            idc = PROG_LIST;
            onLBSelChanged = "[] call life_fnc_progressionSelect";
            sizeEx = 0.030;
            x = 0.235 * safezoneW + safezoneX;
            y = 0.280 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.445 * safezoneH;
        };
        class Details: Life_RscStructuredText {
            idc = PROG_DETAIL;
            text = "";
            x = 0.505 * safezoneW + safezoneX;
            y = 0.280 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.390 * safezoneH;
        };
        class SpendButton: Life_RscButtonMenu {
            idc = PROG_SPEND;
            text = "Spend Point";
            onButtonClick = "[] call life_fnc_spendPerk";
            x = 0.505 * safezoneW + safezoneX;
            y = 0.690 * safezoneH + safezoneY;
            w = 0.110 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0";
            x = 0.665 * safezoneW + safezoneX;
            y = 0.775 * safezoneH + safezoneY;
            w = 0.100 * safezoneW;
            h = 0.038 * safezoneH;
        };
    };
};
