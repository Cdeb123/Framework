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
                title = "Bob's Gun Emporium";
                subtitle = "Civilian firearms, magazines, and accessories";
                side = "civ";
                condition = "";
                requiredLicense = "gun";
                requiredLicenseSide = "civ";

                class License {
                    variable = "gun";
                    displayName = "STR_License_Firearm";
                    price = 500;
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
                title = "Rebel Outpost Armory";
                subtitle = "Restricted weapons and field equipment";
                side = "civ";
                condition = "";
                requiredLicense = "rebel";
                requiredLicenseSide = "civ";

                class License {
                    variable = "rebel";
                    displayName = "STR_License_Rebel";
                    price = 7500;
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
                            class AG_PoliceThing {
                                className = "AG_PoliceThing";
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
                            class RH_m9 {
                                className = "RH_m9";
                                nickname = "";
                                buyPrice = 4500;
                                sellPrice = 3500;
                                condition = "";
                                text = "Standard M9 Beretta Sidearm.";
                            };
                            class RH_g17 {
                                className = "RH_g17";
                                nickname = "";
                                buyPrice = 7500;
                                sellPrice = 3750;
                                condition = "";
                                text = "Standard G17 duty sidearm.";
                            };
                            class RH_g19 {
                                className = "RH_g19";
                                nickname = "";
                                buyPrice = 7500;
                                sellPrice = 3750;
                                condition = "";
                                text = "Khaki G19 duty sidearm.";
                            };
                            class RH_kimber_nw {
                                className = "RH_kimber_nw";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Authorized .45 duty pistol for deputy and above.";
                            };
                            class RH_17Rnd_9x19_g17 {
                                className = "RH_17Rnd_9x19_g17";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 9mm duty magazine.";
                            };
                            class RH_15Rnd_9x19_M9 {
                                className = "RH_15Rnd_9x19_M9";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 20;
                                condition = "";
                                text = "Standard 9mm M9 Magazine.";
                            };
                            class RH_7Rnd_45cal_m1911 {
                                className = "RH_7Rnd_45cal_m1911";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP sidearm magazine.";
                            };
                            class RH_sw659 {
                                className = "RH_sw659";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['sheriff'] call life_fnc_leoAtLeastRank";
                                text = "Authorized 9mm Handgun";
                            };
                            class RH_14Rnd_9x19_sw {
                                className = "RH_14Rnd_9x19_sw";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['sheriff'] call life_fnc_leoAtLeastRank";
                                text = "Smith and Wesson 9mm 14rnd Magazine";
                            };
                        };
                    };

                    class long_guns {
                        title = "Long Guns";
                        description = "Rank-controlled patrol and tactical weapons.";

                        class Items {
                            class hlc_rifle_RU5562 {
                                className = "hlc_rifle_RU5562";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 15000;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Patrol Rifle for Deputies and Above.";
                            };
                            class SMA_AAC_MPW_12_Black {
                                className = "SMA_AAC_MPW_12_Black";
                                nickname = "";
                                buyPrice = 8500;
                                sellPrice = 7500;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Patrol Rifle for Deputies and Above.";
                            };
                            class SMA_ACRREMMOEblk {
                                className = "SMA_ACRREMMOEblk";
                                nickname = "";
                                buyPrice = 22000;
                                sellPrice = 21000;
                                condition = "['senior_deputy'] call life_fnc_leoAtLeastRank";
                                text = "Patrol ACR Rifle for Senior Depuites and Above.";
                            };
                            class hlc_mp510_tac {
                                className = "arifle_MXC_F";
                                nickname = "";
                                buyPrice = 30000;
                                sellPrice = 15000;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "Sergeant-and-above compact rifle.";
                            };
                            class RH_Hk416c {
                                className = "RH_Hk416c";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 24500;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "5.56 Assualt Rifle Sergeant and Above.";
                            };
                            class hlc_30rnd_556x45_EPR {
                                className = "hlc_30rnd_556x45_EPR";
                                nickname = "";
                                buyPrice = 95;
                                sellPrice = 85;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "5.56 EPR Rifle Magazine.";
                            };
                            class hlc_30rnd_556x45_SOST {
                                className = "hlc_30rnd_556x45_SOST";
                                nickname = "";
                                buyPrice = 100;
                                sellPrice = 95;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "5.56 SOST Rifle Magazine.";
                            };
                            class SMA_30Rnd_68x43_SPC_FMJ {
                                className = "SMA_30Rnd_68x43_SPC_FMJ";
                                nickname = "";
                                buyPrice = 150;
                                sellPrice = 145;
                                condition = "['senior_deputy'] call life_fnc_leoAtLeastRank";
                                text = "6.8mm Percision Assault Rifle Magazine";
                            };
                            class hlc_30rnd_556x45_EPR_EMAG {
                                className = "hlc_30rnd_556x45_EPR_EMAG";
                                nickname = "";
                                buyPrice = 155;
                                sellPrice = 150;
                                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                                text = "5.56 EPR EMAG Rifle Magazine";
                            };
                            class hlc_30Rnd_10mm_B_MP5 {
                                className = "hlc_30Rnd_10mm_B_MP5";
                                nickname = "";
                                buyPrice = 85;
                                sellPrice = 75;
                                condition = "['cadet'] call life_fnc_leoAtLeastRank";
                                text = "10mm MP5 SMG Magazine";
                            };
                        };
                    };

                    class attachments {
                        title = "Attachments";
                        description = "Optics, lights, and muzzle devices.";

                        class Items {
                            class RH_X300 {
                                className = "RH_X300";
                                nickname = "";
                                buyPrice = 650;
                                sellPrice = 325;
                                condition = "";
                                text = "Light pistol suppressor.";
                            };
                            class SMA_SFFL_BLK {
                                className = "SMA_SFFL_BLK";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "Surefire Rifle Flashlight";
                            };
                            class RH_ta31rmr {
                                className = "RH_ta31rmr";
                                nickname = "Acog RMR";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['deputy'] call life_fnc_leoAtLeastRank";
                                text = "ACOG TA31F RMR Sight";
                            };
                            class RH_ta01nsn {
                                className = "RH_ta01nsn";
                                nickname = "";
                                buyPrice = 750;
                                sellPrice = 375;
                                condition = "['senior_deputy'] call life_fnc_leoAtLeastRank";
                                text = "ACOG TA01NSN Sight";
                            };
                            class AG_muzzle_Blank {
                                className = "AG_muzzle_Blank";
                                nickname = "";
                                buyPrice = 1;
                                sellPrice = 1;
                                condition = "['cadet'] call life_fnc_leoAtLeastRank";
                                text = "Training Muzzle Device";
                            };
                            class arco {
                                className = "optic_Arco";
                                nickname = "";
                                buyPrice = 350;
                                sellPrice = 250;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Magnified patrol rifle optic.";
                            };
                            class RH_compM2l {
                                className = "RH_compM2l";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['corporal'] call life_fnc_leoAtLeastRank";
                                text = "Comp Aimpoint Red Dot Low";
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
                        features[] = {"Purchase or short-term rental","Civilian registration","Shop-point vehicle storage"};

                        class Vehicles {
                            class d3s_Aprilia_Tuono_V4_1100_RR_AG { className = "d3s_Aprilia_Tuono_V4_1100_RR_AG"; };
                            class d3s_BMW_S_1000_RR_AG { className = "d3s_BMW_S_1000_RR_AG"; };
                            class d3s_f80_14_AG { className = "d3s_f80_14_AG"; };
                            class d3s_f86_15_Black_AG { className = "d3s_f86_15_Black_AG"; };
                            class d3s_CT5_22_AG { className = "d3s_CT5_22_AG"; };
                            class d3s_escalade_16_AG { className = "d3s_escalade_16_AG"; };
                            class d3s_tahoe_15_LT_AG { className = "d3s_tahoe_15_LT_AG"; };
                        };
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
                        features[] = {"Low cost rental","Track-friendly handling","Small storage footprint"};

                        class Vehicles {
                            class C_Kart_01_Blu_F { className = "C_Kart_01_Blu_F"; };
                            class C_Kart_01_Fuel_F { className = "C_Kart_01_Fuel_F"; };
                            class C_Kart_01_Red_F { className = "C_Kart_01_Red_F"; };
                            class C_Kart_01_Vrana_F { className = "C_Kart_01_Vrana_F"; };
                        };
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
                        features[] = {"High storage capacity","Commercial license required","Rental or ownership options"};

                        class Vehicles {
                            class d3s_cascadia_19_Dryvan_AG { className = "d3s_cascadia_19_Dryvan_AG"; };
                        };
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
                        features[] = {"Pilot license required","Air-capable spawn points","Rental or ownership options"};

                        class Vehicles {
                            class C_Heli_Light_01_civil_F { className = "C_Heli_Light_01_civil_F"; };
                            class B_Heli_Light_01_F { className = "B_Heli_Light_01_F"; };
                            class ag_sparrow1 { className = "ag_sparrow1"; };
                            class C_Plane_Civil_01_F { className = "C_Plane_Civil_01_F"; };
                        };
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
                        features[] = {"Boat license required","Water spawn point service","Rental or ownership options"};

                        class Vehicles {
                            class C_Rubberboat { className = "C_Rubberboat"; };
                            class C_Boat_Civil_01_F { className = "C_Boat_Civil_01_F"; };
                            class B_SDV_01_F { className = "B_SDV_01_F"; };
                            class C_Boat_Transport_02_F { className = "C_Boat_Transport_02_F"; };
                            class C_Scooter_Transport_01_F { className = "C_Scooter_Transport_01_F"; };
                        };
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
                    class ground {
                        title = "Ground Vehicles";
                        description = "Rebel ground transport and off-grid utility platforms.";
                        features[] = {"Rebel license required","Ownership only","Ground spawn service"};

                        class Vehicles {
                            class B_Quadbike_01_F { className = "B_Quadbike_01_F"; };
                            class B_G_Offroad_01_F { className = "B_G_Offroad_01_F"; };
                            class O_T_LSV_02_unarmed_F { className = "O_T_LSV_02_unarmed_F"; };
                            class O_MRAP_02_F { className = "O_MRAP_02_F"; };
                            class B_G_Offroad_01_armed_F { className = "B_G_Offroad_01_armed_F"; };
                        };
                    };

                    class aircraft {
                        title = "Aircraft";
                        description = "Rebel aircraft for off-grid air transport.";
                        features[] = {"Rebel license required","Pilot-capable vehicles use pilot access","Ownership only"};

                        class Vehicles {
                            class B_Heli_Light_01_stripped_F { className = "B_Heli_Light_01_stripped_F"; };
                            class B_Heli_Light_01_F { className = "B_Heli_Light_01_F"; };
                            class O_Heli_Light_02_unarmed_F { className = "O_Heli_Light_02_unarmed_F"; };
                        };
                    };

                    class watercraft {
                        title = "Watercraft";
                        description = "Rebel-capable boats and submersible transport.";
                        features[] = {"Rebel license required","Boat-capable vehicles use boat access","Ownership only"};

                        class Vehicles {
                            class C_Rubberboat { className = "C_Rubberboat"; };
                            class C_Boat_Civil_01_F { className = "C_Boat_Civil_01_F"; };
                            class B_SDV_01_F { className = "B_SDV_01_F"; };
                            class C_Boat_Transport_02_F { className = "C_Boat_Transport_02_F"; };
                            class C_Scooter_Transport_01_F { className = "C_Scooter_Transport_01_F"; };
                        };
                    };
                };
            };

            class reb_air {
                legacyShop = "reb_air";
                title = "Rebel Air Yard";
                subtitle = "Restricted rebel aircraft and air transport";
                side = "civ";
                condition = "";
                requiredLicense = "rebel";
                shopFlag = "reb";
                allowRent = 0;
                allowReturn = 0;
                allowStore = 1;

                class Categories {
                    class aircraft {
                        title = "Aircraft";
                        description = "Rebel aircraft for off-grid air transport.";
                        features[] = {"Rebel license required","Pilot-capable vehicles use pilot access","Ownership only"};

                        class Vehicles {
                            class B_Heli_Light_01_stripped_F { className = "B_Heli_Light_01_stripped_F"; };
                            class B_Heli_Light_01_F { className = "B_Heli_Light_01_F"; };
                            class O_Heli_Light_02_unarmed_F { className = "O_Heli_Light_02_unarmed_F"; };
                        };
                    };
                };
            };

            class reb_ship {
                legacyShop = "reb_ship";
                title = "Rebel Maritime Yard";
                subtitle = "Restricted rebel boats and water transport";
                side = "civ";
                condition = "";
                requiredLicense = "rebel";
                shopFlag = "reb";
                allowRent = 0;
                allowReturn = 0;
                allowStore = 1;

                class Categories {
                    class watercraft {
                        title = "Watercraft";
                        description = "Rebel-capable boats and submersible transport.";
                        features[] = {"Rebel license required","Boat-capable vehicles use boat access","Ownership only"};

                        class Vehicles {
                            class C_Rubberboat { className = "C_Rubberboat"; };
                            class C_Boat_Civil_01_F { className = "C_Boat_Civil_01_F"; };
                            class B_SDV_01_F { className = "B_SDV_01_F"; };
                            class C_Boat_Transport_02_F { className = "C_Boat_Transport_02_F"; };
                            class C_Scooter_Transport_01_F { className = "C_Scooter_Transport_01_F"; };
                        };
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
                        features[] = {"Gang access","Ownership only","Ready for modded vehicle classnames"};

                        class Vehicles {
                            class B_Quadbike_01_F { className = "B_Quadbike_01_F"; };
                            class B_G_Offroad_01_F { className = "B_G_Offroad_01_F"; };
                            class O_T_LSV_02_unarmed_F { className = "O_T_LSV_02_unarmed_F"; };
                            class O_MRAP_02_F { className = "O_MRAP_02_F"; };
                            class B_G_Offroad_01_armed_F { className = "B_G_Offroad_01_armed_F"; };
                        };
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
                            class AG_CROWNVIC_Police_AG {
                                className = "AG_CROWNVIC_Police_AG";
                                displayName = "TCSD CVPI Patrol";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"patrol"};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CROWNVIC_Police_ST_AG {
                                className = "AG_CROWNVIC_Police_ST_AG";
                                displayName = "TCSD CVPI Patrol Slicktop";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"patrol"};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CTSV_Police_AG {
                                className = "AG_CTSV_Police_AG";
                                displayName = "TCSD Cadillac CTS-V Patrol";
                                price = 35000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = { "patrol" };
                                features[] = {"Fast Pursuit Response", "Low Maintenance", "Patrol Vehicle", "Prisoner Transport" };
                                text = "A Dependable Patrol Vehicle for Everyday Calls and Transport";
                            };
                            class AG_CHARGER_Police_AG {
                                className = "AG_CHARGER_Police_AG";
                                displayName = "TCSD Charger Patrol";
                                price = 25000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"patrol"};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CHARGER_Police_ST_AG {
                                className = "AG_CHARGER_Police_ST_AG";
                                displayName = "TCSD Charger Patrol Slicktop";
                                price = 24000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"patrol"};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport Qualified" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_Suburban16_Police_AG {
                                className = "AG_Suburban16_Police_AG";
                                displayName = "TCSD Suburban Patrol Utility";
                                price = 33000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            };
                            class AG_Suburban16_Police_ST_AG {
                                className = "AG_Suburban16_Police_ST_AG";
                                displayName = "TCSD Suburban Patrol Utility Slicktop";
                                price = 32000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            }
                            class AG_TAHOE08_Police_AG {
                                className = "AG_TAHOE08_Police_AG";
                                displayName = "TCSD Tahoe Patrol Utility";
                                price = 7500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            };
                            class AG_TAHOE08_Police_ST_AG {
                                className = "AG_TAHOE08_Police_ST_AG";
                                displayName = "TCSD Tahoe Patrol Utility Slicktop";
                                price = 7500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_Silverado_19_Police_AG {
                                className = "AG_Silverado_19_Police_AG";
                                displayName = "TCSD Silverado Patrol Truck";
                                price = 75000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Silverado_19_Police_ST_AG {
                                className = "AG_Silverado_19_Police_ST_AG";
                                displayName = "TCSD Silverado Patrol Truck Slicktop";
                                price = 74000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Durango_Police_AG {
                                className = "AG_Durango_Police_AG";
                                displayName = "TCSD Durango Pursuit Vehicle Utility";
                                price = 85000;
                                condition = "";
                                rank = "captain";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Fast Response Vehicle","Supervisor Access","Prisoner Transport" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Durango_Police_ST_AG {
                                className = "AG_Durango_Police_ST_AG";
                                displayName = "TCSD Durango Pursuit Vehicle Utility Slicktop";
                                price = 84000;
                                condition = "";
                                rank = "captain";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Fast Response Vehicle","Supervisor Access","Prisoner Transport" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_EXPLORER_Police_AG {
                                className = "AG_EXPLORER_Police_AG";
                                displayName = "TCSD FPIU Patrol";
                                price = 15000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Prisoner Transport","Low Maintenance" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_EXPLORER_Police_ST_AG {
                                className = "AG_EXPLORER_Police_ST_AG";
                                displayName = "TCSD FPIU Patrol Slicktop";
                                price = 14000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {"patrol"};
                                features[] = { "Utility Vehicle","Prisoner Transport","Low Maintenance" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_Titan_Police_AG {
                                className = "AG_Titan_Police_AG";
                                displayName = "TCSD Titan Pickup Truck Utility";
                                price = 95000;
                                condition = "";
                                rank = "major";
                                subdivisions[] = {"patrol"};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Majors and Above.";
                            };
                        };
                    };

                    class hse {
                        title = "Speed Enforcement";
                        description = "Speed Enforcement Vehicles";

                        class Vehicles {
                            class AG_MustangGT15_HSU_AG {
                                className = "AG_MustangGT15_HSU_AG";
                                displayName = "TCSD HSE Mustang Pursuit Vehicle";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hse"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT15_HSU_ST_AG {
                                className = "AG_MustangGT15_HSU_ST_AG";
                                displayName = "TCSD HSE Mustang Pursuit Vehicle Slicktop";
                                price = 5400;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hse"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT500_HSU_AG {
                                className = "AG_MustangGT500_HSU_AG";
                                displayName = "TCSD HSE Mustang GT500";
                                price = 7500;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"hse"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT500_HSU_ST_AG {
                                className = "AG_MustangGT500_HSU_ST_AG";
                                displayName = "TCSD HSE Mustang GT500 Slicktop";
                                price = 7400;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"hse"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                        };
                    };

                    class cid {
                        title = "Criminal Investigations Vehicles";
                        description = "CID Unmarked Units";

                        class Vehicles {
                           class AG_CROWNVIC_UNM_AG {
                                className = "AG_CROWNVIC_UNM_AG";
                                displayName = "TCSD CVPI Unmarked Unit";
                                price = 10000;
                                condition = "";
                                rank = "detective";
                                subdivisions[] = {"cid"};
                                features[] = {"Unmarked Unit","Covert Operations","Investigations Unit"};
                                text = "A Unmarked Patrol Car for Criminal Investigators";
                            };
                            class AG_CHARGER_SRT_UNM_AG {
                                className = "AG_CHARGER_SRT_UNM_AG";
                                displayName = "TCSD Charger SRT Unmarked Unit";
                                price = 15000;
                                condition = "";
                                rank = "detective";
                                subdivisions[] = {"cid"};
                                features[] = {"Unmarked Unit","Covert Operations","Investigations Unit","Rapid Response Unit"};
                                text = "A Unmarked Patrol Car for Criminal Investigators";
                            };
                        };
                    };

                    class academy {
                        title = "Academy FTO Patrol Vehicles";
                        description = "Academy Patrol Cars for Field Training Officers";

                        class Vehicles {
                           class AG_X5_AdminServices_AG {
                                className = "AG_X5_AdminServices_AG";
                                displayName = "TCSD FTO X5 Patrol Car";
                                price = 25000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"academy"};
                                features[] = {"Field Training Vehicle","Pursuit Training Vehicle","Rapid Response Unit"};
                                text = "A Training Vehicle for Deputies";
                            };
                            class AG_amgGT_19_AdminServices_AG {
                                className = "AG_amgGT_19_AdminServices_AG";
                                displayName = "TCSD FTO AMG GT Patrol Car";
                                price = 35000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"academy"};
                                features[] = {"Field Training Vehicle","Pursuit Training Vehicle","Rapid Response Unit"};
                                text = "A Training Vehicle for Deputies";
                            };
                        };
                    };

                    class tactical {
                        title = "Tactical";
                        description = "Heavy platforms for supervisors and specialty teams.";

                        class Vehicles {
                            class AG_Bearcat_KCSO_AG {
                                className = "AG_Bearcat_KCSO_AG";
                                displayName = "Lenco Bearcat Tanoa County ERT";
                                price = 5500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"ert"};
                                features[] = {"Armored response","Sergeant Access","High-risk transport"};
                                text = "Armored law enforcement platform for higher-risk operations.";
                            };
                            class AG_Suburban16_SWAT_AG {
                                className = "AG_Suburban16_SWAT_AG";
                                displayName = "TCSD ERT Suburban Utility Vehicle";
                                price = 8500;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"ert"};
                                features[] = {"Armed armored response","Deputy Access","ERT restricted"};
                                text = "Restricted tactical vehicle for authorized command and ERT use.";
                            };
                            class AG_Cherokee_SWAT_AG {
                                className = "AG_Cherokee_SWAT_AG";
                                displayName = "TCSD ERT Cherokee Utility Vehicle";
                                price = 10000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"ert"};
                                features[] = {"Armed armored response","Senior Deputy Access","ERT restricted"};
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
                            class AG_Hummingbird_Police {
                                className = "AG_Hummingbird_Police";
                                displayName = "TCSD Hummingbird Patrol Helicopter";
                                price = 95000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"patrol"};
                                features[] = {"Certified aviation only","Fast patrol observation","Light transport"};
                                text = "Light Helicopter for Certified TCSD Aviation Operations.";
                            };
                            class AG_Hummingbird_Police_Adv {
                                className = "AG_Hummingbird_Police_Adv";
                                displayName = "TCSD Hummingbird Advanced Patrol Helicopter";
                                price = 96000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {"patrol"};
                                features[] = { "Certified aviation only","Fast patrol observation","Light transport" };
                                text = "Light helicopter for certified TCSD aviation operations.";
                            };
                            class AG_Hummingbird_HSU {
                                className = "AG_Hummingbird_HSU";
                                displayName = "TCSD High Speed Enforcement Patrol Helicopter";
                                price = 98000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hse"};
                                features[] = {"Speed Enforcement","Advanced Pilot","Pursuit Helicopter"};
                                text = "High Speed Pursuit Helicopter for Aviation Operations";
                            };
                            class AG_UH60M_Sheriff_AG {
                                className = "AG_UH60M_Sheriff_AG";
                                displayName = "TCSD UH60 Utility Helicopter";
                                price = 97000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"patrol"};
                                features[] = {"Transport Helicopter","Advanced Pilot","Air Operations"};
                                text = "Heavy Police Helicopter for Transport";
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

    class LEOClothingShops {
        class cop {
            title = "TCSD Uniform Locker";
            subtitle = "Duty clothing issued by rank, role, and subdivision";
            side = "cop";
            condition = "playerSide isEqualTo west";
            department = "tcsd";

            class Categories {
                class patrol {
                    title = "Patrol Basics";
                    description = "Standard patrol uniforms, belts, headgear, and duty bags.";

                    class Items {
                        class remove_uniform {
                            className = "NONE";
                            itemType = "uniform";
                            displayName = "Remove Uniform";
                            price = 0;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Removes the currently worn uniform slot.";
                        };
                        class remove_headgear {
                            className = "NONE";
                            itemType = "headgear";
                            displayName = "Remove Headgear";
                            price = 0;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Removes the currently worn headgear slot.";
                        };
                        class remove_goggles {
                            className = "NONE";
                            itemType = "goggles";
                            displayName = "Remove Glasses";
                            price = 0;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Removes the currently worn glasses slot.";
                        };
                        class remove_vest {
                            className = "NONE";
                            itemType = "vest";
                            displayName = "Remove Vest";
                            price = 0;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Removes the currently worn vest slot.";
                        };
                        class remove_backpack {
                            className = "NONE";
                            itemType = "backpack";
                            displayName = "Remove Backpack";
                            price = 0;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Removes the currently worn backpack slot.";
                        };
                        class AG_KCSO_Cadet_Uni {
                            className = "AG_KCSO_Cadet_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Cadet Patrol Uniform";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Cadet Uniform";
                        };
                        class AG_KCSO_Short_Cadet_Uni {
                            className = "AG_KCSO_Short_Cadet_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Cadet Patrol Uniform Short Sleeve";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Cadet Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Cadet_Uni {
                            className = "AG_KCSO_Long_Cadet_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Cadet Patrol Uniform Long Sleeve";
                            price = 350;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Cadet Uniform Long Sleeve";
                        };
                        class AG_KCSO_PTrooper_Uni {
                            className = "AG_KCSO_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Probationary Deputy Uniform";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Probationary Deputy Uniform";
                        };
                        class AG_KCSO_Short_PTrooper_Uni {
                            className = "AG_KCSO_Short_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Probationary Deputy Uniform Short Sleeve";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Probationary Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_PTrooper_Uni {
                            className = "AG_KCSO_Long_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Probationary Deputy Uniform Long Sleeve";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Probationary Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_Trooper_Uni {
                            className = "AG_KCSO_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Deputy Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Deputy Uniform";
                        };
                        class AG_KCSO_Short_Trooper_Uni {
                            className = "AG_KCSO_Short_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Deputy Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Trooper_Uni {
                            className = "AG_KCSO_Long_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Deputy Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_SnrTrooper_Uni {
                            className = "AG_KCSO_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Senior Deputy Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Senior Deputy Uniform";
                        };
                        class AG_KCSO_Short_SnrTrooper_Uni {
                            className = "AG_KCSO_Short_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Senior Deputy Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Senior Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_SnrTrooper_Uni {
                            className = "AG_KCSO_Long_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Senior Deputy Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Senior Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_Short_Corporal_Uni {
                            className = "AG_KCSO_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Corporal Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Corporal Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Corporal_Uni {
                            className = "AG_KCSO_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Corporal Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Corporal Uniform Long Sleeve";
                        };
                        class AG_KCSO_Corporal_Uni {
                            className = "AG_KCSO_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Corporal Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Corporal Uniform";
                        };
                        class AG_KCSO_Sergeant_Uni {
                            className = "AG_KCSO_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant Uniform";
                        };
                        class AG_KCSO_Short_Sergeant_Uni {
                            className = "AG_KCSO_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Sergeant_Uni {
                            className = "AG_KCSO_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant Uniform Long Sleeve";
                        };
                        class AG_KCSO_Sergeant_White_Uni {
                            className = "AG_KCSO_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol White Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant White Uniform";
                        };
                        class AG_KCSO_Short_Sergeant_White_Uni {
                            className = "AG_KCSO_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol White Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant White Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Sergeant_White_Uni {
                            className = "AG_KCSO_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sergeant Patrol White Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sergeant White Uniform Long Sleeve";
                        };
                        class AG_KCSO_Lieutenant_Uni {
                            className = "AG_KCSO_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform";
                        };
                        class AG_KCSO_Short_Lieutenant_Uni {
                            className = "AG_KCSO_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Lieutenant_Uni {
                            className = "AG_KCSO_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform Long Sleeve";
                        };
                        class AG_KCSO_Lieutenant_White_Uni {
                            className = "AG_KCSO_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform White";
                        };
                        class AG_KCSO_Short_Lieutenant_White_Uni {
                            className = "AG_KCSO_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Lieutenant_White_Uni {
                            className = "AG_KCSO_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Lieutenant Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Lieutenant Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Captain_Uni {
                            className = "AG_KCSO_Captain_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform";
                        };
                        class AG_KCSO_Short_Captain_Uni {
                            className = "AG_KCSO_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Captain_Uni {
                            className = "AG_KCSO_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform Long Sleeve";
                        };
                        class AG_KCSO_Captain_White_Uni {
                            className = "AG_KCSO_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform White";
                        };
                        class AG_KCSO_Short_Captain_White_Uni {
                            className = "AG_KCSO_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Captain_White_Uni {
                            className = "AG_KCSO_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Captain Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Captain Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Major_Uni {
                            className = "AG_KCSO_Major_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform";
                        };
                        class AG_KCSO_Short_Major_Uni {
                            className = "AG_KCSO_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Major_Uni {
                            className = "AG_KCSO_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform Long Sleeve";
                        };
                        class AG_KCSO_Major_White_Uni {
                            className = "AG_KCSO_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform White";
                        };
                        class AG_KCSO_Short_Major_White_Uni {
                            className = "AG_KCSO_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Major_White_Uni {
                            className = "AG_KCSO_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Major Uniform White Long Sleeve";
                        };
                        class AG_KCSO_LtCol_Uni {
                            className = "AG_KCSO_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol Uniform";
                        };
                        class AG_KCSO_Short_LtCol_Uni {
                            className = "AG_KCSO_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_LtCol_Uni {
                            className = "AG_KCSO_Long_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol Uniform Long Sleeve";
                        };
                        class AG_KCSO_LtCol_White_Uni {
                            className = "AG_KCSO_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol White";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol White";
                        };
                        class AG_KCSO_Short_LtCol_White_Uni {
                            className = "AG_KCSO_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol White Short Sleeve";
                        };
                        class AG_KCSO_Long_LtCol_White_Uni {
                            className = "AG_KCSO_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Patrol White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Undersheriff Patrol White Long Sleeve";
                        };
                        class AG_KCSO_Col_Uni {
                            className = "AG_KCSO_Col_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform";
                        };
                        class AG_KCSO_Short_Col_Uni {
                            className = "AG_KCSO_Short_Col_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Col_Uni {
                            className = "AG_KCSO_Long_Col_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform Long Sleeve";
                        };
                        class AG_KCSO_Col_White_Uni {
                            className = "AG_KCSO_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform White";
                        };
                        class AG_KCSO_Short_Col_White_Uni {
                            className = "AG_KCSO_Short_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Col_White_Uni {
                            className = "AG_KCSO_Long_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Long_Col_White_Uni {
                            className = "AG_KCSO_Long_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Sheriff Patrol Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Comm_Uni {
                            className = "AG_KCSO_Comm_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform";
                        };
                        class AG_KCSO_Short_Comm_Uni {
                            className = "AG_KCSO_Short_Comm_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Comm_Uni {
                            className = "AG_KCSO_Long_Comm_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Comm_Uni {
                            className = "AG_KCSO_Long_Comm_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform Short Sleeve";
                        };
                        class AG_KCSO_Comm_White_Uni {
                            className = "AG_KCSO_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform White";
                        };
                        class AG_KCSO_Short_Comm_White_Uni {
                            className = "AG_KCSO_Short_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Comm_White_Uni {
                            className = "AG_KCSO_Long_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {"patrol"};
                            rolePermissions[] = {};
                            text = "Standard issued TCSD Commissioner Uniform Long Sleeve";
                        };
                        class AG_KCSO_Beret {
                            className = "AG_KCSO_Beret";
                            itemType = "headgear";
                            displayName = "TCSD Beret";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard TCSD Beret";
                        };
                        class AG_KCSO_CampaignHat {
                            className = "AG_KCSO_CampaignHat";
                            itemType = "headgear";
                            displayName = "TCSD Patrol Campaign Hat";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard Issue Campaign Hat";
                        };
                        class AG_KCSO_PatchCap {
                            className = "AG_KCSO_PatchCap";
                            itemType = "headgear";
                            displayName = "TCSD Patrol Patch Cap";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard Issue Patch Cap";
                        };
                        class AG_KCSO_PatchCap_Alt {
                            className = "AG_KCSO_PatchCap_Alt";
                            itemType = "headgear";
                            displayName = "TCSD Patrol Patch Cap Alt";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard Issue Patch Cap Alt";
                        };
                        class AG_Patrol_Belt_KCSO {
                            className = "AG_Patrol_Belt_KCSO";
                            itemType = "vest";
                            displayName = "TCSD Patrol Belt";
                            price = 20;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard duty belt for patrol equipment.";
                        };
                        class AG_KCSO_CPC_Vest_Green {
                            className = "AG_KCSO_CPC_Vest_Green";
                            itemType = "vest";
                            displayName = "TCSD CPC Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard duty belt for patrol equipment.";
                        };
                        class AG_JPC_Vest_KCSO_Green {
                            className = "AG_JPC_Vest_KCSO_Green";
                            itemType = "vest";
                            displayName = "TCSD JPC Tactical Vest";
                            price = 1000;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Authorized tactical vest for deputies and above.";
                        };
                        class AG_KCSO_PatrolVest_Green {
                            className = "AG_KCSO_PatrolVest_Green";
                            itemType = "vest";
                            displayName = "TCSD LBT Vest";
                            price = 1000;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Authorized tactical vest for senior deputies and above.";
                        };
                        class AG_MMAC_Vest_KCSO_Green {
                            className = "AG_MMAC_Vest_KCSO_Green";
                            itemType = "vest";
                            displayName = "TCSD MMAC Patrol Vest";
                            price = 1000;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Authorized Tactical Vest for Corporals and Above.";
                        };
                        class AG_KCSO_Plate {
                            className = "AG_KCSO_Plate";
                            itemType = "vest";
                            displayName = "TCSD Plate Carrier";
                            price = 500;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard Issue Plate Carrier for Patrol Operations.";
                        };
                        class AG_FactionInvPack {
                            className = "AG_FactionInvPack";
                            itemType = "backpack";
                            displayName = "Faction Backpack";
                            price = 700;
                            condition = "";
                            rank = "";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Large patrol pack for issued field equipment.";
                        };
                    };
                };

                class academy {
                    title = "Training Academy";
                    description = "Academy clothing and FTO-issued gear.";

                    class Items {
                        class AG_AdminServices_PDeputy_Uni {
                            className = "AG_AdminServices_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Probationary Deputy Uniform";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Short_PDeputy_Uni {
                            className = "AG_AdminServices_Short_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Probationary Deputy Uniform Short Sleeve";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued short sleeve uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Long_PDeputy_Uni {
                            className = "AG_AdminServices_Long_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Probationary Deputy Uniform Long Sleeve";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued long sleeve uniform for probationary deputies in training.";
                        };
                        class AG_AdminService_PDeputy_Sweater {
                            className = "AG_AdminService_PDeputy_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Probationary Deputy Sweater Uniform";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued sweater uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Deputy_Uni {
                            className = "AG_AdminServices_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Deputy Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued uniform for qualified FTOs.";
                        };
                        class AG_AdminServices_Short_Deputy_Uni {
                            className = "AG_AdminServices_Short_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Deputy Short Sleeve Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued short sleeve uniform for qualified FTOs.";
                        };
                        class AG_AdminServices_Long_Deputy_Uni {
                            className = "AG_AdminServices_Long_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Deputy Long Sleeve Uniform";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified FTOs.";
                        };
                        class AG_AdminService_Deputy_Sweater {
                            className = "AG_AdminService_Deputy_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Deputy Sweater Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued sweater uniform for qualified FTOs.";
                        };
                        class AG_AdminServices_SnrDeputy_Uni {
                            className = "AG_AdminServices_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Senior Deputy FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Senior Deputy FTOs.";
                        };
                        class AG_AdminServices_Short_SnrDeputy_Uni {
                            className = "AG_AdminServices_Short_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Senior Deputy FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Senior Deputy FTOs.";
                        };
                        class AG_AdminServices_Long_SnrDeputy_Uni {
                            className = "AG_AdminServices_Long_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Academy Senior Deputy FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Senior Deputy FTOs.";
                        };
                        class AG_AdminServices_Corporal_Uni {
                            className = "AG_AdminServices_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Academy Corporal FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Corporal FTOs.";
                        };
                        class AG_AdminServices_Short_Corporal_Uni {
                            className = "AG_AdminServices_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Academy Corporal FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Corporal FTOs.";
                        };
                        class AG_AdminServices_Long_Corporal_Uni {
                            className = "AG_AdminServices_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Academy Corporal FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Corporal FTOs.";
                        };
                        class AG_AdminService_Corporal_Sweater {
                            className = "AG_AdminService_Corporal_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Corporal FTO Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued sweater uniform for qualified Corporal FTOs.";
                        };
                        class AG_AdminServices_Sergeant_White_Uni {
                            className = "AG_AdminServices_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Sergeant_White_Uni {
                            className = "AG_AdminServices_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Short_Sergeant_White_Uni {
                            className = "AG_AdminServices_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white short sleeve uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Long_Sergeant_White_Uni {
                            className = "AG_AdminServices_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white long sleeve uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Short_Sergeant_Uni {
                            className = "AG_AdminServices_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Long_Sergeant_Uni {
                            className = "AG_AdminServices_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminService_Sergeant_Sweater {
                            className = "AG_AdminService_Sergeant_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Sergeant FTO Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued sweater uniform for qualified Sergeant FTOs.";
                        };
                        class AG_AdminServices_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Short_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white short sleeve uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Long_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white long sleeve uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Lieutenant_Uni {
                            className = "AG_AdminServices_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Lieutenant_Uni {
                            className = "AG_AdminServices_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Short_Lieutenant_Uni {
                            className = "AG_AdminServices_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Long_Lieutenant_Uni {
                            className = "AG_AdminServices_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminService_Lieutenant_Sweater {
                            className = "AG_AdminService_Lieutenant_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Lieutenant FTO Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued sweater uniform for qualified Lieutenant FTOs.";
                        };
                        class AG_AdminServices_Captain_Uni {
                            className = "AG_AdminServices_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Short_Captain_Uni {
                            className = "AG_AdminServices_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Long_Captain_Uni {
                            className = "AG_AdminServices_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminService_Captain_Sweater {
                            className = "AG_AdminService_Captain_Sweater";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued sweater uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Captain_White_Uni {
                            className = "AG_AdminServices_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Short_Captain_White_Uni {
                            className = "AG_AdminServices_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white short sleeve uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Long_Captain_White_Uni {
                            className = "AG_AdminServices_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Captain FTO White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white long sleeve uniform for qualified Captain FTOs.";
                        };
                        class AG_AdminServices_Major_Uni {
                            className = "AG_AdminServices_Major_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Short_Major_Uni {
                            className = "AG_AdminServices_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Long_Major_Uni {
                            className = "AG_AdminServices_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Long_Major_Uni {
                            className = "AG_AdminServices_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued long sleeve uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Major_White_Uni {
                            className = "AG_AdminServices_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Short_Major_White_Uni {
                            className = "AG_AdminServices_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white short sleeve uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_Long_Major_White_Uni {
                            className = "AG_AdminServices_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Major FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white long sleeve uniform for qualified Major FTOs.";
                        };
                        class AG_AdminServices_LtCol_Uni {
                            className = "AG_AdminServices_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_Short_LtCol_Uni {
                            className = "AG_AdminServices_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_Short_LtCol_Uni {
                            className = "AG_AdminServices_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued short sleeve uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_LtCol_White_Uni {
                            className = "AG_AdminServices_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_Short_LtCol_White_Uni {
                            className = "AG_AdminServices_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white short sleeve uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_Long_LtCol_White_Uni {
                            className = "AG_AdminServices_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Academy Undersheriff FTO White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued white long sleeve uniform for qualified Undersheriff FTOs.";
                        };
                        class AG_AdminServices_Plate {
                            className = "AG_AdminServices_Plate";
                            itemType = "vest";
                            displayName = "Academy FTO Plate Carrier";
                            price = 55;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {"leo.training.fto"};
                            text = "Academy issued plate carrier for qualified FTOs.";
                        };
                        class AG_AdminServices_PatchCap {
                            className = "AG_AdminServices_PatchCap";
                            itemType = "headgear";
                            displayName = "Academy FTO Patch Cap";
                            price = 10;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued patch cap for qualified FTOs.";
                        };
                        class AG_JPC_Vest_Admin {
                            className = "AG_JPC_Vest_Admin";
                            itemType = "uniform";
                            displayName = "Academy FTO JPC Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued JPC vest for qualified FTOs.";
                        };
                        class AG_AdminServices_CPC_Vest {
                            className = "AG_AdminServices_CPC_Vest";
                            itemType = "vest";
                            displayName = "Academy FTO CPC Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued CPC vest for qualified FTOs.";
                        };
                        class AG_AdminServices_PatrolVest {
                            className = "AG_AdminServices_PatrolVest";
                            itemType = "vest";
                            displayName = "Academy FTO Patrol Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued patrol vest for qualified FTOs.";
                        };
                        class AG_MMAC_Vest_Admin {
                            className = "AG_MMAC_Vest_Admin";
                            itemType = "vest";
                            displayName = "Academy FTO MMAC Vest";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued MMAC vest for qualified FTOs.";
                        };
                        class AG_AdminServices_VestCombo {
                            className = "AG_AdminServices_VestCombo";
                            itemType = "vest";
                            displayName = "Academy FTO Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued vest combo for qualified FTOs.";
                        };
                        class AG_AdminServices_VestCombo2 {
                            className = "AG_AdminServices_VestCombo2";
                            itemType = "vest";
                            displayName = "Academy FTO Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued vest combo for qualified FTOs.";
                        };
                        class AG_AdminServices_VestCombo3 {
                            className = "AG_AdminServices_VestCombo3";
                            itemType = "vest";
                            displayName = "Academy FTO Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued vest combo for qualified FTOs.";
                        };
                        class AG_AdminServices_VestCombo3 {
                            className = "AG_AdminServices_VestCombo3";
                            itemType = "vest";
                            displayName = "Academy FTO Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "academy" };
                            rolePermissions[] = { "leo.training.fto" };
                            text = "Academy issued vest combo for qualified FTOs.";
                        };
                        class AG_AdminServices_Beret {
                            className = "AG_AdminServices_Beret";
                            itemType = "headgear";
                            displayName = "Academy FTO Beret";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued beret for qualified FTOs.";
                        };
                        class AG_AdminServices_CampaignHat {
                            className = "AG_AdminServices_CampaignHat";
                            itemType = "headgear";
                            displayName = "Academy FTO Campaign Hat";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued campaign hat for qualified FTOs.";
                        };
                        class AG_AdminServices_CampaignHat {
                            className = "AG_AdminServices_CampaignHat";
                            itemType = "headgear";
                            displayName = "Academy FTO Campaign Hat";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued campaign hat for qualified FTOs.";
                        };
                        class AG_AdminServices_PatchCap_Back {
                            className = "AG_AdminServices_PatchCap_Back";
                            itemType = "headgear";
                            displayName = "Academy FTO Patch Cap (Back)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued patch cap for qualified FTOs.";
                        };
                        class AG_AdminServices_PatchCapAlt {
                            className = "AG_AdminServices_PatchCapAlt";
                            itemType = "headgear";
                            displayName = "Academy FTO Patch Cap (Alt)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued patch cap for qualified FTOs.";
                        };
                        class AG_AdminServices_PatchCapAlt_Back {
                            className = "AG_AdminServices_PatchCapAlt_Back";
                            itemType = "headgear";
                            displayName = "Academy FTO Patch Cap (Alt Back)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"academy"};
                            rolePermissions[] = {};
                            text = "Academy issued patch cap for qualified FTOs.";
                        };
                    };
                };

                class hse {
                    title = "TCSD Speed Enforcement";
                    description = "Speed Enforcement clothing and equipment for TCSD deputies.";

                    class Items {
                        class AG_FactionInvPack {
                            className = "AG_FactionInvPack";
                            itemType = "backpack";
                            displayName = "TCSD Faction Inventory Pack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Faction inventory pack for TCSD deputies.";
                        };
                        class AG_HSU_Biker_Uni {
                            className = "AG_HSU_Biker_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Biker Uniform";
                            price = 100;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement motor unit uniform";
                        };
                        class AG_HSU_Trooper_Uni {
                            className = "AG_HSU_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "HSE Deputy Uniform";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD deputies.";
                        };
                        class AG_HSU_Short_Trooper_Uni {
                            className = "AG_HSU_Short_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "HSE Deputy Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD deputies.";
                        };
                        class AG_HSU_SnrTrooper_Uni {
                            className = "AG_HSU_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSE Senior Deputy Uniform";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD senior deputies.";
                        };
                        class AG_HSU_Short_SnrTrooper_Uni {
                            className = "AG_HSU_Short_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSE Senior Deputy Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD senior deputies.";
                        };
                        class AG_HSU_Long_SnrTrooper_Uni {
                            className = "AG_HSU_Long_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSE Senior Deputy Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD senior deputies.";
                        };
                        class AG_HSU_Corporal_Uni {
                            className = "AG_HSU_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSE Corporal Uniform";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD corporals.";
                        };
                        class AG_HSU_Short_Corporal_Uni {
                            className = "AG_HSU_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSE Corporal Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD corporals.";
                        };
                        class AG_HSU_Long_Corporal_Uni {
                            className = "AG_HSU_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSE Corporal Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD corporals.";
                        };
                        class AG_HSU_Sergeant_Uni {
                            className = "AG_HSU_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant Uniform";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Short_Sergeant_Uni {
                            className = "AG_HSU_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Long_Sergeant_Uni {
                            className = "AG_HSU_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement Long Sleeve uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Sergeant_White_Uni {
                            className = "AG_HSU_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant White Uniform";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Short_Sergeant_White_Uni {
                            className = "AG_HSU_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Long_Sergeant_White_Uni {
                            className = "AG_HSU_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Long_Sergeant_White_Uni {
                            className = "AG_HSU_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sergeant White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD sergeants.";
                        };
                        class AG_HSU_Lieutenant_Uni {
                            className = "AG_HSU_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant Uniform";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Short_Lieutenant_Uni {
                            className = "AG_HSU_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Long_Lieutenant_Uni {
                            className = "AG_HSU_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Lieutenant_White_Uni {
                            className = "AG_HSU_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant White Uniform";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Short_Lieutenant_White_Uni {
                            className = "AG_HSU_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Long_Lieutenant_White_Uni {
                            className = "AG_HSU_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Lieutenant White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD lieutenants.";
                        };
                        class AG_HSU_Captain_Uni {
                            className = "AG_HSU_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain Uniform";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD captains.";
                        };
                        class AG_HSU_Short_Captain_Uni {
                            className = "AG_HSU_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD captains.";
                        };
                        class AG_HSU_Long_Captain_Uni {
                            className = "AG_HSU_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD captains.";
                        };
                        class AG_HSU_Captain_White_Uni {
                            className = "AG_HSU_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain White Uniform";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD captains.";
                        };
                        class AG_HSU_Short_Captain_White_Uni {
                            className = "AG_HSU_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD captains.";
                        };
                        class AG_HSU_Long_Captain_White_Uni {
                            className = "AG_HSU_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Captain White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD captains.";
                        };
                        class AG_HSU_Major_Uni {
                            className = "AG_HSU_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major Uniform";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD majors.";
                        };
                        class AG_HSU_Short_Major_Uni {
                            className = "AG_HSU_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD majors.";
                        };
                        class AG_HSU_Long_Major_Uni {
                            className = "AG_HSU_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD majors.";
                        };
                        class AG_HSU_Major_White_Uni {
                            className = "AG_HSU_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major White Uniform";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD majors.";
                        };
                        class AG_HSU_Short_Major_White_Uni {
                            className = "AG_HSU_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD majors.";
                        };
                        class AG_HSU_Long_Major_White_Uni {
                            className = "AG_HSU_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Major White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD majors.";
                        };
                        class AG_HSU_LtCol_Uni {
                            className = "AG_HSU_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff Uniform";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_Short_LtCol_Uni {
                            className = "AG_HSU_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_Long_LtCol_Uni {
                            className = "AG_HSU_Long_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_LtCol_White_Uni {
                            className = "AG_HSU_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff White Uniform";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_Short_LtCol_White_Uni {
                            className = "AG_HSU_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_Long_LtCol_White_Uni {
                            className = "AG_HSU_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Undersheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD undersheriffs.";
                        };
                        class AG_HSU_Col_Uni {
                            className = "AG_HSU_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff Uniform";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_Short_Col_Uni {
                            className = "AG_HSU_Short_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement short sleeve uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_Long_Col_Uni {
                            className = "AG_HSU_Long_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement long sleeve uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_Col_White_Uni {
                            className = "AG_HSU_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff White Uniform";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_Short_Col_White_Uni {
                            className = "AG_HSU_Short_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white short sleeve uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_Long_Col_White_Uni {
                            className = "AG_HSU_Long_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSE Sheriff White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement white long sleeve uniform for TCSD sheriffs.";
                        };
                        class AG_HSU_PatchCap {
                            className = "AG_HSU_PatchCap";
                            itemType = "headgear";
                            displayName = "HSE Patch Cap";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement patch cap for TCSD deputies.";
                        };
                        class AG_HSU_PatchCap_Back {
                            className = "AG_HSU_PatchCap_Back";
                            itemType = "headgear";
                            displayName = "HSE Patch Cap (Back)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement patch cap with back logo for TCSD deputies.";
                        };
                        class AG_HSU_PatchCapAlt {
                            className = "AG_HSU_PatchCapAlt";
                            itemType = "headgear";
                            displayName = "HSE Patch Cap (Alt)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement patch cap with alternate logo for TCSD deputies.";
                        };
                        class AG_HSU_PatchCapAlt_Back {
                            className = "AG_HSU_PatchCapAlt_Back";
                            itemType = "headgear";
                            displayName = "HSE Patch Cap (Alt Back)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement patch cap with alternate logo and back logo for TCSD deputies.";
                        };
                        class AG_HSU_Beret {
                            className = "AG_HSU_Beret";
                            itemType = "headgear";
                            displayName = "HSE Beret";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement beret for TCSD corporals and above.";
                        };
                        class AG_HSU_Biker_Uni {
                            className = "AG_HSU_Biker_Uni";
                            itemType = "headgear";
                            displayName = "HSE Biker Helmet";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement biker helmet for TCSD corporals and above.";
                        };
                        class AG_HSU_CampaignHat {
                            className = "AG_HSU_CampaignHat";
                            itemType = "headgear";
                            displayName = "HSE Campaign Hat";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement campaign hat for TCSD deputies.";
                        };
                        class AG_HSU_CampaignHat {
                            className = "AG_HSU_CampaignHat";
                            itemType = "headgear";
                            displayName = "HSE Campaign Hat";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement campaign hat for TCSD deputies.";
                        };
                        class AG_HSU_Plate {
                            className = "AG_HSU_Plate";
                            itemType = "vest";
                            displayName = "HSE Tactical Vest";
                            price = 150;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement tactical vest for TCSD deputies.";
                        };
                        class AG_JPC_Vest_HSU {
                            className = "AG_JPC_Vest_HSU";
                            itemType = "vest";
                            displayName = "HSE JPC Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement JPC tactical vest for TCSD senior deputies and above.";
                        };
                        class AG_HSU_PatrolVest {
                            className = "AG_HSU_PatrolVest";
                            itemType = "vest";
                            displayName = "HSE Patrol Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement patrol tactical vest";
                        };
                        class AG_MMAC_Vest_HSU {
                            className = "AG_MMAC_Vest_HSU";
                            itemType = "vest";
                            displayName = "HSE MMAC Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement MMAC tactical vest for TCSD senior deputies and above.";
                        };
                        class AG_HSU_VestCombo {
                            className = "AG_HSU_VestCombo";
                            itemType = "vest";
                            displayName = "HSE Vest Combo";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement vest combo for TCSD deputies.";
                        };
                        class AG_HSU_VestCombo2 {
                            className = "AG_HSU_VestCombo2";
                            itemType = "vest";
                            displayName = "HSE Vest Combo 2";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement vest combo 2 for TCSD deputies.";
                        };
                        class AG_HSU_VestCombo3 {
                            className = "AG_HSU_VestCombo3";
                            itemType = "vest";
                            displayName = "HSE Vest Combo 3";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hse"};
                            rolePermissions[] = {"leo.vehicle.hse"};
                            text = "Traffic enforcement vest combo 3 for TCSD deputies.";
                        };
                    };
                };

                class ert {
                    title = "Emergency Response";
                    description = "ERT tactical clothing and heavy equipment.";

                    class Items {
                        class AG_SWAT_Uni_short_AAF {
                            className = "AG_SWAT_Uni_short_AAF";
                            itemType = "uniform";
                            displayName = "ERT Short Sleeve Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT short sleeve uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Uni_short_AAF {
                            className = "AG_SWAT_Uni_short_AAF";
                            itemType = "uniform";
                            displayName = "ERT Short Sleeve Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT short sleeve uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Uni_Tshirt_Alt {
                            className = "AG_SWAT_Uni_Tshirt_Alt";
                            itemType = "uniform";
                            displayName = "ERT T Shirt Alt Uniform";
                            price = 450;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT t-shirt uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Combat_Uni {
                            className = "AG_SWAT_Combat_Uni";
                            itemType = "uniform";
                            displayName = "ERT Combat Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT combat uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Trooper_Uni {
                            className = "AG_SWAT_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "ERT Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_SnrTrooper_Uni {
                            className = "AG_SWAT_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "ERT Senior Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT senior tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Corporal_Uni {
                            className = "AG_SWAT_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "ERT Corporal Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT corporal tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Sergeant_Uni {
                            className = "AG_SWAT_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "ERT Sergeant Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT sergeant tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Lieutenant_Uni {
                            className = "AG_SWAT_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "ERT Lieutenant Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT lieutenant tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Captain_Uni {
                            className = "AG_SWAT_Captain_Uni";
                            itemType = "uniform";
                            displayName = "ERT Captain Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT captain tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Beret {
                            className = "AG_SWAT_Beret";
                            itemType = "headgear";
                            displayName = "ERT Beret";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT beret for approved tactical deployments.";
                        };
                        class AG_SWAT_Cap2 {
                            className = "AG_SWAT_Cap2";
                            itemType = "headgear";
                            displayName = "ERT Cap";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT cap for approved tactical deployments.";
                        };
                        class AG_SWAT_PatchCap {
                            className = "AG_SWAT_PatchCap";
                            itemType = "headgear";
                            displayName = "ERT Patch Cap";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT patch cap for approved tactical deployments.";
                        };
                        class AG_SWAT_Helmet {
                            className = "AG_SWAT_Helmet";
                            itemType = "headgear";
                            displayName = "ERT Helmet";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT helmet for approved tactical deployments.";
                        };
                        class AG_SWAT_LightCarrier {
                            className = "AG_SWAT_LightCarrier";
                            itemType = "vest";
                            displayName = "ERT Plate Carrier";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT plate carrier for approved tactical deployments.";
                        };
                        class AG_SWAT_PatrolVest {
                            className = "AG_SWAT_PatrolVest";
                            itemType = "vest";
                            displayName = "ERT Plate Carrier";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT plate carrier for approved tactical deployments.";
                        };
                        class AG_MMAC_Vest_SWAT {
                            className = "AG_MMAC_Vest_SWAT";
                            itemType = "vest";
                            displayName = "ERT MMAC Vest";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT MMAC Vest for approved tactical deployments.";
                        };
                        class SWAT_VestCombo {
                            className = "SWAT_VestCombo";
                            itemType = "vest";
                            displayName = "ERT Vest Combo";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT vest combo for approved tactical deployments.";
                        };
                        class SWAT_VestCombo2 {
                            className = "SWAT_VestCombo2";
                            itemType = "vest";
                            displayName = "ERT Vest Combo 2";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT vest combo 2 for approved tactical deployments.";
                        };
                        class AG_SWAT_HeavyCarrier {
                            className = "AG_SWAT_HeavyCarrier";
                            itemType = "vest";
                            displayName = "ERT Heavy Carrier";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT heavy carrier for approved tactical deployments.";
                        };
                        class AG_FactionInvPack {
                            className = "AG_FactionInvPack";
                            itemType = "backpack";
                            displayName = "TCSD Backpack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "TCSD Backpack";
                        };
                        class AG_SWAT_Assault_Backpack {
                            className = "AG_SWAT_Assault_Backpack";
                            itemType = "backpack";
                            displayName = "ERT Assault Backpack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"ert"};
                            rolePermissions[] = {"leo.tactical.ert"};
                            text = "ERT assault backpack for approved tactical deployments.";
                        };
                    };
                };

                class investigations {
                    title = "Investigations";
                    description = "Plainclothes and investigative subdivision clothing.";

                    class Items {
                        class AG_CID_Trooper_Uni {
                            className = "AG_CID_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "CID Detective Uniform";
                            price = 5000;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID detective uniform for criminal investigations.";
                        };
                        class AG_CID_SnrTrooper_Uni {
                            className = "AG_CID_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "CID Senior Detective Uniform";
                            price = 5000;
                            condition = "";
                            rank = "senior_detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID senior detective uniform for criminal investigations.";
                        };
                        class AG_CID_Corporal_Uni {
                            className = "AG_CID_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "CID Corporal Detective Uniform";
                            price = 5000;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID corporal uniform for criminal investigations";
                        };
                        class AG_CID_Sergeant_Uni {
                            className = "AG_CID_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "CID Sergeant Uniform";
                            price = 5000;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID sergeant uniform for criminal investigations";
                        };
                        class AG_IA_Uni {
                            className = "AG_IA_Uni";
                            itemType = "uniform";
                            displayName = "Internal Affairs Investigator Uniform";
                            price = 3000;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"ia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs investigator uniform for internal investigations.";
                        };
                        class AG_JPC_Vest_CID {
                            className = "AG_JPC_Vest_CID";
                            itemType = "vest";
                            displayName = "CID Tactical Vest";
                            price = 800;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {};
                            text = "CID tactical vest for investigative operations.";
                        };
                        class AG_JPC_Vest_IA {
                            className = "AG_JPC_Vest_IA";
                            itemType = "vest";
                            displayName = "Internal Affairs Tactical Vest";
                            price = 800;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"ia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs tactical vest for investigative operations.";
                        };
                        class AG_CID_LightCarrier {
                            className = "AG_CID_LightCarrier";
                            itemType = "vest";
                            displayName = "";
                            price = 800;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {""};
                            text = "CID Light Plate Carrier for criminal investigations";
                        };
                        class AG_CID_Tiger_Vest {
                            className = "AG_CID_Tiger_Vest";
                            itemType = "vest";
                            displayName = "";
                            price = 800;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {""};
                            text = "CID Tiger Vest for criminal investigations";
                        };
                        class AG_CID_Beret {
                            className = "AG_CID_Beret";
                            itemType = "headgear";
                            displayName = "CID Beret";
                            price = 100;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {};
                            text = "CID beret for investigative operations.";
                        };
                        class AG_CID_Beret_IA {
                            className = "AG_CID_Beret_IA";
                            itemType = "headgear";
                            displayName = "Internal Affairs Beret";
                            price = 100;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"ia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs beret for investigative operations.";
                        };
                        class AG_CID_PatchCap {
                            className = "AG_CID_PatchCap";
                            itemType = "headgear";
                            displayName = "CID Patch Cap";
                            price = 100;
                            condition = "";
                            rank = "detective";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {};
                            text = "CID Patch Cap for investigations";
                        };
                    };
                };

                class command {
                    title = "Command";
                    description = "Command staff clothing and supervisory equipment.";

                    class Items {
                        class AG_KCSO_Cmd_Major_Uni {
                            className = "AG_KCSO_Cmd_Major_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Major Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Major Uniform";
                        };
                        class AG_KCSO_Cmd_LtCol_Uni {
                            className = "AG_KCSO_Cmd_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Undersheriff Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Undersheriff Uniform";
                        };
                        class AG_KCSO_Cmd_Col_Uni {
                            className = "AG_KCSO_Cmd_Col_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Sheriff Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Sheriff Uniform";
                        };
                        class AG_KCSO_Cmd_Comm_Uni {
                            className = "AG_KCSO_Cmd_Comm_Uni";
                            itemType = "uniform";
                            displayName = "TCSD Commissioner Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Commissioner Uniform";
                        };
                        class AG_KCSO_CampaignHat_Cmd {
                            className = "AG_KCSO_CampaignHat_Cmd";
                            itemType = "headgear";
                            displayName = "TCSD Command Campaign Hat";
                            price = 250;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Campaign Hat";
                        };
                        class G_Squares_Tinted {
                            className = "G_Squares_Tinted";
                            itemType = "goggles";
                            displayName = "Tinted Glasses Non Standard Issue";
                            price = 100;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = { "leo.command.terminal" };
                            text = "Tinted Glasses";
                        };
                        class AG_KCSO_Cmd_Beret {
                            className = "AG_KCSO_Cmd_Beret";
                            itemType = "headgear";
                            displayName = "TCSD Command Beret";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = { "leo.command.terminal" };
                            text = "State Command Beret";
                        };
                        class AG_KCSOCmd_VestCombo {
                            className = "AG_KCSOCmd_VestCombo";
                            itemType = "vest";
                            displayName = "TCSD State Command Vest Combo";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Vest Combo";
                        };
                        class AG_KCSOCmd_VestCombo2 {
                            className = "AG_KCSOCmd_VestCombo2";
                            itemType = "vest";
                            displayName = "TCSD State Command Vest Combo 2";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Vest Combo 2";
                        };
                        class AG_KCSOCmd_VestCombo3 {
                            className = "AG_KCSOCmd_VestCombo3";
                            itemType = "vest";
                            displayName = "TCSD State Command Vest Combo 3";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "State Command Vest Combo 3";
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
                price = 7500;
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
