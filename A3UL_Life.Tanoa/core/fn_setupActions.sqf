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
    3,
    false,
    true,
    "",
    '!dialog && {isNull objectParent player} && {!(([] call life_fnc_nearestBuildingDoor) isEqualTo [])}'
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
