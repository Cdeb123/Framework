class Life_Shops {
    class LicenseShops {
        class DMV {
            title = "Department of Motor Vehicles";
            subtitle = "Civil permits and transportation licenses";

            class Licenses {
                class driver {
                    variable = "driver";
                    displayName = "STR_License_Driver";
                    price = 250;
                    side = "civ";
                    text = "Required to legally operate standard road vehicles.";
                };
                class boat {
                    variable = "boat";
                    displayName = "STR_License_Boat";
                    price = 150;
                    side = "civ";
                    text = "Required to legally operate civilian watercraft.";
                };
                class pilot {
                    variable = "pilot";
                    displayName = "STR_License_Pilot";
                    price = 1500;
                    side = "civ";
                    text = "Required to legally operate civilian aircraft.";
                };
                class trucking {
                    variable = "trucking";
                    displayName = "STR_License_Truck";
                    price = 2500;
                    side = "civ";
                    text = "Required to legally operate commercial transport trucks.";
                };
                class dive {
                    variable = "dive";
                    displayName = "STR_License_Diving";
                    price = 950;
                    side = "civ";
                    text = "Required for legal diving work and underwater equipment access.";
                };
                class home {
                    variable = "home";
                    displayName = "STR_License_Home";
                    price = 7500;
                    side = "civ";
                    text = "Required to purchase and register residential property.";
                };
            };
        };
    };
};
