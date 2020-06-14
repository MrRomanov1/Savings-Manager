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
        cout << "Nie udalo sie dodac adresata do pliku." << endl;
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

    cout << "Podaj date przychodu: ";

    choice = choseDate();

    switch (choice) {
    case '1':
        date = AuxiliaryMethods::getCurrentDate();
        break;
    case '2':
        system("cls");
        cout << "Wprowadz date w formacie rrrr-mm-dd w zakresie od 2000-01-01 do konca biezacego miesiaca: ";
        date = AuxiliaryMethods::getDate();
        break;
    }

    numericDate = AuxiliaryMethods::convertDateToInt(date);
    income.setDate(numericDate);
    cout << "Podaj czego dotyczy przychod: ";
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
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dzis" << endl;
    cout << "2. Inny dzien" << endl;
    cout << "---------------------------" << endl;
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

    Income income;
    sortIncomesByDate();

    for (vector <Income>::iterator itr = incomes.begin(); itr < incomes.end(); itr++) {

        if ((itr -> getDate() >= beginDate ) && (itr -> getDate() <= endDate)) {
            cout << AuxiliaryMethods::convertDateToStringWithDashes(itr -> getDate()) << endl << itr -> getAmount() << endl;
        }
    }
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}
