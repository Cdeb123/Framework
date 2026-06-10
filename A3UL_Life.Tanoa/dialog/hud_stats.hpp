#define ST_CENTER 0x02
#define ST_RIGHT 0x01

/*
    Modern framework HUD.

    Keeps the legacy 2200/2201/2202 bar IDCs so older scripts that only call
    life_fnc_hudUpdate continue to work.
*/
class playerHUD {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";
    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    objects[] = {};
    controls[] = {
        Life_HUD_CoreBack,
        Life_HUD_Accent,
        Life_HUD_FoodIcon,
        Life_HUD_HealthIcon,
        Life_HUD_WaterIcon,
        Life_RscProgress_HUDFood,
        Life_RscProgress_HUDHealth,
        Life_RscProgress_HUDWater,
        Life_RscText_HUDFood,
        Life_RscText_HUDHealth,
        Life_RscText_HUDWater,
        Life_HUD_FireModeBack,
        Life_HUD_FireModeIcon,
        Life_HUD_FireModeText,
        Life_HUD_GPSBack,
        Life_HUD_GPSMap,
        Life_HUD_GPSHeading,
        Life_HUD_GPSSpeed,
        Life_HUD_StatusBack,
        Life_HUD_SeatbeltIcon,
        Life_HUD_CuffedIcon,
        Life_HUD_PoisonIcon,
        Life_HUD_VirusIcon,
        Life_HUD_DrunkIcon,
        Life_HUD_WeightIcon,
        Life_HUD_CitationIcon,
        Life_HUD_WarrantIcon
    };

    class Life_HUD_CoreBack: Life_RscText {
        idc = -1;
        colorBackground[] = {0.02,0.025,0.03,0.78};
        x = safezoneX + 0.015 * safezoneW;
        y = safezoneY + 0.825 * safezoneH;
        w = 0.245 * safezoneW;
        h = 0.145 * safezoneH;
    };

    class Life_HUD_Accent: Life_RscText {
        idc = -1;
        colorBackground[] = {0.0,0.78,0.92,0.95};
        x = safezoneX + 0.015 * safezoneW;
        y = safezoneY + 0.825 * safezoneH;
        w = 0.0032 * safezoneW;
        h = 0.145 * safezoneH;
    };

    class Life_HUD_IconBase: Life_RscPictureKeepAspect {
        idc = -1;
        colorText[] = {0.86,0.93,0.96,0.92};
        w = 0.018 * safezoneW;
        h = 0.024 * safezoneH;
    };

    class Life_HUD_FoodIcon: Life_HUD_IconBase {
        idc = 1203;
        text = "icons\ico_apple.paa";
        x = safezoneX + 0.030 * safezoneW;
        y = safezoneY + 0.845 * safezoneH;
    };

    class Life_HUD_HealthIcon: Life_HUD_IconBase {
        idc = 1204;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
        x = safezoneX + 0.030 * safezoneW;
        y = safezoneY + 0.887 * safezoneH;
    };

    class Life_HUD_WaterIcon: Life_HUD_IconBase {
        idc = 1205;
        text = "icons\ico_waterBottle.paa";
        x = safezoneX + 0.030 * safezoneW;
        y = safezoneY + 0.929 * safezoneH;
    };

    class LIFE_RscProgress_HUDCommon: Life_RscProgress {
        colorFrame[] = {0,0,0,0};
        colorBackground[] = {1,1,1,0.08};
        x = safezoneX + 0.055 * safezoneW;
        w = 0.142 * safezoneW;
        h = 0.010 * safezoneH;
    };

    class Life_RscProgress_HUDFood: LIFE_RscProgress_HUDCommon {
        idc = 2200;
        colorBar[] = {0.98,0.64,0.20,0.95};
        y = safezoneY + 0.854 * safezoneH;
    };

    class Life_RscProgress_HUDHealth: LIFE_RscProgress_HUDCommon {
        idc = 2201;
        colorBar[] = {0.13,0.85,0.54,0.95};
        y = safezoneY + 0.896 * safezoneH;
    };

    class Life_RscProgress_HUDWater: LIFE_RscProgress_HUDCommon {
        idc = 2202;
        colorBar[] = {0.0,0.68,0.95,0.95};
        y = safezoneY + 0.938 * safezoneH;
    };

    class Life_HUD_ValueText: Life_RscText {
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.58)";
        style = ST_RIGHT;
        colorText[] = {0.92,0.97,1,0.95};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.202 * safezoneW;
        w = 0.041 * safezoneW;
        h = 0.023 * safezoneH;
    };

    class Life_RscText_HUDFood: Life_HUD_ValueText {
        idc = 1200;
        text = "100%";
        y = safezoneY + 0.846 * safezoneH;
    };

    class Life_RscText_HUDHealth: Life_HUD_ValueText {
        idc = 1201;
        text = "100%";
        y = safezoneY + 0.888 * safezoneH;
    };

    class Life_RscText_HUDWater: Life_HUD_ValueText {
        idc = 1202;
        text = "100%";
        y = safezoneY + 0.930 * safezoneH;
    };

    class Life_HUD_FireModeBack: Life_RscText {
        idc = -1;
        colorBackground[] = {0.02,0.025,0.03,0.70};
        x = safezoneX + 0.275 * safezoneW;
        y = safezoneY + 0.924 * safezoneH;
        w = 0.130 * safezoneW;
        h = 0.046 * safezoneH;
    };

    class Life_HUD_FireModeIcon: Life_RscPictureKeepAspect {
        idc = 2308;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\rifle_ca.paa";
        colorText[] = {0.0,0.78,0.92,0.9};
        x = safezoneX + 0.284 * safezoneW;
        y = safezoneY + 0.934 * safezoneH;
        w = 0.018 * safezoneW;
        h = 0.024 * safezoneH;
    };

    class Life_HUD_FireModeText: Life_RscText {
        idc = 1300;
        text = "SAFE";
        style = ST_CENTER;
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.68)";
        colorText[] = {0.92,0.97,1,0.96};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.306 * safezoneW;
        y = safezoneY + 0.932 * safezoneH;
        w = 0.087 * safezoneW;
        h = 0.028 * safezoneH;
    };

    class Life_HUD_GPSBack: Life_RscText {
        idc = -1;
        colorBackground[] = {0.02,0.025,0.03,0.72};
        x = safezoneX + safezoneW - 0.235 * safezoneW;
        y = safezoneY + 0.715 * safezoneH;
        w = 0.220 * safezoneW;
        h = 0.255 * safezoneH;
    };

    class Life_HUD_GPSMap: Life_RscMapControl {
        idc = 2400;
        x = safezoneX + safezoneW - 0.227 * safezoneW;
        y = safezoneY + 0.727 * safezoneH;
        w = 0.204 * safezoneW;
        h = 0.190 * safezoneH;
        alphaFadeStartScale = 0.12;
        alphaFadeEndScale = 0.18;
        maxSatelliteAlpha = 0.45;
        scaleDefault = 0.06;
    };

    class Life_HUD_GPSHeading: Life_RscText {
        idc = 1301;
        text = "GPS";
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.56)";
        colorText[] = {0.92,0.97,1,0.95};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + safezoneW - 0.226 * safezoneW;
        y = safezoneY + 0.923 * safezoneH;
        w = 0.095 * safezoneW;
        h = 0.024 * safezoneH;
    };

    class Life_HUD_GPSSpeed: Life_RscText {
        idc = 1302;
        text = "0 KM/H";
        style = ST_RIGHT;
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.56)";
        colorText[] = {0.0,0.78,0.92,0.95};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + safezoneW - 0.128 * safezoneW;
        y = safezoneY + 0.923 * safezoneH;
        w = 0.102 * safezoneW;
        h = 0.024 * safezoneH;
    };

    class Life_HUD_StatusBack: Life_RscText {
        idc = -1;
        colorBackground[] = {0.02,0.025,0.03,0.70};
        x = safezoneX + safezoneW - 0.052 * safezoneW;
        y = safezoneY + 0.335 * safezoneH;
        w = 0.037 * safezoneW;
        h = 0.332 * safezoneH;
    };

    class Life_HUD_StatusIcon: Life_RscPictureKeepAspect {
        colorText[] = {0.86,0.93,0.96,0.9};
        x = safezoneX + safezoneW - 0.045 * safezoneW;
        w = 0.024 * safezoneW;
        h = 0.032 * safezoneH;
    };

    class Life_HUD_SeatbeltIcon: Life_HUD_StatusIcon {
        idc = 2300;
        text = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        y = safezoneY + 0.347 * safezoneH;
    };

    class Life_HUD_CuffedIcon: Life_HUD_StatusIcon {
        idc = 2301;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
        y = safezoneY + 0.388 * safezoneH;
    };

    class Life_HUD_PoisonIcon: Life_HUD_StatusIcon {
        idc = 2302;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\danger_ca.paa";
        y = safezoneY + 0.429 * safezoneH;
    };

    class Life_HUD_VirusIcon: Life_HUD_StatusIcon {
        idc = 2303;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
        y = safezoneY + 0.470 * safezoneH;
    };

    class Life_HUD_DrunkIcon: Life_HUD_StatusIcon {
        idc = 2304;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
        y = safezoneY + 0.511 * safezoneH;
    };

    class Life_HUD_WeightIcon: Life_HUD_StatusIcon {
        idc = 2305;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa";
        y = safezoneY + 0.552 * safezoneH;
    };

    class Life_HUD_CitationIcon: Life_HUD_StatusIcon {
        idc = 2306;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\documents_ca.paa";
        y = safezoneY + 0.593 * safezoneH;
    };

    class Life_HUD_WarrantIcon: Life_HUD_StatusIcon {
        idc = 2307;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
        y = safezoneY + 0.634 * safezoneH;
    };
};
