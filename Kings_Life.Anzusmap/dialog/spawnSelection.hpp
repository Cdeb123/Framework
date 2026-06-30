#define LIFE_SPAWN_IDD 38500
#define LIFE_SPAWN_TITLE 38501
#define LIFE_SPAWN_MAP 38502
#define LIFE_SPAWN_DETAILS 38503
#define LIFE_SPAWN_TYPE 38504
#define LIFE_SPAWN_COUNT 38505
#define LIFE_SPAWN_LIST 38510

class life_spawn_selection {
    idd = LIFE_SPAWN_IDD;
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class ScreenShade: Life_RscText {
            idc = -1;
            colorBackground[] = {0,0,0,0.38};
            x = safezoneX;
            y = safezoneY;
            w = safezoneW;
            h = safezoneH;
        };

        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.024,0.026,0.96};
            x = 0.135 * safezoneW + safezoneX;
            y = 0.115 * safezoneH + safezoneY;
            w = 0.730 * safezoneW;
            h = 0.770 * safezoneH;
        };

        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.050,0.052,1};
            x = 0.135 * safezoneW + safezoneX;
            y = 0.115 * safezoneH + safezoneY;
            w = 0.730 * safezoneW;
            h = 0.092 * safezoneH;
        };

        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.68,0.74,1};
            x = 0.135 * safezoneW + safezoneX;
            y = 0.115 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.770 * safezoneH;
        };

        class ListFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.165 * safezoneW + safezoneX;
            y = 0.257 * safezoneH + safezoneY;
            w = 0.257 * safezoneW;
            h = 0.438 * safezoneH;
        };

        class MapFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.444 * safezoneW + safezoneX;
            y = 0.257 * safezoneH + safezoneY;
            w = 0.391 * safezoneW;
            h = 0.438 * safezoneH;
        };

        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.165 * safezoneW + safezoneX;
            y = 0.715 * safezoneH + safezoneY;
            w = 0.458 * safezoneW;
            h = 0.104 * safezoneH;
        };

        class TitleLabel: Life_RscText {
            idc = -1;
            text = "Deployment";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.040;
            x = 0.165 * safezoneW + safezoneX;
            y = 0.132 * safezoneH + safezoneY;
            w = 0.310 * safezoneW;
            h = 0.044 * safezoneH;
        };

        class Subtitle: Life_RscText {
            idc = -1;
            text = "Select Arrival Point";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.167 * safezoneW + safezoneX;
            y = 0.174 * safezoneH + safezoneY;
            w = 0.320 * safezoneW;
            h = 0.030 * safezoneH;
        };

        class CountLabel: Life_RscText {
            idc = LIFE_SPAWN_COUNT;
            text = "";
            style = 1;
            colorText[] = {0.52,0.86,0.88,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.650 * safezoneW + safezoneX;
            y = 0.154 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.028 * safezoneH;
        };

        class MapView: Life_RscMapControl {
            idc = LIFE_SPAWN_MAP;
            x = 0.454 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.371 * safezoneW;
            h = 0.402 * safezoneH;
            maxSatelliteAlpha = 0.78;
            alphaFadeStartScale = 1.10;
            alphaFadeEndScale = 1.28;
        };
    };

    class controls {
        class SectionLabel: Life_RscText {
            idc = -1;
            text = "Locations";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.030;
            x = 0.165 * safezoneW + safezoneX;
            y = 0.222 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.032 * safezoneH;
        };

        class SpawnPointList: Life_RscListNBox {
            idc = LIFE_SPAWN_LIST;
            text = "";
            sizeEx = 0.025;
            columns[] = {0.035,0.160,0.755};
            drawSideArrows = 0;
            idcLeft = -1;
            idcRight = -1;
            rowHeight = 0.046;
            colorBackground[] = {0.025,0.035,0.042,0.90};
            colorSelect[] = {0.95,0.99,1,1};
            colorSelect2[] = {0.95,0.99,1,1};
            colorSelectBackground[] = {0.0,0.58,0.76,0.62};
            colorSelectBackground2[] = {0.0,0.72,0.90,0.78};
            x = 0.177 * safezoneW + safezoneX;
            y = 0.278 * safezoneH + safezoneY;
            w = 0.233 * safezoneW;
            h = 0.396 * safezoneH;
            onLBSelChanged = "_this call life_fnc_spawnPointSelected;";
        };

        class SelectedType: Life_RscText {
            idc = LIFE_SPAWN_TYPE;
            text = "";
            colorText[] = {0.0,0.78,0.88,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.180 * safezoneW + safezoneX;
            y = 0.729 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
            h = 0.026 * safezoneH;
        };

        class SpawnPointTitle: Life_RscText {
            idc = LIFE_SPAWN_TITLE;
            text = "";
            colorText[] = {0.96,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.034;
            x = 0.180 * safezoneW + safezoneX;
            y = 0.755 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class SpawnDetails: Life_RscStructuredText {
            idc = LIFE_SPAWN_DETAILS;
            x = 0.405 * safezoneW + safezoneX;
            y = 0.733 * safezoneH + safezoneY;
            w = 0.198 * safezoneW;
            h = 0.066 * safezoneH;
            size = 0.026;
        };

        class SpawnButton: Life_RscButtonMenu {
            idc = -1;
            text = "Deploy";
            onButtonClick = "[] call life_fnc_spawnConfirm";
            x = 0.678 * safezoneW + safezoneX;
            y = 0.738 * safezoneH + safezoneY;
            w = 0.136 * safezoneW;
            h = 0.045 * safezoneH;
        };
    };
};
