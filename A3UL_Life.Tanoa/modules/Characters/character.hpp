class life_character_select {
    idd = 7800;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "_this spawn life_fnc_characterMenuLoad";
    onUnload = "[] call life_fnc_characterPreviewStop";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.015,0.02,0.025,0.94};
            x = 0.18 * safezoneW + safezoneX;
            y = 0.16 * safezoneH + safezoneY;
            w = 0.64 * safezoneW;
            h = 0.68 * safezoneH;
        };

        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.78,0.92,1};
            x = 0.18 * safezoneW + safezoneX;
            y = 0.16 * safezoneH + safezoneY;
            w = 0.006 * safezoneW;
            h = 0.68 * safezoneH;
        };

        class HeaderBar: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.78,0.92,0.12};
            x = 0.18 * safezoneW + safezoneX;
            y = 0.16 * safezoneH + safezoneY;
            w = 0.64 * safezoneW;
            h = 0.06 * safezoneH;
        };

        class Title: Life_RscText {
            idc = -1;
            text = "Characters";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.045;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.24 * safezoneW;
            h = 0.05 * safezoneH;
        };
    };

    class controls {
        class CharacterListLabel: Life_RscText {
            idc = -1;
            text = "Saved Characters";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.245 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class CharacterInfoLabel: Life_RscText {
            idc = -1;
            text = "Details";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.590 * safezoneH + safezoneY;
            w = 0.245 * safezoneW;
            h = 0.03 * safezoneH;
        };
        class CharacterList: Life_RscListBox {
            idc = 7801;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.245 * safezoneW;
            h = 0.35 * safezoneH;
            sizeEx = 0.032;
            onLBSelChanged = "life_character_selectedChanged = true; [] call life_fnc_characterPreviewUpdate";
        };

        class CharacterInfo: Life_RscStructuredText {
            idc = 7802;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.620 * safezoneH + safezoneY;
            w = 0.245 * safezoneW;
            h = 0.13 * safezoneH;
        };

        class NameLabel: Life_RscText {
            idc = -1;
            text = "Name";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.285 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class NameEdit: Life_RscEdit {
            idc = 7803;
            text = "";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.285 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class DobEdit: Life_RscEdit {
            idc = 7804;
            text = "";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.305 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class DobLabel: Life_RscText {
            idc = -1;
            text = "Date of Birth";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.03;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class PoliticalEdit: Life_RscEdit {
            idc = 7805;
            text = "";
            x = 0.640 * safezoneW + safezoneX;
            y = 0.305 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class PoliticalLabel: Life_RscText {
            idc = -1;
            text = "Political Affiliation";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.03;
            x = 0.640 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class BackgroundEdit: Life_RscEdit {
            idc = 7806;
            text = "";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.355 * safezoneH + safezoneY;
            w = 0.285 * safezoneW;
            h = 0.080 * safezoneH;
        };

        class BackgroundLabel: Life_RscText {
            idc = -1;
            text = "Background / Bio";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.03;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.325 * safezoneH + safezoneY;
            w = 0.285 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class FaceCombo: Life_RscCombo {
            idc = 7807;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.455 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.038 * safezoneH;
            onLBSelChanged = "[] call life_fnc_characterPreviewUpdate";
        };

        class FaceLabel: Life_RscText {
            idc = -1;
            text = "Face";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.425 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class UniformCombo: Life_RscCombo {
            idc = 7808;
            x = 0.640 * safezoneW + safezoneX;
            y = 0.455 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.038 * safezoneH;
            onLBSelChanged = "[] call life_fnc_characterPreviewUpdate";
        };

        class UniformLabel: Life_RscText {
            idc = -1;
            text = "Uniform";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.640 * safezoneW + safezoneX;
            y = 0.425 * safezoneH + safezoneY;
            w = 0.135 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class CreateButton: Life_RscButtonMenu {
            idc = -1;
            text = "Create";
            onButtonClick = "[] call life_fnc_characterCreate";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.525 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.042 * safezoneH;
        };

        class SelectButton: Life_RscButtonMenu {
            idc = -1;
            text = "Select";
            onButtonClick = "[] call life_fnc_characterSelect";
            x = 0.590 * safezoneW + safezoneX;
            y = 0.525 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.042 * safezoneH;
        };

        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.690 * safezoneW + safezoneX;
            y = 0.525 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.042 * safezoneH;
        };
    };
};

class life_id_card {
    idd = 7900;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_refreshID;}";

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
        class Face: Life_RscPictureKeepAspect {
            idc = 7901;
            text = "";
            x = 0.356 * safezoneW + safezoneX;
            y = 0.374 * safezoneH + safezoneY;
            w = 0.064 * safezoneW;
            h = 0.097 * safezoneH;
        };

        class Header: Life_RscText {
            idc = 7902;
            text = "TANOA RESIDENT ID";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.025;
            x = 0.350 * safezoneW + safezoneX;
            y = 0.318 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };

        class Body: Life_RscStructuredText {
            idc = 7903;
            x = 0.435 * safezoneW + safezoneX;
            y = 0.365 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.095 * safezoneH;
        };

        class Records: Life_RscStructuredText {
            idc = 7904;
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
