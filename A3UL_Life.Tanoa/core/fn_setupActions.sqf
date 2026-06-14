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
    true,
    true,
    "",
    '!dialog && {isNull objectParent player} && {isNull cursorObject || {player distance cursorObject > 4} || {!((cursorObject isKindOf "CAManBase") || {cursorObject isKindOf "LandVehicle"} || {cursorObject isKindOf "Ship"} || {cursorObject isKindOf "Air"} || {cursorObject isKindOf "ReammoBox_F"} || {(typeOf cursorObject) in ["Land_BottlePlastic_V1_F","Land_TacticalBacon_F","Land_Can_V3_F","Land_CanisterFuel_F","Land_Suitcase_F","Land_Money_F","Land_Atm_01_F","Land_Atm_02_F"]})}} && {!(([] call life_fnc_nearestBuildingDoor) isEqualTo [])}'
]);

life_actions pushBack (player addAction[
    "Vehicle Interaction",
    {[cursorObject] call life_fnc_vInteractionMenu},
    "",
    0,
    true,
    true,
    "",
    '!dialog && {isNull objectParent player} && {!isNull cursorObject} && {(cursorObject isKindOf "LandVehicle") || {cursorObject isKindOf "Ship"} || {cursorObject isKindOf "Air"}} && {player distance cursorObject < (((boundingBox cursorObject) select 1) select 0) + 2} && {!(player getVariable ["restrained",false])} && {!(player getVariable ["playerSurrender",false])} && {!life_isknocked} && {!life_istazed}'
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
