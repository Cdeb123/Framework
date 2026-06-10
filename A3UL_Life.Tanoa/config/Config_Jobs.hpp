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

    class leo {
        displayName = "Law Enforcement";
        side = "cop";
        conditions = "playerSide isEqualTo west && {['leo.access'] call life_fnc_hasPermission}";
        permissions[] = {"leo.access","police.access","police.cuff","police.ticket","police.warrant","police.search"};
    };

    class police {
        displayName = "Law Enforcement (Legacy Alias)";
        side = "cop";
        conditions = "playerSide isEqualTo west && {(['leo.access'] call life_fnc_hasPermission) || {call life_coplevel > 0}}";
        permissions[] = {"leo.access","police.access","police.cuff","police.ticket","police.warrant","police.search"};
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

class Life_CommunityOwnerGrant {
    roleName = "Community Owner";
    ownerUIDs[] = {"76561198810688206"};
    adminRank = 5;
    policeRank = 7;
    medicRank = 5;
    permissions[] = {
        "owner.access",
        "owner.community",
        "whitelist.override",
        "jobs.override",
        "civilian.basic",
        "leo.access",
        "leo.department.tcsd",
        "leo.rank.tcsd.sheriff",
        "leo.subdivision.tcsd.patrol",
        "leo.subdivision.tcsd.academy",
        "leo.subdivision.tcsd.hse",
        "leo.subdivision.tcsd.ert",
        "leo.subdivision.tcsd.ia",
        "leo.subdivision.tcsd.mcu",
        "leo.subdivision.tcsd.cid",
        "leo.command.terminal",
        "leo.command.hire",
        "leo.command.fire",
        "leo.command.permissions",
        "leo.command.owner",
        "leo.training.view",
        "leo.training.edit",
        "leo.training.roster",
        "leo.vehicle.hse",
        "leo.tactical.ert",
        "leo.investigations.major",
        "leo.investigations.criminal",
        "leo.records.internal",
        "police.access",
        "police.cuff",
        "police.ticket",
        "police.warrant",
        "police.search",
        "ems.access",
        "ems.revive",
        "ems.treat",
        "doj.access",
        "doj.records",
        "doj.citation_review",
        "staff.access",
        "staff.whitelist",
        "staff.permissions",
        "staff.telemetry"
    };
};

class Life_DiscordBridge {
    enabled = 1;
    sharedSecret = "CHANGE_ME";
    permissionsTable = "discord_permissions";
    whitelistTable = "steam_whitelist";
};
