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
            {"U_Rangemaster", "['deputy'] call life_fnc_leoAtLeastRank"}
        };
        headgear[] = {
            {"H_Cap_blk", "['deputy'] call life_fnc_leoAtLeastRank"}
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
        items[] = {};
        linkedItems[] = {
            {"ItemMap", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemCompass", "['deputy'] call life_fnc_leoAtLeastRank"},
            {"ItemWatch", "['deputy'] call life_fnc_leoAtLeastRank"}
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
            {"U_C_Commoner1_1", "!life_is_arrested"}
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
            {"ItemWatch", ""}
        };
    };

    // MED
    class GUER {
        uniform[] = {
            {"U_Rangemaster", "call life_medicLevel >= 1"}
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
            {"ItemWatch", "call life_medicLevel >= 1"}
        };
    };
};
