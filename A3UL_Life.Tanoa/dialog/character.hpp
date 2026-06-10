class life_character_select {
    idd = 7800;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "_this spawn life_fnc_characterMenuLoad";
    onUnload = "[] call life_fnc_characterPreviewStop";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.02,0.025,0.03,0.92};
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
            w = 0.004 * safezoneW;
            h = 0.68 * safezoneH;
        };

        class Title: Life_RscText {
            idc = -1;
            text = "Characters";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.045;
            x = 0.205 * safezoneW + safezoneX;
            y = 0.185 * safezoneH + safezoneY;
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

        class FirstNameLabel: Life_RscText {
            idc = -1;
            text = "First Name";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.490 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.14 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class LastNameLabel: Life_RscText {
            idc = -1;
            text = "Last Name";
            colorText[] = {0.92,0.97,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.032;
            x = 0.635 * safezoneW + safezoneX;
            y = 0.225 * safezoneH + safezoneY;
            w = 0.14 * safezoneW;
            h = 0.03 * safezoneH;
        };

        class FirstNameEdit: Life_RscEdit {
            idc = 7803;
            text = "";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.14 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class LastNameEdit: Life_RscEdit {
            idc = 7810;
            text = "";
            x = 0.635 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.14 * safezoneW;
            h = 0.038 * safezoneH;
        };

        class DobEdit: Life_RscCombo {
            idc = 7804;
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

        class PoliticalEdit: Life_RscCombo {
            idc = 7805;
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

        class BackgroundEdit: Life_RscCombo {
            idc = 7806;
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
    onLoad = "[] call life_fnc_refreshID";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.02,0.025,0.03,0.94};
            x = 0.31 * safezoneW + safezoneX;
            y = 0.22 * safezoneH + safezoneY;
            w = 0.38 * safezoneW;
            h = 0.46 * safezoneH;
        };

        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.78,0.92,1};
            x = 0.31 * safezoneW + safezoneX;
            y = 0.22 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.46 * safezoneH;
        };
    };

    class controls {
        class Face: Life_RscPictureKeepAspect {
            idc = 7901;
            text = "";
            x = 0.335 * safezoneW + safezoneX;
            y = 0.270 * safezoneH + safezoneY;
            w = 0.105 * safezoneW;
            h = 0.155 * safezoneH;
        };

        class Header: Life_RscText {
            idc = 7902;
            text = "IDENTIFICATION";
            colorText[] = {0.0,0.78,0.92,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.035;
            x = 0.465 * safezoneW + safezoneX;
            y = 0.260 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.045 * safezoneH;
        };

        class Body: Life_RscStructuredText {
            idc = 7903;
            x = 0.465 * safezoneW + safezoneX;
            y = 0.315 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.230 * safezoneH;
        };

        class Records: Life_RscStructuredText {
            idc = 7904;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.455 * safezoneH + safezoneY;
            w = 0.320 * safezoneW;
            h = 0.145 * safezoneH;
        };

        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.560 * safezoneW + safezoneX;
            y = 0.615 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
