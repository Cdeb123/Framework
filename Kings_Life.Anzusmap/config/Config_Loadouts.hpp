/*
    class PLAYERSIDE { // PLAYERSIDE can be: WEST (for cops), CIV (for civ/reb), GUER (for medics), EAST (for opfor)
        // NOTES:
        //     empty array means that nothing will be add on players
        //     if you put more than a uniform on the CIV's class, they will be selected randonly,
        //         otherwise, for the other teams, player will get the uniform related to his level

        itemType[] = { // itemType can be: uniform, headgear, vest, backpack, weapon, items or linkedItems
            { "classname", "conditions" }
        };
    };
*/
class Loadouts {
    // COP
    class WEST {
        uniform[] = {
            {"U_Rangemaster", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"U_B_GEN_Soldier_F", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"U_B_GEN_Commander_F", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        headgear[] = {
            {"H_Cap_police", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        vest[] = {
            {"V_Rangemaster_belt", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        backpack[] = {};
        weapon[] = {
            {"hgun_P07_snds_F", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        mags[] = {
            {"16Rnd_9x21_Mag", 6, "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        items[] = {
            {"FirstAidKit", 2, "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        linkedItems[] = {
            {"ItemMap", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemCompass", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemWatch", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemGPS", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemRadio", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
    };

    // CIV
    class CIV {
        uniform[] = {
            {"U_C_Poloshirt_blue", "!life_is_arrested"},
            {"U_C_Poloshirt_burgundy", "!life_is_arrested"},
            {"U_C_Poloshirt_stripped", "!life_is_arrested"},
            {"U_C_Poloshirt_tricolour", "!life_is_arrested"},
            {"U_C_Poloshirt_salmon", "!life_is_arrested"},
            {"U_C_Poloshirt_redwhite", "!life_is_arrested"},
            {"U_C_Commoner1_1", "!life_is_arrested"},
            {"U_C_Man_casual_1_F", "!life_is_arrested"},
            {"U_C_Man_casual_2_F", "!life_is_arrested"},
            {"U_C_Man_casual_3_F", "!life_is_arrested"},
            {"U_C_Man_casual_4_F", "!life_is_arrested"},
            {"U_C_Man_casual_5_F", "!life_is_arrested"},
            {"U_C_Man_casual_6_F", "!life_is_arrested"},
            {"U_C_man_sport_1_F", "!life_is_arrested"},
            {"U_C_man_sport_2_F", "!life_is_arrested"},
            {"U_C_man_sport_3_F", "!life_is_arrested"}
        };
        headgear[] = {};
        vest[] = {};
        backpack[] = {};
        weapon[] = {};
        mags[] = {};
        items[] = {};
        linkedItems[] = {
            {"ItemMap", ""},
            {"ItemCompass", ""},
            {"ItemWatch", ""},
            {"ItemGPS", ""},
            {"ItemRadio", ""}
        };
    };

    // MED
    class GUER {
        uniform[] = {
            {"U_Rangemaster", "call life_medicLevel >= 1"},
            {"U_C_Paramedic_01_F", "call life_medicLevel >= 1"},
            {"U_C_WorkerCoveralls", "call life_medicLevel >= 1"}
        };
        headgear[] = {
            {"H_Cap_red", "call life_medicLevel >= 1"}
        };
        vest[] = {};
        backpack[] = {};
        weapon[] = {};
        mags[] = {};
        items[] = {
            {"FirstAidKit", 2, "call life_medicLevel >= 1"}
        };
        linkedItems[] = {
            {"ItemMap", "call life_medicLevel >= 1"},
            {"ItemCompass", "call life_medicLevel >= 1"},
            {"ItemWatch", "call life_medicLevel >= 1"},
            {"ItemGPS", "call life_medicLevel >= 1"},
            {"ItemRadio", "call life_medicLevel >= 1"}
        };
    };
};
