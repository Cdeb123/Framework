/*
    Named law enforcement role framework.

    Departments, ranks, and subdivisions are keyed by stable text identifiers.
    Shops, loadouts, terminals, and database rows should reference these keys
    instead of legacy numeric cop levels.
*/
class Life_LEO {
    defaultDepartment = "kcso";
    commandRanks[] = {"lieutenant","captain","major","undersheriff","sheriff","commissioner"};

    class Citations {
        maxAmount = 250000;
        factionBank = "law_enforcement";
    };

    class Departments {
        class kcso {
            displayName = "Kings County Sheriff's Office";
            shortName = "KCSO";
            side = "cop";
            defaultRank = "cadet";
            defaultSubdivision = "admin_services";
            permissions[] = {"leo.access","leo.department.kcso","police.access"};

            class Ranks {
                class cadet {
                    displayName = "Cadet";
                    order = 0;
                    command = 0;
                    legacyCopLevel = 0;
                    permissions[] = {"leo.training.cadet","leo.training.view"};
                };
                class probationary_deputy {
                    displayName = "Probationary Deputy";
                    order = 1;
                    command = 0;
                    legacyCopLevel = 1;
                    permissions[] = {"leo.access","leo.rank.kcso.probationary_deputy","police.access","police.cuff","police.ticket","police.search","leo.training.view"};
                };
                class deputy {
                    displayName = "Deputy";
                    order = 2;
                    command = 0;
                    legacyCopLevel = 2;
                    permissions[] = {"leo.rank.kcso.deputy","police.warrant"};
                };
                class senior_deputy {
                    displayName = "Senior Deputy";
                    order = 3;
                    command = 0;
                    legacyCopLevel = 3;
                    permissions[] = {"leo.rank.kcso.senior_deputy","police.warrant","leo.training.view"};
                };
                class corporal {
                    displayName = "Corporal";
                    order = 4;
                    command = 0;
                    legacyCopLevel = 4;
                    permissions[] = {"leo.rank.kcso.corporal","leo.supervisor.basic","leo.training.view"};
                };
                class sergeant {
                    displayName = "Sergeant";
                    order = 5;
                    command = 0;
                    legacyCopLevel = 5;
                    permissions[] = {"leo.rank.kcso.sergeant","leo.supervisor.shift","leo.training.view","leo.training.admin_services"};
                };
                class lieutenant {
                    displayName = "Lieutenant";
                    order = 6;
                    command = 1;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.kcso.lieutenant","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.training.view","leo.training.edit","leo.training.admin_services"};
                };
                class captain {
                    displayName = "Captain";
                    order = 7;
                    command = 1;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.kcso.captain","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services"};
                };
                class major {
                    displayName = "Major";
                    order = 8;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.kcso.major","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services"};
                };
                class undersheriff {
                    displayName = "Undersheriff";
                    order = 9;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.kcso.undersheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.department.oversight","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services"};
                };
                class sheriff {
                    displayName = "Sheriff";
                    order = 10;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.kcso.sheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.department.oversight","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services"};
                };
                class commissioner {
                    displayName = "Commissioner";
                    order = 11;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.kcso.commissioner","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.department.oversight","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services"};
                };
            };

            class Subdivisions {
                class kcsu {
                    displayName = "Kings County Sheriff's Office Support Unit";
                    roles[] = {"support_deputy","support_supervisor","support_command"};
                    permissions[] = {"leo.subdivision.kcso.kcsu","leo.support.services"};
                };
                class cid {
                    displayName = "Criminal Investigation Division";
                    roles[] = {"cid_investigator","cid_supervisor","cid_command"};
                    permissions[] = {"leo.subdivision.kcso.cid","leo.investigations.criminal","leo.records.view"};
                };
                class kcia {
                    displayName = "Kings County Internal Affairs Division";
                    parentSubdivision = "cid";
                    roles[] = {"kcia_investigator","kcia_supervisor","kcia_command"};
                    permissions[] = {"leo.subdivision.kcso.kcia","leo.subdivision.kcso.cid","leo.records.internal"};
                };
                class swat {
                    displayName = "Kings County SWAT";
                    roles[] = {"swat_operator","swat_team_lead","swat_command"};
                    permissions[] = {"leo.subdivision.kcso.swat","leo.tactical.swat"};
                };
                class hsu {
                    displayName = "High Speed Unit";
                    roles[] = {"hsu_deputy","hsu_supervisor","hsu_command"};
                    permissions[] = {"leo.subdivision.kcso.hsu","leo.vehicle.hsu"};
                };
                class admin_services {
                    displayName = "Admin Services";
                    roles[] = {"admin_services_trainer","admin_services_supervisor","admin_services_command"};
                    permissions[] = {"leo.subdivision.kcso.admin_services","leo.training.view","leo.training.edit","leo.training.roster","leo.training.admin_services","leo.records.view"};
                };
            };
        };

        class usms {
            displayName = "United States Marshal Service";
            shortName = "USMS";
            side = "cop";
            defaultRank = "deputy_marshal";
            defaultSubdivision = "field_operations";
            permissions[] = {"leo.access","leo.department.usms","police.access"};

            class Ranks {
                class deputy_marshal {
                    displayName = "Deputy U.S. Marshal";
                    order = 1;
                    command = 0;
                    legacyCopLevel = 5;
                    permissions[] = {"leo.rank.usms.deputy_marshal","police.access","police.cuff","police.ticket","police.search","police.warrant"};
                };
                class senior_deputy_marshal {
                    displayName = "Senior Deputy U.S. Marshal";
                    order = 2;
                    command = 0;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.usms.senior_deputy_marshal","leo.federal.usms"};
                };
                class supervisory_deputy_marshal {
                    displayName = "Supervisory Deputy U.S. Marshal";
                    order = 3;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.usms.supervisory_deputy_marshal","leo.command.terminal","leo.command.documents","leo.federal.usms"};
                };
                class chief_deputy_marshal {
                    displayName = "Chief Deputy U.S. Marshal";
                    order = 4;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.usms.chief_deputy_marshal","leo.command.terminal","leo.command.documents","leo.command.executive","leo.federal.usms"};
                };
                class marshal {
                    displayName = "U.S. Marshal";
                    order = 5;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.usms.marshal","leo.command.terminal","leo.command.documents","leo.command.executive","leo.department.oversight","leo.federal.usms"};
                };
            };

            class Subdivisions {
                class field_operations {
                    displayName = "Field Operations";
                    roles[] = {"deputy_marshal","supervisor","command"};
                    permissions[] = {"leo.subdivision.usms.field_operations"};
                };
                class fugitive_task_force {
                    displayName = "Fugitive Task Force";
                    roles[] = {"task_force_operator","task_force_lead","task_force_command"};
                    permissions[] = {"leo.subdivision.usms.fugitive_task_force","leo.federal.fugitives"};
                };
                class judicial_security {
                    displayName = "Judicial Security";
                    roles[] = {"court_security","transport","security_command"};
                    permissions[] = {"leo.subdivision.usms.judicial_security","leo.federal.courts"};
                };
            };
        };

        class dea {
            displayName = "Drug Enforcement Administration";
            shortName = "DEA";
            side = "cop";
            defaultRank = "special_agent";
            defaultSubdivision = "field_operations";
            permissions[] = {"leo.access","leo.department.dea","police.access"};

            class Ranks {
                class special_agent {
                    displayName = "Special Agent";
                    order = 1;
                    command = 0;
                    legacyCopLevel = 5;
                    permissions[] = {"leo.rank.dea.special_agent","police.access","police.cuff","police.ticket","police.search","police.warrant","leo.federal.dea"};
                };
                class senior_special_agent {
                    displayName = "Senior Special Agent";
                    order = 2;
                    command = 0;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.dea.senior_special_agent","leo.investigations.narcotics","leo.federal.dea"};
                };
                class supervisory_special_agent {
                    displayName = "Supervisory Special Agent";
                    order = 3;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.dea.supervisory_special_agent","leo.command.terminal","leo.command.documents","leo.investigations.narcotics","leo.federal.dea"};
                };
                class assistant_special_agent_in_charge {
                    displayName = "Assistant Special Agent in Charge";
                    order = 4;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.dea.assistant_special_agent_in_charge","leo.command.terminal","leo.command.documents","leo.command.executive","leo.federal.dea"};
                };
                class special_agent_in_charge {
                    displayName = "Special Agent in Charge";
                    order = 5;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.dea.special_agent_in_charge","leo.command.terminal","leo.command.documents","leo.command.executive","leo.department.oversight","leo.federal.dea"};
                };
            };

            class Subdivisions {
                class field_operations {
                    displayName = "Field Operations";
                    roles[] = {"special_agent","supervisor","command"};
                    permissions[] = {"leo.subdivision.dea.field_operations"};
                };
                class narcotics_enforcement {
                    displayName = "Narcotics Enforcement";
                    roles[] = {"narcotics_agent","narcotics_supervisor","narcotics_command"};
                    permissions[] = {"leo.subdivision.dea.narcotics_enforcement","leo.investigations.narcotics"};
                };
                class diversion_control {
                    displayName = "Diversion Control";
                    roles[] = {"diversion_investigator","diversion_supervisor","diversion_command"};
                    permissions[] = {"leo.subdivision.dea.diversion_control","leo.investigations.diversion"};
                };
            };
        };

        class fbi {
            displayName = "Federal Bureau of Investigation";
            shortName = "FBI";
            side = "cop";
            defaultRank = "special_agent";
            defaultSubdivision = "field_office";
            permissions[] = {"leo.access","leo.department.fbi","police.access"};

            class Ranks {
                class special_agent {
                    displayName = "Special Agent";
                    order = 1;
                    command = 0;
                    legacyCopLevel = 5;
                    permissions[] = {"leo.rank.fbi.special_agent","police.access","police.cuff","police.ticket","police.search","police.warrant","leo.federal.fbi"};
                };
                class senior_special_agent {
                    displayName = "Senior Special Agent";
                    order = 2;
                    command = 0;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.fbi.senior_special_agent","leo.investigations.federal","leo.federal.fbi"};
                };
                class supervisory_special_agent {
                    displayName = "Supervisory Special Agent";
                    order = 3;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.fbi.supervisory_special_agent","leo.command.terminal","leo.command.documents","leo.investigations.federal","leo.federal.fbi"};
                };
                class assistant_special_agent_in_charge {
                    displayName = "Assistant Special Agent in Charge";
                    order = 4;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.fbi.assistant_special_agent_in_charge","leo.command.terminal","leo.command.documents","leo.command.executive","leo.federal.fbi"};
                };
                class special_agent_in_charge {
                    displayName = "Special Agent in Charge";
                    order = 5;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.fbi.special_agent_in_charge","leo.command.terminal","leo.command.documents","leo.command.executive","leo.department.oversight","leo.federal.fbi"};
                };
            };

            class Subdivisions {
                class field_office {
                    displayName = "Field Office";
                    roles[] = {"special_agent","supervisor","command"};
                    permissions[] = {"leo.subdivision.fbi.field_office"};
                };
                class criminal_investigations {
                    displayName = "Criminal Investigations";
                    roles[] = {"criminal_investigator","criminal_supervisor","criminal_command"};
                    permissions[] = {"leo.subdivision.fbi.criminal_investigations","leo.investigations.federal"};
                };
                class major_case {
                    displayName = "Major Case";
                    roles[] = {"major_case_agent","major_case_supervisor","major_case_command"};
                    permissions[] = {"leo.subdivision.fbi.major_case","leo.investigations.major"};
                };
                class internal_affairs {
                    displayName = "Internal Affairs";
                    roles[] = {"internal_affairs_agent","internal_affairs_supervisor","internal_affairs_command"};
                    permissions[] = {"leo.subdivision.fbi.internal_affairs","leo.records.internal"};
                };
            };
        };
    };
};
