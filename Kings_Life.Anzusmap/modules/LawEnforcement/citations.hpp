#define CITATION_ISSUE_IDD 8350
#define CITATION_ISSUE_TITLE 8351
#define CITATION_CIV_NAME 8353
#define CITATION_VEHICLE 8355
#define CITATION_PLATE 8357
#define CITATION_OFFENSE 8359
#define CITATION_AMOUNT 8361
#define CITATION_NOTICE 8363

#define CITATION_PAY_IDD 8370
#define CITATION_PAY_DETAILS 8371

#define CITATION_RECORDS_IDD 8390
#define CITATION_RECORDS_LIST 8391
#define CITATION_RECORDS_FILTER 8392
#define CITATION_RECORDS_DETAILS 8393
#define CITATION_RECORDS_COUNT 8394

class life_citation_issue {
    idd = CITATION_ISSUE_IDD;
    name = "life_citation_issue";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_citationLoad;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.012,0.016,0.022,0.96};
            x = 0.265 * safezoneW + safezoneX;
            y = 0.150 * safezoneH + safezoneY;
            w = 0.470 * safezoneW;
            h = 0.700 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.020,0.036,0.048,0.98};
            x = 0.265 * safezoneW + safezoneX;
            y = 0.150 * safezoneH + safezoneY;
            w = 0.470 * safezoneW;
            h = 0.075 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.66,0.84,1};
            x = 0.265 * safezoneW + safezoneX;
            y = 0.150 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.700 * safezoneH;
        };
        class FormFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.38};
            x = 0.295 * safezoneW + safezoneX;
            y = 0.255 * safezoneH + safezoneY;
            w = 0.410 * safezoneW;
            h = 0.468 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = CITATION_ISSUE_TITLE;
            text = "Issue Citation";
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.036;
            x = 0.295 * safezoneW + safezoneX;
            y = 0.169 * safezoneH + safezoneY;
            w = 0.360 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class Subtitle: Life_RscText {
            idc = -1;
            text = "Kings County Citation Form";
            colorText[] = {0.56,0.70,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.021;
            x = 0.297 * safezoneW + safezoneX;
            y = 0.202 * safezoneH + safezoneY;
            w = 0.260 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class FieldLabel: Life_RscText {
            idc = -1;
            text = "Civilian Name";
            colorText[] = {0.66,0.78,0.84,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.315 * safezoneW + safezoneX;
            y = 0.280 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
            h = 0.024 * safezoneH;
        };
        class CivilianName: Life_RscEdit {
            idc = CITATION_CIV_NAME;
            text = "";
            x = 0.315 * safezoneW + safezoneX;
            y = 0.307 * safezoneH + safezoneY;
            w = 0.370 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class VehicleLabel: FieldLabel {
            text = "Car Description";
            y = 0.356 * safezoneH + safezoneY;
        };
        class VehicleDescription: CivilianName {
            idc = CITATION_VEHICLE;
            y = 0.383 * safezoneH + safezoneY;
        };
        class PlateLabel: FieldLabel {
            text = "License Plate";
            y = 0.432 * safezoneH + safezoneY;
        };
        class Plate: CivilianName {
            idc = CITATION_PLATE;
            y = 0.459 * safezoneH + safezoneY;
        };
        class OffenseLabel: FieldLabel {
            text = "Offense";
            y = 0.508 * safezoneH + safezoneY;
        };
        class Offense: CivilianName {
            idc = CITATION_OFFENSE;
            y = 0.535 * safezoneH + safezoneY;
        };
        class AmountLabel: FieldLabel {
            text = "Ticket Amount";
            y = 0.584 * safezoneH + safezoneY;
        };
        class Amount: CivilianName {
            idc = CITATION_AMOUNT;
            text = "500";
            y = 0.611 * safezoneH + safezoneY;
            w = 0.160 * safezoneW;
        };
        class Notice: Life_RscStructuredText {
            idc = CITATION_NOTICE;
            text = "";
            x = 0.315 * safezoneW + safezoneX;
            y = 0.665 * safezoneH + safezoneY;
            w = 0.370 * safezoneW;
            h = 0.045 * safezoneH;
            size = 0.021;
        };
        class SubmitButton: Life_RscButtonMenu {
            idc = -1;
            text = "Submit Citation";
            onButtonClick = "[] call life_fnc_citationSubmit";
            x = 0.315 * safezoneW + safezoneX;
            y = 0.760 * safezoneH + safezoneY;
            w = 0.145 * safezoneW;
            h = 0.042 * safezoneH;
        };
        class RecordsButton: Life_RscButtonMenu {
            idc = -1;
            text = "Records";
            onButtonClick = "closeDialog 0; [] spawn {uiSleep 0.05; [] call life_fnc_openCitationRecords;}";
            x = 0.480 * safezoneW + safezoneX;
            y = 0.760 * safezoneH + safezoneY;
            w = 0.090 * safezoneW;
            h = 0.042 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.590 * safezoneW + safezoneX;
            y = 0.760 * safezoneH + safezoneY;
            w = 0.095 * safezoneW;
            h = 0.042 * safezoneH;
        };
    };
};

class life_citation_pay {
    idd = CITATION_PAY_IDD;
    name = "life_citation_pay";
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.012,0.016,0.022,0.96};
            x = 0.305 * safezoneW + safezoneX;
            y = 0.195 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.520 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.020,0.036,0.048,0.98};
            x = 0.305 * safezoneW + safezoneX;
            y = 0.195 * safezoneH + safezoneY;
            w = 0.390 * safezoneW;
            h = 0.070 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.66,0.84,1};
            x = 0.305 * safezoneW + safezoneX;
            y = 0.195 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.520 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = -1;
            text = "Citation Received";
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.036;
            x = 0.335 * safezoneW + safezoneX;
            y = 0.215 * safezoneH + safezoneY;
            w = 0.310 * safezoneW;
            h = 0.036 * safezoneH;
        };
        class Details: Life_RscStructuredText {
            idc = CITATION_PAY_DETAILS;
            text = "";
            x = 0.335 * safezoneW + safezoneX;
            y = 0.295 * safezoneH + safezoneY;
            w = 0.330 * safezoneW;
            h = 0.300 * safezoneH;
            size = 0.024;
        };
        class PayButton: Life_RscButtonMenu {
            idc = -1;
            text = "Pay Now";
            onButtonClick = "[] call life_fnc_citationPay";
            x = 0.335 * safezoneW + safezoneX;
            y = 0.645 * safezoneH + safezoneY;
            w = 0.145 * safezoneW;
            h = 0.042 * safezoneH;
        };
        class DeclineButton: Life_RscButtonMenu {
            idc = -1;
            text = "Decline";
            onButtonClick = "[] call life_fnc_citationDecline";
            x = 0.520 * safezoneW + safezoneX;
            y = 0.645 * safezoneH + safezoneY;
            w = 0.145 * safezoneW;
            h = 0.042 * safezoneH;
        };
    };
};

class life_citation_records {
    idd = CITATION_RECORDS_IDD;
    name = "life_citation_records";
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = "[] spawn {uiSleep 0.01; [] call life_fnc_citationRecordsLoad;}";

    class controlsBackground {
        class Back: Life_RscText {
            idc = -1;
            colorBackground[] = {0.010,0.014,0.020,0.96};
            x = 0.140 * safezoneW + safezoneX;
            y = 0.130 * safezoneH + safezoneY;
            w = 0.720 * safezoneW;
            h = 0.720 * safezoneH;
        };
        class Header: Life_RscText {
            idc = -1;
            colorBackground[] = {0.018,0.030,0.040,0.98};
            x = 0.140 * safezoneW + safezoneX;
            y = 0.130 * safezoneH + safezoneY;
            w = 0.720 * safezoneW;
            h = 0.080 * safezoneH;
        };
        class Accent: Life_RscText {
            idc = -1;
            colorBackground[] = {0.0,0.72,0.92,1};
            x = 0.140 * safezoneW + safezoneX;
            y = 0.130 * safezoneH + safezoneY;
            w = 0.004 * safezoneW;
            h = 0.720 * safezoneH;
        };
        class ListFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.38};
            x = 0.165 * safezoneW + safezoneX;
            y = 0.245 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.470 * safezoneH;
        };
        class DetailFrame: Life_RscFrame {
            idc = -1;
            colorText[] = {0.0,0.72,0.92,0.38};
            x = 0.485 * safezoneW + safezoneX;
            y = 0.245 * safezoneH + safezoneY;
            w = 0.350 * safezoneW;
            h = 0.470 * safezoneH;
        };
    };

    class controls {
        class Title: Life_RscText {
            idc = -1;
            text = "Citation Records";
            colorText[] = {0.94,0.99,1,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.038;
            x = 0.170 * safezoneW + safezoneX;
            y = 0.151 * safezoneH + safezoneY;
            w = 0.300 * safezoneW;
            h = 0.038 * safezoneH;
        };
        class Count: Life_RscText {
            idc = CITATION_RECORDS_COUNT;
            text = "";
            colorText[] = {0.56,0.70,0.78,1};
            colorBackground[] = {0,0,0,0};
            sizeEx = 0.022;
            x = 0.505 * safezoneW + safezoneX;
            y = 0.158 * safezoneH + safezoneY;
            w = 0.250 * safezoneW;
            h = 0.026 * safezoneH;
        };
        class Filter: Life_RscEdit {
            idc = CITATION_RECORDS_FILTER;
            text = "";
            x = 0.165 * safezoneW + safezoneX;
            y = 0.218 * safezoneH + safezoneY;
            w = 0.220 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class SearchButton: Life_RscButtonMenu {
            idc = -1;
            text = "Search";
            onButtonClick = "[] call life_fnc_citationRecordsLoad";
            x = 0.395 * safezoneW + safezoneX;
            y = 0.218 * safezoneH + safezoneY;
            w = 0.070 * safezoneW;
            h = 0.034 * safezoneH;
        };
        class RecordList: Life_RscListBox {
            idc = CITATION_RECORDS_LIST;
            x = 0.176 * safezoneW + safezoneX;
            y = 0.270 * safezoneH + safezoneY;
            w = 0.278 * safezoneW;
            h = 0.420 * safezoneH;
            sizeEx = 0.025;
            onLBSelChanged = "[] call life_fnc_citationRecordsSelect";
        };
        class Details: Life_RscStructuredText {
            idc = CITATION_RECORDS_DETAILS;
            text = "";
            x = 0.505 * safezoneW + safezoneX;
            y = 0.270 * safezoneH + safezoneY;
            w = 0.310 * safezoneW;
            h = 0.420 * safezoneH;
            size = 0.025;
        };
        class RefreshButton: Life_RscButtonMenu {
            idc = -1;
            text = "Refresh";
            onButtonClick = "[] call life_fnc_citationRecordsLoad";
            x = 0.176 * safezoneW + safezoneX;
            y = 0.755 * safezoneH + safezoneY;
            w = 0.105 * safezoneW;
            h = 0.040 * safezoneH;
        };
        class CloseButton: Life_RscButtonMenu {
            idc = -1;
            text = "Close";
            onButtonClick = "closeDialog 0";
            x = 0.710 * safezoneW + safezoneX;
            y = 0.755 * safezoneH + safezoneY;
            w = 0.105 * safezoneW;
            h = 0.040 * safezoneH;
        };
    };
};
