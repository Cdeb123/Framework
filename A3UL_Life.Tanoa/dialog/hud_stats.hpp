#define ST_CENTER 0x02
#define ST_RIGHT 0x01

/*
    Compact framework HUD.

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
        Life_HUD_FoodIcon,
        Life_HUD_HealthIcon,
        Life_HUD_WaterIcon,
        Life_RscProgress_HUDFood,
        Life_RscProgress_HUDHealth,
        Life_RscProgress_HUDWater,
        Life_RscText_HUDFood,
        Life_RscText_HUDHealth,
        Life_RscText_HUDWater,
        Life_HUD_FireModeIcon,
        Life_HUD_FireModeText,
        Life_HUD_SeatbeltIcon,
        Life_HUD_CuffedIcon,
        Life_HUD_PoisonIcon,
        Life_HUD_VirusIcon,
        Life_HUD_DrunkIcon,
        Life_HUD_WeightIcon,
        Life_HUD_CitationIcon,
        Life_HUD_WarrantIcon
    };

    class Life_HUD_IconBase: Life_RscPictureKeepAspect {
        idc = -1;
        colorText[] = {0.86,0.93,0.96,0.92};
        x = safezoneX + 0.018 * safezoneW;
        w = 0.014 * safezoneW;
        h = 0.018 * safezoneH;
    };

    class Life_HUD_FoodIcon: Life_HUD_IconBase {
        idc = 1203;
        text = "icons\ico_apple.paa";
        y = safezoneY + 0.926 * safezoneH;
    };

    class Life_HUD_HealthIcon: Life_HUD_IconBase {
        idc = 1204;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
        y = safezoneY + 0.949 * safezoneH;
    };

    class Life_HUD_WaterIcon: Life_HUD_IconBase {
        idc = 1205;
        text = "icons\ico_waterBottle.paa";
        y = safezoneY + 0.972 * safezoneH;
    };

    class LIFE_RscProgress_HUDCommon: Life_RscProgress {
        colorFrame[] = {0,0,0,0};
        colorBackground[] = {0,0,0,0.26};
        x = safezoneX + 0.036 * safezoneW;
        w = 0.072 * safezoneW;
        h = 0.0048 * safezoneH;
    };

    class Life_RscProgress_HUDFood: LIFE_RscProgress_HUDCommon {
        idc = 2200;
        colorBar[] = {0.98,0.64,0.20,0.95};
        y = safezoneY + 0.935 * safezoneH;
    };

    class Life_RscProgress_HUDHealth: LIFE_RscProgress_HUDCommon {
        idc = 2201;
        colorBar[] = {0.13,0.85,0.54,0.95};
        y = safezoneY + 0.958 * safezoneH;
    };

    class Life_RscProgress_HUDWater: LIFE_RscProgress_HUDCommon {
        idc = 2202;
        colorBar[] = {0.0,0.68,0.95,0.95};
        y = safezoneY + 0.981 * safezoneH;
    };

    class Life_HUD_ValueText: Life_RscText {
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.42)";
        style = ST_RIGHT;
        colorText[] = {0.92,0.97,1,0.94};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.110 * safezoneW;
        w = 0.031 * safezoneW;
        h = 0.016 * safezoneH;
    };

    class Life_RscText_HUDFood: Life_HUD_ValueText {
        idc = 1200;
        text = "100%";
        y = safezoneY + 0.927 * safezoneH;
    };

    class Life_RscText_HUDHealth: Life_HUD_ValueText {
        idc = 1201;
        text = "100%";
        y = safezoneY + 0.950 * safezoneH;
    };

    class Life_RscText_HUDWater: Life_HUD_ValueText {
        idc = 1202;
        text = "100%";
        y = safezoneY + 0.973 * safezoneH;
    };

    class Life_HUD_FireModeIcon: Life_RscPictureKeepAspect {
        idc = 2308;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\rifle_ca.paa";
        colorText[] = {0.0,0.78,0.92,0.90};
        x = safezoneX + 0.164 * safezoneW;
        y = safezoneY + 0.952 * safezoneH;
        w = 0.014 * safezoneW;
        h = 0.018 * safezoneH;
    };

    class Life_HUD_FireModeText: Life_RscText {
        idc = 1300;
        text = "";
        style = ST_CENTER;
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.44)";
        colorText[] = {0.92,0.97,1,0.94};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.179 * safezoneW;
        y = safezoneY + 0.953 * safezoneH;
        w = 0.045 * safezoneW;
        h = 0.016 * safezoneH;
    };

    class Life_HUD_StatusIcon: Life_RscPictureKeepAspect {
        colorText[] = {0.86,0.93,0.96,0};
        x = safezoneX + safezoneW - 0.034 * safezoneW;
        y = safezoneY + 0.390 * safezoneH;
        w = 0.018 * safezoneW;
        h = 0.024 * safezoneH;
    };

    class Life_HUD_SeatbeltIcon: Life_HUD_StatusIcon {
        idc = 2300;
        text = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
    };

    class Life_HUD_CuffedIcon: Life_HUD_StatusIcon {
        idc = 2301;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
    };

    class Life_HUD_PoisonIcon: Life_HUD_StatusIcon {
        idc = 2302;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\danger_ca.paa";
    };

    class Life_HUD_VirusIcon: Life_HUD_StatusIcon {
        idc = 2303;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
    };

    class Life_HUD_DrunkIcon: Life_HUD_StatusIcon {
        idc = 2304;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
    };

    class Life_HUD_WeightIcon: Life_HUD_StatusIcon {
        idc = 2305;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa";
    };

    class Life_HUD_CitationIcon: Life_HUD_StatusIcon {
        idc = 2306;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\documents_ca.paa";
    };

    class Life_HUD_WarrantIcon: Life_HUD_StatusIcon {
        idc = 2307;
        text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
    };
};
