#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income) {

    if (!checkIfFileExists()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeID", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", AuxiliaryMethods::convertDateToStringWithDashes(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount",AuxiliaryMethods::convertDoubleToString(income.getAmount()));

    lastIncomeId++;

    if (xml.Save("incomes.xml")) {
        return true;
    }
    else
        return false;
}

vector <Income> FileWithIncomes::loadLoggedInUserIncomesFromFile(int loggedInUserId) {

    Income income;
    vector <Income> incomes;

    xml.ResetPos();
    if (checkIfFileExists()) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.FindChildElem("UserID");
            if ((AuxiliaryMethods::convertStringToInt(xml.GetChildData()) == loggedInUserId)) {

                income.setUserId(loggedInUserId);
                xml.FindChildElem("IncomeID");
                income.setIncomeId(AuxiliaryMethods::convertStringToInt(xml.GetChildData()));
                xml.FindChildElem("Date");
                income.setDate(AuxiliaryMethods::convertStringToInt(xml.GetChildData()));
                xml.FindChildElem("Item");
                income.setItem(xml.GetChildData());
                xml.FindChildElem("Amount");
                income.setAmount(AuxiliaryMethods::convertStringToDouble(xml.GetChildData()));
                incomes.push_back(income);
            }
            lastIncomeId++;
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}
