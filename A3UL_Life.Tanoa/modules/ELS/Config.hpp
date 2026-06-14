class Life_ELS {
    enabled = 1;
    code1Key = 2; // 1 key
    code2Key = 3; // 2 key
    code3Key = 4; // 3 key
    requireDriver = 1;
    policeOnly = 1;

    class Profiles {
        class d3s_default {
            lightVariable = "ani_lightbar";
            sirenVariable = "ani_siren";
            lightAnimation = "ani_lightbar";
            sirenAnimation = "ani_siren";
            animationMode = "animate";
            engineOn = 0;
            forceHeadlights = 0;
            fallbackSirenSound = "";
            fallbackSirenDistance = 500;
            fallbackSirenDuration = 4.87;

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
            classNames[] = {};
        };
    };
};
