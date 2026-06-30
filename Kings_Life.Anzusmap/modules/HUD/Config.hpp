/*
    Client HUD configuration.

    Add themes, weapon ratings, and magazine labels here. Unknown modded
    weapons fall back to their CfgAmmo caliber and typicalSpeed values.
*/
class Life_WeaponHUD {
    defaultWeaponHUD = 1;
    defaultStaminaHUD = 1;
    defaultBallistics = 1;
    defaultScale = 1;
    defaultOpacity = 0.88;
    defaultTheme = "graphite";

    class Themes {
        class graphite {
            displayName = "Graphite Ice";
            accent[] = {0.16,0.72,0.88,1};
            panel[] = {0.018,0.026,0.034,1};
            panelAlt[] = {0.032,0.046,0.058,1};
            text[] = {0.91,0.96,0.98,1};
            muted[] = {0.50,0.63,0.68,1};
        };

        class amber {
            displayName = "Warm Amber";
            accent[] = {0.96,0.60,0.18,1};
            panel[] = {0.030,0.025,0.020,1};
            panelAlt[] = {0.055,0.043,0.030,1};
            text[] = {0.98,0.95,0.90,1};
            muted[] = {0.68,0.60,0.49,1};
        };

        class tactical {
            displayName = "Tactical Sage";
            accent[] = {0.42,0.78,0.53,1};
            panel[] = {0.020,0.030,0.026,1};
            panelAlt[] = {0.035,0.055,0.045,1};
            text[] = {0.91,0.97,0.92,1};
            muted[] = {0.52,0.66,0.56,1};
        };

        class monochrome {
            displayName = "Low-Light Mono";
            accent[] = {0.78,0.84,0.87,1};
            panel[] = {0.015,0.018,0.021,1};
            panelAlt[] = {0.035,0.039,0.043,1};
            text[] = {0.90,0.92,0.93,1};
            muted[] = {0.55,0.59,0.61,1};
        };
    };

    /* {weapon class, penetration rating (0-100), optional ammo label override} */
    weaponProfiles[] = {
        {"hgun_Rook40_F",18,""},
        {"hgun_Pistol_01_F",17,""},
        {"hgun_Pistol_heavy_02_F",24,".45 ACP"},
        {"hgun_ACPC2_F",22,".45 ACP"},
        {"hgun_PDW2000_F",19,"9x21 mm FMJ"},
        {"SMG_05_F",20,"9 mm FMJ"},
        {"hgun_P07_F",17,"9x21 mm FMJ"},
        {"hgun_P07_khk_F",17,"9x21 mm FMJ"},
        {"hgun_P07_snds_F",4,"9x21 mm less-lethal"},
        {"hgun_Pistol_heavy_01_F",25,".45 ACP"},
        {"SMG_02_ACO_F",21,"9x21 mm FMJ"},
        {"arifle_TRG20_F",38,"5.56x45 mm NATO"},
        {"arifle_Katiba_F",52,"6.5x39 mm caseless"},
        {"srifle_DMR_01_F",74,"7.62x54 mm"},
        {"arifle_SDAR_F",31,"5.56x45 mm dual-purpose"},
        {"arifle_AK12_F",58,"7.62x39 mm"},
        {"arifle_AKS_F",42,"5.45x39 mm"},
        {"arifle_AKM_F",56,"7.62x39 mm"},
        {"arifle_ARX_blk_F",53,"6.5x39 mm caseless"},
        {"arifle_SPAR_01_blk_F",39,"5.56x45 mm NATO"},
        {"arifle_CTAR_blk_F",44,"5.8x42 mm"},
        {"arifle_MX_F",54,"6.5x39 mm caseless"},
        {"arifle_MXC_F",50,"6.5x39 mm caseless"},
        {"srifle_DMR_07_blk_F",61,"6.5x54 mm"}
    };

    /* {magazine class, readable ammo type, fallback penetration rating} */
    ammoProfiles[] = {
        {"10Rnd_9x21_Mag","9x21 mm FMJ",17},
        {"16Rnd_9x21_Mag","9x21 mm FMJ",18},
        {"30Rnd_9x21_Mag","9x21 mm FMJ",20},
        {"30Rnd_9x21_Mag_SMG_02","9x21 mm FMJ",21},
        {"6Rnd_45ACP_Cylinder",".45 ACP",24},
        {"9Rnd_45ACP_Mag",".45 ACP",22},
        {"11Rnd_45ACP_Mag",".45 ACP",25},
        {"30Rnd_556x45_Stanag","5.56x45 mm NATO",39},
        {"20Rnd_556x45_UW_mag","5.56x45 mm dual-purpose",31},
        {"30Rnd_545x39_Mag_F","5.45x39 mm",42},
        {"30Rnd_580x42_Mag_F","5.8x42 mm",44},
        {"30Rnd_762x39_Mag_F","7.62x39 mm",57},
        {"10Rnd_762x54_Mag","7.62x54 mm",74},
        {"30Rnd_65x39_caseless_green","6.5x39 mm caseless",52},
        {"30Rnd_65x39_caseless_mag","6.5x39 mm caseless",54},
        {"20Rnd_650x39_Cased_Mag_F","6.5x54 mm",61}
    };
};

class Life_VehicleHUD {
    defaultVehicleHUD = 1;
    defaultGPS = 1;
    gpsToggleKey = 34; // Ctrl + G
};
