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
            colorBackground[] = {0.003,0.007,0.010,0.34};
        };

        class WheelGlow: Life_RscPictureKeepAspect {
            idc = -1;
            text = "modules\RadialMenu\textures\radial_ring.paa";
            colorText[] = {0.08,0.44,0.62,0.16};
            x = 0.318 * safezoneW + safezoneX;
            y = 0.180 * safezoneH + safezoneY;
            w = 0.364 * safezoneW;
            h = 0.640 * safezoneH;
        };
        class WheelRing: WheelGlow {
            colorText[] = {0.18,0.68,0.88,0.34};
            x = 0.344 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.312 * safezoneW;
            h = 0.550 * safezoneH;
        };

        class CenterDisc: WheelGlow {
            text = "modules\RadialMenu\textures\radial_disc.paa";
            colorText[] = {0.012,0.025,0.032,0.96};
            x = 0.424 * safezoneW + safezoneX;
            y = 0.368 * safezoneH + safezoneY;
            w = 0.152 * safezoneW;
            h = 0.264 * safezoneH;
        };
        class CenterEdge: CenterDisc {
            text = "modules\RadialMenu\textures\radial_ring.paa";
            colorText[] = {0.20,0.72,0.91,0.72};
            x = 0.430 * safezoneW + safezoneX;
            y = 0.378 * safezoneH + safezoneY;
            w = 0.140 * safezoneW;
            h = 0.244 * safezoneH;
        };
        class CenterFill: CenterDisc {
            colorText[] = {0.012,0.025,0.032,0.98};
            x = 0.437 * safezoneW + safezoneX;
            y = 0.390 * safezoneH + safezoneY;
            w = 0.126 * safezoneW;
            h = 0.220 * safezoneH;
        };

        class SlotBack0: WheelGlow {
            idc = 9260;
            text = "modules\RadialMenu\textures\radial_disc.paa";
            colorText[] = {0.018,0.038,0.049,0.96};
            x = 0.461 * safezoneW + safezoneX;
            y = 0.210 * safezoneH + safezoneY;
            w = 0.078 * safezoneW;
            h = 0.128 * safezoneH;
        };
        class SlotBack1: SlotBack0 {idc = 9261; x = 0.551 * safezoneW + safezoneX; y = 0.285 * safezoneH + safezoneY;};
        class SlotBack2: SlotBack0 {idc = 9262; x = 0.590 * safezoneW + safezoneX; y = 0.436 * safezoneH + safezoneY;};
        class SlotBack3: SlotBack0 {idc = 9263; x = 0.551 * safezoneW + safezoneX; y = 0.587 * safezoneH + safezoneY;};
        class SlotBack4: SlotBack0 {idc = 9264; x = 0.461 * safezoneW + safezoneX; y = 0.662 * safezoneH + safezoneY;};
        class SlotBack5: SlotBack0 {idc = 9265; x = 0.371 * safezoneW + safezoneX; y = 0.587 * safezoneH + safezoneY;};
        class SlotBack6: SlotBack0 {idc = 9266; x = 0.332 * safezoneW + safezoneX; y = 0.436 * safezoneH + safezoneY;};
        class SlotBack7: SlotBack0 {idc = 9267; x = 0.371 * safezoneW + safezoneX; y = 0.285 * safezoneH + safezoneY;};
    };

    class controls {
        class CenterIcon: Life_RscPictureKeepAspect {
            idc = 9201;
            text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
            colorText[] = {0.35,0.82,0.98,0.96};
            x = 0.481 * safezoneW + safezoneX;
            y = 0.415 * safezoneH + safezoneY;
            w = 0.038 * safezoneW;
            h = 0.064 * safezoneH;
        };
        class CenterTitle: Life_RscText {
            idc = 9202;
            text = "INTERACT";
            style = 2;
            sizeEx = 0.027;
            shadow = 0;
            colorText[] = {0.94,0.98,1,1};
            x = 0.443 * safezoneW + safezoneX;
            y = 0.482 * safezoneH + safezoneY;
            w = 0.114 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class CenterDetail: Life_RscStructuredText {
            idc = 9203;
            text = "F1 interaction wheel";
            size = 0.018;
            colorBackground[] = {0,0,0,0};
            x = 0.450 * safezoneW + safezoneX;
            y = 0.515 * safezoneH + safezoneY;
            w = 0.100 * safezoneW;
            h = 0.052 * safezoneH;
            class Attributes {font = "RobotoCondensed"; color = "#9bb3bf"; align = "center"; shadow = 0;};
        };
        class CenterPage: Life_RscText {
            idc = 9204;
            text = "1 / 1";
            style = 2;
            sizeEx = 0.016;
            shadow = 0;
            colorText[] = {0.35,0.72,0.84,0.88};
            x = 0.466 * safezoneW + safezoneX;
            y = 0.570 * safezoneH + safezoneY;
            w = 0.068 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class CenterButton: Life_RscButtonTextOnly {
            idc = 9205;
            type = 1;
            text = "";
            tooltip = "Close / Back";
            onButtonClick = "if (life_radial_category isEqualTo 'main') then {closeDialog 0} else {life_radial_category = 'main'; life_radial_page = 0; [] call life_fnc_radialMenuLoad;}";
            x = 0.437 * safezoneW + safezoneX;
            y = 0.390 * safezoneH + safezoneY;
            w = 0.126 * safezoneW;
            h = 0.220 * safezoneH;
        };

        class SlotIcon0: Life_RscPictureKeepAspect {
            idc = 9230;
            text = "";
            colorText[] = {0.64,0.86,0.94,1};
            x = 0.482 * safezoneW + safezoneX;
            y = 0.227 * safezoneH + safezoneY;
            w = 0.036 * safezoneW;
            h = 0.059 * safezoneH;
        };
        class SlotIcon1: SlotIcon0 {idc = 9231; x = 0.572 * safezoneW + safezoneX; y = 0.302 * safezoneH + safezoneY;};
        class SlotIcon2: SlotIcon0 {idc = 9232; x = 0.611 * safezoneW + safezoneX; y = 0.453 * safezoneH + safezoneY;};
        class SlotIcon3: SlotIcon0 {idc = 9233; x = 0.572 * safezoneW + safezoneX; y = 0.604 * safezoneH + safezoneY;};
        class SlotIcon4: SlotIcon0 {idc = 9234; x = 0.482 * safezoneW + safezoneX; y = 0.679 * safezoneH + safezoneY;};
        class SlotIcon5: SlotIcon0 {idc = 9235; x = 0.392 * safezoneW + safezoneX; y = 0.604 * safezoneH + safezoneY;};
        class SlotIcon6: SlotIcon0 {idc = 9236; x = 0.353 * safezoneW + safezoneX; y = 0.453 * safezoneH + safezoneY;};
        class SlotIcon7: SlotIcon0 {idc = 9237; x = 0.392 * safezoneW + safezoneX; y = 0.302 * safezoneH + safezoneY;};

        class SlotLabel0: Life_RscText {
            idc = 9240;
            text = "";
            style = 2;
            sizeEx = 0.018;
            shadow = 1;
            colorText[] = {0.92,0.97,0.99,1};
            x = 0.465 * safezoneW + safezoneX;
            y = 0.286 * safezoneH + safezoneY;
            w = 0.070 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class SlotLabel1: SlotLabel0 {idc = 9241; x = 0.555 * safezoneW + safezoneX; y = 0.361 * safezoneH + safezoneY;};
        class SlotLabel2: SlotLabel0 {idc = 9242; x = 0.594 * safezoneW + safezoneX; y = 0.512 * safezoneH + safezoneY;};
        class SlotLabel3: SlotLabel0 {idc = 9243; x = 0.555 * safezoneW + safezoneX; y = 0.663 * safezoneH + safezoneY;};
        class SlotLabel4: SlotLabel0 {idc = 9244; x = 0.465 * safezoneW + safezoneX; y = 0.738 * safezoneH + safezoneY;};
        class SlotLabel5: SlotLabel0 {idc = 9245; x = 0.375 * safezoneW + safezoneX; y = 0.663 * safezoneH + safezoneY;};
        class SlotLabel6: SlotLabel0 {idc = 9246; x = 0.336 * safezoneW + safezoneX; y = 0.512 * safezoneH + safezoneY;};
        class SlotLabel7: SlotLabel0 {idc = 9247; x = 0.375 * safezoneW + safezoneX; y = 0.361 * safezoneH + safezoneY;};

        class SlotKey0: Life_RscText {
            idc = 9250;
            text = "1";
            style = 2;
            sizeEx = 0.015;
            shadow = 0;
            colorText[] = {0.35,0.75,0.90,1};
            colorBackground[] = {0.01,0.03,0.04,0.82};
            x = 0.500 * safezoneW + safezoneX;
            y = 0.312 * safezoneH + safezoneY;
            w = 0.014 * safezoneW;
            h = 0.021 * safezoneH;
        };
        class SlotKey1: SlotKey0 {idc = 9251; text = "2"; x = 0.590 * safezoneW + safezoneX; y = 0.387 * safezoneH + safezoneY;};
        class SlotKey2: SlotKey0 {idc = 9252; text = "3"; x = 0.629 * safezoneW + safezoneX; y = 0.538 * safezoneH + safezoneY;};
        class SlotKey3: SlotKey0 {idc = 9253; text = "4"; x = 0.590 * safezoneW + safezoneX; y = 0.689 * safezoneH + safezoneY;};
        class SlotKey4: SlotKey0 {idc = 9254; text = "5"; x = 0.500 * safezoneW + safezoneX; y = 0.764 * safezoneH + safezoneY;};
        class SlotKey5: SlotKey0 {idc = 9255; text = "6"; x = 0.410 * safezoneW + safezoneX; y = 0.689 * safezoneH + safezoneY;};
        class SlotKey6: SlotKey0 {idc = 9256; text = "7"; x = 0.371 * safezoneW + safezoneX; y = 0.538 * safezoneH + safezoneY;};
        class SlotKey7: SlotKey0 {idc = 9257; text = "8"; x = 0.410 * safezoneW + safezoneX; y = 0.387 * safezoneH + safezoneY;};

        class Slot0: Life_RscButtonTextOnly {
            idc = 9210;
            type = 1;
            text = "";
            x = 0.461 * safezoneW + safezoneX;
            y = 0.210 * safezoneH + safezoneY;
            w = 0.078 * safezoneW;
            h = 0.128 * safezoneH;
            onMouseEnter = "[0] call life_fnc_radialMenuHover";
            onMouseExit = "[-1] call life_fnc_radialMenuHover";
        };
        class Slot1: Slot0 {idc = 9211; x = 0.551 * safezoneW + safezoneX; y = 0.285 * safezoneH + safezoneY; onMouseEnter = "[1] call life_fnc_radialMenuHover";};
        class Slot2: Slot0 {idc = 9212; x = 0.590 * safezoneW + safezoneX; y = 0.436 * safezoneH + safezoneY; onMouseEnter = "[2] call life_fnc_radialMenuHover";};
        class Slot3: Slot0 {idc = 9213; x = 0.551 * safezoneW + safezoneX; y = 0.587 * safezoneH + safezoneY; onMouseEnter = "[3] call life_fnc_radialMenuHover";};
        class Slot4: Slot0 {idc = 9214; x = 0.461 * safezoneW + safezoneX; y = 0.662 * safezoneH + safezoneY; onMouseEnter = "[4] call life_fnc_radialMenuHover";};
        class Slot5: Slot0 {idc = 9215; x = 0.371 * safezoneW + safezoneX; y = 0.587 * safezoneH + safezoneY; onMouseEnter = "[5] call life_fnc_radialMenuHover";};
        class Slot6: Slot0 {idc = 9216; x = 0.332 * safezoneW + safezoneX; y = 0.436 * safezoneH + safezoneY; onMouseEnter = "[6] call life_fnc_radialMenuHover";};
        class Slot7: Slot0 {idc = 9217; x = 0.371 * safezoneW + safezoneX; y = 0.285 * safezoneH + safezoneY; onMouseEnter = "[7] call life_fnc_radialMenuHover";};

        class PrevPage: Life_RscButtonTextOnly {
            idc = 9220;
            type = 1;
            text = "<";
            sizeEx = 0.032;
            tooltip = "Previous page (A / Left Arrow)";
            onButtonClick = "[-1] call life_fnc_radialMenuPage";
            x = 0.415 * safezoneW + safezoneX;
            y = 0.486 * safezoneH + safezoneY;
            w = 0.025 * safezoneW;
            h = 0.050 * safezoneH;
        };
        class NextPage: PrevPage {
            idc = 9221;
            text = ">";
            tooltip = "Next page (D / Right Arrow)";
            onButtonClick = "[1] call life_fnc_radialMenuPage";
            x = 0.560 * safezoneW + safezoneX;
        };
        class Footer: Life_RscText {
            idc = -1;
            text = "F1 CLOSE  |  1-8 SELECT  |  HOVER FOR DETAILS";
            style = 2;
            sizeEx = 0.016;
            shadow = 0;
            colorText[] = {0.48,0.63,0.69,0.85};
            x = 0.390 * safezoneW + safezoneX;
            y = 0.835 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.025 * safezoneH;
        };
    };
};
