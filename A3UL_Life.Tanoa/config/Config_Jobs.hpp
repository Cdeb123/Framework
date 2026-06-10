/*
    Standalone job and permission framework.

    Jobs describe sign-on state. Permissions describe what a player is allowed
    to do. A player can be signed on as one job while retaining permissions from
    ranks, whitelists, Discord roles, or admin grants.
*/
class Life_Jobs {
    class unemployed {
        displayName = "Unemployed";
        side = "";
        conditions = "true";
        permissions[] = {};
    };

    class civilian {
        displayName = "Civilian";
        side = "civ";
        conditions = "playerSide isEqualTo civilian";
        permissions[] = {"civilian.basic"};
    };

    class police {
        displayName = "Law Enforcement";
        side = "cop";
        conditions = "playerSide isEqualTo west && {call life_coplevel > 0}";
        permissions[] = {"police.access","police.cuff","police.ticket","police.warrant","police.search"};
    };

    class ems {
        displayName = "Medical";
        side = "med";
        conditions = "playerSide isEqualTo independent && {call life_mediclevel > 0}";
        permissions[] = {"ems.access","ems.revive","ems.treat"};
    };

    class doj {
        displayName = "Department of Justice";
        side = "civ";
        conditions = "['doj.access'] call life_fnc_hasPermission";
        permissions[] = {"doj.access","doj.records","doj.citation_review"};
    };

    class staff {
        displayName = "Staff";
        side = "";
        conditions = "call life_adminlevel > 0";
        permissions[] = {"staff.access","staff.whitelist","staff.permissions","staff.telemetry"};
    };
};

class Life_DiscordBridge {
    enabled = 1;
    sharedSecret = "CHANGE_ME";
    permissionsTable = "discord_permissions";
    whitelistTable = "steam_whitelist";
};
