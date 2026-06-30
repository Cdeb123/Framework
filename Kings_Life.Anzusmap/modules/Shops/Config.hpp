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
            class kcso_armory {
                legacyShop = "cop_basic";
                title = "KCSO Armory";
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

            class usms_armory {
                legacyShop = "cop_basic";
                title = "USMS Armory";
                subtitle = "United States Marshal Service equipment";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.usms'] call life_fnc_hasPermission}";
                requiredLicense = "";
                requiredLicenseSide = "cop";

                class Categories {
                    class duty {
                        title = "Duty Essentials";
                        description = "Baseline federal field equipment.";

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
                                condition = "['deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Less-lethal distraction device.";
                            };
                        };
                    };

                    class sidearms {
                        title = "Sidearms";
                        description = "Authorized USMS duty pistols.";

                        class Items {
                            class RH_g17 {
                                className = "RH_g17";
                                nickname = "";
                                buyPrice = 7500;
                                sellPrice = 3750;
                                condition = "";
                                text = "Standard G17 duty sidearm.";
                            };
                            class RH_m9 {
                                className = "RH_m9";
                                nickname = "";
                                buyPrice = 4500;
                                sellPrice = 3500;
                                condition = "";
                                text = "Standard M9 sidearm.";
                            };
                            class RH_17Rnd_9x19_g17 {
                                className = "RH_17Rnd_9x19_g17";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 9mm G17 magazine.";
                            };
                            class RH_15Rnd_9x19_M9 {
                                className = "RH_15Rnd_9x19_M9";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 20;
                                condition = "";
                                text = "Standard 9mm M9 magazine.";
                            };
                            class RH_kimber_nw {
                                className = "RH_kimber_nw";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Authorized .45 sidearm for senior marshals and above.";
                            };
                            class RH_7Rnd_45cal_m1911 {
                                className = "RH_7Rnd_45cal_m1911";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP sidearm magazine.";
                            };
                        };
                    };

                    class long_guns {
                        title = "Long Guns";
                        description = "Federal rifle platforms by rank.";

                        class Items {
                            class hlc_rifle_RU5562 {
                                className = "hlc_rifle_RU5562";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 15000;
                                condition = "['deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "USMS patrol rifle.";
                            };
                            class SMA_AAC_MPW_12_Black {
                                className = "SMA_AAC_MPW_12_Black";
                                nickname = "";
                                buyPrice = 8500;
                                sellPrice = 7500;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Compact USMS rifle.";
                            };
                            class RH_Hk416c {
                                className = "RH_Hk416c";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 24500;
                                condition = "['supervisory_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Supervisory tactical rifle.";
                            };
                            class hlc_30rnd_556x45_SOST {
                                className = "hlc_30rnd_556x45_SOST";
                                nickname = "";
                                buyPrice = 100;
                                sellPrice = 95;
                                condition = "['deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "5.56 SOST rifle magazine.";
                            };
                            class hlc_30rnd_556x45_EPR {
                                className = "hlc_30rnd_556x45_EPR";
                                nickname = "";
                                buyPrice = 95;
                                sellPrice = 85;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "5.56 EPR rifle magazine.";
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
                                text = "Duty weapon light.";
                            };
                            class SMA_SFFL_BLK {
                                className = "SMA_SFFL_BLK";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Rifle flashlight.";
                            };
                            class RH_ta31rmr {
                                className = "RH_ta31rmr";
                                nickname = "ACOG RMR";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['senior_deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "ACOG TA31F RMR sight.";
                            };
                            class RH_compM2l {
                                className = "RH_compM2l";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['deputy_marshal','usms'] call life_fnc_leoAtLeastRank";
                                text = "Aimpoint red dot.";
                            };
                        };
                    };
                };
            };

            class dea_armory {
                legacyShop = "cop_basic";
                title = "DEA Armory";
                subtitle = "Drug Enforcement Administration equipment";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.dea'] call life_fnc_hasPermission}";
                requiredLicense = "";
                requiredLicenseSide = "cop";

                class Categories {
                    class duty {
                        title = "Duty Essentials";
                        description = "Federal narcotics enforcement equipment.";

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
                                condition = "['special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Less-lethal distraction device.";
                            };
                        };
                    };

                    class sidearms {
                        title = "Sidearms";
                        description = "Authorized DEA duty pistols.";

                        class Items {
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
                                text = "Compact G19 sidearm.";
                            };
                            class RH_17Rnd_9x19_g17 {
                                className = "RH_17Rnd_9x19_g17";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 9mm G17 magazine.";
                            };
                            class RH_kimber_nw {
                                className = "RH_kimber_nw";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Authorized .45 sidearm for senior agents and above.";
                            };
                            class RH_7Rnd_45cal_m1911 {
                                className = "RH_7Rnd_45cal_m1911";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP sidearm magazine.";
                            };
                        };
                    };

                    class long_guns {
                        title = "Long Guns";
                        description = "DEA rifle platforms by rank.";

                        class Items {
                            class hlc_rifle_RU5562 {
                                className = "hlc_rifle_RU5562";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 15000;
                                condition = "['special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "DEA field rifle.";
                            };
                            class SMA_AAC_MPW_12_Black {
                                className = "SMA_AAC_MPW_12_Black";
                                nickname = "";
                                buyPrice = 8500;
                                sellPrice = 7500;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Compact DEA rifle.";
                            };
                            class RH_Hk416c {
                                className = "RH_Hk416c";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 24500;
                                condition = "['supervisory_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Supervisory tactical rifle.";
                            };
                            class hlc_30rnd_556x45_SOST {
                                className = "hlc_30rnd_556x45_SOST";
                                nickname = "";
                                buyPrice = 100;
                                sellPrice = 95;
                                condition = "['special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "5.56 SOST rifle magazine.";
                            };
                            class hlc_30rnd_556x45_EPR {
                                className = "hlc_30rnd_556x45_EPR";
                                nickname = "";
                                buyPrice = 95;
                                sellPrice = 85;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "5.56 EPR rifle magazine.";
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
                                text = "Duty weapon light.";
                            };
                            class SMA_SFFL_BLK {
                                className = "SMA_SFFL_BLK";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Rifle flashlight.";
                            };
                            class RH_ta31rmr {
                                className = "RH_ta31rmr";
                                nickname = "ACOG RMR";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['senior_special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "ACOG TA31F RMR sight.";
                            };
                            class RH_compM2l {
                                className = "RH_compM2l";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['special_agent','dea'] call life_fnc_leoAtLeastRank";
                                text = "Aimpoint red dot.";
                            };
                        };
                    };
                };
            };

            class fbi_armory {
                legacyShop = "cop_basic";
                title = "FBI Armory";
                subtitle = "Federal Bureau of Investigation equipment";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.fbi'] call life_fnc_hasPermission}";
                requiredLicense = "";
                requiredLicenseSide = "cop";

                class Categories {
                    class duty {
                        title = "Duty Essentials";
                        description = "Federal investigation field equipment.";

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
                                condition = "['special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Less-lethal distraction device.";
                            };
                        };
                    };

                    class sidearms {
                        title = "Sidearms";
                        description = "Authorized FBI duty pistols.";

                        class Items {
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
                                text = "Compact G19 sidearm.";
                            };
                            class RH_17Rnd_9x19_g17 {
                                className = "RH_17Rnd_9x19_g17";
                                nickname = "";
                                buyPrice = 125;
                                sellPrice = 60;
                                condition = "";
                                text = "Standard 9mm G17 magazine.";
                            };
                            class RH_kimber_nw {
                                className = "RH_kimber_nw";
                                nickname = "";
                                buyPrice = 9500;
                                sellPrice = 4750;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Authorized .45 sidearm for senior agents and above.";
                            };
                            class RH_7Rnd_45cal_m1911 {
                                className = "RH_7Rnd_45cal_m1911";
                                nickname = "";
                                buyPrice = 130;
                                sellPrice = 65;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = ".45 ACP sidearm magazine.";
                            };
                        };
                    };

                    class long_guns {
                        title = "Long Guns";
                        description = "FBI rifle platforms by rank.";

                        class Items {
                            class hlc_rifle_RU5562 {
                                className = "hlc_rifle_RU5562";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 15000;
                                condition = "['special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "FBI field rifle.";
                            };
                            class SMA_AAC_MPW_12_Black {
                                className = "SMA_AAC_MPW_12_Black";
                                nickname = "";
                                buyPrice = 8500;
                                sellPrice = 7500;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Compact FBI rifle.";
                            };
                            class RH_Hk416c {
                                className = "RH_Hk416c";
                                nickname = "";
                                buyPrice = 25000;
                                sellPrice = 24500;
                                condition = "['supervisory_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Supervisory tactical rifle.";
                            };
                            class hlc_30rnd_556x45_SOST {
                                className = "hlc_30rnd_556x45_SOST";
                                nickname = "";
                                buyPrice = 100;
                                sellPrice = 95;
                                condition = "['special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "5.56 SOST rifle magazine.";
                            };
                            class hlc_30rnd_556x45_EPR {
                                className = "hlc_30rnd_556x45_EPR";
                                nickname = "";
                                buyPrice = 95;
                                sellPrice = 85;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "5.56 EPR rifle magazine.";
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
                                text = "Duty weapon light.";
                            };
                            class SMA_SFFL_BLK {
                                className = "SMA_SFFL_BLK";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Rifle flashlight.";
                            };
                            class RH_ta31rmr {
                                className = "RH_ta31rmr";
                                nickname = "ACOG RMR";
                                buyPrice = 250;
                                sellPrice = 125;
                                condition = "['senior_special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "ACOG TA31F RMR sight.";
                            };
                            class RH_compM2l {
                                className = "RH_compM2l";
                                nickname = "";
                                buyPrice = 25;
                                sellPrice = 15;
                                condition = "['special_agent','fbi'] call life_fnc_leoAtLeastRank";
                                text = "Aimpoint red dot.";
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
                title = "Kings County Auto Gallery";
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
                title = "KCSO Motor Pool";
                subtitle = "Patrol and specialty ground vehicles";
                side = "cop";
                condition = "playerSide isEqualTo west";
                requiredCertification = "";
                department = "kcso";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class patrol {
                        title = "Patrol";
                        description = "Standard patrol-ready vehicles.";

                        class Vehicles {
                            class AG_CROWNVIC_Police_AG {
                                className = "AG_CROWNVIC_Police_AG";
                                displayName = "KCSO CVPI Patrol";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CROWNVIC_Police_ST_AG {
                                className = "AG_CROWNVIC_Police_ST_AG";
                                displayName = "KCSO CVPI Patrol Slicktop";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CTSV_Police_AG {
                                className = "AG_CTSV_Police_AG";
                                displayName = "KCSO Cadillac CTS-V Patrol";
                                price = 35000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {};
                                features[] = {"Fast Pursuit Response", "Low Maintenance", "Patrol Vehicle", "Prisoner Transport" };
                                text = "A Dependable Patrol Vehicle for Everyday Calls and Transport";
                            };
                            class AG_CHARGER_Police_AG {
                                className = "AG_CHARGER_Police_AG";
                                displayName = "KCSO Charger Patrol";
                                price = 25000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_CHARGER_Police_ST_AG {
                                className = "AG_CHARGER_Police_ST_AG";
                                displayName = "KCSO Charger Patrol Slicktop";
                                price = 24000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {};
                                features[] = {"Basic Patrol Vehicle","Low Maintenance","Prisoner Transport Qualified" };
                                text = "A dependable patrol vehicle for everyday calls and transport.";
                            };
                            class AG_Suburban16_Police_AG {
                                className = "AG_Suburban16_Police_AG";
                                displayName = "KCSO Suburban Patrol Utility";
                                price = 33000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            };
                            class AG_Suburban16_Police_ST_AG {
                                className = "AG_Suburban16_Police_ST_AG";
                                displayName = "KCSO Suburban Patrol Utility Slicktop";
                                price = 32000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            };
                            class AG_TAHOE08_Police_AG {
                                className = "AG_TAHOE08_Police_AG";
                                displayName = "KCSO Tahoe Patrol Utility";
                                price = 7500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for qualified corporals and above.";
                            };
                            class AG_TAHOE08_Police_ST_AG {
                                className = "AG_TAHOE08_Police_ST_AG";
                                displayName = "KCSO Tahoe Patrol Utility Slicktop";
                                price = 7500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Patrol Vehicle","Prisoner Transport","All Terrain Response" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_Silverado_19_Police_AG {
                                className = "AG_Silverado_19_Police_AG";
                                displayName = "KCSO Silverado Patrol Truck";
                                price = 75000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Silverado_19_Police_ST_AG {
                                className = "AG_Silverado_19_Police_ST_AG";
                                displayName = "KCSO Silverado Patrol Truck Slicktop";
                                price = 74000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Durango_Police_AG {
                                className = "AG_Durango_Police_AG";
                                displayName = "KCSO Durango Pursuit Vehicle Utility";
                                price = 85000;
                                condition = "";
                                rank = "captain";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Fast Response Vehicle","Supervisor Access","Prisoner Transport" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_Durango_Police_ST_AG {
                                className = "AG_Durango_Police_ST_AG";
                                displayName = "KCSO Durango Pursuit Vehicle Utility Slicktop";
                                price = 84000;
                                condition = "";
                                rank = "captain";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Fast Response Vehicle","Supervisor Access","Prisoner Transport" };
                                text = "A Utility Patrol Pickup Truck for Qualified Lieutenants and Above.";
                            };
                            class AG_EXPLORER_Police_AG {
                                className = "AG_EXPLORER_Police_AG";
                                displayName = "KCSO FPIU Patrol";
                                price = 15000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Prisoner Transport","Low Maintenance" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_EXPLORER_Police_ST_AG {
                                className = "AG_EXPLORER_Police_ST_AG";
                                displayName = "KCSO FPIU Patrol Slicktop";
                                price = 14000;
                                condition = "";
                                rank = "corporal";
                                subdivisions[] = {};
                                features[] = { "Utility Vehicle","Prisoner Transport","Low Maintenance" };
                                text = "A Utility Patrol Vehicle for Qualified Corporals and Above.";
                            };
                            class AG_Titan_Police_AG {
                                className = "AG_Titan_Police_AG";
                                displayName = "KCSO Titan Pickup Truck Utility";
                                price = 95000;
                                condition = "";
                                rank = "major";
                                subdivisions[] = {};
                                features[] = { "Pickup Truck","All Terrain Response","Supervisor Access","Utility Vehicle" };
                                text = "A Utility Patrol Pickup Truck for Qualified Majors and Above.";
                            };
                        };
                    };

                    class hsu {
                        title = "Speed Enforcement";
                        description = "Speed Enforcement Vehicles";

                        class Vehicles {
                            class AG_MustangGT15_HSU_AG {
                                className = "AG_MustangGT15_HSU_AG";
                                displayName = "KCSO HSU Mustang Pursuit Vehicle";
                                price = 5000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hsu"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT15_HSU_ST_AG {
                                className = "AG_MustangGT15_HSU_ST_AG";
                                displayName = "KCSO HSU Mustang Pursuit Vehicle Slicktop";
                                price = 5400;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hsu"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT500_HSU_AG {
                                className = "AG_MustangGT500_HSU_AG";
                                displayName = "KCSO HSU Mustang GT500";
                                price = 7500;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"hsu"};
                                features[] = {"Rapid Response Unit","Pursuit Vehicle","Pit Certified","High Risk Unit"};
                                text = "A Fast Pursuit Vehicle for Qualified Deputies";
                            };
                            class AG_MustangGT500_HSU_ST_AG {
                                className = "AG_MustangGT500_HSU_ST_AG";
                                displayName = "KCSO HSU Mustang GT500 Slicktop";
                                price = 7400;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"hsu"};
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
                                displayName = "KCSO CVPI Unmarked Unit";
                                price = 10000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"cid"};
                                features[] = {"Unmarked Unit","Covert Operations","Investigations Unit"};
                                text = "A Unmarked Patrol Car for Criminal Investigators";
                            };
                            class AG_CHARGER_SRT_UNM_AG {
                                className = "AG_CHARGER_SRT_UNM_AG";
                                displayName = "KCSO Charger SRT Unmarked Unit";
                                price = 15000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"cid"};
                                features[] = {"Unmarked Unit","Covert Operations","Investigations Unit","Rapid Response Unit"};
                                text = "A Unmarked Patrol Car for Criminal Investigators";
                            };
                        };
                    };

                    class admin_services {
                        title = "Admin Services Trainer Patrol Vehicles";
                        description = "Admin Services patrol cars for Admin Services trainers";

                        class Vehicles {
                           class AG_X5_AdminServices_AG {
                                className = "AG_X5_AdminServices_AG";
                                displayName = "KCSO Trainer X5 Patrol Car";
                                price = 25000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"admin_services"};
                                features[] = {"Admin Services Training Vehicle","Pursuit Training Vehicle","Rapid Response Unit"};
                                text = "A Training Vehicle for Deputies";
                            };
                            class AG_amgGT_19_AdminServices_AG {
                                className = "AG_amgGT_19_AdminServices_AG";
                                displayName = "KCSO Trainer AMG GT Patrol Car";
                                price = 35000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"admin_services"};
                                features[] = {"Admin Services Training Vehicle","Pursuit Training Vehicle","Rapid Response Unit"};
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
                                displayName = "Lenco Bearcat Kings County SWAT";
                                price = 5500;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {"swat"};
                                features[] = {"Armored response","Sergeant Access","High-risk transport"};
                                text = "Armored law enforcement platform for higher-risk operations.";
                            };
                            class AG_Suburban16_SWAT_AG {
                                className = "AG_Suburban16_SWAT_AG";
                                displayName = "KCSO SWAT Suburban Utility Vehicle";
                                price = 8500;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"swat"};
                                features[] = {"Armed armored response","Deputy Access","SWAT restricted"};
                                text = "Restricted tactical vehicle for authorized command and SWAT use.";
                            };
                            class AG_Cherokee_SWAT_AG {
                                className = "AG_Cherokee_SWAT_AG";
                                displayName = "KCSO SWAT Cherokee Utility Vehicle";
                                price = 10000;
                                condition = "";
                                rank = "senior_deputy";
                                subdivisions[] = {"swat"};
                                features[] = {"Armed armored response","Senior Deputy Access","SWAT restricted"};
                                text = "Restricted tactical vehicle for authorized command and SWAT use.";
                            };
                        };
                    };
                };
            };

            class cop_air {
                legacyShop = "cop_air";
                title = "KCSO Aviation";
                subtitle = "Aircraft requiring LEO Aviation certification";
                side = "cop";
                condition = "['sergeant'] call life_fnc_leoAtLeastRank";
                requiredCertification = "cAir";
                department = "kcso";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class rotary {
                        title = "Rotary Wing";
                        description = "Air support aircraft for certified pilots.";

                        class Vehicles {
                            class AG_Hummingbird_Police {
                                className = "AG_Hummingbird_Police";
                                displayName = "KCSO Hummingbird Patrol Helicopter";
                                price = 95000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = {"Certified aviation only","Fast patrol observation","Light transport"};
                                text = "Light Helicopter for Certified KCSO Aviation Operations.";
                            };
                            class AG_Hummingbird_Police_Adv {
                                className = "AG_Hummingbird_Police_Adv";
                                displayName = "KCSO Hummingbird Advanced Patrol Helicopter";
                                price = 96000;
                                condition = "";
                                rank = "lieutenant";
                                subdivisions[] = {};
                                features[] = { "Certified aviation only","Fast patrol observation","Light transport" };
                                text = "Light helicopter for certified KCSO aviation operations.";
                            };
                            class AG_Hummingbird_HSU {
                                className = "AG_Hummingbird_HSU";
                                displayName = "KCSO High Speed Enforcement Patrol Helicopter";
                                price = 98000;
                                condition = "";
                                rank = "deputy";
                                subdivisions[] = {"hsu"};
                                features[] = {"Speed Enforcement","Advanced Pilot","Pursuit Helicopter"};
                                text = "High Speed Pursuit Helicopter for Aviation Operations";
                            };
                            class AG_UH60M_Sheriff_AG {
                                className = "AG_UH60M_Sheriff_AG";
                                displayName = "KCSO UH60 Utility Helicopter";
                                price = 97000;
                                condition = "";
                                rank = "sergeant";
                                subdivisions[] = {};
                                features[] = {"Transport Helicopter","Advanced Pilot","Air Operations"};
                                text = "Heavy Police Helicopter for Transport";
                            };
                        };
                    };
                };
            };

            class cop_ship {
                legacyShop = "cop_ship";
                title = "KCSO Maritime";
                subtitle = "Marine units requiring LEO Maritime certification";
                side = "cop";
                condition = "playerSide isEqualTo west";
                requiredCertification = "cg";
                department = "kcso";
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
                                subdivisions[] = {"swat"};
                                features[] = {"Armed maritime platform","Sergeant access","SWAT restricted"};
                                text = "Restricted armed marine platform for approved operations.";
                            };
                            class sdv {
                                className = "B_SDV_01_F";
                                displayName = "SDV";
                                price = -1;
                                condition = "";
                                rank = "";
                                subdivisions[] = {"hsu"};
                                features[] = {"Submersible operations","HSU restricted","Low visibility movement"};
                                text = "Specialty submersible for maritime search and interdiction.";
                            };
                        };
                    };
                };
            };

            class usms_motor_pool {
                legacyShop = "cop_car";
                title = "USMS Motor Pool";
                subtitle = "United States Marshal Service ground vehicles";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.usms'] call life_fnc_hasPermission}";
                requiredCertification = "";
                department = "usms";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class field_operations {
                        title = "Field Operations";
                        description = "Unmarked service vehicles for routine federal operations.";

                        class Vehicles {
                            class AG_CROWNVIC_UNM_AG {
                                className = "AG_CROWNVIC_UNM_AG";
                                displayName = "USMS CVPI Unmarked";
                                price = 10000;
                                condition = "";
                                rank = "deputy_marshal";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Federal Operations","Transport"};
                                text = "Unmarked USMS service vehicle.";
                            };
                            class AG_CHARGER_SRT_UNM_AG {
                                className = "AG_CHARGER_SRT_UNM_AG";
                                displayName = "USMS Charger SRT Unmarked";
                                price = 15000;
                                condition = "";
                                rank = "deputy_marshal";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Rapid Response","Transport"};
                                text = "Unmarked USMS rapid response vehicle.";
                            };
                        };
                    };

                    class fugitive_task_force {
                        title = "Fugitive Task Force";
                        description = "Specialized transport and apprehension vehicles.";

                        class Vehicles {
                            class AG_Taurus_Unm_AG {
                                className = "AG_Taurus_Unm_AG";
                                displayName = "USMS Taurus Unmarked";
                                price = 18000;
                                condition = "";
                                rank = "senior_deputy_marshal";
                                subdivisions[] = {"fugitive_task_force"};
                                features[] = {"Fugitive Operations","Unmarked Unit","Covert Response"};
                                text = "Unmarked fugitive task force vehicle.";
                            };
                            class AG_Suburban16_Unm_AG {
                                className = "AG_Suburban16_Unm_AG";
                                displayName = "USMS Suburban Unmarked";
                                price = 30000;
                                condition = "";
                                rank = "senior_deputy_marshal";
                                subdivisions[] = {"fugitive_task_force"};
                                features[] = {"Team Transport","Federal Operations","Utility Vehicle"};
                                text = "USMS task force utility vehicle.";
                            };
                        };
                    };

                    class command {
                        title = "Command";
                        description = "Supervisor and command vehicles.";

                        class Vehicles {
                            class AG_Silverado_19_Unm_AG_TIER3 {
                                className = "AG_Silverado_19_Unm_AG_TIER3";
                                displayName = "USMS Silverado Command";
                                price = 74000;
                                condition = "";
                                rank = "supervisory_deputy_marshal";
                                subdivisions[] = {};
                                features[] = {"Command Vehicle","Utility Vehicle","Federal Operations"};
                                text = "USMS command utility vehicle.";
                            };
                        };
                    };
                };
            };

            class dea_motor_pool {
                legacyShop = "cop_car";
                title = "DEA Motor Pool";
                subtitle = "Drug Enforcement Administration ground vehicles";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.dea'] call life_fnc_hasPermission}";
                requiredCertification = "";
                department = "dea";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class field_operations {
                        title = "Field Operations";
                        description = "Unmarked vehicles for federal narcotics enforcement.";

                        class Vehicles {
                            class AG_CROWNVIC_UNM_AG {
                                className = "AG_CROWNVIC_UNM_AG";
                                displayName = "DEA CVPI Unmarked";
                                price = 10000;
                                condition = "";
                                rank = "special_agent";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Narcotics Enforcement","Surveillance"};
                                text = "Unmarked DEA field operations vehicle.";
                            };
                            class AG_CHARGER_SRT_UNM_AG {
                                className = "AG_CHARGER_SRT_UNM_AG";
                                displayName = "DEA Charger SRT Unmarked";
                                price = 15000;
                                condition = "";
                                rank = "special_agent";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Rapid Response","Surveillance"};
                                text = "Unmarked DEA rapid response vehicle.";
                            };
                        };
                    };

                    class narcotics_enforcement {
                        title = "Narcotics Enforcement";
                        description = "Specialized narcotics and diversion enforcement vehicles.";

                        class Vehicles {
                            class AG_Taurus_Unm_AG {
                                className = "AG_Taurus_Unm_AG";
                                displayName = "DEA Taurus Unmarked";
                                price = 18000;
                                condition = "";
                                rank = "senior_special_agent";
                                subdivisions[] = {"narcotics_enforcement"};
                                features[] = {"Narcotics Enforcement","Unmarked Unit","Covert Response"};
                                text = "Unmarked DEA narcotics enforcement vehicle.";
                            };
                            class AG_Suburban16_Unm_AG {
                                className = "AG_Suburban16_Unm_AG";
                                displayName = "DEA Suburban Unmarked";
                                price = 30000;
                                condition = "";
                                rank = "senior_special_agent";
                                subdivisions[] = {"narcotics_enforcement","diversion_control"};
                                features[] = {"Team Transport","Federal Operations","Utility Vehicle"};
                                text = "DEA team utility vehicle.";
                            };
                        };
                    };

                    class command {
                        title = "Command";
                        description = "Supervisor and command vehicles.";

                        class Vehicles {
                            class AG_Silverado_19_Unm_AG_TIER3 {
                                className = "AG_Silverado_19_Unm_AG_TIER3";
                                displayName = "DEA Silverado Command";
                                price = 74000;
                                condition = "";
                                rank = "supervisory_special_agent";
                                subdivisions[] = {};
                                features[] = {"Command Vehicle","Utility Vehicle","Federal Operations"};
                                text = "DEA command utility vehicle.";
                            };
                        };
                    };
                };
            };

            class fbi_motor_pool {
                legacyShop = "cop_car";
                title = "FBI Motor Pool";
                subtitle = "Federal Bureau of Investigation ground vehicles";
                side = "cop";
                condition = "playerSide isEqualTo west && {['leo.department.fbi'] call life_fnc_hasPermission}";
                requiredCertification = "";
                department = "fbi";
                shopFlag = "cop";
                useFactionBank = 1;

                class Categories {
                    class field_office {
                        title = "Field Office";
                        description = "Unmarked vehicles for federal investigations.";

                        class Vehicles {
                            class AG_CROWNVIC_UNM_AG {
                                className = "AG_CROWNVIC_UNM_AG";
                                displayName = "FBI CVPI Unmarked";
                                price = 10000;
                                condition = "";
                                rank = "special_agent";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Federal Investigations","Surveillance"};
                                text = "Unmarked FBI field office vehicle.";
                            };
                            class AG_CHARGER_SRT_UNM_AG {
                                className = "AG_CHARGER_SRT_UNM_AG";
                                displayName = "FBI Charger SRT Unmarked";
                                price = 15000;
                                condition = "";
                                rank = "special_agent";
                                subdivisions[] = {};
                                features[] = {"Unmarked Unit","Rapid Response","Surveillance"};
                                text = "Unmarked FBI rapid response vehicle.";
                            };
                        };
                    };

                    class investigations {
                        title = "Investigations";
                        description = "Criminal investigation and major case vehicles.";

                        class Vehicles {
                            class AG_Taurus_Unm_AG {
                                className = "AG_Taurus_Unm_AG";
                                displayName = "FBI Taurus Unmarked";
                                price = 18000;
                                condition = "";
                                rank = "senior_special_agent";
                                subdivisions[] = {"criminal_investigations"};
                                features[] = {"Criminal Investigations","Unmarked Unit","Covert Response"};
                                text = "Unmarked FBI investigation vehicle.";
                            };
                            class AG_Suburban16_Unm_AG {
                                className = "AG_Suburban16_Unm_AG";
                                displayName = "FBI Suburban Unmarked";
                                price = 30000;
                                condition = "";
                                rank = "senior_special_agent";
                                subdivisions[] = {"criminal_investigations","major_case"};
                                features[] = {"Team Transport","Federal Operations","Utility Vehicle"};
                                text = "FBI team utility vehicle.";
                            };
                        };
                    };

                    class command {
                        title = "Command";
                        description = "Supervisor and command vehicles.";

                        class Vehicles {
                            class AG_Silverado_19_Unm_AG_TIER3 {
                                className = "AG_Silverado_19_Unm_AG_TIER3";
                                displayName = "FBI Silverado Command";
                                price = 74000;
                                condition = "";
                                rank = "supervisory_special_agent";
                                subdivisions[] = {};
                                features[] = {"Command Vehicle","Utility Vehicle","Federal Operations"};
                                text = "FBI command utility vehicle.";
                            };
                        };
                    };
                };
            };
        };
    };

    class LEOClothingShops {
        class cop {
            title = "KCSO Uniform Locker";
            subtitle = "Duty clothing issued by rank, role, and subdivision";
            side = "cop";
            condition = "playerSide isEqualTo west";
            department = "kcso";

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
                            displayName = "KCSO Cadet Patrol Uniform";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Cadet Uniform";
                        };
                        class AG_KCSO_Short_Cadet_Uni {
                            className = "AG_KCSO_Short_Cadet_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Cadet Patrol Uniform Short Sleeve";
                            price = 25;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Cadet Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Cadet_Uni {
                            className = "AG_KCSO_Long_Cadet_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Cadet Patrol Uniform Long Sleeve";
                            price = 350;
                            condition = "";
                            rank = "cadet";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Cadet Uniform Long Sleeve";
                        };
                        class AG_KCSO_PTrooper_Uni {
                            className = "AG_KCSO_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Probationary Deputy Uniform";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Probationary Deputy Uniform";
                        };
                        class AG_KCSO_Short_PTrooper_Uni {
                            className = "AG_KCSO_Short_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Probationary Deputy Uniform Short Sleeve";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Probationary Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_PTrooper_Uni {
                            className = "AG_KCSO_Long_PTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Probationary Deputy Uniform Long Sleeve";
                            price = 350;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Probationary Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_Trooper_Uni {
                            className = "AG_KCSO_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Deputy Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Deputy Uniform";
                        };
                        class AG_KCSO_Short_Trooper_Uni {
                            className = "AG_KCSO_Short_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Deputy Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Trooper_Uni {
                            className = "AG_KCSO_Long_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Deputy Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_SnrTrooper_Uni {
                            className = "AG_KCSO_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Senior Deputy Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Senior Deputy Uniform";
                        };
                        class AG_KCSO_Short_SnrTrooper_Uni {
                            className = "AG_KCSO_Short_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Senior Deputy Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Senior Deputy Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_SnrTrooper_Uni {
                            className = "AG_KCSO_Long_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Senior Deputy Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Senior Deputy Uniform Long Sleeve";
                        };
                        class AG_KCSO_Short_Corporal_Uni {
                            className = "AG_KCSO_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Corporal Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Corporal Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Corporal_Uni {
                            className = "AG_KCSO_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Corporal Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Corporal Uniform Long Sleeve";
                        };
                        class AG_KCSO_Corporal_Uni {
                            className = "AG_KCSO_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Corporal Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Corporal Uniform";
                        };
                        class AG_KCSO_Sergeant_Uni {
                            className = "AG_KCSO_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant Uniform";
                        };
                        class AG_KCSO_Short_Sergeant_Uni {
                            className = "AG_KCSO_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Sergeant_Uni {
                            className = "AG_KCSO_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant Uniform Long Sleeve";
                        };
                        class AG_KCSO_Sergeant_White_Uni {
                            className = "AG_KCSO_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol White Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant White Uniform";
                        };
                        class AG_KCSO_Short_Sergeant_White_Uni {
                            className = "AG_KCSO_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol White Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant White Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Sergeant_White_Uni {
                            className = "AG_KCSO_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sergeant Patrol White Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sergeant White Uniform Long Sleeve";
                        };
                        class AG_KCSO_Lieutenant_Uni {
                            className = "AG_KCSO_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform";
                        };
                        class AG_KCSO_Short_Lieutenant_Uni {
                            className = "AG_KCSO_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Lieutenant_Uni {
                            className = "AG_KCSO_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform Long Sleeve";
                        };
                        class AG_KCSO_Lieutenant_White_Uni {
                            className = "AG_KCSO_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform White";
                        };
                        class AG_KCSO_Short_Lieutenant_White_Uni {
                            className = "AG_KCSO_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Lieutenant_White_Uni {
                            className = "AG_KCSO_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Lieutenant Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Lieutenant Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Captain_Uni {
                            className = "AG_KCSO_Captain_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform";
                        };
                        class AG_KCSO_Short_Captain_Uni {
                            className = "AG_KCSO_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Captain_Uni {
                            className = "AG_KCSO_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform Long Sleeve";
                        };
                        class AG_KCSO_Captain_White_Uni {
                            className = "AG_KCSO_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform White";
                        };
                        class AG_KCSO_Short_Captain_White_Uni {
                            className = "AG_KCSO_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Captain_White_Uni {
                            className = "AG_KCSO_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Captain Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Captain Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Major_Uni {
                            className = "AG_KCSO_Major_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform";
                        };
                        class AG_KCSO_Short_Major_Uni {
                            className = "AG_KCSO_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Major_Uni {
                            className = "AG_KCSO_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform Long Sleeve";
                        };
                        class AG_KCSO_Major_White_Uni {
                            className = "AG_KCSO_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform White";
                        };
                        class AG_KCSO_Short_Major_White_Uni {
                            className = "AG_KCSO_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Major_White_Uni {
                            className = "AG_KCSO_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Major Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Major Uniform White Long Sleeve";
                        };
                        class AG_KCSO_LtCol_Uni {
                            className = "AG_KCSO_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol Uniform";
                        };
                        class AG_KCSO_Short_LtCol_Uni {
                            className = "AG_KCSO_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_LtCol_Uni {
                            className = "AG_KCSO_Long_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol Uniform Long Sleeve";
                        };
                        class AG_KCSO_LtCol_White_Uni {
                            className = "AG_KCSO_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol White";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol White";
                        };
                        class AG_KCSO_Short_LtCol_White_Uni {
                            className = "AG_KCSO_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol White Short Sleeve";
                        };
                        class AG_KCSO_Long_LtCol_White_Uni {
                            className = "AG_KCSO_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Patrol White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Undersheriff Patrol White Long Sleeve";
                        };
                        class AG_KCSO_Col_Uni {
                            className = "AG_KCSO_Col_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform";
                        };
                        class AG_KCSO_Short_Col_Uni {
                            className = "AG_KCSO_Short_Col_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Col_Uni {
                            className = "AG_KCSO_Long_Col_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform Long Sleeve";
                        };
                        class AG_KCSO_Col_White_Uni {
                            className = "AG_KCSO_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform White";
                        };
                        class AG_KCSO_Short_Col_White_Uni {
                            className = "AG_KCSO_Short_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Col_White_Uni {
                            className = "AG_KCSO_Long_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Sheriff Patrol Uniform White Long Sleeve";
                        };
                        class AG_KCSO_Comm_Uni {
                            className = "AG_KCSO_Comm_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform";
                        };
                        class AG_KCSO_Short_Comm_Uni {
                            className = "AG_KCSO_Short_Comm_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform Short Sleeve";
                        };
                        class AG_KCSO_Long_Comm_Uni {
                            className = "AG_KCSO_Long_Comm_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform Short Sleeve";
                        };
                        class AG_KCSO_Comm_White_Uni {
                            className = "AG_KCSO_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform White";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform White";
                        };
                        class AG_KCSO_Short_Comm_White_Uni {
                            className = "AG_KCSO_Short_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform White Short Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform White Short Sleeve";
                        };
                        class AG_KCSO_Long_Comm_White_Uni {
                            className = "AG_KCSO_Long_Comm_White_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Patrol Uniform White Long Sleeve";
                            price = 550;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard issued KCSO Commissioner Uniform Long Sleeve";
                        };
                        class AG_KCSO_Beret {
                            className = "AG_KCSO_Beret";
                            itemType = "headgear";
                            displayName = "KCSO Beret";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard KCSO Beret";
                        };
                        class AG_KCSO_CampaignHat {
                            className = "AG_KCSO_CampaignHat";
                            itemType = "headgear";
                            displayName = "KCSO Patrol Campaign Hat";
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
                            displayName = "KCSO Patrol Patch Cap";
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
                            displayName = "KCSO Patrol Patch Cap Alt";
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
                            displayName = "KCSO Patrol Belt";
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
                            displayName = "KCSO CPC Tactical Vest";
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
                            displayName = "KCSO JPC Tactical Vest";
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
                            displayName = "KCSO LBT Vest";
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
                            displayName = "KCSO MMAC Patrol Vest";
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
                            displayName = "KCSO Plate Carrier";
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

                class admin_services {
                    title = "Admin Services";
                    description = "Admin Services clothing and Trainer-issued gear.";

                    class Items {
                        class AG_AdminServices_PDeputy_Uni {
                            className = "AG_AdminServices_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Probationary Deputy Uniform";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Short_PDeputy_Uni {
                            className = "AG_AdminServices_Short_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Probationary Deputy Uniform Short Sleeve";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued short sleeve uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Long_PDeputy_Uni {
                            className = "AG_AdminServices_Long_PDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Probationary Deputy Uniform Long Sleeve";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued long sleeve uniform for probationary deputies in training.";
                        };
                        class AG_AdminService_PDeputy_Sweater {
                            className = "AG_AdminService_PDeputy_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Probationary Deputy Sweater Uniform";
                            price = 25;
                            condition = "";
                            rank = "probationary_deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued sweater uniform for probationary deputies in training.";
                        };
                        class AG_AdminServices_Deputy_Uni {
                            className = "AG_AdminServices_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Deputy Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued uniform for qualified trainers.";
                        };
                        class AG_AdminServices_Short_Deputy_Uni {
                            className = "AG_AdminServices_Short_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Deputy Short Sleeve Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued short sleeve uniform for qualified trainers.";
                        };
                        class AG_AdminServices_Long_Deputy_Uni {
                            className = "AG_AdminServices_Long_Deputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Deputy Long Sleeve Uniform";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified trainers.";
                        };
                        class AG_AdminService_Deputy_Sweater {
                            className = "AG_AdminService_Deputy_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Deputy Sweater Uniform";
                            price = 25;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued sweater uniform for qualified trainers.";
                        };
                        class AG_AdminServices_SnrDeputy_Uni {
                            className = "AG_AdminServices_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Senior Deputy Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Senior Deputy trainers.";
                        };
                        class AG_AdminServices_Short_SnrDeputy_Uni {
                            className = "AG_AdminServices_Short_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Senior Deputy Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Senior Deputy trainers.";
                        };
                        class AG_AdminServices_Long_SnrDeputy_Uni {
                            className = "AG_AdminServices_Long_SnrDeputy_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Senior Deputy Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Senior Deputy trainers.";
                        };
                        class AG_AdminServices_Corporal_Uni {
                            className = "AG_AdminServices_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Corporal Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Corporal trainers.";
                        };
                        class AG_AdminServices_Short_Corporal_Uni {
                            className = "AG_AdminServices_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Corporal Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Corporal trainers.";
                        };
                        class AG_AdminServices_Long_Corporal_Uni {
                            className = "AG_AdminServices_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Corporal Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Corporal trainers.";
                        };
                        class AG_AdminService_Corporal_Sweater {
                            className = "AG_AdminService_Corporal_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Corporal Trainer Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued sweater uniform for qualified Corporal trainers.";
                        };
                        class AG_AdminServices_Sergeant_White_Uni {
                            className = "AG_AdminServices_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminServices_Short_Sergeant_White_Uni {
                            className = "AG_AdminServices_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white short sleeve uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminServices_Long_Sergeant_White_Uni {
                            className = "AG_AdminServices_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white long sleeve uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminServices_Short_Sergeant_Uni {
                            className = "AG_AdminServices_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminServices_Long_Sergeant_Uni {
                            className = "AG_AdminServices_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminService_Sergeant_Sweater {
                            className = "AG_AdminService_Sergeant_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Sergeant Trainer Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued sweater uniform for qualified Sergeant trainers.";
                        };
                        class AG_AdminServices_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Short_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white short sleeve uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Long_Lieutenant_White_Uni {
                            className = "AG_AdminServices_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white long sleeve uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Lieutenant_Uni {
                            className = "AG_AdminServices_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Short_Lieutenant_Uni {
                            className = "AG_AdminServices_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Long_Lieutenant_Uni {
                            className = "AG_AdminServices_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminService_Lieutenant_Sweater {
                            className = "AG_AdminService_Lieutenant_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Lieutenant Trainer Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued sweater uniform for qualified Lieutenant trainers.";
                        };
                        class AG_AdminServices_Captain_Uni {
                            className = "AG_AdminServices_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Short_Captain_Uni {
                            className = "AG_AdminServices_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Long_Captain_Uni {
                            className = "AG_AdminServices_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Captain trainers.";
                        };
                        class AG_AdminService_Captain_Sweater {
                            className = "AG_AdminService_Captain_Sweater";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer Sweater Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued sweater uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Captain_White_Uni {
                            className = "AG_AdminServices_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Short_Captain_White_Uni {
                            className = "AG_AdminServices_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white short sleeve uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Long_Captain_White_Uni {
                            className = "AG_AdminServices_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Captain Trainer White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white long sleeve uniform for qualified Captain trainers.";
                        };
                        class AG_AdminServices_Major_Uni {
                            className = "AG_AdminServices_Major_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_Short_Major_Uni {
                            className = "AG_AdminServices_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_Long_Major_Uni {
                            className = "AG_AdminServices_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued long sleeve uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_Major_White_Uni {
                            className = "AG_AdminServices_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_Short_Major_White_Uni {
                            className = "AG_AdminServices_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white short sleeve uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_Long_Major_White_Uni {
                            className = "AG_AdminServices_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Major Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white long sleeve uniform for qualified Major trainers.";
                        };
                        class AG_AdminServices_LtCol_Uni {
                            className = "AG_AdminServices_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Undersheriff Trainer Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued uniform for qualified Undersheriff trainers.";
                        };
                        class AG_AdminServices_Short_LtCol_Uni {
                            className = "AG_AdminServices_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Undersheriff Trainer Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued short sleeve uniform for qualified Undersheriff trainers.";
                        };
                        class AG_AdminServices_LtCol_White_Uni {
                            className = "AG_AdminServices_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Undersheriff Trainer White Uniform";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white uniform for qualified Undersheriff trainers.";
                        };
                        class AG_AdminServices_Short_LtCol_White_Uni {
                            className = "AG_AdminServices_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Undersheriff Trainer White Uniform Short Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white short sleeve uniform for qualified Undersheriff trainers.";
                        };
                        class AG_AdminServices_Long_LtCol_White_Uni {
                            className = "AG_AdminServices_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "Admin Services Undersheriff Trainer White Uniform Long Sleeve";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued white long sleeve uniform for qualified Undersheriff trainers.";
                        };
                        class AG_AdminServices_Plate {
                            className = "AG_AdminServices_Plate";
                            itemType = "vest";
                            displayName = "Admin Services Trainer Plate Carrier";
                            price = 55;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {"leo.training.admin_services"};
                            text = "Admin Services issued plate carrier for qualified trainers.";
                        };
                        class AG_AdminServices_PatchCap {
                            className = "AG_AdminServices_PatchCap";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Patch Cap";
                            price = 10;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued patch cap for qualified trainers.";
                        };
                        class AG_JPC_Vest_Admin {
                            className = "AG_JPC_Vest_Admin";
                            itemType = "uniform";
                            displayName = "Admin Services Trainer JPC Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued JPC vest for qualified trainers.";
                        };
                        class AG_AdminServices_CPC_Vest {
                            className = "AG_AdminServices_CPC_Vest";
                            itemType = "vest";
                            displayName = "Admin Services Trainer CPC Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued CPC vest for qualified trainers.";
                        };
                        class AG_AdminServices_PatrolVest {
                            className = "AG_AdminServices_PatrolVest";
                            itemType = "vest";
                            displayName = "Admin Services Trainer Patrol Vest";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued patrol vest for qualified trainers.";
                        };
                        class AG_MMAC_Vest_Admin {
                            className = "AG_MMAC_Vest_Admin";
                            itemType = "vest";
                            displayName = "Admin Services Trainer MMAC Vest";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued MMAC vest for qualified trainers.";
                        };
                        class AG_AdminServices_VestCombo {
                            className = "AG_AdminServices_VestCombo";
                            itemType = "vest";
                            displayName = "Admin Services Trainer Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued vest combo for qualified trainers.";
                        };
                        class AG_AdminServices_VestCombo2 {
                            className = "AG_AdminServices_VestCombo2";
                            itemType = "vest";
                            displayName = "Admin Services Trainer Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued vest combo for qualified trainers.";
                        };
                        class AG_AdminServices_VestCombo3 {
                            className = "AG_AdminServices_VestCombo3";
                            itemType = "vest";
                            displayName = "Admin Services Trainer Vest Combo";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = { "admin_services" };
                            rolePermissions[] = { "leo.training.admin_services" };
                            text = "Admin Services issued vest combo for qualified trainers.";
                        };
                        class AG_AdminServices_Beret {
                            className = "AG_AdminServices_Beret";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Beret";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {};
                            text = "Admin Services issued beret for qualified trainers.";
                        };
                        class AG_AdminServices_CampaignHat {
                            className = "AG_AdminServices_CampaignHat";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Campaign Hat";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {};
                            text = "Admin Services issued campaign hat for qualified trainers.";
                        };
                        class AG_AdminServices_PatchCap_Back {
                            className = "AG_AdminServices_PatchCap_Back";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Patch Cap (Back)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {};
                            text = "Admin Services issued patch cap for qualified trainers.";
                        };
                        class AG_AdminServices_PatchCapAlt {
                            className = "AG_AdminServices_PatchCapAlt";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Patch Cap (Alt)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {};
                            text = "Admin Services issued patch cap for qualified trainers.";
                        };
                        class AG_AdminServices_PatchCapAlt_Back {
                            className = "AG_AdminServices_PatchCapAlt_Back";
                            itemType = "headgear";
                            displayName = "Admin Services Trainer Patch Cap (Alt Back)";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"admin_services"};
                            rolePermissions[] = {};
                            text = "Admin Services issued patch cap for qualified trainers.";
                        };
                    };
                };

                class hsu {
                    title = "KCSO Speed Enforcement";
                    description = "Speed Enforcement clothing and equipment for KCSO deputies.";

                    class Items {
                        class AG_FactionInvPack {
                            className = "AG_FactionInvPack";
                            itemType = "backpack";
                            displayName = "KCSO Faction Inventory Pack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Faction inventory pack for KCSO deputies.";
                        };
                        class AG_HSU_Biker_Uni {
                            className = "AG_HSU_Biker_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Biker Uniform";
                            price = 100;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement motor unit uniform";
                        };
                        class AG_HSU_Trooper_Uni {
                            className = "AG_HSU_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "HSU Deputy Uniform";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO deputies.";
                        };
                        class AG_HSU_Short_Trooper_Uni {
                            className = "AG_HSU_Short_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "HSU Deputy Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO deputies.";
                        };
                        class AG_HSU_SnrTrooper_Uni {
                            className = "AG_HSU_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSU Senior Deputy Uniform";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO senior deputies.";
                        };
                        class AG_HSU_Short_SnrTrooper_Uni {
                            className = "AG_HSU_Short_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSU Senior Deputy Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO senior deputies.";
                        };
                        class AG_HSU_Long_SnrTrooper_Uni {
                            className = "AG_HSU_Long_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "HSU Senior Deputy Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO senior deputies.";
                        };
                        class AG_HSU_Corporal_Uni {
                            className = "AG_HSU_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSU Corporal Uniform";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO corporals.";
                        };
                        class AG_HSU_Short_Corporal_Uni {
                            className = "AG_HSU_Short_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSU Corporal Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO corporals.";
                        };
                        class AG_HSU_Long_Corporal_Uni {
                            className = "AG_HSU_Long_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "HSU Corporal Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO corporals.";
                        };
                        class AG_HSU_Sergeant_Uni {
                            className = "AG_HSU_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant Uniform";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Short_Sergeant_Uni {
                            className = "AG_HSU_Short_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Long_Sergeant_Uni {
                            className = "AG_HSU_Long_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement Long Sleeve uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Sergeant_White_Uni {
                            className = "AG_HSU_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant White Uniform";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Short_Sergeant_White_Uni {
                            className = "AG_HSU_Short_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Long_Sergeant_White_Uni {
                            className = "AG_HSU_Long_Sergeant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sergeant White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO sergeants.";
                        };
                        class AG_HSU_Lieutenant_Uni {
                            className = "AG_HSU_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant Uniform";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Short_Lieutenant_Uni {
                            className = "AG_HSU_Short_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Long_Lieutenant_Uni {
                            className = "AG_HSU_Long_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Lieutenant_White_Uni {
                            className = "AG_HSU_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant White Uniform";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Short_Lieutenant_White_Uni {
                            className = "AG_HSU_Short_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Long_Lieutenant_White_Uni {
                            className = "AG_HSU_Long_Lieutenant_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Lieutenant White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO lieutenants.";
                        };
                        class AG_HSU_Captain_Uni {
                            className = "AG_HSU_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain Uniform";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO captains.";
                        };
                        class AG_HSU_Short_Captain_Uni {
                            className = "AG_HSU_Short_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO captains.";
                        };
                        class AG_HSU_Long_Captain_Uni {
                            className = "AG_HSU_Long_Captain_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO captains.";
                        };
                        class AG_HSU_Captain_White_Uni {
                            className = "AG_HSU_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain White Uniform";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO captains.";
                        };
                        class AG_HSU_Short_Captain_White_Uni {
                            className = "AG_HSU_Short_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO captains.";
                        };
                        class AG_HSU_Long_Captain_White_Uni {
                            className = "AG_HSU_Long_Captain_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Captain White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO captains.";
                        };
                        class AG_HSU_Major_Uni {
                            className = "AG_HSU_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major Uniform";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO majors.";
                        };
                        class AG_HSU_Short_Major_Uni {
                            className = "AG_HSU_Short_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO majors.";
                        };
                        class AG_HSU_Long_Major_Uni {
                            className = "AG_HSU_Long_Major_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO majors.";
                        };
                        class AG_HSU_Major_White_Uni {
                            className = "AG_HSU_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major White Uniform";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO majors.";
                        };
                        class AG_HSU_Short_Major_White_Uni {
                            className = "AG_HSU_Short_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO majors.";
                        };
                        class AG_HSU_Long_Major_White_Uni {
                            className = "AG_HSU_Long_Major_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Major White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO majors.";
                        };
                        class AG_HSU_LtCol_Uni {
                            className = "AG_HSU_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff Uniform";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_Short_LtCol_Uni {
                            className = "AG_HSU_Short_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_Long_LtCol_Uni {
                            className = "AG_HSU_Long_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_LtCol_White_Uni {
                            className = "AG_HSU_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff White Uniform";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_Short_LtCol_White_Uni {
                            className = "AG_HSU_Short_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_Long_LtCol_White_Uni {
                            className = "AG_HSU_Long_LtCol_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Undersheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO undersheriffs.";
                        };
                        class AG_HSU_Col_Uni {
                            className = "AG_HSU_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff Uniform";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_Short_Col_Uni {
                            className = "AG_HSU_Short_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement short sleeve uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_Long_Col_Uni {
                            className = "AG_HSU_Long_Col_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement long sleeve uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_Col_White_Uni {
                            className = "AG_HSU_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff White Uniform";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_Short_Col_White_Uni {
                            className = "AG_HSU_Short_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff White Uniform Short Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white short sleeve uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_Long_Col_White_Uni {
                            className = "AG_HSU_Long_Col_White_Uni";
                            itemType = "uniform";
                            displayName = "HSU Sheriff White Uniform Long Sleeve";
                            price = 500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement white long sleeve uniform for KCSO sheriffs.";
                        };
                        class AG_HSU_PatchCap {
                            className = "AG_HSU_PatchCap";
                            itemType = "headgear";
                            displayName = "HSU Patch Cap";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement patch cap for KCSO deputies.";
                        };
                        class AG_HSU_PatchCap_Back {
                            className = "AG_HSU_PatchCap_Back";
                            itemType = "headgear";
                            displayName = "HSU Patch Cap (Back)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement patch cap with back logo for KCSO deputies.";
                        };
                        class AG_HSU_PatchCapAlt {
                            className = "AG_HSU_PatchCapAlt";
                            itemType = "headgear";
                            displayName = "HSU Patch Cap (Alt)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement patch cap with alternate logo for KCSO deputies.";
                        };
                        class AG_HSU_PatchCapAlt_Back {
                            className = "AG_HSU_PatchCapAlt_Back";
                            itemType = "headgear";
                            displayName = "HSU Patch Cap (Alt Back)";
                            price = 50;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement patch cap with alternate logo and back logo for KCSO deputies.";
                        };
                        class AG_HSU_Beret {
                            className = "AG_HSU_Beret";
                            itemType = "headgear";
                            displayName = "HSU Beret";
                            price = 50;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement beret for KCSO corporals and above.";
                        };
                        class AG_HSU_CampaignHat {
                            className = "AG_HSU_CampaignHat";
                            itemType = "headgear";
                            displayName = "HSU Campaign Hat";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement campaign hat for KCSO deputies.";
                        };
                        class AG_HSU_Plate {
                            className = "AG_HSU_Plate";
                            itemType = "vest";
                            displayName = "HSU Tactical Vest";
                            price = 150;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement tactical vest for KCSO deputies.";
                        };
                        class AG_JPC_Vest_HSU {
                            className = "AG_JPC_Vest_HSU";
                            itemType = "vest";
                            displayName = "HSU JPC Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement JPC tactical vest for KCSO senior deputies and above.";
                        };
                        class AG_HSU_PatrolVest {
                            className = "AG_HSU_PatrolVest";
                            itemType = "vest";
                            displayName = "HSU Patrol Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement patrol tactical vest";
                        };
                        class AG_MMAC_Vest_HSU {
                            className = "AG_MMAC_Vest_HSU";
                            itemType = "vest";
                            displayName = "HSU MMAC Tactical Vest";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement MMAC tactical vest for KCSO senior deputies and above.";
                        };
                        class AG_HSU_VestCombo {
                            className = "AG_HSU_VestCombo";
                            itemType = "vest";
                            displayName = "HSU Vest Combo";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement vest combo for KCSO deputies.";
                        };
                        class AG_HSU_VestCombo2 {
                            className = "AG_HSU_VestCombo2";
                            itemType = "vest";
                            displayName = "HSU Vest Combo 2";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement vest combo 2 for KCSO deputies.";
                        };
                        class AG_HSU_VestCombo3 {
                            className = "AG_HSU_VestCombo3";
                            itemType = "vest";
                            displayName = "HSU Vest Combo 3";
                            price = 20;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"hsu"};
                            rolePermissions[] = {"leo.vehicle.hsu"};
                            text = "Traffic enforcement vest combo 3 for KCSO deputies.";
                        };
                    };
                };

                class swat {
                    title = "SWAT";
                    description = "SWAT tactical clothing and heavy equipment.";

                    class Items {
                        class AG_SWAT_Uni_short_AAF {
                            className = "AG_SWAT_Uni_short_AAF";
                            itemType = "uniform";
                            displayName = "SWAT Short Sleeve Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT short sleeve uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Uni_Tshirt_Alt {
                            className = "AG_SWAT_Uni_Tshirt_Alt";
                            itemType = "uniform";
                            displayName = "SWAT T Shirt Alt Uniform";
                            price = 450;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT t-shirt uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Combat_Uni {
                            className = "AG_SWAT_Combat_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Combat Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT combat uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Trooper_Uni {
                            className = "AG_SWAT_Trooper_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_SnrTrooper_Uni {
                            className = "AG_SWAT_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Senior Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT senior tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Corporal_Uni {
                            className = "AG_SWAT_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Corporal Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "corporal";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT corporal tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Sergeant_Uni {
                            className = "AG_SWAT_Sergeant_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Sergeant Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT sergeant tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Lieutenant_Uni {
                            className = "AG_SWAT_Lieutenant_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Lieutenant Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "lieutenant";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT lieutenant tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Captain_Uni {
                            className = "AG_SWAT_Captain_Uni";
                            itemType = "uniform";
                            displayName = "SWAT Captain Tactical Uniform";
                            price = 550;
                            condition = "";
                            rank = "captain";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT captain tactical uniform for approved tactical deployments.";
                        };
                        class AG_SWAT_Beret {
                            className = "AG_SWAT_Beret";
                            itemType = "headgear";
                            displayName = "SWAT Beret";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT beret for approved tactical deployments.";
                        };
                        class AG_SWAT_Cap2 {
                            className = "AG_SWAT_Cap2";
                            itemType = "headgear";
                            displayName = "SWAT Cap";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT cap for approved tactical deployments.";
                        };
                        class AG_SWAT_PatchCap {
                            className = "AG_SWAT_PatchCap";
                            itemType = "headgear";
                            displayName = "SWAT Patch Cap";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT patch cap for approved tactical deployments.";
                        };
                        class AG_SWAT_Helmet {
                            className = "AG_SWAT_Helmet";
                            itemType = "headgear";
                            displayName = "SWAT Helmet";
                            price = 80;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT helmet for approved tactical deployments.";
                        };
                        class AG_SWAT_LightCarrier {
                            className = "AG_SWAT_LightCarrier";
                            itemType = "vest";
                            displayName = "SWAT Plate Carrier";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT plate carrier for approved tactical deployments.";
                        };
                        class AG_SWAT_PatrolVest {
                            className = "AG_SWAT_PatrolVest";
                            itemType = "vest";
                            displayName = "SWAT Plate Carrier";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT plate carrier for approved tactical deployments.";
                        };
                        class AG_MMAC_Vest_SWAT {
                            className = "AG_MMAC_Vest_SWAT";
                            itemType = "vest";
                            displayName = "SWAT MMAC Vest";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT MMAC Vest for approved tactical deployments.";
                        };
                        class SWAT_VestCombo {
                            className = "SWAT_VestCombo";
                            itemType = "vest";
                            displayName = "SWAT Vest Combo";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT vest combo for approved tactical deployments.";
                        };
                        class SWAT_VestCombo2 {
                            className = "SWAT_VestCombo2";
                            itemType = "vest";
                            displayName = "SWAT Vest Combo 2";
                            price = 500;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT vest combo 2 for approved tactical deployments.";
                        };
                        class AG_SWAT_HeavyCarrier {
                            className = "AG_SWAT_HeavyCarrier";
                            itemType = "vest";
                            displayName = "SWAT Heavy Carrier";
                            price = 500;
                            condition = "";
                            rank = "sergeant";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT heavy carrier for approved tactical deployments.";
                        };
                        class AG_FactionInvPack {
                            className = "AG_FactionInvPack";
                            itemType = "backpack";
                            displayName = "KCSO Backpack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "KCSO Backpack";
                        };
                        class AG_SWAT_Assault_Backpack {
                            className = "AG_SWAT_Assault_Backpack";
                            itemType = "backpack";
                            displayName = "SWAT Assault Backpack";
                            price = 100;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"swat"};
                            rolePermissions[] = {"leo.tactical.swat"};
                            text = "SWAT assault backpack for approved tactical deployments.";
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
                            displayName = "CID Investigator Uniform";
                            price = 5000;
                            condition = "";
                            rank = "deputy";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID investigator uniform for criminal investigations.";
                        };
                        class AG_CID_SnrTrooper_Uni {
                            className = "AG_CID_SnrTrooper_Uni";
                            itemType = "uniform";
                            displayName = "CID Senior Investigator Uniform";
                            price = 5000;
                            condition = "";
                            rank = "senior_deputy";
                            subdivisions[] = {"cid"};
                            rolePermissions[] = {"leo.investigations.criminal"};
                            text = "CID senior investigator uniform for criminal investigations.";
                        };
                        class AG_CID_Corporal_Uni {
                            className = "AG_CID_Corporal_Uni";
                            itemType = "uniform";
                            displayName = "CID Corporal Investigator Uniform";
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
                            subdivisions[] = {"kcia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs investigator uniform for internal investigations.";
                        };
                        class AG_JPC_Vest_CID {
                            className = "AG_JPC_Vest_CID";
                            itemType = "vest";
                            displayName = "CID Tactical Vest";
                            price = 800;
                            condition = "";
                            rank = "deputy";
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
                            subdivisions[] = {"kcia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs tactical vest for investigative operations.";
                        };
                        class AG_CID_LightCarrier {
                            className = "AG_CID_LightCarrier";
                            itemType = "vest";
                            displayName = "";
                            price = 800;
                            condition = "";
                            rank = "deputy";
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
                            rank = "deputy";
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
                            rank = "deputy";
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
                            subdivisions[] = {"kcia"};
                            rolePermissions[] = {"leo.records.internal"};
                            text = "Internal Affairs beret for investigative operations.";
                        };
                        class AG_CID_PatchCap {
                            className = "AG_CID_PatchCap";
                            itemType = "headgear";
                            displayName = "CID Patch Cap";
                            price = 100;
                            condition = "";
                            rank = "deputy";
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
                            displayName = "KCSO Major Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Major Uniform";
                        };
                        class AG_KCSO_Cmd_LtCol_Uni {
                            className = "AG_KCSO_Cmd_LtCol_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Undersheriff Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "undersheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Undersheriff Uniform";
                        };
                        class AG_KCSO_Cmd_Col_Uni {
                            className = "AG_KCSO_Cmd_Col_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Sheriff Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "sheriff";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Sheriff Uniform";
                        };
                        class AG_KCSO_Cmd_Comm_Uni {
                            className = "AG_KCSO_Cmd_Comm_Uni";
                            itemType = "uniform";
                            displayName = "KCSO Commissioner Command Uniform";
                            price = 1500;
                            condition = "";
                            rank = "commissioner";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Commissioner Uniform";
                        };
                        class AG_KCSO_CampaignHat_Cmd {
                            className = "AG_KCSO_CampaignHat_Cmd";
                            itemType = "headgear";
                            displayName = "KCSO Command Campaign Hat";
                            price = 250;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Campaign Hat";
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
                            displayName = "KCSO Command Beret";
                            price = 50;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = { "leo.command.terminal" };
                            text = "KCSO Command Beret";
                        };
                        class AG_KCSOCmd_VestCombo {
                            className = "AG_KCSOCmd_VestCombo";
                            itemType = "vest";
                            displayName = "KCSO Command Vest Combo";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Vest Combo";
                        };
                        class AG_KCSOCmd_VestCombo2 {
                            className = "AG_KCSOCmd_VestCombo2";
                            itemType = "vest";
                            displayName = "KCSO Command Vest Combo 2";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Vest Combo 2";
                        };
                        class AG_KCSOCmd_VestCombo3 {
                            className = "AG_KCSOCmd_VestCombo3";
                            itemType = "vest";
                            displayName = "KCSO Command Vest Combo 3";
                            price = 120;
                            condition = "";
                            rank = "major";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "KCSO Command Vest Combo 3";
                        };
                    };
                };
            };
        };

        class usms {
            title = "USMS Uniform Locker";
            subtitle = "United States Marshal Service clothing and field gear";
            side = "cop";
            condition = "playerSide isEqualTo west && {['leo.department.usms'] call life_fnc_hasPermission}";
            department = "usms";

            class Categories {
                class uniforms {
                    title = "Uniforms";
                    description = "Federal field and command uniforms.";

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
                        class U_B_GEN_Soldier_F {
                            className = "U_B_GEN_Soldier_F";
                            itemType = "uniform";
                            displayName = "USMS Field Uniform";
                            price = 350;
                            condition = "";
                            rank = "deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard USMS field uniform.";
                        };
                        class U_B_GEN_Commander_F {
                            className = "U_B_GEN_Commander_F";
                            itemType = "uniform";
                            displayName = "USMS Command Uniform";
                            price = 550;
                            condition = "";
                            rank = "supervisory_deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "USMS command uniform.";
                        };
                    };
                };

                class headgear {
                    title = "Headgear";
                    description = "Federal caps and command headgear.";

                    class Items {
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
                        class H_Cap_police {
                            className = "H_Cap_police";
                            itemType = "headgear";
                            displayName = "USMS Field Cap";
                            price = 25;
                            condition = "";
                            rank = "deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "USMS field cap.";
                        };
                        class H_Beret_blk_POLICE {
                            className = "H_Beret_blk_POLICE";
                            itemType = "headgear";
                            displayName = "USMS Command Beret";
                            price = 50;
                            condition = "";
                            rank = "supervisory_deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "USMS command beret.";
                        };
                    };
                };

                class equipment {
                    title = "Equipment";
                    description = "Vests, glasses, and bags.";

                    class Items {
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
                        class V_TacVest_blk_POLICE {
                            className = "V_TacVest_blk_POLICE";
                            itemType = "vest";
                            displayName = "USMS Tactical Vest";
                            price = 1000;
                            condition = "";
                            rank = "deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "USMS tactical vest.";
                        };
                        class B_AssaultPack_blk {
                            className = "B_AssaultPack_blk";
                            itemType = "backpack";
                            displayName = "USMS Field Bag";
                            price = 2000;
                            condition = "";
                            rank = "deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "USMS field bag.";
                        };
                        class G_Aviator {
                            className = "G_Aviator";
                            itemType = "goggles";
                            displayName = "USMS Sunglasses";
                            price = 100;
                            condition = "";
                            rank = "deputy_marshal";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "USMS sunglasses.";
                        };
                    };
                };
            };
        };

        class dea {
            title = "DEA Uniform Locker";
            subtitle = "Drug Enforcement Administration clothing and field gear";
            side = "cop";
            condition = "playerSide isEqualTo west && {['leo.department.dea'] call life_fnc_hasPermission}";
            department = "dea";

            class Categories {
                class uniforms {
                    title = "Uniforms";
                    description = "Federal field and command uniforms.";

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
                        class U_B_CombatUniform_mcam_tshirt {
                            className = "U_B_CombatUniform_mcam_tshirt";
                            itemType = "uniform";
                            displayName = "DEA Field Uniform";
                            price = 350;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard DEA field uniform.";
                        };
                        class U_B_GEN_Commander_F {
                            className = "U_B_GEN_Commander_F";
                            itemType = "uniform";
                            displayName = "DEA Command Uniform";
                            price = 550;
                            condition = "";
                            rank = "supervisory_special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "DEA command uniform.";
                        };
                    };
                };

                class headgear {
                    title = "Headgear";
                    description = "Federal caps and command headgear.";

                    class Items {
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
                        class H_Cap_police {
                            className = "H_Cap_police";
                            itemType = "headgear";
                            displayName = "DEA Field Cap";
                            price = 25;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "DEA field cap.";
                        };
                        class H_Beret_blk_POLICE {
                            className = "H_Beret_blk_POLICE";
                            itemType = "headgear";
                            displayName = "DEA Command Beret";
                            price = 50;
                            condition = "";
                            rank = "supervisory_special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "DEA command beret.";
                        };
                    };
                };

                class equipment {
                    title = "Equipment";
                    description = "Vests, glasses, and bags.";

                    class Items {
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
                        class V_TacVest_blk_POLICE {
                            className = "V_TacVest_blk_POLICE";
                            itemType = "vest";
                            displayName = "DEA Tactical Vest";
                            price = 1000;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "DEA tactical vest.";
                        };
                        class B_AssaultPack_blk {
                            className = "B_AssaultPack_blk";
                            itemType = "backpack";
                            displayName = "DEA Field Bag";
                            price = 2000;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "DEA field bag.";
                        };
                        class G_Aviator {
                            className = "G_Aviator";
                            itemType = "goggles";
                            displayName = "DEA Sunglasses";
                            price = 100;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "DEA sunglasses.";
                        };
                    };
                };
            };
        };

        class fbi {
            title = "FBI Uniform Locker";
            subtitle = "Federal Bureau of Investigation clothing and field gear";
            side = "cop";
            condition = "playerSide isEqualTo west && {['leo.department.fbi'] call life_fnc_hasPermission}";
            department = "fbi";

            class Categories {
                class uniforms {
                    title = "Uniforms";
                    description = "Federal field and command uniforms.";

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
                        class U_B_CombatUniform_mcam_worn {
                            className = "U_B_CombatUniform_mcam_worn";
                            itemType = "uniform";
                            displayName = "FBI Field Uniform";
                            price = 350;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "Standard FBI field uniform.";
                        };
                        class U_B_GEN_Commander_F {
                            className = "U_B_GEN_Commander_F";
                            itemType = "uniform";
                            displayName = "FBI Command Uniform";
                            price = 550;
                            condition = "";
                            rank = "supervisory_special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "FBI command uniform.";
                        };
                    };
                };

                class headgear {
                    title = "Headgear";
                    description = "Federal caps and command headgear.";

                    class Items {
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
                        class H_Cap_police {
                            className = "H_Cap_police";
                            itemType = "headgear";
                            displayName = "FBI Field Cap";
                            price = 25;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "FBI field cap.";
                        };
                        class H_Beret_blk_POLICE {
                            className = "H_Beret_blk_POLICE";
                            itemType = "headgear";
                            displayName = "FBI Command Beret";
                            price = 50;
                            condition = "";
                            rank = "supervisory_special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {"leo.command.terminal"};
                            text = "FBI command beret.";
                        };
                    };
                };

                class equipment {
                    title = "Equipment";
                    description = "Vests, glasses, and bags.";

                    class Items {
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
                        class V_TacVest_blk_POLICE {
                            className = "V_TacVest_blk_POLICE";
                            itemType = "vest";
                            displayName = "FBI Tactical Vest";
                            price = 1000;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "FBI tactical vest.";
                        };
                        class B_AssaultPack_blk {
                            className = "B_AssaultPack_blk";
                            itemType = "backpack";
                            displayName = "FBI Field Bag";
                            price = 2000;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "FBI field bag.";
                        };
                        class G_Aviator {
                            className = "G_Aviator";
                            itemType = "goggles";
                            displayName = "FBI Sunglasses";
                            price = 100;
                            condition = "";
                            rank = "special_agent";
                            subdivisions[] = {};
                            rolePermissions[] = {};
                            text = "FBI sunglasses.";
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
