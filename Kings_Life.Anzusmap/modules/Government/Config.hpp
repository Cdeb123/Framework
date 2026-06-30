class Life_Government {
    startingBalance = 0;

    class Taxes {
        class food {
            title = "Food";
            rate = 0.05;
        };
        class fuel {
            title = "Fuel";
            rate = 0.10;
        };
        class weapons {
            title = "Weapons";
            rate = 0.02;
        };
        class clothing {
            title = "Clothing";
            rate = 0.03;
        };
        class houses {
            title = "Property";
            rate = 0.03;
        };
        class weed {
            title = "Weed";
            rate = 0;
        };
        class illegal_drugs {
            title = "Illegal Drug Profits";
            rate = 0.25;
        };
    };

    class TaxCategories {
        foodItems[] = {"apple","peach","tbacon","donuts","rabbit","salema","ornate","mackerel","tuna","mullet","catshark","turtle_soup","hen","rooster","sheep","goat","coffee","waterBottle","beer","whiskey","redgull"};
        fuelItems[] = {"fuelEmpty","fuelFull"};
        weedItems[] = {"cannabis","marijuana"};
        illegalDrugItems[] = {"heroin_unprocessed","heroin_processed","cocaine_unprocessed","cocaine_processed","meth_unprocessed","meth_processed"};
    };
};
