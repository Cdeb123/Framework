class Life_VehicleControls {
    enabled = 1;

    // Direct controls. F1 always exposes the same actions for discoverability.
    contextDoorKey = 219;       // Left Windows
    leftSignalKey = 26;         // [
    rightSignalKey = 27;        // ]
    hazardSignalKey = 43;       // Backslash key
    backupCameraKey = 19;       // Ctrl + R

    signalInterval = 0.46;
    signalFallbackLights = 1;
    signalAutoDetectSources = 1;
    leftSignalSources[] = {"turn_left","signal_left","indicator_left","blinker_left","indicators_left"};
    rightSignalSources[] = {"turn_right","signal_right","indicator_right","blinker_right","indicators_right"};

    // Add modded class names here. A vehicle can also opt in at runtime with
    // vehicle setVariable ["life_backup_camera",true,true].
    backupCameraVehicles[] = {
        "C_SUV_01_F",
        "C_Hatchback_01_sport_F",
        "C_Van_01_box_F",
        "I_Truck_02_covered_F",
        "B_Truck_01_box_F",
        "AG_CROWNVIC_Police_AG",
        "AG_CROWNVIC_Police_ST_AG",
        "AG_CROWNVIC_UNM_AG_TIER3",
        "AG_Bearcat_KCSO_AG",
        "AG_Titan_Police_AG",
        "AG_Camaro_21_HSU_AG_TIER3",
        "AG_CTSV_AdminServices_AG_TIER3"
    };
};
