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
        Life_RscText_HUDFoodLabel,
        Life_RscText_HUDHealthLabel,
        Life_RscText_HUDWaterLabel,
        Life_RscProgress_HUDFood,
        Life_RscProgress_HUDHealth,
        Life_RscProgress_HUDWater,
        Life_RscText_HUDFood,
        Life_RscText_HUDHealth,
        Life_RscText_HUDWater,
        Life_HUD_WeaponShadow,
        Life_HUD_WeaponPanel,
        Life_HUD_WeaponAccent,
        Life_HUD_WeaponDivider,
        Life_HUD_MagazineBarBack,
        Life_HUD_MagazineBarFill,
        Life_HUD_WeaponIcon,
        Life_HUD_WeaponName,
        Life_HUD_AmmoType,
        Life_HUD_MagazineRounds,
        Life_HUD_MagazineCapacity,
        Life_HUD_ReserveRounds,
        Life_HUD_Penetration,
        Life_HUD_TotalRounds,
        Life_HUD_StaminaShadow,
        Life_HUD_StaminaPanel,
        Life_HUD_StaminaAccent,
        Life_HUD_StaminaBarBack,
        Life_HUD_StaminaBarFill,
        Life_HUD_StaminaLabel,
        Life_HUD_StaminaValue,
        Life_HUD_VehicleShadow,
        Life_HUD_VehiclePanel,
        Life_HUD_VehicleAccent,
        Life_HUD_VehicleFuelBack,
        Life_HUD_VehicleFuelFill,
        Life_HUD_VehicleHullBack,
        Life_HUD_VehicleHullFill,
        Life_HUD_VehicleEngineBack,
        Life_HUD_VehicleEngineFill,
        Life_HUD_VehicleFuelSysBack,
        Life_HUD_VehicleFuelSysFill,
        Life_HUD_VehicleMobilityBack,
        Life_HUD_VehicleMobilityFill,
        Life_HUD_VehicleGPSPanel,
        Life_HUD_VehicleTitle,
        Life_HUD_VehicleSpeed,
        Life_HUD_VehicleMPH,
        Life_HUD_VehicleRole,
        Life_HUD_VehicleFuelLabel,
        Life_HUD_VehicleFuelValue,
        Life_HUD_VehicleName,
        Life_HUD_VehicleHullLabel,
        Life_HUD_VehicleEngineLabel,
        Life_HUD_VehicleFuelSysLabel,
        Life_HUD_VehicleMobilityLabel,
        Life_HUD_VehicleGPSLocation,
        Life_HUD_VehicleGPSGrid,
        Life_HUD_VehicleGPSHeading,
        Life_HUD_VehicleGPSCardinal,
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
        colorBackground[] = {0,0,0,0.34};
        x = safezoneX + 0.036 * safezoneW;
        w = 0.074 * safezoneW;
        h = 0.0060 * safezoneH;
    };

    class Life_HUD_LabelText: Life_RscText {
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.31)";
        style = ST_LEFT;
        colorText[] = {0.64,0.76,0.80,0.88};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.036 * safezoneW;
        w = 0.070 * safezoneW;
        h = 0.012 * safezoneH;
    };

    class Life_RscText_HUDFoodLabel: Life_HUD_LabelText {
        idc = 1210;
        text = "HUNGER";
        y = safezoneY + 0.918 * safezoneH;
    };

    class Life_RscText_HUDHealthLabel: Life_HUD_LabelText {
        idc = 1211;
        text = "HEALTH";
        y = safezoneY + 0.941 * safezoneH;
    };

    class Life_RscText_HUDWaterLabel: Life_HUD_LabelText {
        idc = 1212;
        text = "THIRST";
        y = safezoneY + 0.964 * safezoneH;
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
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.48)";
        style = ST_LEFT;
        colorText[] = {0.92,0.97,1,0.94};
        colorBackground[] = {0,0,0,0};
        x = safezoneX + 0.114 * safezoneW;
        w = 0.028 * safezoneW;
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

    class Life_HUD_WeaponShadow: Life_RscText {
        idc = 2400;
        x = -10;
        y = -10;
        w = 0;
        h = 0;
        colorBackground[] = {0,0,0,0.38};
        shadow = 0;
    };

    class Life_HUD_WeaponPanel: Life_HUD_WeaponShadow {
        idc = 2401;
        colorBackground[] = {0.018,0.026,0.034,0.92};
    };

    class Life_HUD_WeaponAccent: Life_HUD_WeaponShadow {
        idc = 2402;
        colorBackground[] = {0.16,0.72,0.88,0.95};
    };

    class Life_HUD_WeaponDivider: Life_HUD_WeaponShadow {
        idc = 2406;
        colorBackground[] = {0.50,0.63,0.68,0.25};
    };

    class Life_HUD_MagazineBarBack: Life_HUD_WeaponShadow {
        idc = 2404;
        colorBackground[] = {0.032,0.046,0.058,0.95};
    };

    class Life_HUD_MagazineBarFill: Life_HUD_WeaponShadow {
        idc = 2405;
        colorBackground[] = {0.16,0.72,0.88,0.96};
    };

    class Life_HUD_WeaponIcon: Life_RscPictureKeepAspect {
        idc = 2403;
        x = -10;
        y = -10;
        w = 0;
        h = 0;
        text = "";
        colorText[] = {0.91,0.96,0.98,0.90};
    };

    class Life_HUD_WeaponText: Life_RscText {
        x = -10;
        y = -10;
        w = 0;
        h = 0;
        colorBackground[] = {0,0,0,0};
        colorText[] = {0.91,0.96,0.98,1};
        font = "RobotoCondensed";
        shadow = 0;
        style = ST_LEFT;
    };

    class Life_HUD_WeaponName: Life_HUD_WeaponText {
        idc = 1400;
        font = "RobotoCondensedBold";
        text = "WEAPON";
    };

    class Life_HUD_AmmoType: Life_HUD_WeaponText {
        idc = 1401;
        colorText[] = {0.16,0.72,0.88,0.94};
        text = "AMMUNITION";
    };

    class Life_HUD_MagazineRounds: Life_HUD_WeaponText {
        idc = 1402;
        font = "RobotoCondensedBold";
        text = "0";
    };

    class Life_HUD_MagazineCapacity: Life_HUD_WeaponText {
        idc = 1403;
        colorText[] = {0.50,0.63,0.68,0.94};
        text = "/ 0  MAG";
    };

    class Life_HUD_ReserveRounds: Life_HUD_MagazineCapacity {
        idc = 1404;
        text = "0  RESERVE";
    };

    class Life_HUD_Penetration: Life_RscTextMulti {
        idc = 1405;
        x = -10;
        y = -10;
        w = 0;
        h = 0;
        colorBackground[] = {0,0,0,0};
        colorText[] = {0.91,0.96,0.98,0.90};
        font = "RobotoCondensedBold";
        shadow = 0;
        text = "PEN 0 / 100";
    };

    class Life_HUD_TotalRounds: Life_HUD_MagazineCapacity {
        idc = 1406;
        text = "0 ROUNDS TOTAL";
    };

    class Life_HUD_StaminaShadow: Life_HUD_WeaponShadow {
        idc = 2420;
    };

    class Life_HUD_StaminaPanel: Life_HUD_WeaponPanel {
        idc = 2421;
    };

    class Life_HUD_StaminaAccent: Life_HUD_WeaponAccent {
        idc = 2422;
    };

    class Life_HUD_StaminaBarBack: Life_HUD_MagazineBarBack {
        idc = 2423;
    };

    class Life_HUD_StaminaBarFill: Life_HUD_MagazineBarFill {
        idc = 2424;
    };

    class Life_HUD_StaminaLabel: Life_HUD_MagazineCapacity {
        idc = 1420;
        text = "STAMINA";
    };

    class Life_HUD_StaminaValue: Life_HUD_WeaponText {
        idc = 1421;
        font = "RobotoCondensedBold";
        style = ST_RIGHT;
        text = "100%";
    };

    class Life_HUD_VehicleShadow: Life_HUD_WeaponShadow {
        idc = 2500;
    };

    class Life_HUD_VehiclePanel: Life_HUD_WeaponPanel {
        idc = 2501;
    };

    class Life_HUD_VehicleAccent: Life_HUD_WeaponAccent {
        idc = 2502;
    };

    class Life_HUD_VehicleFuelBack: Life_HUD_MagazineBarBack {
        idc = 2503;
    };

    class Life_HUD_VehicleFuelFill: Life_HUD_MagazineBarFill {
        idc = 2504;
    };

    class Life_HUD_VehicleHullBack: Life_HUD_MagazineBarBack {
        idc = 2505;
    };

    class Life_HUD_VehicleHullFill: Life_HUD_MagazineBarFill {
        idc = 2506;
    };

    class Life_HUD_VehicleEngineBack: Life_HUD_MagazineBarBack {
        idc = 2507;
    };

    class Life_HUD_VehicleEngineFill: Life_HUD_MagazineBarFill {
        idc = 2508;
    };

    class Life_HUD_VehicleFuelSysBack: Life_HUD_MagazineBarBack {
        idc = 2509;
    };

    class Life_HUD_VehicleFuelSysFill: Life_HUD_MagazineBarFill {
        idc = 2510;
    };

    class Life_HUD_VehicleMobilityBack: Life_HUD_MagazineBarBack {
        idc = 2511;
    };

    class Life_HUD_VehicleMobilityFill: Life_HUD_MagazineBarFill {
        idc = 2512;
    };

    class Life_HUD_VehicleGPSPanel: Life_HUD_MagazineBarBack {
        idc = 2513;
    };

    class Life_HUD_VehicleText: Life_HUD_WeaponText {
        colorText[] = {0.91,0.96,0.98,1};
        text = "";
    };

    class Life_HUD_VehicleTitle: Life_HUD_VehicleText {
        idc = 1500;
        font = "RobotoCondensedBold";
        text = "VEHICLE STATUS";
    };

    class Life_HUD_VehicleSpeed: Life_HUD_VehicleText {
        idc = 1501;
        font = "RobotoCondensedBold";
        text = "0";
    };

    class Life_HUD_VehicleMPH: Life_HUD_VehicleText {
        idc = 1502;
        text = "MPH";
    };

    class Life_HUD_VehicleRole: Life_HUD_VehicleText {
        idc = 1503;
        style = ST_RIGHT;
        text = "GROUND / DRIVER";
    };

    class Life_HUD_VehicleFuelLabel: Life_HUD_VehicleText {
        idc = 1504;
        text = "FUEL";
    };

    class Life_HUD_VehicleFuelValue: Life_HUD_VehicleText {
        idc = 1505;
        style = ST_RIGHT;
        font = "RobotoCondensedBold";
        text = "100%";
    };

    class Life_HUD_VehicleName: Life_HUD_VehicleText {
        idc = 1506;
        text = "VEHICLE";
    };

    class Life_HUD_VehicleHullLabel: Life_HUD_VehicleText {
        idc = 1507;
        text = "HULL 0%";
    };

    class Life_HUD_VehicleEngineLabel: Life_HUD_VehicleText {
        idc = 1508;
        text = "ENG 0%";
    };

    class Life_HUD_VehicleFuelSysLabel: Life_HUD_VehicleText {
        idc = 1509;
        text = "FUEL 0%";
    };

    class Life_HUD_VehicleMobilityLabel: Life_HUD_VehicleText {
        idc = 1510;
        text = "MOB 0%";
    };

    class Life_HUD_VehicleGPSLocation: Life_HUD_VehicleText {
        idc = 1511;
        font = "RobotoCondensedBold";
        text = "GPS";
    };

    class Life_HUD_VehicleGPSGrid: Life_HUD_VehicleText {
        idc = 1512;
        text = "GRID";
    };

    class Life_HUD_VehicleGPSHeading: Life_HUD_VehicleText {
        idc = 1513;
        text = "HDG 0";
    };

    class Life_HUD_VehicleGPSCardinal: Life_HUD_VehicleText {
        idc = 1514;
        style = ST_RIGHT;
        font = "RobotoCondensedBold";
        text = "N";
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
