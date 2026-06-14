class Life_Progression {
    maxCharacterLevel = 150;
    baseLevelXP = 900;
    levelGrowth = 1.115;
    levelLinearBonus = 125;
    perkPointsPerLevel = 1;
    dutyTickSeconds = 600;

    class Categories {
        class character {
            title = "Character";
            shortTitle = "CHAR";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\documents_ca.paa";
            description = "Overall character level. Role, gang, and crafting XP also feeds character XP.";
        };
        class leo {
            title = "Law Enforcement";
            shortTitle = "LEO";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\defend_ca.paa";
            description = "Gained from arrests, paid tickets, license administration, gang-affiliated takedowns, and time on duty.";
        };
        class ems {
            title = "EMS / Fire";
            shortTitle = "EMS";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
            description = "Gained from revives, rescue work, healing events, and time on duty.";
        };
        class gang {
            title = "Gang";
            shortTitle = "GANG";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\attack_ca.paa";
            description = "Gained from fighting rival gangs and selling illegal goods.";
        };
        class crafting {
            title = "Crafting";
            shortTitle = "CRAFT";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa";
            description = "Gained by crafting. Higher levels unlock better weapons, gear, backpacks, and future vehicles.";
        };
    };

    class XPEvents {
        arrest = 175;
        ticketPaid = 65;
        licenseAdmin = 90;
        leoGangKill = 140;
        leoDuty = 45;
        emsDuty = 45;
        revive = 160;
        heal = 55;
        rescue = 140;
        gangKill = 130;
        illegalSale = 3;
        gather = 10;
        mine = 14;
        craft = 80;
    };

    class Unlocks {
        class character {
            unlocks[] = {
                {5,"First perk path opens"},
                {15,"Second perk rank bracket"},
                {35,"Advanced utility perks"},
                {75,"Elite role bonuses"},
                {120,"Veteran progression tier"}
            };
        };
        class leo {
            unlocks[] = {
                {5,"Traffic officer coursework"},
                {15,"Field training credentials"},
                {30,"Special enforcement path"},
                {55,"Command support path"}
            };
        };
        class ems {
            unlocks[] = {
                {5,"Responder tools"},
                {15,"Advanced life support"},
                {30,"Rescue specialist path"},
                {55,"Fire command support"}
            };
        };
        class gang {
            unlocks[] = {
                {5,"Crew operations"},
                {15,"Contraband handling"},
                {30,"Rival pressure bonuses"},
                {55,"Organized crime tier"}
            };
        };
        class crafting {
            unlocks[] = {
                {1,"Pistols"},
                {5,"Small backpacks"},
                {20,"SMGs"},
                {40,"Assault rifles"},
                {55,"Large backpacks"},
                {80,"Vehicle crafting framework"}
            };
        };
    };

    class CraftingRequirements {
        class pistols {
            title = "Pistols";
            requiredLevel = 1;
        };
        class small_backpacks {
            title = "Small Backpacks";
            requiredLevel = 5;
        };
        class smgs {
            title = "SMGs";
            requiredLevel = 20;
        };
        class assault_rifles {
            title = "Assault Rifles";
            requiredLevel = 40;
        };
        class large_backpacks {
            title = "Large Backpacks";
            requiredLevel = 55;
        };
        class vehicles {
            title = "Vehicles";
            requiredLevel = 80;
        };
    };

    class Perks {
        class harvesting_speed {
            title = "Swift Harvest";
            group = "Civilian";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = -0.06;
            minMultiplier = 0.55;
            description = "Reduces harvesting action time by 6% per rank.";
        };
        class mining_speed {
            title = "Efficient Mining";
            group = "Civilian";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\mine_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = -0.06;
            minMultiplier = 0.55;
            description = "Reduces mining action time by 6% per rank.";
        };
        class carry_weight {
            title = "Pack Discipline";
            group = "All Roles";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = 4;
            description = "Reserved carry-weight perk for the inventory balance pass.";
        };
        class leo_fieldwork {
            title = "Field Officer";
            group = "LEO";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\defend_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = 0.04;
            description = "Reserved LEO fieldwork bonus for arrest and ticket systems.";
        };
        class ems_triage {
            title = "Rapid Triage";
            group = "EMS / Fire";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\heal_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = 0.04;
            description = "Reserved EMS bonus for revive and rescue systems.";
        };
        class gang_operator {
            title = "Street Operator";
            group = "Gang";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\attack_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = 0.04;
            description = "Reserved gang bonus for rival combat and contraband systems.";
        };
        class crafting_focus {
            title = "Bench Focus";
            group = "Crafting";
            icon = "\A3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa";
            maxRank = 5;
            cost = 1;
            modifier = 0.04;
            description = "Reserved crafting efficiency bonus for the workbench module.";
        };
    };
};
