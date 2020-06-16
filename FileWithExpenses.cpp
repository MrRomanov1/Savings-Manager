#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense) {

    if (!checkIfFileExists()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseID", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", Date::convertDateToStringWithDashes(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount",AuxiliaryMethods::convertDoubleToString(expense.getAmount()));

    lastExpenseId++;

    if (xml.Save("expenses.xml")) {
        return true;
    } else
        return false;
}

vector <Expense> FileWithExpenses::loadLoggedInUserExpensesFromFile(int loggedInUserId) {

    Expense expense;
    vector <Expense> expenses;
    string dane = "";
    xml.ResetPos();

    if (checkIfFileExists()) {

        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Expense")) {

            xml.IntoElem();
            xml.FindElem("UserId");

            if (AuxiliaryMethods::convertStringToInt(xml.GetData()) == loggedInUserId) {

                expense.setUserId(loggedInUserId);
                xml.FindElem("ExpenseID");
                expense.setExpenseId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
                xml.FindElem("Date");
                expense.setDate(Date::convertDateToInt(xml.GetData()));
                xml.FindElem("Item");
                expense.setItem(xml.GetData());
                xml.FindElem("Amount");
                expense.setAmount(AuxiliaryMethods::convertStringToDouble(xml.GetData()));
                expenses.push_back(expense);
            }
            xml.OutOfElem();
            lastExpenseId++;
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}
