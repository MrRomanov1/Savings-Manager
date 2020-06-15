#include "IncomesManager.h"

void IncomesManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = insertNewIncome();
    incomes.push_back(income);
    if (fileWithIncomes.addIncomeToFile(income)) {
        cout << "Dodano nowy przychod" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie udalo sie dodac przychodu do pliku." << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

Income IncomesManager::insertNewIncome() {
    Income income;

    string date, item;
    int numericDate;
    double amount;
    char choice;

    income.setIncomeId((fileWithIncomes.getLastIncomeId()+1));
    income.setUserId(LOGGED_IN_USER_ID);

    choice = choseDate();

    switch (choice) {
    case '1':
        date = Date::getCurrentDate();
        break;
    case '2':
        system("cls");
        cout << "Wprowadz date w formacie rrrr-mm-dd w zakresie od 2000-01-01 do konca biezacego miesiaca: ";
        date = Date::getDate();
        break;
    }

    numericDate = Date::convertDateToInt(date);
    income.setDate(numericDate);
    cout << "Podaj zrodlo przychodu: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);
    cout << "Podaj wysokosc przychodu: ";
    amount = AuxiliaryMethods::getDouble();
    income.setAmount(amount);
    return income;
}

char IncomesManager::choseDate() {
    char choice;

    system("cls");
    cout << "Podaj date przychodu:" << endl;
    cout << "---------------------" << endl;
    cout << "1. Dzis" << endl;
    cout << "2. Inny dzien" << endl;
    cout << "---------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getCharacter();

    return choice;
}

void IncomesManager::sortIncomesByDate(){

    sort(incomes.begin(), incomes.end(), [] ( auto && lhs, auto && rhs ) {
        return lhs.getDate() < rhs.getDate();
    });
}

void IncomesManager::writeOutIncomesByDate(int beginDate, int endDate) {

    system("cls");
    int incomeCounter = 0;

    Income income;
    sortIncomesByDate();
    if (!incomes.empty()) {
        cout << "+----------------------------------------------------+" << endl;
        cout << setw(20) << "| Zestawienie przychodow od " << Date::convertDateToStringWithDashes(beginDate) << " do " << Date::convertDateToStringWithDashes(endDate) << " |"<<endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << setw(15) << left << "| Data" << setw(20) << left << "Zrodlo przychodu" << setw(15) << left << "Wartosc przychodu |" << endl;
        cout << "+----------------------------------------------------+" << endl;

        for (vector <Income>::iterator itr = incomes.begin(); itr < incomes.end(); itr++) {

            if ((itr -> getDate() >= beginDate ) && (itr -> getDate() <= endDate)) {
                cout << "| " <<setw(15) << left << Date::convertDateToStringWithDashes(itr -> getDate()) << setw(20) << left << itr -> getItem() << setw(15) << left << itr -> getAmount() << " |" << endl;
                cout << "+----------------------------------------------------+" << endl;
                incomeCounter++;
            }
        }
        if (incomeCounter == 0) {
            cout << "|     Nie posiadasz przychodow z podanego okresu.    |" << endl;
            cout << "+----------------------------------------------------+" << endl;
        }
    } else {
        cout << "+----------------------------------------------+" << endl;
        cout << "| Nie posiadasz zadnych zapisanych przychodow. |" << endl;
        cout << "+----------------------------------------------+" << endl;
    }
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}
