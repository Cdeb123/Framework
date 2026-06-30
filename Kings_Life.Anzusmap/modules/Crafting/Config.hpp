class Life_Crafting {
    minCraftDistance = 7;
    defaultQuantity = 1;
    maxMagazineQuantity = 100;
    vehicleColorIndex = 0;

    /*
        Storage level format:
        {level, capacity, upgradeCost}
        Workbench and item storage capacity is virtual item weight.
        Gear storage capacity is physical item slots.
    */
    class Storage {
        workbenchLevels[] = {
            {1,350,0},
            {2,550,25000},
            {3,800,75000},
            {4,1100,150000},
            {5,1500,300000}
        };
        itemStorageLevels[] = {
            {1,500,0},
            {2,800,35000},
            {3,1200,90000},
            {4,1700,175000},
            {5,2400,325000}
        };
        gearStorageLevels[] = {
            {1,35,0},
            {2,55,30000},
            {3,80,85000},
            {4,115,160000},
            {5,160,300000}
        };
        workbenchItems[] = {
            "copper_unrefined","copper_refined",
            "iron_unrefined","iron_refined",
            "salt_unrefined","salt_refined",
            "sand","glass","rock","cement",
            "diamond_uncut","diamond_cut",
            "oil_unprocessed","oil_processed",
            "goldbar"
        };
    };

    class Themes {
        class civilian {
            title = "Home Workbench";
            subtitle = "Civilian crafting, storage, tools, firearms, and vehicles";
            accent[] = {0.0,0.68,0.74,1};
            header[] = {0.035,0.050,0.052,1};
            back[] = {0.018,0.024,0.026,0.96};
            text[] = {0.92,0.98,0.98,1};
            muted[] = {0.62,0.78,0.78,1};
        };
        class rebel {
            title = "Rebel Fabricator";
            subtitle = "Restricted weapons, field gear, and black-market vehicles";
            accent[] = {0.86,0.24,0.17,1};
            header[] = {0.075,0.035,0.028,1};
            back[] = {0.026,0.019,0.017,0.96};
            text[] = {1.0,0.92,0.88,1};
            muted[] = {0.82,0.62,0.56,1};
        };
        class leo {
            title = "KCSO Fabrication Bench";
            subtitle = "Ranked duty equipment, certified platforms, and department vehicles";
            accent[] = {0.0,0.72,0.92,1};
            header[] = {0.018,0.030,0.040,0.98};
            back[] = {0.010,0.014,0.020,0.96};
            text[] = {0.94,0.99,1,1};
            muted[] = {0.56,0.70,0.78,1};
        };
    };

    #include "configs\Civilian.hpp"
    #include "configs\Rebel.hpp"
    #include "configs\LawEnforcement.hpp"
};
