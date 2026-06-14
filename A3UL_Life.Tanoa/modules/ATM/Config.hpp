class Life_ATM {
    dailyDepositLimit = 500000;
    maxTransaction = 9999999;
    playerTransferTax = 0.05;

    class FactionBanks {
        class civilian {
            title = "Civilian Treasury";
            side = "civ";
            canDeposit = 1;
            canWithdraw = 0;
        };
        class law_enforcement {
            title = "Law Enforcement Operating Fund";
            side = "cop";
            canDeposit = 1;
            canWithdraw = 0;
        };
        class medical {
            title = "EMS and Fire Operating Fund";
            side = "med";
            canDeposit = 1;
            canWithdraw = 0;
        };
    };
};
