class life_door_keypad {
    idd = 8300;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "uiNamespace setVariable ['life_door_keypad_display',(_this select 0)]";
    onUnload = "uiNamespace setVariable ['life_door_keypad_display',displayNull]; life_door_keypad_target = []";
    onKeyDown = "if ((_this select 1) isEqualTo 28) then {[] call life_fnc_submitDoorCode; true} else {false};";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.008,0.012,0.016,0.96};
            x = 0.365 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.270 * safezoneW;
            h = 0.370 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.034,0.042,0.98};
            x = 0.365 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.270 * safezoneW;
            h = 0.075 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.72,0.92,1};
            x = 0.365 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.370 * safezoneH;
        };
        class Outline: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.55};
            x = 0.365 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.270 * safezoneW;
            h = 0.370 * safezoneH;
        };
        class Logo: Life_RscPictureKeepAspect {
            idc = -1;
            text = "\A3\ui_f\data\map\markers\nato\b_installation.paa";
            colorText[] = {0.0,0.72,0.92,0.95};
            x = 0.386 * safezoneW + safezoneX;
            y = 0.333 * safezoneH + safezoneY;
            w = 0.030 * safezoneW;
            h = 0.042 * safezoneH;
        };
        class Title: Life_RscText {
            idc = -1;
            text = "Access Terminal";
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.036;
            x = 0.422 * safezoneW + safezoneX;
            y = 0.329 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = -1;
            text = "Secure keypad authorization";
            colorText[] = {0.56,0.70,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.424 * safezoneW + safezoneX;
            y = 0.360 * safezoneH + safezoneY;
            w = 0.185 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class InputFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.45};
            x = 0.394 * safezoneW + safezoneX;
            y = 0.438 * safezoneH + safezoneY;
            w = 0.212 * safezoneW;
            h = 0.068 * safezoneH;
        };
    };

    class controls {
        class DoorLabel: Life_RscText {
            idc = 8302;
            text = "Door Access Required";
            colorText[] = {0.68,0.86,0.92,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.025;
            x = 0.394 * safezoneW + safezoneX;
            y = 0.406 * safezoneH + safezoneY;
            w = 0.212 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class CodeEdit: Life_RscEdit {
            idc = 8301;
            text = "";
            maxChars = 4;
            sizeEx = 0.050;
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0.020,0.030,0.040,0.92};
            x = 0.404 * safezoneW + safezoneX;
            y = 0.448 * safezoneH + safezoneY;
            w = 0.192 * safezoneW;
            h = 0.048 * safezoneH;
        };
        class Status: Life_RscStructuredText {
            idc = 8303;
            text = "<t color='#8FB4C1'>Enter the assigned 4-digit code.</t>";
            x = 0.394 * safezoneW + safezoneX;
            y = 0.520 * safezoneH + safezoneY;
            w = 0.212 * safezoneW;
            h = 0.050 * safezoneH;
            size = 0.025;
        };
        class Submit: Life_RscButtonMenu {
            idc = 8304;
            text = "AUTHORIZE";
            onButtonClick = "[] call life_fnc_submitDoorCode";
            x = 0.394 * safezoneW + safezoneX;
            y = 0.596 * safezoneH + safezoneY;
            w = 0.102 * safezoneW;
            h = 0.045 * safezoneH;
        };
        class Cancel: Life_RscButtonMenu {
            idc = 8305;
            text = "CANCEL";
            onButtonClick = "closeDialog 0";
            colorBackground[] = {0.060,0.070,0.078,0.96};
            colorBackgroundFocused[] = {0.12,0.16,0.18,0.96};
            x = 0.504 * safezoneW + safezoneX;
            y = 0.596 * safezoneH + safezoneY;
            w = 0.102 * safezoneW;
            h = 0.045 * safezoneH;
        };
    };
};
