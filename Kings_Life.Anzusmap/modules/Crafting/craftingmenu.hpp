#define CRAFT_IDD 9300
#define CRAFT_ACCENT 9301
#define CRAFT_HEADER 9302
#define CRAFT_TITLE 9303
#define CRAFT_SUBTITLE 9304
#define CRAFT_TAB_CRAFT 9310
#define CRAFT_TAB_VEHICLES 9311
#define CRAFT_TAB_WORKBENCH 9312
#define CRAFT_TAB_STORAGE 9313
#define CRAFT_TAB_GEAR 9314
#define CRAFT_LEFT_TITLE 9320
#define CRAFT_RIGHT_TITLE 9321
#define CRAFT_LEFT_LIST 9322
#define CRAFT_RIGHT_LIST 9323
#define CRAFT_DETAILS 9324
#define CRAFT_QUANTITY 9325
#define CRAFT_PRIMARY 9326
#define CRAFT_SECONDARY 9327
#define CRAFT_UPGRADE 9328
#define CRAFT_PROGRESS 9329
#define CRAFT_PROGRESS_TEXT 9330
#define CRAFT_CLOSE 9331

class life_crafting_menu {
    idd = CRAFT_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_craftingLoad;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.024,0.026,0.96};
            x = 0.105 * safezoneW + safezoneX;
            y = 0.090 * safezoneH + safezoneY;
            w = 0.790 * safezoneW;
            h = 0.820 * safezoneH;
        };
        class Header: Life_RscText {
            idc = CRAFT_HEADER;
            colorBackground[] = {0.035,0.050,0.052,1};
            x = 0.105 * safezoneW + safezoneX;
            y = 0.090 * safezoneH + safezoneY;
            w = 0.790 * safezoneW;
            h = 0.096 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = CRAFT_ACCENT;
            colorBackground[] = {0.0,0.68,0.74,1};
            x = 0.105 * safezoneW + safezoneX;
            y = 0.090 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.820 * safezoneH;
        };
        class LeftFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.132 * safezoneW + safezoneX;
            y = 0.282 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.465 * safezoneH;
        };
        class RightFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.412 * safezoneW + safezoneX;
            y = 0.282 * safezoneH + safezoneY;
            w = 0.205 * safezoneW;
            h = 0.465 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.637 * safezoneW + safezoneX;
            y = 0.282 * safezoneH + safezoneY;
            w = 0.230 * safezoneW;
            h = 0.465 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = CRAFT_TITLE;
            text = "Crafting";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.041;
            x = 0.135 * safezoneW + safezoneX;
            y = 0.112 * safezoneH + safezoneY;
            w = 0.315 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = CRAFT_SUBTITLE;
            text = "";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.023;
            x = 0.137 * safezoneW + safezoneX;
            y = 0.150 * safezoneH + safezoneY;
            w = 0.520 * safezoneW;
            h = 0.028 * safezoneH;
        };
        class TabCraft: Life_RscButtonMenu {
            idc = CRAFT_TAB_CRAFT;
            text = "Crafting";
            onButtonClick = "['craft'] call life_fnc_craftingSetTab";
            x = 0.135 * safezoneW + safezoneX;
            y = 0.214 * safezoneH + safezoneY;
            w = 0.092 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class TabVehicles: Life_RscButtonMenu {
            idc = CRAFT_TAB_VEHICLES;
            text = "Vehicles";
            onButtonClick = "['vehicles'] call life_fnc_craftingSetTab";
            x = 0.234 * safezoneW + safezoneX;
            y = 0.214 * safezoneH + safezoneY;
            w = 0.092 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class TabWorkbench: Life_RscButtonMenu {
            idc = CRAFT_TAB_WORKBENCH;
            text = "Workbench";
            onButtonClick = "['workbench'] call life_fnc_craftingSetTab";
            x = 0.333 * safezoneW + safezoneX;
            y = 0.214 * safezoneH + safezoneY;
            w = 0.092 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class TabStorage: Life_RscButtonMenu {
            idc = CRAFT_TAB_STORAGE;
            text = "Storage";
            onButtonClick = "['storage'] call life_fnc_craftingSetTab";
            x = 0.432 * safezoneW + safezoneX;
            y = 0.214 * safezoneH + safezoneY;
            w = 0.092 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class TabGear: Life_RscButtonMenu {
            idc = CRAFT_TAB_GEAR;
            text = "Gear";
            onButtonClick = "['gear'] call life_fnc_craftingSetTab";
            x = 0.531 * safezoneW + safezoneX;
            y = 0.214 * safezoneH + safezoneY;
            w = 0.092 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class LeftTitle: Life_RscText {
            idc = CRAFT_LEFT_TITLE;
            text = "Recipes";
            colorText[] = {0.62,0.88,0.96,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.144 * safezoneW + safezoneX;
            y = 0.294 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class RightTitle: Life_RscText {
            idc = CRAFT_RIGHT_TITLE;
            text = "Ingredients";
            colorText[] = {0.62,0.88,0.96,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.026;
            x = 0.424 * safezoneW + safezoneX;
            y = 0.294 * safezoneH + safezoneY;
            w = 0.170 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class LeftList: Life_RscListBox {
            idc = CRAFT_LEFT_LIST;
            x = 0.144 * safezoneW + safezoneX;
            y = 0.330 * safezoneH + safezoneY;
            w = 0.236 * safezoneW;
            h = 0.392 * safezoneH;
            sizeEx = 0.026;
            onLBSelChanged = "[] call life_fnc_craftingSelect";
        };
        class RightList: Life_RscListBox {
            idc = CRAFT_RIGHT_LIST;
            x = 0.424 * safezoneW + safezoneX;
            y = 0.330 * safezoneH + safezoneY;
            w = 0.181 * safezoneW;
            h = 0.392 * safezoneH;
            sizeEx = 0.025;
        };
        class Details: Life_RscStructuredText {
            idc = CRAFT_DETAILS;
            text = "";
            x = 0.650 * safezoneW + safezoneX;
            y = 0.305 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.300 * safezoneH;
            size = 0.025;
        };
        class Quantity: Life_RscEdit {
            idc = CRAFT_QUANTITY;
            text = "1";
            maxChars = 3;
            x = 0.650 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class PrimaryButton: Life_RscButtonMenu {
            idc = CRAFT_PRIMARY;
            text = "Craft";
            onButtonClick = "[] spawn life_fnc_craftingCraft";
            x = 0.650 * safezoneW + safezoneX;
            y = 0.682 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class SecondaryButton: Life_RscButtonMenu {
            idc = CRAFT_SECONDARY;
            text = "Transfer";
            onButtonClick = "['secondary'] call life_fnc_craftingTransfer";
            x = 0.757 * safezoneW + safezoneX;
            y = 0.682 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class UpgradeButton: Life_RscButtonMenu {
            idc = CRAFT_UPGRADE;
            text = "Upgrade";
            onButtonClick = "[] call life_fnc_craftingUpgrade";
            x = 0.650 * safezoneW + safezoneX;
            y = 0.735 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class CraftProgress: Life_RscProgress {
            idc = CRAFT_PROGRESS;
            x = 0.650 * safezoneW + safezoneX;
            y = 0.792 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.018 * safezoneH;
            colorBar[] = {0.96,0.68,0.22,0.95};
        };
        class ProgressText: Life_RscText {
            idc = CRAFT_PROGRESS_TEXT;
            text = "";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.021;
            x = 0.650 * safezoneW + safezoneX;
            y = 0.815 * safezoneH + safezoneY;
            w = 0.202 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = CRAFT_CLOSE;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.772 * safezoneW + safezoneX;
            y = 0.854 * safezoneH + safezoneY;
            w = 0.080 * safezoneW;
            h = 0.038 * safezoneH;
        };
    };
};
