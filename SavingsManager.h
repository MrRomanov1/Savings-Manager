#ifndef SAVINGSMANAGER_H
#define SAVINGSMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class SavingsManager {

    UserManager userManager;
    IncomesManager *incomesManager;
    const string INCOMES_FILE_NAME;
    ExpensesManager *expensesManager;
    const string EXPENSES_FILE_NAME;

public:
    SavingsManager(string fileName, string incomesFileName, string expensesFileName) : userManager(fileName),INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        incomesManager = NULL;
        expensesManager = NULL;
    };

    ~SavingsManager() {

        delete incomesManager;
        incomesManager = NULL;
        delete expensesManager;
        expensesManager = NULL;
    };

    void registerUser();
    void signInUser();
    void changeLoggedInUserPassword();
    bool checkIfUserIsLoggedIn();
    void signOutUser();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showChosenPeriodBalance();
    char choseOptionFromMainMenu();
    char choseOptionFromUserMenu();
    void showBalanceTotal();
};

#endif
