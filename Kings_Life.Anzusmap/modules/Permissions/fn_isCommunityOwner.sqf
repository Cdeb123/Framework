#include "..\..\script_macros.hpp"
/*
    File: fn_isCommunityOwner.sqf

    Returns:
    BOOL - true when the local player is listed as a framework owner.
*/
private _uid = getPlayerUID player;
_uid in getArray (missionConfigFile >> "Life_CommunityOwnerGrant" >> "ownerUIDs");
