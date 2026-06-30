#define ATM_IDD 2700
#define ATM_BALANCE 2701
#define ATM_AMOUNT 2702
#define ATM_PLAYER_LIST 2703
#define ATM_GANG_LIST 2704
#define ATM_FACTION_LIST 2705
#define ATM_NOTICE 2706

class Life_atm_management {
    idd = ATM_IDD;
    name = "life_atm_menu";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_atmLoad;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.035,0.045,0.050,0.98};
            x = 0.285 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.430 * safezoneW;
            h = 0.640 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.00,0.33,0.38,1};
            x = 0.285 * safezoneW + safezoneX;
            y = 0.170 * safezoneH + safezoneY;
            w = 0.430 * safezoneW;
            h = 0.080 * safezoneH;
        };
        class Screen: Life_RscText {
            idc = -1;
            colorBackground[] = {0.78,0.87,0.82,1};
            x = 0.315 * safezoneW + safezoneX;
            y = 0.285 * safezoneH + safezoneY;
            w = 0.370 * safezoneW;
            h = 0.410 * safezoneH;
        };
        class LeftRail: Life_RscText {
            idc = -1;
            colorBackground[] = {0.10,0.12,0.13,1};
            x = 0.300 * safezoneW + safezoneX;
            y = 0.285 * safezoneH + safezoneY;
            w = 0.010 * safezoneW;
            h = 0.410 * safezoneH;
        };
        class RightRail: Life_RscText {
            idc = -1;
            colorBackground[] = {0.10,0.12,0.13,1};
            x = 0.690 * safezoneW + safezoneX;
            y = 0.285 * safezoneH + safezoneY;
            w = 0.010 * safezoneW;
            h = 0.410 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = -1;
            text = "KINGS COUNTY NATIONAL BANK";
            colorText[] = {0.94,0.98,0.98,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.035;
            x = 0.315 * safezoneW + safezoneX;
            y = 0.190 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.035 * safezoneH;
        };
        class Balance: Life_RscStructuredText {
            idc = ATM_BALANCE;
            text = "";
            x = 0.335 * safezoneW + safezoneX;
            y = 0.305 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.090 * safezoneH;
        };
        class AmountLabel: Life_RscText {
            idc = -1;
            text = "Amount";
            colorText[] = {0.04,0.10,0.10,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.024;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.405 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class Amount: Life_RscEdit {
            idc = ATM_AMOUNT;
            text = "1000";
            sizeEx = 0.030;
            x = 0.415 * safezoneW + safezoneX;
            y = 0.405 * safezoneH + safezoneY;
            w = 0.130 * safezoneW;
            h = 0.032 * safezoneH;
        };
        class DepositButton: Life_RscButtonMenu {
            idc = -1;
            text = "Deposit";
            onButtonClick = "['deposit'] call life_fnc_atmAction";
            x = 0.555 * safezoneW + safezoneX;
            y = 0.402 * safezoneH + safezoneY;
            w = 0.055 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class WithdrawButton: Life_RscButtonMenu {
            idc = -1;
            text = "Withdraw";
            onButtonClick = "['withdraw'] call life_fnc_atmAction";
            x = 0.615 * safezoneW + safezoneX;
            y = 0.402 * safezoneH + safezoneY;
            w = 0.058 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class PlayerList: Life_RscCombo {
            idc = ATM_PLAYER_LIST;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.465 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class PlayerTransferButton: Life_RscButtonMenu {
            idc = -1;
            text = "Send Player";
            onButtonClick = "['player'] call life_fnc_atmAction";
            x = 0.555 * safezoneW + safezoneX;
            y = 0.462 * safezoneH + safezoneY;
            w = 0.118 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class GangList: Life_RscCombo {
            idc = ATM_GANG_LIST;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.525 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class GangTransferButton: Life_RscButtonMenu {
            idc = -1;
            text = "Send Gang";
            onButtonClick = "['gang'] call life_fnc_atmAction";
            x = 0.555 * safezoneW + safezoneX;
            y = 0.522 * safezoneH + safezoneY;
            w = 0.118 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class FactionList: Life_RscCombo {
            idc = ATM_FACTION_LIST;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.585 * safezoneH + safezoneY;
            w = 0.210 * safezoneW;
            h = 0.030 * safezoneH;
        };
        class FactionTransferButton: Life_RscButtonMenu {
            idc = -1;
            text = "Deposit";
            onButtonClick = "['faction'] call life_fnc_atmAction";
            x = 0.555 * safezoneW + safezoneX;
            y = 0.582 * safezoneH + safezoneY;
            w = 0.056 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class FactionWithdrawButton: Life_RscButtonMenu {
            idc = -1;
            text = "Withdraw";
            onButtonClick = "['factionWithdraw'] call life_fnc_atmAction";
            x = 0.617 * safezoneW + safezoneX;
            y = 0.582 * safezoneH + safezoneY;
            w = 0.056 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class Notice: Life_RscStructuredText {
            idc = ATM_NOTICE;
            text = "";
            x = 0.335 * safezoneW + safezoneX;
            y = 0.640 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "$STR_Global_Close";
            onButtonClick = "closeDialog 0";
            x = 0.600 * safezoneW + safezoneX;
            y = 0.640 * safezoneH + safezoneY;
            w = 0.073 * safezoneW;
            h = 0.036 * safezoneH;
        };
    };
};
