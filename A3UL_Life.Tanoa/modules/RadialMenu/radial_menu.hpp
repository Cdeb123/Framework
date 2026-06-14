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
            colorBackground[] = {0.008,0.012,0.016,0.22};
        };
        class Panel: Life_RscText {
            idc = -1;
            x = 0.410 * safezoneW + safezoneX;
            y = 0.320 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.360 * safezoneH;
            colorBackground[] = {0.025,0.032,0.040,0.92};
        };
        class PanelOutline: Life_RscFrame {
            idc = -1;
            x = 0.410 * safezoneW + safezoneX;
            y = 0.320 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.360 * safezoneH;
            colorText[] = {0.24,0.86,1.00,0.55};
        };
        class AccentTop: Life_RscText {
            idc = -1;
            x = 0.410 * safezoneW + safezoneX;
            y = 0.320 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.003 * safezoneH;
            colorBackground[] = {0.24,0.86,1.00,0.95};
        };
        class CenterMark: Life_RscPictureKeepAspect {
            idc = -1;
            text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
            colorText[] = {0.24,0.86,1.00,0.86};
            x = 0.421 * safezoneW + safezoneX;
            y = 0.336 * safezoneH + safezoneY;
            w = 0.018 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class CenterTitle: Life_RscText {
            idc = 9201;
            text = "F1 Menu";
            sizeEx = 0.026;
            shadow = 0;
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            x = 0.443 * safezoneW + safezoneX;
            y = 0.333 * safezoneH + safezoneY;
            w = 0.132 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class CenterSubtitle: Life_RscText {
            idc = 9202;
            text = "Nearby actions";
            sizeEx = 0.018;
            shadow = 0;
            colorText[] = {0.62,0.74,0.80,1};
            colorBackground[] = {0,0,0,0};
            x = 0.421 * safezoneW + safezoneX;
            y = 0.363 * safezoneH + safezoneY;
            w = 0.158 * safezoneW;
            h = 0.023 * safezoneH;
        };
    };

    class controls {
        class Slot0: Life_RscButtonMenu {
            idc = 9210;
            text = "";
            sizeEx = 0.021;
            x = 0.421 * safezoneW + safezoneX;
            y = 0.393 * safezoneH + safezoneY;
            w = 0.158 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class Slot1: Slot0 {
            idc = 9211;
            y = 0.423 * safezoneH + safezoneY;
        };
        class Slot2: Slot0 {
            idc = 9212;
            y = 0.453 * safezoneH + safezoneY;
        };
        class Slot3: Slot0 {
            idc = 9213;
            y = 0.483 * safezoneH + safezoneY;
        };
        class Slot4: Slot0 {
            idc = 9214;
            y = 0.513 * safezoneH + safezoneY;
        };
        class Slot5: Slot0 {
            idc = 9215;
            y = 0.543 * safezoneH + safezoneY;
        };
        class Slot6: Slot0 {
            idc = 9216;
            y = 0.573 * safezoneH + safezoneY;
        };
        class Slot7: Slot0 {
            idc = 9217;
            y = 0.603 * safezoneH + safezoneY;
        };
        class PrevPage: Life_RscButtonMenu {
            idc = 9220;
            text = "<";
            sizeEx = 0.020;
            onButtonClick = "[-1] call life_fnc_radialMenuPage";
            x = 0.421 * safezoneW + safezoneX;
            y = 0.642 * safezoneH + safezoneY;
            w = 0.044 * safezoneW;
            h = 0.027 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            sizeEx = 0.020;
            onButtonClick = "closeDialog 0";
            x = 0.478 * safezoneW + safezoneX;
            y = 0.642 * safezoneH + safezoneY;
            w = 0.044 * safezoneW;
            h = 0.027 * safezoneH;
        };
        class NextPage: PrevPage {
            idc = 9221;
            text = ">";
            onButtonClick = "[1] call life_fnc_radialMenuPage";
            x = 0.535 * safezoneW + safezoneX;
        };
    };
};
