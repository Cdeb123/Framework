#define SHOWN_ID_IDD 7910
#define SHOWN_ID_FACE 7911
#define SHOWN_ID_BODY 7912
#define SHOWN_ID_LICENSES 7913

class life_shown_id_card {
    idd = SHOWN_ID_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_refreshShownID;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.91,0.94,0.91,0.98};
            x = 0.323 * safezoneW + safezoneX;
            y = 0.285 * safezoneH + safezoneY;
            w = 0.354 * safezoneW;
            h = 0.326 * safezoneH;
        };
        class TopBand: Life_RscText {
            idc = -1;
            colorBackground[] = {0.02,0.12,0.16,1};
            x = 0.323 * safezoneW + safezoneX;
            y = 0.285 * safezoneH + safezoneY;
            w = 0.354 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.00,0.55,0.62,1};
            x = 0.323 * safezoneW + safezoneX;
            y = 0.319 * safezoneH + safezoneY;
            w = 0.354 * safezoneW;
            h = 0.005 * safezoneH;
        };
        class PhotoBack: Life_RscText {
            idc = -1;
            colorBackground[] = {0.78,0.82,0.80,1};
            x = 0.340 * safezoneW + safezoneX;
            y = 0.340 * safezoneH + safezoneY;
            w = 0.078 * safezoneW;
            h = 0.118 * safezoneH;
        };
    };

    class controls {
        class Header: Life_RscText {
            idc = -1;
            text = "TANOA RESIDENT ID";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.025;
            x = 0.338 * safezoneW + safezoneX;
            y = 0.288 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class Face: Life_RscPictureKeepAspect {
            idc = SHOWN_ID_FACE;
            text = "";
            x = 0.344 * safezoneW + safezoneX;
            y = 0.345 * safezoneH + safezoneY;
            w = 0.070 * safezoneW;
            h = 0.108 * safezoneH;
        };
        class Body: Life_RscStructuredText {
            idc = SHOWN_ID_BODY;
            x = 0.428 * safezoneW + safezoneX;
            y = 0.336 * safezoneH + safezoneY;
            w = 0.230 * safezoneW;
            h = 0.134 * safezoneH;
        };
        class Licenses: Life_RscStructuredText {
            idc = SHOWN_ID_LICENSES;
            x = 0.340 * safezoneW + safezoneX;
            y = 0.468 * safezoneH + safezoneY;
            w = 0.318 * safezoneW;
            h = 0.103 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.604 * safezoneW + safezoneX;
            y = 0.582 * safezoneH + safezoneY;
            w = 0.054 * safezoneW;
            h = 0.024 * safezoneH;
        };
    };
};
