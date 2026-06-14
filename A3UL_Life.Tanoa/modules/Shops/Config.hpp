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

    class WeaponShops {
        /*
            New module weapon shops are class-based so modded items can be added
            without counting array indexes. Legacy WeaponShops still exist as a
            fallback for shops that have not been converted yet.
        */
        class Civilian {
            class gun {
                legacyShop = "gun";
                title = "Billy Joe's Firearms";
                subtitle = "Civilian firearms, magazines, and accessories";
                side = "civ";
                condition = "";
                requiredLicense = "gun";
                requiredLicenseSide = "civ";

                class License {
                    variable = "gun";
                    displayName = "STR_License_Firearm";
                    price = 10000;
                    side = "civ";
                    text = "Required before purchasing regulated civilian firearms from licensed dealers.";
                };

                class Categories {
                    class sidearms {
                        title = "Sidearms";
                        description = "Entry-level handguns for legal civilian carry.";

                        class Items {
                            class rook40 {
                                className = "hgun_Rook40_F";
                                nickname = "";
                                buyPrice = 6500;
                                sellPrice = 3250;
                                condition = "";
                                text = "Reliable 9mm pistol with affordable magazines.";
                            };
                            class pm9 {
                                className = "hgun_Pistol_01_F";
                                nickname = "";
                                buyPrice = 7000;
                                sellPrice = 3500;
                                condition = "";
                                text = "Compact Apex 9mm pistol for light civilian use.";
                            };
                            class zubr {
                                className = "hgun_Pistol_heavy_02_F";
                                nickname = "";
                                buyPrice = 9850;
                                sellPrice = 4925;
                                condition = "";
                                text = "High-impact revolver with limited capacity.";
                            };
                            class acpc2 {
                                className = "hgun_ACPC2_F";
                                nickname = "";
                                buyPrice = 11500;
                                sellPrice = 5750;
                                condition = "";
                                text = "Heavy .45 ACP sidearm with strong stopping power.";
                            };
                        };
                    };

                    class compact {
                        title = "Compact Firearms";
                        description = "Higher-cost civilian compact weapons.";

                        class Items {
                            class protector {
                                className = "SMG_05_F";
                                nickname = "";
                                buyPrice = 18000;
                                sellPrice = 9000;
                                condition = "";
                                text = "Compact 9mm SMG platform for licensed civilian buyers.";
                            };
                            class pdw2000 {
                                className = "hgun_PDW2000_F";
                                nickname = "";
                                buyPrice = 20000;
                                sellPrice = 10000;
                                condition = "";
                                text = "Personal defense weapon with strong magazine capacity.";
                            };
                        };
                    };

                    class magazines {
                        title = "Magazines";
                        description = "Ammunition magazines compatible with shop firearms.";

                        class Items {
                            class mag_16_9 {
                                className = "16Rnd_9x21_Mag";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 16 round 9mm magazine.";
                            };
                            class mag_6_45 {
                                className = "6Rnd_45ACP_Cylinder";
                                nickname = "";
                                buyPrice = 150;
                                sellPrice = 75;
                                condition = "";
                                text = "Six round .45 ACP revolver cylinder.";
                            };
                            class mag_9_45 {
                                className = "9Rnd_45ACP_Mag";
                                nickname = "";
                                buyPrice = 200;
                                sellPrice = 100;
                                condition = "";
                                text = "Nine round .45 ACP pistol magazine.";
                            };
                            class mag_30_9 {
                                className = "30Rnd_9x21_Mag";
                                nickname = "";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "";
                                text = "Thirty round 9mm magazine.";
                            };
                            class mag_30_smg {
                                className = "30Rnd_9x21_Mag_SMG_02";
                                nickname = "";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "";
                                text = "Thirty round Protector SMG magazine.";
                            };
                            class mag_10_9 {
                                className = "10Rnd_9x21_Mag";
                                nickname = "";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "";
                                text = "Ten round compact 9mm magazine.";
                            };
                        };
                    };

                    class accessories {
                        title = "Accessories";
                        description = "Legal optics and utility attachments.";

                        class Items {
                            class pistol_light {
                                className = "acc_flashlight_pistol";
                                nickname = "Pistol Flashlight";
                                buyPrice = 1000;
                                sellPrice = 500;
                                condition = "";
                                text = "Under-barrel light for compatible pistols.";
                            };
                            class smg_aco {
                                className = "optic_ACO_grn_smg";
                                nickname = "";
                                buyPrice = 2500;
                                sellPrice = 1250;
                                condition = "";
                                text = "Compact green-dot optic for compatible weapons.";
                            };
                        };
                    };
                };
            };

            class rebel {
                legacyShop = "rebel";
                title = "Rebel Trader";
                subtitle = "Restricted weapons and field equipment";
                side = "civ";
                condition = "";
                requiredLicense = "rebel";
                requiredLicenseSide = "civ";

                class License {
                    variable = "rebel";
                    displayName = "STR_License_Rebel";
                    price = 75000;
                    side = "civ";
                    text = "Required before accessing rebel weapons, vehicles, and restricted black-market supplies.";
                };

                class Categories {
                    class rifles {
                        title = "Rifles";
                        description = "Restricted rebel long guns. Modded weapons can be added to Config_Weapons.hpp class rebel items[].";
                        legacyShop = "rebel";
                        legacyArray = "items";
                    };
                    class magazines {
                        title = "Magazines";
                        description = "Ammunition magazines for rebel firearms.";
                        legacyShop = "rebel";
                        legacyArray = "mags";
                    };
                    class attachments {
                        title = "Attachments";
                        description = "Optics and accessories for rebel weapons.";
                        legacyShop = "rebel";
                        legacyArray = "accs";
                    };
                };
            };

            class gang {
                legacyShop = "gang";
                title = "Crime Base Armory";
                subtitle = "Gang firearms and low-profile weapons";
                side = "civ";
                condition = "";
                requiredLicense = "";
                requiredLicenseSide = "civ";

                class Categories {
                    class sidearms {
                        title = "Street Weapons";
                        description = "Gang-accessible firearms. Modded weapons can be added to Config_Weapons.hpp class gang items[].";
                        legacyShop = "gang";
                        legacyArray = "items";
                    };
                    class magazines {
                        title = "Magazines";
                        description = "Ammunition magazines for gang firearms.";
                        legacyShop = "gang";
                        legacyArray = "mags";
                    };
                    class attachments {
                        title = "Attachments";
                        description = "Low-profile attachments and optics.";
                        legacyShop = "gang";
                        legacyArray = "accs";
                    };
                };
            };

            class genstore {
                legacyShop = "genstore";
                title = "General Store";
                subtitle = "Navigation, medical, and utility equipment";
                side = "civ";
                condition = "";
                requiredLicense = "";
                requiredLicenseSide = "civ";

                class Categories {
                    class utility {
                        title = "Utility";
                        description = "General-use legal equipment from Config_Weapons.hpp class genstore.";
                        legacyShop = "genstore";
                        legacyArray = "items";
                    };
                };
            };

            class f_station_store: genstore {
                legacyShop = "f_station_store";
                title = "Fuel Station Store";
                subtitle = "Roadside equipment and travel supplies";

                class Categories {
                    class utility {
                        title = "Travel Utility";
                        description = "Fuel station utility stock from Config_Weapons.hpp class f_station_store.";
                        legacyShop = "f_station_store";
                        legacyArray = "items";
                    };
                };
            };
        };

        class LawEnforcement {
            class tcsd_armory {
                legacyShop = "cop_basic";
                title = "TCSD Armory";
                subtitle = "Duty equipment issued by rank, role, and subdivision";
                side = "cop";
                condition = "playerSide isEqualTo west";
                requiredLicense = "";
                requiredLicenseSide = "cop";

                class Categories {
                    class duty {
                        title = "Duty Essentials";
                        description = "Baseline issued equipment for sworn personnel.";

                        class Items {
                            class binocular {
                                className = "Binocular";
                                nickname = "";
                                buyPrice = 150;
                                sellPrice = 75;
                                condition = "";
                                text = "Standard field binoculars.";
                            };
                            class gps {
                                className = "ItemGPS";
                                nickname = "";
                                buyPrice = 100;
                                sellPrice = 50;
                                condition = "";
                                text = "Duty GPS unit.";
                            };
                            class firstaid {
                                className = "FirstAidKit";
                                nickname = "";
                                buyPrice = 150;
                                sellPrice = 75;
                                condition = "";
                                text = "Basic medical kit.";
                            };
                            class nvg {
                                className = "NVGoggles";
                                nickname = "";
                                buyPrice = 2000;
                                sellPrice = 1000;
                                condition = "";
                                text = "Night vision equipment.";
                            };
                            class flashbang {
                                className = "HandGrenade_Stone";
                                nickname = "Flashbang";
                                buyPrice = 1700;
                                sellPrice = 850;
                                condition = "";
                                text = "Less-lethal distraction device.";
                            };
                        };
                    };

                    class less_lethal {
                        title = "Less Lethal";
                        description = "Taser and less-lethal duty systems.";

                        class Items {
                            class stun_pistol {
                                className = "hgun_P07_snds_F";
                                nickname = "Stun Pistol";
                                buyPrice = 2000;
                                sellPrice = 1000;
                                condition = "";
                                text = "Sidearm configured for less-lethal use.";
                            };
                            class taser_rifle {
                                className = "arifle_SDAR_F";
                                nickname = "Taser Rifle";
                                buyPrice = 20000;
                                sellPrice = 10000;
                                condition = "";
                                text = "Long less-lethal platform.";
                            };
                            class taser_mag {
                                className = "20Rnd_556x45_UW_mag";
                                nickname = "Taser Rifle Magazine";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Magazine used by the less-lethal rifle.";
                            };
                        };
                    };

                    class sidearms {
                        title = "Sidearms";
                        description = "Authorized duty pistols.";

                        class Items {
                            class p07 {
                                className = "hgun_P07_F";
                                nickname = "";
                                buyPrice = 7500;
                                sellPrice = 3750;
                                condition = "";
                                text = "Standard P07 duty sidearm.";
                            };
                            class p07_khk {
                                className = "hgun_P07_khk_F";
                                nickname = "";
                                buyPrice = 7500;
                                sellPrice = 3750;
                                condition = "";
                                text = "Khaki P07 duty sidearm.";
                            };
                            class fourfive {
                                className = "hgun_Pistol_heavy_01_F";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Authorized .45 duty pistol for deputy and above.";
                            };
                            class mag_16_9 {
                                className = "16Rnd_9x21_Mag";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 9mm duty magazine.";
                            };
                            class mag_11_45 {
                                className = "11Rnd_45ACP_Mag";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP sidearm magazine.";
                            };
                        };
                    };

                    class long_guns {
                        title = "Long Guns";
                        description = "Rank-controlled patrol and tactical weapons.";

                        class Items {
                            class sting {
                                className = "SMG_02_ACO_F";
                                nickname = "";
                                buyPrice = 30000;
                                sellPrice = 15000;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Corporal-and-above compact patrol weapon.";
                            };
                            class mx {
                                className = "arifle_MX_F";
                                nickname = "";
                                buyPrice = 35000;
                                sellPrice = 17500;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Corporal-and-above patrol rifle.";
                            };
                            class acpc2 {
                                className = "hgun_ACPC2_F";
                                nickname = "";
                                buyPrice = 17500;
                                sellPrice = 8750;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "Sergeant-and-above heavy sidearm.";
                            };
                            class mxc {
                                className = "arifle_MXC_F";
                                nickname = "";
                                buyPrice = 30000;
                                sellPrice = 15000;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "Sergeant-and-above compact rifle.";
                            };
                            class cmr76 {
                                className = "srifle_DMR_07_blk_F";
                                nickname = "";
                                buyPrice = 32000;
                                sellPrice = 16000;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "Sergeant-and-above precision rifle.";
                            };
                            class mag_mx {
                                className = "30Rnd_65x39_caseless_mag";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "6.5mm rifle magazine.";
                            };
                            class mag_sting {
                                className = "30Rnd_9x21_Mag";
                                nickname = "";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "9mm SMG magazine.";
                            };
                            class mag_acpc {
                                className = "9Rnd_45ACP_Mag";
                                nickname = "";
                                buyPrice = 200;
                                sellPrice = 100;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP heavy sidearm magazine.";
                            };
                            class mag_cmr {
                                className = "20Rnd_650x39_Cased_Mag_F";
                                nickname = "";
                                buyPrice = 200;
                                sellPrice = 100;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "6.5mm precision rifle magazine.";
                            };
                        };
                    };

                    class attachments {
                        title = "Attachments";
                        description = "Optics, lights, and muzzle devices.";

                        class Items {
                            class muzzle_light {
                                className = "muzzle_snds_L";
                                nickname = "";
                                buyPrice = 650;
                                sellPrice = 325;
                                condition = "";
                                text = "Light pistol suppressor.";
                            };
                            class mrd {
                                className = "optic_MRD";
                                nickname = "";
                                buyPrice = 2750;
                                sellPrice = 1375;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Deputy-and-above mini reflex sight.";
                            };
                            class pistol_light {
                                className = "acc_flashlight_pistol";
                                nickname = "Pistol Flashlight";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Duty pistol light.";
                            };
                            class rifle_light {
                                className = "acc_flashlight";
                                nickname = "";
                                buyPrice = 750;
                                sellPrice = 375;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Rifle-mounted light.";
                            };
                            class holo {
                                className = "optic_Holosight";
                                nickname = "";
                                buyPrice = 1200;
                                sellPrice = 600;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Holographic optic.";
                            };
                            class arco {
                                className = "optic_Arco";
                                nickname = "";
                                buyPrice = 2500;
                                sellPrice = 1250;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Magnified patrol rifle optic.";
                            };
                            class muzzle_h {
                                className = "muzzle_snds_H";
                                nickname = "";
                                buyPrice = 2750;
                                sellPrice = 1375;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "6.5mm rifle suppressor.";
                            };
                        };
                    };
                };
            };
        };
    };

    class VehicleShops {
        class Civilian {
            class civ_car {
                legacyShop = "civ_car";
                title = "Tanoa Auto Gallery";
                subtitle = "Civilian road vehicles with purchase, rental, return, and storage service";
                side = "civ";
                condition = "";
                requiredLicense = "driver";
                shopFlag = "civ";
                allowRent = 1;
                allowReturn = 1;
                allowStore = 1;

                class Categories {
                    class cars {
                        title = "Cars and Utility";
                        description = "Daily drivers and utility platforms for civilian life.";
                        legacyVehicles = "civ_car";
                        features[] = {"Purchase or short-term rental","Civilian registration","Shop-point vehicle storage"};
                    };
                };
            };

            class kart_shop {
                legacyShop = "kart_shop";
                title = "Kart Center";
                subtitle = "Recreational kart rentals and purchases";
                side = "civ";
                condition = "";
                requiredLicense = "driver";
                shopFlag = "civ";
                allowRent = 1;
                allowReturn = 1;
                allowStore = 1;

                class Categories {
                    class karts {
                        title = "Karts";
                        description = "Light recreational vehicles.";
                        legacyVehicles = "kart_shop";
                        features[] = {"Low cost rental","Track-friendly handling","Small storage footprint"};
                    };
                };
            };

            class civ_truck {
                legacyShop = "civ_truck";
                title = "Commercial Truck Center";
                subtitle = "Cargo platforms for legal transport and industry";
                side = "civ";
                condition = "";
                requiredLicense = "trucking";
                shopFlag = "civ";
                allowRent = 1;
                allowReturn = 1;
                allowStore = 1;

                class Categories {
                    class trucks {
                        title = "Commercial Trucks";
                        description = "Cargo, box, covered, and fuel-capable trucks.";
                        legacyVehicles = "civ_truck";
                        features[] = {"High storage capacity","Commercial license required","Rental or ownership options"};
                    };
                };
            };

            class civ_air {
                legacyShop = "civ_air";
                title = "Civil Aviation Sales";
                subtitle = "Aircraft for certified civilian pilots";
                side = "civ";
                condition = "";
                requiredLicense = "pilot";
                shopFlag = "civ";
                allowRent = 1;
                allowReturn = 1;
                allowStore = 1;

                class Categories {
                    class aircraft {
                        title = "Aircraft";
                        description = "Light aircraft and helicopters.";
                        legacyVehicles = "civ_air";
                        features[] = {"Pilot license required","Air-capable spawn points","Rental or ownership options"};
                    };
                };
            };

            class civ_ship {
                legacyShop = "civ_ship";
                title = "Maritime Dealer";
                subtitle = "Watercraft for certified boat operators";
                side = "civ";
                condition = "";
                requiredLicense = "boat";
                shopFlag = "civ";
                allowRent = 1;
                allowReturn = 1;
                allowStore = 1;

                class Categories {
                    class boats {
                        title = "Watercraft";
                        description = "Civilian boats and water transport.";
                        legacyVehicles = "civ_ship";
                        features[] = {"Boat license required","Water spawn point service","Rental or ownership options"};
                    };
                };
            };

            class reb_car {
                legacyShop = "reb_car";
                title = "Rebel Trader Motor Yard";
                subtitle = "Restricted rebel vehicles and off-grid transport";
                side = "civ";
                condition = "";
                requiredLicense = "rebel";
                shopFlag = "civ";
                allowRent = 0;
                allowReturn = 0;
                allowStore = 1;

                class Categories {
                    class rebel {
                        title = "Rebel Vehicles";
                        description = "Restricted vehicles for licensed rebel access.";
                        legacyVehicles = "reb_car";
                        features[] = {"Rebel license required","Ownership only","Supports modded classnames in Config_Vehicles.hpp"};
                    };
                };
            };

            class crime_vehicle: reb_car {
                legacyShop = "reb_car";
                title = "Crime Base Motor Pool";
                subtitle = "Gang transport and off-road vehicles";
                requiredLicense = "";

                class Categories {
                    class gang {
                        title = "Gang Vehicles";
                        description = "Crime Base vehicles using the rebel vehicle pool until custom gang vehicles are configured.";
                        legacyVehicles = "reb_car";
                        features[] = {"Gang access","Ownership only","Ready for modded vehicle classnames"};
                    };
                };
            };
        };

        class LawEnforcement {
            class cop_car {
                legacyShop = "cop_car";
                title = "TCSD Motor Pool";
                subtitle = "Patrol and specialty ground vehicles";
                side = "cop";
                condition = "playerSide isEqualTo west";
                requiredCertification = "";
                department = "tcsd";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class patrol {
                        title = "Patrol";
                        description = "Standard patrol-ready vehicles.";

                        class Vehicles {
                            class offroad {
                                className = "C_Offroad_01_F";
                                displayName = "Patrol Offroad";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {};
                                features[] = {"General patrol platform","Low upkeep","Light utility cargo"};
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class suv {
                                className = "C_SUV_01_F";
                                displayName = "Patrol SUV";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {};
                                features[] = {"Higher road speed","Command-friendly interior","General response"};
                                text = "A clean patrol SUV for supervisors and standard patrol use.";
                            };
                            class sport {
                                className = "C_Hatchback_01_sport_F";
                                displayName = "Interceptor Hatchback";
                                price = -1;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {};
                                features[] = {"Fast pursuit response","Compact footprint","Deputy access"};
                                text = "A faster pursuit vehicle for qualified deputies and above.";
                            };
                        };
                    };

                    class tactical {
                        title = "Tactical";
                        description = "Heavy platforms for supervisors and specialty teams.";

                        class Vehicles {
                            class hunter {
                                className = "B_MRAP_01_F";
                                displayName = "Hunter";
                                price = -1;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {};
                                features[] = {"Armored response","Corporal access","High-risk transport"};
                                text = "Armored law enforcement platform for higher-risk operations.";
                            };
                            class hunter_hmg {
                                className = "B_MRAP_01_hmg_F";
                                displayName = "Hunter HMG";
                                price = -1;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"ert"};
                                features[] = {"Armed armored response","Sergeant access","ERT restricted"};
                                text = "Restricted tactical vehicle for authorized command and ERT use.";
                            };
                        };
                    };
                };
            };

            class cop_air {
                legacyShop = "cop_air";
                title = "TCSD Aviation";
                subtitle = "Aircraft requiring LEO Aviation certification";
                side = "cop";
                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                requiredCertification = "cAir";
                department = "tcsd";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class rotary {
                        title = "Rotary Wing";
                        description = "Air support aircraft for certified pilots.";

                        class Vehicles {
                            class hummingbird {
                                className = "B_Heli_Light_01_F";
                                displayName = "Police Hummingbird";
                                price = -1;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = {"Certified aviation only","Fast patrol observation","Light transport"};
                                text = "Light helicopter for certified TCSD aviation operations.";
                            };
                            class ghosthawk {
                                className = "B_Heli_Transport_01_F";
                                displayName = "Ghosthawk";
                                price = -1;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {"hse"};
                                features[] = {"Command airframe","Lieutenant access","HSE restricted"};
                                text = "Heavy transport aircraft for command-approved aviation use.";
                            };
                        };
                    };
                };
            };

            class cop_ship {
                legacyShop = "cop_ship";
                title = "TCSD Maritime";
                subtitle = "Marine units requiring LEO Maritime certification";
                side = "cop";
                condition = "playerSide isEqualTo west";
                requiredCertification = "cg";
                department = "tcsd";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class patrol {
                        title = "Patrol Boats";
                        description = "Watercraft for certified maritime operations.";

                        class Vehicles {
                            class assault_boat {
                                className = "B_Boat_Transport_01_F";
                                displayName = "Assault Boat";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {};
                                features[] = {"Certified maritime only","Rapid shore access","Small crew"};
                                text = "Small patrol boat for quick maritime response.";
                            };
                            class police_boat {
                                className = "C_Boat_Civil_01_police_F";
                                displayName = "Police Boat";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {};
                                features[] = {"Patrol boat","Civilian-facing livery","Maritime certification"};
                                text = "Standard police boat for visible marine patrol.";
                            };
                            class rhib {
                                className = "C_Boat_Transport_02_F";
                                displayName = "RHIB";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {};
                                features[] = {"Apex RHIB","Transport utility","Open water support"};
                                text = "Fast response craft for marine transport and interdiction.";
                            };
                            class armed_boat {
                                className = "B_Boat_Armed_01_minigun_F";
                                displayName = "Armed Patrol Boat";
                                price = -1;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"ert"};
                                features[] = {"Armed maritime platform","Sergeant access","ERT restricted"};
                                text = "Restricted armed marine platform for approved operations.";
                            };
                            class sdv {
                                className = "B_SDV_01_F";
                                displayName = "SDV";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {"hse"};
                                features[] = {"Submersible operations","HSE restricted","Low visibility movement"};
                                text = "Specialty submersible for maritime search and interdiction.";
                            };
                        };
                    };
                };
            };
        };
    };

    class ItemShops {
        class market {
            title = "Island Market";
            subtitle = "Food, drinks, tools, and everyday supplies";
            side = "civ";
            condition = "";
            requiredLicense = "";
            requiredLicenseSide = "civ";

            class Categories {
                class supplies {
                    title = "Market Goods";
                    taxCategory = "";
                    legacyVirtual = "market";
                };
            };
        };

        class med_market {
            title = "Medical Market";
            subtitle = "Responder supplies and recovery equipment";
            side = "med";
            condition = "";

            class Categories {
                class supplies {
                    title = "Medical Supplies";
                    taxCategory = "";
                    legacyVirtual = "med_market";
                };
            };
        };

        class f_station_coffee {
            title = "Fuel Station Market";
            subtitle = "Roadside supplies, drinks, and tools";
            side = "";
            condition = "";

            class Categories {
                class travel {
                    title = "Travel Supplies";
                    taxCategory = "";
                    legacyVirtual = "f_station_coffee";
                };
            };
        };

        class coffee {
            title = "Coffee Stand";
            subtitle = "Drinks and quick food";
            side = "civ";
            condition = "";

            class Categories {
                class food {
                    title = "Food and Drinks";
                    taxCategory = "food";
                    legacyVirtual = "coffee";
                };
            };
        };

        class rebel {
            title = "Rebel Trader";
            subtitle = "Restricted supplies, field gear, and black-market tools";
            side = "civ";
            condition = "";
            requiredLicense = "rebel";
            requiredLicenseSide = "civ";

            class License {
                variable = "rebel";
                displayName = "STR_License_Rebel";
                price = 75000;
                side = "civ";
                text = "Required before accessing rebel weapons, vehicles, clothing, and restricted supplies.";
            };

            class Categories {
                class supplies {
                    title = "Restricted Supplies";
                    taxCategory = "";
                    legacyVirtual = "rebel";
                };
                class uniforms {
                    title = "Rebel Clothing";
                    taxCategory = "clothing";
                    legacyClothing = "reb";
                    legacySection = "uniforms";
                };
                class headgear {
                    title = "Headgear";
                    taxCategory = "clothing";
                    legacyClothing = "reb";
                    legacySection = "headgear";
                };
                class vests {
                    title = "Vests";
                    taxCategory = "clothing";
                    legacyClothing = "reb";
                    legacySection = "vests";
                };
                class backpacks {
                    title = "Backpacks";
                    taxCategory = "clothing";
                    legacyClothing = "reb";
                    legacySection = "backpacks";
                };
            };
        };

        class gang {
            title = "Crime Base";
            subtitle = "Gang supplies, tools, clothing, and street equipment";
            side = "civ";
            condition = "";
            requiredLicense = "";
            requiredLicenseSide = "civ";

            class Categories {
                class supplies {
                    title = "Crime Supplies";
                    taxCategory = "";
                    legacyVirtual = "gang";
                };
                class clothing {
                    title = "Gang Clothing";
                    taxCategory = "clothing";
                    legacyClothing = "gang_clothing";
                    legacySection = "vests";
                };
                class backpacks {
                    title = "Backpacks";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "backpacks";
                };
            };
        };

        class bruce {
            title = "Bruce's Outfits";
            subtitle = "Civilian clothing, bags, hats, and accessories";
            side = "civ";
            condition = "";

            class Categories {
                class uniforms {
                    title = "Clothing";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "uniforms";
                };
                class headgear {
                    title = "Hats";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "headgear";
                };
                class goggles {
                    title = "Glasses";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "goggles";
                };
                class vests {
                    title = "Vests";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "vests";
                };
                class backpacks {
                    title = "Backpacks";
                    taxCategory = "clothing";
                    legacyClothing = "bruce";
                    legacySection = "backpacks";
                };
            };
        };

        class dive: bruce {
            title = "Diving Outfitters";
            subtitle = "Licensed diving suits and water equipment";
            condition = "license_civ_dive";

            class Categories {
                class uniforms {
                    title = "Wetsuits";
                    taxCategory = "clothing";
                    legacyClothing = "dive";
                    legacySection = "uniforms";
                };
                class goggles {
                    title = "Diving Goggles";
                    taxCategory = "clothing";
                    legacyClothing = "dive";
                    legacySection = "goggles";
                };
                class vests {
                    title = "Rebreathers";
                    taxCategory = "clothing";
                    legacyClothing = "dive";
                    legacySection = "vests";
                };
            };
        };

        class reb: rebel {
            title = "Rebel Clothing";
            subtitle = "Restricted rebel outfits and equipment";
        };

        class gang_clothing: gang {
            title = "Crime Base Clothing";
            subtitle = "Gang clothing and concealment gear";
        };

        class kart: bruce {
            title = "Kart Gear";
            subtitle = "Racing outfits and kart accessories";

            class Categories {
                class uniforms {
                    title = "Kart Suits";
                    taxCategory = "clothing";
                    legacyClothing = "kart";
                    legacySection = "uniforms";
                };
                class headgear {
                    title = "Racing Helmets";
                    taxCategory = "clothing";
                    legacyClothing = "kart";
                    legacySection = "headgear";
                };
            };
        };

        class cop {
            title = "Department Supply";
            subtitle = "Law enforcement field supplies";
            side = "cop";
            condition = "";

            class Categories {
                class supplies {
                    title = "Department Supplies";
                    taxCategory = "";
                    legacyVirtual = "cop";
                };
            };
        };
    };
};
