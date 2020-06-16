#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "Date.h"

using namespace std;

class FileWithExpenses : public XmlFile {

    int lastExpenseId;

    Expense getIncomeData();
    int getUserId();

public:
    FileWithExpenses(string fileName): XmlFile(fileName) {
        lastExpenseId = 0;
    };

    bool addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedInUserExpensesFromFile(int loggedInUserId);
    int getLastExpenseId();
    void setLastExpenseId();

};
#endif
