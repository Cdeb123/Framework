/*
    Named law enforcement role framework.

    Departments, ranks, and subdivisions are keyed by stable text identifiers.
    Shops, loadouts, terminals, and database rows should reference these keys
    instead of legacy numeric cop levels.
*/
class Life_LEO {
    defaultDepartment = "tcsd";
    commandRanks[] = {"lieutenant","captain","assistant_sheriff","undersheriff","sheriff"};

    class Departments {
        class tcsd {
            displayName = "Tanoa County Sheriff's Department";
            shortName = "TCSD";
            side = "cop";
            defaultRank = "deputy";
            defaultSubdivision = "academy";
            permissions[] = {"leo.access","leo.department.tcsd","police.access"};

            class Ranks {
                class deputy {
                    displayName = "Deputy";
                    order = 1;
                    command = 0;
                    legacyCopLevel = 1;
                    permissions[] = {"leo.access","leo.rank.tcsd.deputy","police.access","police.cuff","police.ticket","police.search"};
                };
                class senior_deputy {
                    displayName = "Senior Deputy";
                    order = 2;
                    command = 0;
                    legacyCopLevel = 2;
                    permissions[] = {"leo.rank.tcsd.senior_deputy","police.warrant"};
                };
                class corporal {
                    displayName = "Corporal";
                    order = 3;
                    command = 0;
                    legacyCopLevel = 3;
                    permissions[] = {"leo.rank.tcsd.corporal","leo.supervisor.basic"};
                };
                class detective {
                    displayName = "Detective";
                    order = 4;
                    command = 0;
                    legacyCopLevel = 3;
                    permissions[] = {"leo.rank.tcsd.detective","leo.investigations.basic","leo.records.view"};
                };
                class sergeant {
                    displayName = "Sergeant";
                    order = 5;
                    command = 0;
                    legacyCopLevel = 4;
                    permissions[] = {"leo.rank.tcsd.sergeant","leo.supervisor.shift","leo.training.view"};
                };
                class lieutenant {
                    displayName = "Lieutenant";
                    order = 6;
                    command = 1;
                    legacyCopLevel = 5;
                    permissions[] = {"leo.rank.tcsd.lieutenant","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.training.edit"};
                };
                class captain {
                    displayName = "Captain";
                    order = 7;
                    command = 1;
                    legacyCopLevel = 6;
                    permissions[] = {"leo.rank.tcsd.captain","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.training.roster"};
                };
                class assistant_sheriff {
                    displayName = "Assistant Sheriff";
                    order = 8;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.tcsd.assistant_sheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.training.view","leo.training.edit","leo.training.roster"};
                };
                class undersheriff {
                    displayName = "Undersheriff";
                    order = 9;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.tcsd.undersheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.training.view","leo.training.edit","leo.training.roster"};
                };
                class sheriff {
                    displayName = "Sheriff";
                    order = 10;
                    command = 1;
                    legacyCopLevel = 7;
                    permissions[] = {"leo.rank.tcsd.sheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.ranks","leo.command.divisions","leo.command.roles","leo.command.documents","leo.command.executive","leo.command.owner","leo.department.oversight","leo.training.view","leo.training.edit","leo.training.roster","staff.whitelist","staff.permissions"};
                };
            };

            class Subdivisions {
                class patrol {
                    displayName = "Patrol Operations";
                    roles[] = {"patrol_deputy","patrol_supervisor","patrol_command"};
                    permissions[] = {"leo.subdivision.tcsd.patrol"};
                };
                class academy {
                    displayName = "Training Academy";
                    roles[] = {"recruit","field_training_officer","academy_supervisor"};
                    permissions[] = {"leo.subdivision.tcsd.academy","leo.training.view","leo.training.edit","leo.training.roster","leo.training.fto","leo.records.view"};
                };
                class hse {
                    displayName = "Traffic Enforcement Unit";
                    roles[] = {"hse_deputy","hse_supervisor","hse_command"};
                    permissions[] = {"leo.subdivision.tcsd.hse","leo.vehicle.hse"};
                };
                class ert {
                    displayName = "Emergency Response Unit";
                    roles[] = {"ert_operator","ert_team_lead","ert_command"};
                    permissions[] = {"leo.subdivision.tcsd.ert","leo.tactical.ert"};
                };
                class ia {
                    displayName = "Internal Affairs";
                    roles[] = {"ia_investigator","ia_supervisor","ia_command"};
                    permissions[] = {"leo.subdivision.tcsd.ia","leo.records.internal"};
                };
                class mcu {
                    displayName = "Major Crimes Unit";
                    roles[] = {"mcu_detective","mcu_lead","mcu_command"};
                    permissions[] = {"leo.subdivision.tcsd.mcu","leo.investigations.major"};
                };
                class cid {
                    displayName = "Criminal Investigations Bureau";
                    roles[] = {"cid_detective","cid_supervisor","cid_command"};
                    permissions[] = {"leo.subdivision.tcsd.cid","leo.investigations.criminal"};
                };
            };
        };

        class thp {
            displayName = "Tanoa Highway Patrol";
            shortName = "THP";
            side = "cop";
            defaultRank = "trooper";
            defaultSubdivision = "patrol";
            permissions[] = {"leo.access","leo.department.thp","police.access"};
            ranks[] = {"trooper","senior_trooper","corporal","sergeant","lieutenant","captain","chief"};
            subdivisions[] = {"patrol","high_speed_enforcement","commercial_vehicle"};
        };

        class usms {
            displayName = "United States Marshal Service";
            shortName = "USMS";
            side = "cop";
            defaultRank = "deputy_marshal";
            defaultSubdivision = "field_operations";
            permissions[] = {"leo.access","leo.department.usms","police.access"};
            ranks[] = {"deputy_marshal","senior_deputy_marshal","supervisory_deputy","chief_deputy","marshal"};
            subdivisions[] = {"field_operations","fugitive_task_force","judicial_security"};
        };

        class fbi {
            displayName = "Federal Bureau of Investigation";
            shortName = "FBI";
            side = "cop";
            defaultRank = "special_agent";
            defaultSubdivision = "field_office";
            permissions[] = {"leo.access","leo.department.fbi","police.access"};
            ranks[] = {"special_agent","senior_special_agent","supervisory_special_agent","assistant_special_agent_in_charge","special_agent_in_charge"};
            subdivisions[] = {"field_office","criminal_investigations","major_case","internal_affairs"};
        };
    };
};
