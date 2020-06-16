#include "ExpensesManager.h"

void ExpensesManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = insertNewExpense();
    expenses.push_back(expense);
    if (fileWithExpenses.addExpenseToFile(expense)) {
        cout << "Dodano nowy wydatek." << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie udalo sie dodac wydatku do pliku." << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

Expense ExpensesManager::insertNewExpense() {
    Expense expense;

    string date, item;
    int numericDate;
    double amount;
    char choice;

    expense.setExpenseId((fileWithExpenses.getLastExpenseId()+1));
    expense.setUserId(LOGGED_IN_USER_ID);

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
    expense.setDate(numericDate);
    cout << "Podaj zrodlo wydatku: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);
    cout << "Podaj wysokosc wydatku: ";
    amount = AuxiliaryMethods::getDouble();
    expense.setAmount(amount);
    return expense;
}

char ExpensesManager::choseDate() {
    char choice;

    system("cls");
    cout << "Podaj date wydatku:" << endl;
    cout << "---------------------" << endl;
    cout << "1. Dzis" << endl;
    cout << "2. Inny dzien" << endl;
    cout << "---------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getCharacter();

    return choice;
}

void ExpensesManager::sortExpensesByDate() {

    sort(expenses.begin(), expenses.end(), [] ( auto && lhs, auto && rhs ) {
        return lhs.getDate() < rhs.getDate();
    });
}

void ExpensesManager::writeOutExpensesByDate(int beginDate, int endDate) {

    int expenseCounter = 0;
    expensesTotal = 0;
    Expense expense;
    sortExpensesByDate();
    if (!expenses.empty()) {
        cout << "+----------------------------------------------------+" << endl;
        cout << setw(20) << "| Zestawienie wydatkow od " << Date::convertDateToStringWithDashes(beginDate) << " do " << Date::convertDateToStringWithDashes(endDate) << "   |"<<endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << setw(15) << left << "| Data" << setw(20) << left << "Zrodlo wydatku" << setw(15) << left << "Wartosc wydatku   |" << endl;
        cout << "+----------------------------------------------------+" << endl;

        for (vector <Expense>::iterator itr = expenses.begin(); itr < expenses.end(); itr++) {

            if ((itr -> getDate() >= beginDate ) && (itr -> getDate() <= endDate)) {
                cout << "| " <<setw(15) << left << Date::convertDateToStringWithDashes(itr -> getDate()) << setw(20) << left << itr -> getItem() << setw(15) << left << itr -> getAmount() << " |" << endl;
                cout << "+----------------------------------------------------+" << endl;
                expenseCounter++;
                expensesTotal += itr -> getAmount();
            }
        }
        cout << "|" <<setw(15) << left << " SUMA WYDATKOW  " << setw(20) << left << "" << setw(15) << left << expensesTotal << " |"  << endl;
        cout << "+----------------------------------------------------+" << endl;
        if (expenseCounter == 0) {
            cout << "|     Nie posiadasz wydatkow z podanego okresu.      |" << endl;
            cout << "+----------------------------------------------------+" << endl;
        }
    } else {
        cout << "+----------------------------------------------------+" << endl;
        cout << "|     Nie posiadasz zadnych zapisanych wydatkow.     |" << endl;
        cout << "+----------------------------------------------------+" << endl;
    }
}

double ExpensesManager::getTotalExpenses() {
    return expensesTotal;
}
