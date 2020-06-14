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
    } else
        return false;
}

vector <Income> FileWithIncomes::loadLoggedInUserIncomesFromFile(int loggedInUserId) {

    Income income;
    vector <Income> incomes;
    string dane = "";
    xml.ResetPos();

    if (checkIfFileExists()) {

        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")) {

            xml.IntoElem();
            xml.FindElem("UserId");

            if (AuxiliaryMethods::convertStringToInt(xml.GetData()) == loggedInUserId) {

                income.setUserId(loggedInUserId);
                xml.FindElem("IncomeID");
                income.setIncomeId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
                xml.FindElem("Date");
                income.setDate(AuxiliaryMethods::convertDateToInt(xml.GetData()));
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                income.setAmount(AuxiliaryMethods::convertStringToDouble(xml.GetData()));
                incomes.push_back(income);
            }
            xml.OutOfElem();
            lastIncomeId++;
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}
