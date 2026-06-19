class Life_ELS {
    enabled = 1;
    code1Key = 2; // 1 key
    code2Key = 3; // 2 key
    code3Key = 4; // 3 key
    priorityKey = 5; // 4 key
    airhornKey = 6; // 5 key
    requireDriver = 1;
    policeOnly = 1;

    class Profiles {
        class d3s_default {
            /*
                ELS writes configured variables/animations first, then falls
                back to local lightpoints and mission siren audio. This keeps
                added modded vehicles usable even when their exact animation
                source names differ.
            */
            lightVariable = "ani_lightbar";
            sirenVariable = "ani_siren";
            lightVariables[] = {"ani_lightbar"};
            sirenVariables[] = {"ani_siren"};
            lightBooleanVariables[] = {};
            sirenBooleanVariables[] = {};
            lightAnimation = "ani_lightbar";
            sirenAnimation = "ani_siren";
            lightAnimations[] = {"ani_lightbar"};
            sirenAnimations[] = {"ani_siren"};
            lightSources[] = {"ani_lightbar","lightbar","lights","beacon","beacons","emergency_lights","emergencyLights"};
            sirenSources[] = {"ani_siren","siren","sirens","speaker","siren_speaker"};
            autoDetectLightSources = 1;
            autoDetectSirenSources = 1;
            animationMode = "animate";
            engineOn = 0;
            forceHeadlights = 0;

            localLightpoints = 1;
            lightTime = 0.18;
            leftLightColor[] = {20,0.1,0.1};
            rightLightColor[] = {0.1,0.1,20};
            lightBrightness = 6;
            lightIntensity = 10;
            lightFlareSize = 0.38;
            lightFlareMaxDistance = 150;
            lightLeftOffset[] = {};
            lightRightOffset[] = {};

            fallbackSirenSound = "sirenWail";
            fallbackSirenDistance = 500;
            fallbackSirenDuration = 5.01;
            prioritySirenSound = "sirenPriority";
            prioritySirenDistance = 500;
            prioritySirenDuration = 0.31;
            priorityTitle = "Priority Siren";

            airhornCooldown = 0.4;
            airhornWeapons[] = {};
            fallbackAirhornSound = "policeAirhorn";
            fallbackAirhornDistance = 350;
            fallbackAirhornPitch = 1;

            class Stages {
                class Code1 {
                    title = "Code 1";
                    lightValue = 0;
                    sirenValue = 0;
                };
                class Code2 {
                    title = "Code 2";
                    lightValue = 1;
                    sirenValue = 0;
                };
                class Code3 {
                    title = "Code 3";
                    lightValue = 1;
                    sirenValue = 1;
                };
            };
        };
    };

    class Vehicles {
        /*
            Add D3S police classnames here:

            class TCSD_D3S {
                profile = "d3s_default";
                classNames[] = {"YOUR_D3S_POLICE_CLASSNAME"};
            };

            If a car needs different light/siren values, copy d3s_default into a
            new profile and point the vehicle group at that profile.
        */
        class TCSD_D3S {
            profile = "d3s_default";
            classNames[] = { "AG_CROWNVIC_Police_AG", "AG_CROWNVIC_Police_ST_AG", "AG_CROWNVIC_UNM_AG_TIER3", "AG_Bearcat_KCSO_AG", "AG_Titan_Police_AG", "AG_Camaro_21_HSU_AG_TIER3", "AG_CTSV_AdminServices_AG_TIER3", "AG_Bearcat_KCSO_AG", "AG_Titan_Police_AG" };
        };
    };
};
