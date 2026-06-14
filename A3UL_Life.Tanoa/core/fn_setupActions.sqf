/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Master addAction file handler for all client-based actions.
*/

life_actions = [];

life_actions pushBack (player addAction[
    "Door Access",
    {[] call life_fnc_doorInteraction},
    "",
    -5,
    false,
    true,
    "",
    '!dialog && {isNull objectParent player} && {isNull cursorObject || {player distance cursorObject > 4} || {!((cursorObject isKindOf "CAManBase") || {cursorObject isKindOf "LandVehicle"} || {cursorObject isKindOf "Ship"} || {cursorObject isKindOf "Air"} || {cursorObject isKindOf "ReammoBox_F"} || {(typeOf cursorObject) in ["Land_BottlePlastic_V1_F","Land_TacticalBacon_F","Land_Can_V3_F","Land_CanisterFuel_F","Land_Suitcase_F","Land_Money_F","Land_Atm_01_F","Land_Atm_02_F"]})}} && {!(([] call life_fnc_nearestBuildingDoor) isEqualTo [])}'
]);

life_actions pushBack (player addAction[
    format ["%1 ($%2)",localize (getText(missionConfigFile >> "Licenses" >> "driver" >> "displayName")),[(getNumber(missionConfigFile >> "Licenses" >> "driver" >> "price"))] call life_fnc_numberText],
    life_fnc_buyLicense,
    "driver",
    8,
    false,
    false,
    "",
    '!dialog && {isNull objectParent player} && {[] call life_fnc_nearDMV} && {!license_civ_driver} && {playerSide isEqualTo civilian}',
    5
]);

life_actions pushBack (player addAction[
    format ["%1 ($%2)",localize (getText(missionConfigFile >> "Licenses" >> "boat" >> "displayName")),[(getNumber(missionConfigFile >> "Licenses" >> "boat" >> "price"))] call life_fnc_numberText],
    life_fnc_buyLicense,
    "boat",
    8,
    false,
    false,
    "",
    '!dialog && {isNull objectParent player} && {[] call life_fnc_nearDMV} && {!license_civ_boat} && {playerSide isEqualTo civilian}',
    5
]);

life_actions pushBack (player addAction[
    format ["%1 ($%2)",localize (getText(missionConfigFile >> "Licenses" >> "pilot" >> "displayName")),[(getNumber(missionConfigFile >> "Licenses" >> "pilot" >> "price"))] call life_fnc_numberText],
    life_fnc_buyLicense,
    "pilot",
    8,
    false,
    false,
    "",
    '!dialog && {isNull objectParent player} && {[] call life_fnc_nearDMV} && {!license_civ_pilot} && {playerSide isEqualTo civilian}',
    5
]);

life_actions pushBack (player addAction[
    format ["%1 ($%2)",localize (getText(missionConfigFile >> "Licenses" >> "trucking" >> "displayName")),[(getNumber(missionConfigFile >> "Licenses" >> "trucking" >> "price"))] call life_fnc_numberText],
    life_fnc_buyLicense,
    "trucking",
    8,
    false,
    false,
    "",
    '!dialog && {isNull objectParent player} && {[] call life_fnc_nearDMV} && {!license_civ_trucking} && {playerSide isEqualTo civilian}',
    5
]);

life_actions pushBack (player addAction[
    format ["%1 ($%2)",localize (getText(missionConfigFile >> "Licenses" >> "home" >> "displayName")),[(getNumber(missionConfigFile >> "Licenses" >> "home" >> "price"))] call life_fnc_numberText],
    life_fnc_buyLicense,
    "home",
    8,
    false,
    false,
    "",
    '!dialog && {isNull objectParent player} && {[] call life_fnc_nearDMV} && {!license_civ_home} && {playerSide isEqualTo civilian}',
    5
]);

switch (playerSide) do {

    //Civilian
    case civilian: {
        //Drop fishing net
        life_actions pushBack (player addAction[localize "STR_pAct_DropFishingNet",life_fnc_dropFishingNet,"",0,false,false,"",'
        (surfaceisWater (getPos vehicle player)) && (vehicle player isKindOf "Ship") && life_carryWeight < life_maxWeight && speed (vehicle player) < 2 && speed (vehicle player) > -1 && !life_net_dropped ']);

        //Rob person
        life_actions pushBack (player addAction[localize "STR_pAct_RobPerson",life_fnc_robAction,"",0,false,false,"",'
        !isNull cursorObject && player distance cursorObject < 3.5 && isPlayer cursorObject && animationState cursorObject == "Incapacitated" && !(cursorObject getVariable ["robbed",false]) ']);
    };
    
    //Cops
    case west: { };
    
    //EMS
    case independent: { };

};
