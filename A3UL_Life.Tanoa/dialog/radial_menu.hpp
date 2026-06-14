class life_radial_menu {
    idd = 9200;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] call life_fnc_radialMenuLoad";
    onKeyDown = "_this call life_fnc_radialMenuKey";

    class controlsBackground {
        class ScreenTint: Life_RscText {
            idc = -1;
            x = safezoneX;
            y = safezoneY;
            w = safezoneW;
            h = safezoneH;
            colorBackground[] = {0.008,0.012,0.016,0.58};
        };
        class Ring: Life_RscText {
            idc = -1;
            x = 0.370 * safezoneW + safezoneX;
            y = 0.235 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.470 * safezoneH;
            colorBackground[] = {0.030,0.040,0.050,0.88};
        };
        class RingOutline: Life_RscFrame {
            idc = -1;
            x = 0.370 * safezoneW + safezoneX;
            y = 0.235 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.470 * safezoneH;
            colorText[] = {0.24,0.86,1.00,0.72};
        };
        class AccentTop: Life_RscText {
            idc = -1;
            x = 0.370 * safezoneW + safezoneX;
            y = 0.235 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.004 * safezoneH;
            colorBackground[] = {0.24,0.86,1.00,1};
        };
        class CenterMark: Life_RscPictureKeepAspect {
            idc = -1;
            text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
            colorText[] = {0.24,0.86,1.00,0.92};
            x = 0.475 * safezoneW + safezoneX;
            y = 0.413 * safezoneH + safezoneY;
            w = 0.050 * safezoneW;
            h = 0.074 * safezoneH;
        };
        class CenterTitle: Life_RscText {
            idc = 9201;
            text = "Tanoa Life Radial";
            sizeEx = 0.034;
            shadow = 0;
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            x = 0.410 * safezoneW + safezoneX;
            y = 0.493 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class CenterSubtitle: Life_RscText {
            idc = 9202;
            text = "Nearby actions";
            sizeEx = 0.021;
            shadow = 0;
            colorText[] = {0.62,0.74,0.80,1};
            colorBackground[] = {0,0,0,0};
            x = 0.410 * safezoneW + safezoneX;
            y = 0.527 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.026 * safezoneH;
        };
    };

    class controls {
        class Slot0: Life_RscButtonMenu {
            idc = 9210;
            text = "";
            x = 0.424 * safezoneW + safezoneX;
            y = 0.158 * safezoneH + safezoneY;
            w = 0.152 * safezoneW;
            h = 0.052 * safezoneH;
        };
        class Slot1: Slot0 {
            idc = 9211;
            x = 0.609 * safezoneW + safezoneX;
            y = 0.271 * safezoneH + safezoneY;
        };
        class Slot2: Slot0 {
            idc = 9212;
            x = 0.646 * safezoneW + safezoneX;
            y = 0.444 * safezoneH + safezoneY;
        };
        class Slot3: Slot0 {
            idc = 9213;
            x = 0.609 * safezoneW + safezoneX;
            y = 0.617 * safezoneH + safezoneY;
        };
        class Slot4: Slot0 {
            idc = 9214;
            x = 0.424 * safezoneW + safezoneX;
            y = 0.730 * safezoneH + safezoneY;
        };
        class Slot5: Slot0 {
            idc = 9215;
            x = 0.239 * safezoneW + safezoneX;
            y = 0.617 * safezoneH + safezoneY;
        };
        class Slot6: Slot0 {
            idc = 9216;
            x = 0.202 * safezoneW + safezoneX;
            y = 0.444 * safezoneH + safezoneY;
        };
        class Slot7: Slot0 {
            idc = 9217;
            x = 0.239 * safezoneW + safezoneX;
            y = 0.271 * safezoneH + safezoneY;
        };
        class PrevPage: Life_RscButtonMenu {
            idc = 9220;
            text = "<";
            onButtonClick = "[-1] call life_fnc_radialMenuPage";
            x = 0.411 * safezoneW + safezoneX;
            y = 0.662 * safezoneH + safezoneY;
            w = 0.060 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class NextPage: PrevPage {
            idc = 9221;
            text = ">";
            onButtonClick = "[1] call life_fnc_radialMenuPage";
            x = 0.529 * safezoneW + safezoneX;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.470 * safezoneW + safezoneX;
            y = 0.662 * safezoneH + safezoneY;
            w = 0.060 * safezoneW;
            h = 0.038 * safezoneH;
        };
    };
};
