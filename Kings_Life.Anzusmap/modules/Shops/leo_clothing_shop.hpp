#define LEO_CLOTHING_SHOP_IDD 8950
#define LEO_CLOTHING_SHOP_TITLE 8951
#define LEO_CLOTHING_SHOP_SUBTITLE 8952
#define LEO_CLOTHING_SHOP_CATEGORIES 8953
#define LEO_CLOTHING_SHOP_ITEMS 8954
#define LEO_CLOTHING_SHOP_DETAILS 8955
#define LEO_CLOTHING_SHOP_PICTURE 8956
#define LEO_CLOTHING_SHOP_BUY 8957

class life_leo_clothing_shop {
    idd = LEO_CLOTHING_SHOP_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [missionNamespace getVariable ['life_leo_clothing_shop_type','cop']] call life_fnc_leoClothingShopLoad;}";
    onUnload = "[] call life_fnc_playerSkins";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.024,0.026,0.96};
            x = 0.160 * safezoneW + safezoneX;
            y = 0.145 * safezoneH + safezoneY;
            w = 0.680 * safezoneW;
            h = 0.710 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.050,0.052,1};
            x = 0.160 * safezoneW + safezoneX;
            y = 0.145 * safezoneH + safezoneY;
            w = 0.680 * safezoneW;
            h = 0.090 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.68,0.74,1};
            x = 0.160 * safezoneW + safezoneX;
            y = 0.145 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.710 * safezoneH;
        };
        class CategoryFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.188 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.145 * safezoneW;
            h = 0.430 * safezoneH;
        };
        class ItemFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.350 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.430 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.68,0.74,0.45};
            x = 0.588 * safezoneW + safezoneX;
            y = 0.275 * safezoneH + safezoneY;
            w = 0.224 * safezoneW;
            h = 0.430 * safezoneH;
        };
        class PictureBack: Life_RscText {
            idc = -1;
            colorBackground[] = {0.030,0.043,0.050,0.92};
            x = 0.618 * safezoneW + safezoneX;
            y = 0.296 * safezoneH + safezoneY;
            w = 0.164 * safezoneW;
            h = 0.112 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = LEO_CLOTHING_SHOP_TITLE;
            text = "KCSO Uniform Locker";
            colorText[] = {0.92,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.038;
            x = 0.190 * safezoneW + safezoneX;
            y = 0.164 * safezoneH + safezoneY;
            w = 0.400 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = LEO_CLOTHING_SHOP_SUBTITLE;
            text = "Duty clothing issued by rank, role, and subdivision";
            colorText[] = {0.62,0.78,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.192 * safezoneW + safezoneX;
            y = 0.202 * safezoneH + safezoneY;
            w = 0.430 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class Categories: Life_RscListBox {
            idc = LEO_CLOTHING_SHOP_CATEGORIES;
            x = 0.198 * safezoneW + safezoneX;
            y = 0.298 * safezoneH + safezoneY;
            w = 0.124 * safezoneW;
            h = 0.382 * safezoneH;
            sizeEx = 0.026;
            onLBSelChanged = "[] call life_fnc_leoClothingShopCategory";
        };
        class Items: Life_RscListBox {
            idc = LEO_CLOTHING_SHOP_ITEMS;
            x = 0.362 * safezoneW + safezoneX;
            y = 0.298 * safezoneH + safezoneY;
            w = 0.196 * safezoneW;
            h = 0.382 * safezoneH;
            sizeEx = 0.025;
            onLBSelChanged = "[] call life_fnc_leoClothingShopSelect";
        };
        class Picture: Life_RscPictureKeepAspect {
            idc = LEO_CLOTHING_SHOP_PICTURE;
            text = "";
            x = 0.628 * safezoneW + safezoneX;
            y = 0.306 * safezoneH + safezoneY;
            w = 0.144 * safezoneW;
            h = 0.090 * safezoneH;
        };
        class Details: Life_RscStructuredText {
            idc = LEO_CLOTHING_SHOP_DETAILS;
            x = 0.606 * safezoneW + safezoneX;
            y = 0.426 * safezoneH + safezoneY;
            w = 0.188 * safezoneW;
            h = 0.254 * safezoneH;
            size = 0.027;
        };
        class BuyButton: Life_RscButtonMenu {
            idc = LEO_CLOTHING_SHOP_BUY;
            text = "Purchase";
            onButtonClick = "[] call life_fnc_leoClothingShopBuy";
            x = 0.606 * safezoneW + safezoneX;
            y = 0.744 * safezoneH + safezoneY;
            w = 0.094 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.718 * safezoneW + safezoneX;
            y = 0.744 * safezoneH + safezoneY;
            w = 0.078 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
