#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>

#include "Income.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesManager {

    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    string incomesFileName;
    double incomesTotal;

    Income insertNewIncome();
    void writeOutAllIncomes();
public:
    IncomesManager(string incomesFileName, int loggedInUserId):
        fileWithIncomes(incomesFileName), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = fileWithIncomes.loadLoggedInUserIncomesFromFile(LOGGED_IN_USER_ID);
        incomesTotal = 0;
    };
    void addIncome();
    char choseDate();
    void writeOutIncomesByDate(int beginDate, int endDate);
    void sortIncomesByDate();
    double getTotalIncomes();
};

#endif
