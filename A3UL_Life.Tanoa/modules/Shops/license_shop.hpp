#define LICENSE_SHOP_IDD 8300
#define LICENSE_SHOP_LIST 8301
#define LICENSE_SHOP_DETAILS 8302
#define LICENSE_SHOP_BUY 8303
#define LICENSE_SHOP_TITLE 8304
#define LICENSE_SHOP_SUBTITLE 8305

class life_license_shop {
    idd = LICENSE_SHOP_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "['dmv'] call life_fnc_licenseShopLoad";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.024,0.026,0.96};
            x = 0.230 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.540 * safezoneW;
            h = 0.640 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.050,0.052,1};
            x = 0.230 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.540 * safezoneW;
            h = 0.088 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.68,0.74,1};
            x = 0.230 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.640 * safezoneH;
        };
        class ListFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.258 * safezoneW + safezoneX;
            y = 0.294 * safezoneH + safezoneY;
            w = 0.245 * safezoneW;
            h = 0.382 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.522 * safezoneW + safezoneX;
            y = 0.294 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.382 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = LICENSE_SHOP_TITLE;
            text = "Department of Motor Vehicles";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.038;
            x = 0.260 * safezoneW + safezoneX;
            y = 0.188 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = LICENSE_SHOP_SUBTITLE;
            text = "Civil permits and transportation licenses";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.262 * safezoneW + safezoneX;
            y = 0.226 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class LicenseList: Life_RscListBox {
            idc = LICENSE_SHOP_LIST;
            x = 0.270 * safezoneW + safezoneX;
            y = 0.316 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.338 * safezoneH;
            sizeEx = 0.027;
            onLBSelChanged = "[] call life_fnc_licenseShopSelect";
        };
        class Details: Life_RscStructuredText {
            idc = LICENSE_SHOP_DETAILS;
            x = 0.536 * safezoneW + safezoneX;
            y = 0.318 * safezoneH + safezoneY;
            w = 0.190 * safezoneW;
            h = 0.332 * safezoneH;
            size = 0.028;
        };
        class BuyButton: Life_RscButtonMenu {
            idc = LICENSE_SHOP_BUY;
            text = "Purchase";
            onButtonClick = "[] call life_fnc_licenseShopBuy";
            x = 0.536 * safezoneW + safezoneX;
            y = 0.702 * safezoneH + safezoneY;
            w = 0.094 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.648 * safezoneW + safezoneX;
            y = 0.702 * safezoneH + safezoneY;
            w = 0.078 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
