#ifndef SAVINGSMANAGER_H
#define SAVINGSMANAGER_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class SavingsManager {

    UserManager userManager;

    /*SavingsManager() {}
    ;
    ~SavingsManager() {
    };*/
public:
    void registerUser();
    void signInUser();      //TODO
    void changeLoggedInUserPassword();  //TODO
    bool checkIfUserIsLoggedIn();   //TODO
    void signOutUser(); //TODO
    void addIncome();   //TODO
    void addExpense();  //TODO
    string setBalancePeriod();  //TODO
    void showBalance(); //TODO
    char choseOptionFromMainMenu(); //TODO
    char choseOptionFromUserMenu(); //TODO

};

#endif
