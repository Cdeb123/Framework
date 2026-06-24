class LifeCraftingMenu {
    idd = 2400;
    name = "life_crafting_menu";
    movingEnable = false;
    enableSimulation = true;
    onLoad = "[] spawn life_fnc_craftingMenu;";

    class controlsBackground {
        class Life_RscTitleBackground: Life_RscText {
            colorBackground[] = {0.2, 0.2, 0.2, 1};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.8;
            h = (1 / 25);
        };

        class MainBackground: Life_RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.8;
            h = 0.6 - (22 / 250);
        };
    };

    class controls {
        class Title: Life_RscTitle {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "$STR_CRAFTING_Title";
            x = 0.1;
            y = 0.2;
            w = 0.6;
            h = (1 / 25);
        };

        class CraftList: Life_RscListBox {
            idc = 2401;
            text = "";
            sizeEx = 0.035;
            onLBSelChanged = "[_this] spawn life_fnc_craftingLBChange
;";
            x = 0.12; y = 0.26;
            w = 0.3; h = 0.4;
        };
    };
};