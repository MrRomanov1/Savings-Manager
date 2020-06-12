#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    int lastIncomeId;

    Income getIncomeData();
    int getUserId();

public:
    FileWithIncomes(string fileName): XmlFile(fileName) {
        lastIncomeId = 0;
    };

    bool addIncomeToFile(Income income);
    vector <Income> loadLoggedInUserIncomesFromFile(int loggedInUserId);
    int getLastIncomeId();
    void setLastIncomeId();

};
#endif
