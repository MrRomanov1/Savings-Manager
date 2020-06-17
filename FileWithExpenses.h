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

public:
    FileWithExpenses(string fileName): XmlFile(fileName) {
        lastExpenseId = 0;
    };

    bool addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedInUserExpensesFromFile(int loggedInUserId);
    int getLastExpenseId();
};
#endif
