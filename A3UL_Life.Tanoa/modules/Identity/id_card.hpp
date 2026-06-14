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
            x = 0.335 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.205 * safezoneH;
        };
        class TopBand: Life_RscText {
            idc = -1;
            colorBackground[] = {0.02,0.12,0.16,1};
            x = 0.335 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.00,0.55,0.62,1};
            x = 0.335 * safezoneW + safezoneX;
            y = 0.349 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.005 * safezoneH;
        };
        class PhotoBack: Life_RscText {
            idc = -1;
            colorBackground[] = {0.78,0.82,0.80,1};
            x = 0.352 * safezoneW + safezoneX;
            y = 0.370 * safezoneH + safezoneY;
            w = 0.072 * safezoneW;
            h = 0.105 * safezoneH;
        };
    };

    class controls {
        class Header: Life_RscText {
            idc = -1;
            text = "TANOA RESIDENT ID";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.025;
            x = 0.350 * safezoneW + safezoneX;
            y = 0.318 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class Face: Life_RscPictureKeepAspect {
            idc = SHOWN_ID_FACE;
            text = "";
            x = 0.356 * safezoneW + safezoneX;
            y = 0.374 * safezoneH + safezoneY;
            w = 0.064 * safezoneW;
            h = 0.097 * safezoneH;
        };
        class Body: Life_RscStructuredText {
            idc = SHOWN_ID_BODY;
            x = 0.435 * safezoneW + safezoneX;
            y = 0.365 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.095 * safezoneH;
        };
        class Licenses: Life_RscStructuredText {
            idc = SHOWN_ID_LICENSES;
            x = 0.352 * safezoneW + safezoneX;
            y = 0.480 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.033 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.604 * safezoneW + safezoneX;
            y = 0.480 * safezoneH + safezoneY;
            w = 0.045 * safezoneW;
            h = 0.028 * safezoneH;
        };
    };
};
