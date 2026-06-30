#define LEO_LICENSE_IDD 8350
#define LEO_LICENSE_LIST 8351
#define LEO_LICENSE_DETAILS 8352
#define LEO_LICENSE_TARGET 8353

class life_leo_license_admin {
    idd = LEO_LICENSE_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] call life_fnc_licenseAdminLoad";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.014,0.018,0.024,0.96};
            x = 0.255 * safezoneW + safezoneX;
            y = 0.185 * safezoneH + safezoneY;
            w = 0.490 * safezoneW;
            h = 0.575 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.024,0.036,0.048,1};
            x = 0.255 * safezoneW + safezoneX;
            y = 0.185 * safezoneH + safezoneY;
            w = 0.490 * safezoneW;
            h = 0.078 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.58,0.92,1};
            x = 0.255 * safezoneW + safezoneX;
            y = 0.185 * safezoneH + safezoneY;
            w = 0.005 * safezoneW;
            h = 0.575 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = -1;
            text = "LEO License Actions";
            colorText[] = {0.94,0.98,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.036;
            x = 0.285 * safezoneW + safezoneX;
            y = 0.202 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class Target: Life_RscText {
            idc = LEO_LICENSE_TARGET;
            text = "";
            colorText[] = {0.62,0.76,0.86,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.540 * safezoneW + safezoneX;
            y = 0.208 * safezoneH + safezoneY;
            w = 0.170 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class LicenseList: Life_RscListBox {
            idc = LEO_LICENSE_LIST;
            x = 0.286 * safezoneW + safezoneX;
            y = 0.295 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.300 * safezoneH;
            sizeEx = 0.027;
            onLBSelChanged = "[] call life_fnc_licenseAdminSelect";
        };
        class Details: Life_RscStructuredText {
            idc = LEO_LICENSE_DETAILS;
            x = 0.518 * safezoneW + safezoneX;
            y = 0.295 * safezoneH + safezoneY;
            w = 0.188 * safezoneW;
            h = 0.300 * safezoneH;
            size = 0.027;
        };
        class ViewID: Life_RscButtonMenu {
            idc = -1;
            text = "View ID";
            onButtonClick = "[life_license_admin_target] call life_fnc_showID";
            x = 0.286 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Suspend: Life_RscButtonMenu {
            idc = -1;
            text = "Suspend";
            onButtonClick = "['suspend'] call life_fnc_licenseAdminApply";
            x = 0.388 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class Revoke: Life_RscButtonMenu {
            idc = -1;
            text = "Revoke";
            onButtonClick = "['revoke'] call life_fnc_licenseAdminApply";
            x = 0.490 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.085 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class IssueGun: Life_RscButtonMenu {
            idc = -1;
            text = "Issue Firearm";
            onButtonClick = "['issue_gun'] call life_fnc_licenseAdminApply";
            x = 0.592 * safezoneW + safezoneX;
            y = 0.630 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.612 * safezoneW + safezoneX;
            y = 0.695 * safezoneH + safezoneY;
            w = 0.074 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
