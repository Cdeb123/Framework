#define GARAGE_IDD 2800
#define GARAGE_TITLE 2801
#define GARAGE_LIST 2802
#define GARAGE_DETAILS 2803
#define GARAGE_PICTURE 2804
#define GARAGE_SUBTITLE 2805

class Life_impound_menu {
    idd = GARAGE_IDD;
    name = "life_vehicle_garage";
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.024,0.026,0.96};
            x = 0.145 * safezoneW + safezoneX;
            y = 0.125 * safezoneH + safezoneY;
            w = 0.710 * safezoneW;
            h = 0.750 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.050,0.052,1};
            x = 0.145 * safezoneW + safezoneX;
            y = 0.125 * safezoneH + safezoneY;
            w = 0.710 * safezoneW;
            h = 0.090 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.68,0.74,1};
            x = 0.145 * safezoneW + safezoneX;
            y = 0.125 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.750 * safezoneH;
        };
        class VehicleFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.172 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.490 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.334 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class PictureBack: Life_RscText {
            idc = -1;
            colorBackground[] = {0.030,0.043,0.050,0.92};
            x = 0.562 * safezoneW + safezoneX;
            y = 0.274 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.138 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = GARAGE_TITLE;
            text = "Vehicle Garage";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.038;
            x = 0.176 * safezoneW + safezoneX;
            y = 0.144 * safezoneH + safezoneY;
            w = 0.440 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = GARAGE_SUBTITLE;
            text = "Character-owned vehicles | Storage and retrieval are free";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.178 * safezoneW + safezoneX;
            y = 0.182 * safezoneH + safezoneY;
            w = 0.560 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class VehicleList: Life_RscListBox {
            idc = GARAGE_LIST;
            text = "";
            sizeEx = 0.027;
            onLBSelChanged = "_this call life_fnc_garageLBChange";
            x = 0.184 * safezoneW + safezoneX;
            y = 0.276 * safezoneH + safezoneY;
            w = 0.276 * safezoneW;
            h = 0.414 * safezoneH;
        };
        class VehiclePicture: Life_RscPictureKeepAspect {
            idc = GARAGE_PICTURE;
            text = "";
            x = 0.576 * safezoneW + safezoneX;
            y = 0.286 * safezoneH + safezoneY;
            w = 0.162 * safezoneW;
            h = 0.112 * safezoneH;
        };
        class VehicleDetails: Life_RscStructuredText {
            idc = GARAGE_DETAILS;
            text = "";
            size = 0.026;
            x = 0.514 * safezoneW + safezoneX;
            y = 0.432 * safezoneH + safezoneY;
            w = 0.286 * safezoneW;
            h = 0.238 * safezoneH;
        };
        class RetrieveButton: Life_RscButtonMenu {
            idc = -1;
            text = "Retrieve - $0";
            onButtonClick = "[] call life_fnc_unimpound";
            x = 0.184 * safezoneW + safezoneX;
            y = 0.752 * safezoneH + safezoneY;
            w = 0.132 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class StoreButton: Life_RscButtonMenu {
            idc = -1;
            text = "Store Nearby - $0";
            onButtonClick = "[] spawn life_fnc_storeVehicle";
            x = 0.328 * safezoneW + safezoneX;
            y = 0.752 * safezoneH + safezoneY;
            w = 0.144 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class SellButton: Life_RscButtonMenu {
            idc = -1;
            text = "Sell Vehicle";
            onButtonClick = "[] call life_fnc_sellGarage; closeDialog 0";
            x = 0.586 * safezoneW + safezoneX;
            y = 0.752 * safezoneH + safezoneY;
            w = 0.104 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.708 * safezoneW + safezoneX;
            y = 0.752 * safezoneH + safezoneY;
            w = 0.088 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class LoadingBack: Life_RscText {
            idc = 2810;
            colorBackground[] = {0.018,0.024,0.026,0.98};
            x = 0.172 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.652 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class LoadingText: Life_RscText {
            idc = 2811;
            text = "Loading character vehicles...";
            colorText[] = {0.62,0.78,0.78,1};
            style = 2;
            sizeEx = 0.032;
            x = 0.300 * safezoneW + safezoneX;
            y = 0.452 * safezoneH + safezoneY;
            w = 0.400 * safezoneW;
            h = 0.060 * safezoneH;
        };
    };
};
