class SettingsMenu {
    idd = 2900;
    name = "SettingsMenu";
    movingEnable = 1;
    enableSimulation = 1;

    class controlsBackground {
        class Shadow: Life_RscText {
            idc = -1;
            x = 0.188;
            y = 0.108;
            w = 0.624;
            h = 0.764;
            colorBackground[] = {0,0,0,0.42};
        };

        class Main: Life_RscText {
            idc = -1;
            x = 0.195;
            y = 0.100;
            w = 0.610;
            h = 0.760;
            colorBackground[] = {0.018,0.026,0.034,0.97};
        };

        class TitleBar: Life_RscText {
            idc = -1;
            x = 0.195;
            y = 0.100;
            w = 0.610;
            h = 0.052;
            colorBackground[] = {0.025,0.045,0.058,1};
        };

        class TitleAccent: Life_RscText {
            idc = -1;
            x = 0.195;
            y = 0.100;
            w = 0.006;
            h = 0.760;
            colorBackground[] = {0.16,0.72,0.88,0.95};
        };

        class Title: Life_RscText {
            idc = -1;
            text = "CLIENT SETTINGS";
            font = "RobotoCondensedBold";
            SizeEx = 0.031;
            colorText[] = {0.92,0.97,1,1};
            x = 0.218;
            y = 0.108;
            w = 0.30;
            h = 0.036;
        };

        class Subtitle: Life_RscText {
            idc = -1;
            text = "Saved locally to this player's profile";
            SizeEx = 0.020;
            style = 1;
            colorText[] = {0.48,0.62,0.68,1};
            x = 0.500;
            y = 0.111;
            w = 0.278;
            h = 0.030;
        };

        class GameplayHeader: Life_RscText {
            idc = -1;
            text = "GAMEPLAY & VISIBILITY";
            font = "RobotoCondensedBold";
            SizeEx = 0.022;
            colorText[] = {0.16,0.72,0.88,1};
            colorBackground[] = {0.032,0.046,0.058,0.92};
            x = 0.218;
            y = 0.174;
            w = 0.560;
            h = 0.036;
        };

        class HUDHeader: GameplayHeader {
            text = "HUD & WEAPON DISPLAY";
            y = 0.410;
        };

        class HUDNote: Life_RscText {
            idc = -1;
            text = "Weapon data, ammunition, penetration rating, and stamina are rendered client-side.";
            SizeEx = 0.019;
            colorText[] = {0.48,0.62,0.68,1};
            x = 0.224;
            y = 0.449;
            w = 0.548;
            h = 0.028;
        };

        class FooterLine: Life_RscText {
            idc = -1;
            x = 0.218;
            y = 0.804;
            w = 0.560;
            h = 0.001;
            colorBackground[] = {0.50,0.63,0.68,0.22};
        };
    };

    class controls {
        class Label: Life_RscText {
            idc = -1;
            SizeEx = 0.021;
            colorText[] = {0.82,0.89,0.92,1};
            w = 0.190;
            h = 0.032;
        };

        class OnFootLabel: Label {text = "On-foot view distance"; x = 0.225; y = 0.226;};
        class CarLabel: Label {text = "Vehicle view distance"; x = 0.225; y = 0.274;};
        class AirLabel: Label {text = "Air view distance"; x = 0.225; y = 0.322;};

        class VD_onfoot_slider: life_RscXSliderH {
            idc = 2901;
            onSliderPosChanged = "[0,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip1";
            x = 0.410;
            y = 0.230;
            w = 0.190;
            h = 0.024;
        };

        class VD_onfoot_value: Life_RscEdit {
            idc = 2902;
            onChar = "[_this select 0,_this select 1,'ground',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0,_this select 1,'ground',true] call life_fnc_s_onChar;";
            x = 0.610;
            y = 0.224;
            w = 0.072;
            h = 0.033;
        };

        class VD_car_slider: VD_onfoot_slider {
            idc = 2911;
            onSliderPosChanged = "[1,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip2";
            y = 0.278;
        };

        class VD_car_value: VD_onfoot_value {
            idc = 2912;
            onChar = "[_this select 0,_this select 1,'vehicle',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0,_this select 1,'vehicle',true] call life_fnc_s_onChar;";
            y = 0.272;
        };

        class VD_air_slider: VD_onfoot_slider {
            idc = 2921;
            onSliderPosChanged = "[2,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "$STR_SM_ToolTip3";
            y = 0.326;
        };

        class VD_air_value: VD_onfoot_value {
            idc = 2922;
            onChar = "[_this select 0,_this select 1,'air',false] call life_fnc_s_onChar;";
            onKeyUp = "[_this select 0,_this select 1,'air',true] call life_fnc_s_onChar;";
            y = 0.320;
        };

        class PlayerTagsLabel: Label {text = "Tags"; x = 0.694; y = 0.224; w = 0.075;};
        class SideChatLabel: PlayerTagsLabel {text = "Side chat"; y = 0.264;};
        class RevealLabel: PlayerTagsLabel {text = "Reveal"; y = 0.304;};
        class BroadcastLabel: PlayerTagsLabel {text = "News feed"; y = 0.344;};

        class Toggle: Life_Checkbox {
            idc = -1;
            x = 0.755;
            w = 0.026;
            h = 0.026;
        };

        class PlayerTagsONOFF: Toggle {
            idc = 2970;
            tooltip = "$STR_GUI_PlayTags";
            onCheckedChanged = "['tags',_this select 1] call life_fnc_s_onCheckedChange;";
            y = 0.227;
        };

        class SideChatONOFF: PlayerTagsONOFF {
            idc = 2971;
            tooltip = "$STR_GUI_SideSwitch";
            onCheckedChanged = "['sidechat',_this select 1] call life_fnc_s_onCheckedChange;";
            y = 0.267;
        };

        class RevealONOFF: PlayerTagsONOFF {
            idc = 2972;
            tooltip = "$STR_GUI_PlayerReveal";
            onCheckedChanged = "['objects',_this select 1] call life_fnc_s_onCheckedChange;";
            y = 0.307;
        };

        class BroadcastONOFF: PlayerTagsONOFF {
            idc = 2973;
            tooltip = "$STR_GUI_BroadcastSwitch";
            onCheckedChanged = "['broadcast',_this select 1] call life_fnc_s_onCheckedChange;";
            y = 0.347;
        };

        class WeaponHUDLabel: Label {text = "Weapon HUD"; x = 0.225; y = 0.489;};
        class StaminaHUDLabel: Label {text = "Stamina indicator"; x = 0.225; y = 0.529;};
        class BallisticsHUDLabel: Label {text = "Penetration details"; x = 0.225; y = 0.569;};

        class WeaponHUDToggle: Toggle {
            idc = 2980;
            tooltip = "Show the custom weapon and ammunition panel";
            onCheckedChanged = "['weapon',_this select 1] call life_fnc_hudSettingsChanged;";
            x = 0.385;
            y = 0.492;
        };

        class StaminaHUDToggle: WeaponHUDToggle {
            idc = 2981;
            tooltip = "Show the custom stamina panel";
            onCheckedChanged = "['stamina',_this select 1] call life_fnc_hudSettingsChanged;";
            y = 0.532;
        };

        class BallisticsHUDToggle: WeaponHUDToggle {
            idc = 2982;
            tooltip = "Show the weapon penetration rating";
            onCheckedChanged = "['ballistics',_this select 1] call life_fnc_hudSettingsChanged;";
            y = 0.572;
        };

        class ThemeLabel: Label {text = "Color theme"; x = 0.445; y = 0.489; w = 0.108;};
        class ThemeCombo: Life_RscCombo {
            idc = 2983;
            x = 0.555;
            y = 0.486;
            w = 0.218;
            h = 0.034;
            onLBSelChanged = "if ((_this select 1) >= 0) then {['theme',lbData [2983,_this select 1]] call life_fnc_hudSettingsChanged;}";
        };

        class ScaleLabel: Label {text = "HUD scale"; x = 0.225; y = 0.632; w = 0.120;};
        class ScaleSlider: life_RscXSliderH {
            idc = 2984;
            x = 0.340;
            y = 0.636;
            w = 0.330;
            h = 0.024;
            tooltip = "Scale the custom HUD from 80% to 125%";
            onSliderPosChanged = "['scale',_this select 1] call life_fnc_hudSettingsChanged;";
        };
        class ScaleValue: Label {idc = 2985; text = "100%"; style = 1; x = 0.680; y = 0.632; w = 0.090;};

        class OpacityLabel: ScaleLabel {text = "Panel opacity"; y = 0.681;};
        class OpacitySlider: ScaleSlider {
            idc = 2986;
            y = 0.685;
            tooltip = "Set panel opacity from 45% to 100%";
            onSliderPosChanged = "['opacity',_this select 1] call life_fnc_hudSettingsChanged;";
        };
        class OpacityValue: ScaleValue {idc = 2987; text = "88%"; y = 0.681;};

        class ResetHUD: Life_RscButtonMenu {
            idc = 2988;
            text = "RESET HUD";
            tooltip = "Restore the framework HUD defaults";
            onButtonClick = "['reset',0] call life_fnc_hudSettingsChanged;";
            x = 0.225;
            y = 0.744;
            w = 0.155;
            h = 0.038;
        };

        class ButtonClose: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0;";
            x = 0.618;
            y = 0.818;
            w = 0.160;
            h = 0.034;
        };
    };
};
