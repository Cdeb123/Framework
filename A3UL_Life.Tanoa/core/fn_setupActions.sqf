/*
    File: fn_setupActions.sqf
    Author:

    Description:
    Master addAction file handler for all client-based actions.
*/

life_actions = [];

life_actions pushBack (player addAction[
    "License Shop",
    {["License Shop"] call life_fnc_openRadialMenu},
    "",
    8,
    false,
    true,
    "",
    '!dialog && {isNull objectParent player} && {["License Shop"] call life_fnc_hasNearbyInteractionCategory}'
]);

life_actions pushBack (player addAction[
    "Access Shop",
    {["Access Shop"] call life_fnc_openRadialMenu},
    "",
    7,
    false,
    true,
    "",
    '!dialog && {isNull objectParent player} && {["Access Shop"] call life_fnc_hasNearbyInteractionCategory}'
]);

life_actions pushBack (player addAction[
    "Interaction Menu",
    {["main"] call life_fnc_openRadialMenu},
    "",
    6,
    false,
    true,
    "",
    '!dialog && {[] call life_fnc_hasNearbyInteractionCategory}'
]);

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
