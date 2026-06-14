#define CIV_VEHICLE_SHOP_IDD 9000
#define CIV_VEHICLE_SHOP_TITLE 9001
#define CIV_VEHICLE_SHOP_SUBTITLE 9002
#define CIV_VEHICLE_SHOP_CATEGORIES 9003
#define CIV_VEHICLE_SHOP_VEHICLES 9004
#define CIV_VEHICLE_SHOP_DETAILS 9005
#define CIV_VEHICLE_SHOP_PICTURE 9006
#define CIV_VEHICLE_SHOP_BUY 9007
#define CIV_VEHICLE_SHOP_COLORS 9008
#define CIV_VEHICLE_SHOP_RENT 9009
#define CIV_VEHICLE_SHOP_RETURN 9010
#define CIV_VEHICLE_SHOP_STORE 9011

class life_civilian_vehicle_shop {
    idd = CIV_VEHICLE_SHOP_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [missionNamespace getVariable ['life_vehicle_shop_type','civ_car']] call life_fnc_civVehicleShopLoad;}";
    onUnload = "[] call life_fnc_3dPreviewExit";

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
        class CategoryFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.172 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.144 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class VehicleFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.332 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.218 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.568 * safezoneW + safezoneX;
            y = 0.252 * safezoneH + safezoneY;
            w = 0.256 * safezoneW;
            h = 0.466 * safezoneH;
        };
        class PictureBack: Life_RscText {
            idc = -1;
            colorBackground[] = {0.030,0.043,0.050,0.92};
            x = 0.606 * safezoneW + safezoneX;
            y = 0.272 * safezoneH + safezoneY;
            w = 0.180 * safezoneW;
            h = 0.126 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = CIV_VEHICLE_SHOP_TITLE;
            text = "Civilian Auto";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.038;
            x = 0.176 * safezoneW + safezoneX;
            y = 0.144 * safezoneH + safezoneY;
            w = 0.400 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = CIV_VEHICLE_SHOP_SUBTITLE;
            text = "Purchase, rent, return, and store vehicles";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.178 * safezoneW + safezoneX;
            y = 0.182 * safezoneH + safezoneY;
            w = 0.430 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class Categories: Life_RscListBox {
            idc = CIV_VEHICLE_SHOP_CATEGORIES;
            x = 0.182 * safezoneW + safezoneX;
            y = 0.276 * safezoneH + safezoneY;
            w = 0.122 * safezoneW;
            h = 0.414 * safezoneH;
            sizeEx = 0.026;
            onLBSelChanged = "[] call life_fnc_civVehicleShopCategory";
        };
        class Vehicles: Life_RscListBox {
            idc = CIV_VEHICLE_SHOP_VEHICLES;
            x = 0.344 * safezoneW + safezoneX;
            y = 0.276 * safezoneH + safezoneY;
            w = 0.194 * safezoneW;
            h = 0.414 * safezoneH;
            sizeEx = 0.025;
            onLBSelChanged = "[] call life_fnc_civVehicleShopSelect";
        };
        class Picture: Life_RscPictureKeepAspect {
            idc = CIV_VEHICLE_SHOP_PICTURE;
            text = "";
            x = 0.616 * safezoneW + safezoneX;
            y = 0.284 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
            h = 0.102 * safezoneH;
        };
        class Details: Life_RscStructuredText {
            idc = CIV_VEHICLE_SHOP_DETAILS;
            x = 0.586 * safezoneW + safezoneX;
            y = 0.414 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.204 * safezoneH;
            size = 0.026;
        };
        class Colors: Life_RscCombo {
            idc = CIV_VEHICLE_SHOP_COLORS;
            x = 0.586 * safezoneW + safezoneX;
            y = 0.642 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class BuyButton: Life_RscButtonMenu {
            idc = CIV_VEHICLE_SHOP_BUY;
            text = "Purchase";
            onButtonClick = "[true] call life_fnc_civVehicleShopBuy";
            x = 0.586 * safezoneW + safezoneX;
            y = 0.724 * safezoneH + safezoneY;
            w = 0.104 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class RentButton: Life_RscButtonMenu {
            idc = CIV_VEHICLE_SHOP_RENT;
            text = "Rent";
            onButtonClick = "[false] call life_fnc_civVehicleShopBuy";
            x = 0.702 * safezoneW + safezoneX;
            y = 0.724 * safezoneH + safezoneY;
            w = 0.094 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class ReturnButton: Life_RscButtonMenu {
            idc = CIV_VEHICLE_SHOP_RETURN;
            text = "Return Rental";
            onButtonClick = "[] call life_fnc_civVehicleShopReturn";
            x = 0.586 * safezoneW + safezoneX;
            y = 0.766 * safezoneH + safezoneY;
            w = 0.104 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class StoreButton: Life_RscButtonMenu {
            idc = CIV_VEHICLE_SHOP_STORE;
            text = "Store Owned";
            onButtonClick = "[] spawn life_fnc_civVehicleShopStore";
            x = 0.702 * safezoneW + safezoneX;
            y = 0.766 * safezoneH + safezoneY;
            w = 0.094 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.708 * safezoneW + safezoneX;
            y = 0.814 * safezoneH + safezoneY;
            w = 0.088 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
