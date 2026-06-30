class life_backup_camera_display {
    idd = 9600;
    duration = 1e+10;
    fadeIn = 0.15;
    fadeOut = 0.15;
    movingEnable = 0;
    onLoad = "uiNamespace setVariable ['life_backup_camera_display',_this select 0]";
    onUnload = "uiNamespace setVariable ['life_backup_camera_display',displayNull]";

    class controls {
        class CameraShade: Life_RscText {
            idc = -1;
            x = 0.700 * safezoneW + safezoneX;
            y = 0.655 * safezoneH + safezoneY;
            w = 0.270 * safezoneW;
            h = 0.285 * safezoneH;
            colorBackground[] = {0.005,0.012,0.016,0.94};
        };
        class CameraFeed: Life_RscPicture {
            idc = 9601;
            text = "#(argb,512,512,1)r2t(lifebackuprender,1.0)";
            x = 0.707 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.256 * safezoneW;
            h = 0.215 * safezoneH;
        };
        class CameraTitle: Life_RscText {
            idc = -1;
            text = "REAR CAMERA";
            sizeEx = 0.019;
            shadow = 0;
            colorText[] = {0.55,0.84,0.94,1};
            x = 0.708 * safezoneW + safezoneX;
            y = 0.660 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class CameraHint: Life_RscText {
            idc = -1;
            text = "CTRL + R TO CLOSE";
            style = 1;
            sizeEx = 0.015;
            shadow = 0;
            colorText[] = {0.42,0.59,0.65,1};
            x = 0.840 * safezoneW + safezoneX;
            y = 0.660 * safezoneH + safezoneY;
            w = 0.122 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class GuideLeft: Life_RscText {
            idc = -1;
            x = 0.777 * safezoneW + safezoneX;
            y = 0.835 * safezoneH + safezoneY;
            w = 0.002 * safezoneW;
            h = 0.052 * safezoneH;
            colorBackground[] = {0.20,0.88,0.58,0.68};
        };
        class GuideRight: GuideLeft {x = 0.891 * safezoneW + safezoneX;};
        class CameraStatus: Life_RscText {
            idc = 9602;
            text = "MONITORING REAR APPROACH";
            style = 2;
            sizeEx = 0.015;
            shadow = 0;
            colorText[] = {0.55,0.75,0.80,1};
            x = 0.707 * safezoneW + safezoneX;
            y = 0.907 * safezoneH + safezoneY;
            w = 0.256 * safezoneW;
            h = 0.024 * safezoneH;
        };
    };
};
