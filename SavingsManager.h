#ifndef SAVINGSMANAGER_H
#define SAVINGSMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"

using namespace std;

class SavingsManager {

    UserManager userManager;
    IncomesManager *incomesManager;
    const string INCOMES_FILE_NAME;

public:
    SavingsManager(string fileName, string incomesFileName) : userManager(fileName),INCOMES_FILE_NAME(incomesFileName)  {
    incomesManager = NULL;
    }
    ;
    ~SavingsManager() {

        delete incomesManager;
        incomesManager = NULL;
    };
    void registerUser();
    void signInUser();
    void changeLoggedInUserPassword();  //TODO
    bool checkIfUserIsLoggedIn();
    void signOutUser(); //TODO
    void addIncome();   //TODO
    void addExpense();  //TODO
    string setBalancePeriod();  //TODO
    void showBalance(); //TODO
    char choseOptionFromMainMenu();
    char choseOptionFromUserMenu(); //TODO

};

#endif
