#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>

#include "Expense.h"
#include "FileWithExpenses.h"

using namespace std;

class ExpensesManager {

    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    string expensesFileName;
    double expensesTotal;

    Expense insertNewExpense();
    char choseDate();
public:
    ExpensesManager(string expensesFileName, int loggedInUserId):
        fileWithExpenses(expensesFileName), LOGGED_IN_USER_ID(loggedInUserId) {
        expenses = fileWithExpenses.loadLoggedInUserExpensesFromFile(LOGGED_IN_USER_ID);
        expensesTotal = 0;
    };
    void addExpense();
    void writeOutExpensesByDate(int beginDate, int endDate);
    void sortExpensesByDate();
    double getTotalExpenses();
};

#endif
