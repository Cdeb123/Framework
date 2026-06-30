/*
    Configurable building door access.

    Unmatched doors stay public. Add entries under Life_DoorAccess >> Doors for
    police, Fire/EMS, keycard, or keypad-controlled doors.
*/
class Life_DoorAccess {
    doorSearchDistance = 5.0;
    buildingSearchRadius = 14;
    maxFallbackDoors = 40;

    selectionPatterns[] = {
        "Door_%1_trigger",
        "Door_%1_action",
        "Door_%1_button",
        "Door_%1_handle",
        "Door_%1_axis",
        "Door_%1",
        "door_%1_trigger",
        "door_%1_action",
        "door_%1_button",
        "door_%1_handle",
        "door_%1_axis",
        "door_%1",
        "Door%1_trigger",
        "Door%1_action",
        "Door%1",
        "door%1_trigger",
        "door%1_action",
        "door%1"
    };

    sourcePatterns[] = {
        "Door_%1_source",
        "Door_%1_sound_source",
        "Door_%1_noSound_source",
        "Door_%1_Source",
        "Door%1_source",
        "Door%1_Source",
        "door_%1_source",
        "door_%1_sound_source",
        "door_%1_noSound_source",
        "door%1_source",
        "Door_%1",
        "Door%1",
        "door_%1",
        "door%1",
        "Door_%1_Open",
        "door_%1_open",
        "Door%1_Open",
        "door%1_open"
    };

    animationPatterns[] = {
        "door_%1a_move",
        "door_%1_move",
        "door_%1_rot",
        "door_%1a_rot",
        "Door_%1_move",
        "Door_%1_rot",
        "Door_%1",
        "Door%1",
        "door_%1",
        "door%1"
    };

    class Access {
        class public {
            mode = "public";
            label = "Public Access";
            keypad = 0;
            sides[] = {};
            permissions[] = {};
            keycards[] = {};
            codes[] = {};
        };

        class police {
            mode = "permission";
            label = "Police Access";
            keypad = 0;
            sides[] = {"WEST","COP","POLICE"};
            permissions[] = {"police.access","leo.access","leo.department.oversight"};
            keycards[] = {"policeKeycard","commandKeycard"};
            codes[] = {};
        };

        class fire_ems {
            mode = "permission";
            label = "Fire / EMS Access";
            keypad = 0;
            sides[] = {"GUER","INDEPENDENT","MED","EMS","FIRE"};
            permissions[] = {"ems.access","fire.access","medic.access"};
            keycards[] = {"emsKeycard","fireKeycard"};
            codes[] = {};
        };

        class emergency_services {
            mode = "permission";
            label = "Emergency Services";
            keypad = 0;
            sides[] = {"WEST","COP","POLICE","GUER","INDEPENDENT","MED","EMS","FIRE"};
            permissions[] = {"police.access","leo.access","ems.access","fire.access","medic.access","leo.department.oversight"};
            keycards[] = {"policeKeycard","commandKeycard","emsKeycard","fireKeycard"};
            codes[] = {};
        };

        class command {
            mode = "permission";
            label = "Command Access";
            keypad = 0;
            sides[] = {};
            permissions[] = {"leo.command.terminal","leo.department.oversight","leo.department.oversight","staff.permissions"};
            keycards[] = {"commandKeycard"};
            codes[] = {};
        };

        class keycard {
            mode = "keycard";
            label = "Keycard Access";
            keypad = 0;
            sides[] = {};
            permissions[] = {};
            keycards[] = {"policeKeycard","emsKeycard","fireKeycard","commandKeycard"};
            codes[] = {};
        };

        class keypad {
            mode = "keypad";
            label = "Keypad Access";
            keypad = 1;
            sides[] = {};
            permissions[] = {};
            keycards[] = {};
            codes[] = {"0000"};
        };
    };

    class Doors {
        /*
            Examples:

            class PoliceStationFront {
                classnames[] = {"Land_i_Barracks_V2_F"};
                doors[] = {1,2};
                access = "police";
            };

            class FireStationKeypad {
                classnames[] = {"Land_MyMod_FireStation_F"};
                doors[] = {1};
                access = "fire_ems";
                keypad = 1;
                codes[] = {"2468"};
            };

            Leave classnames[] empty to apply a rule to any building, and leave
            doors[] empty to apply it to every detected door on matching classes.

            Placed objects can also override access with variables:
            this setVariable ["life_door_access_1","police",true];
            this setVariable ["life_door_keypad_1",true,true];
            this setVariable ["life_door_codes_1",["2468"],true];
            this setVariable ["life_door_sources_1",["MyDoor_1_Source"],true];
        */
    };
};
