#include "SavingsManager.h"

void SavingsManager::registerUser() {
    userManager.registerUser();
}

bool SavingsManager::checkIfUserIsLoggedIn() {
    return userManager.checkIfUserIsLoggedIn();
}

void SavingsManager::signInUser() {
    userManager.signInUser();
    if (userManager.checkIfUserIsLoggedIn()) {
        incomesManager = new IncomesManager(INCOMES_FILE_NAME, userManager.getLoggedInUserId());
        expensesManager = new ExpensesManager(EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void SavingsManager::changeLoggedInUserPassword() {
    if (userManager.checkIfUserIsLoggedIn()) {
        userManager.changeLoggedInUserPassword();
    }
}

char SavingsManager::choseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getCharacter();

    return choice;
}

void SavingsManager::signOutUser() {
    userManager.signOutUser();
    delete incomesManager;
    incomesManager = NULL;
    delete expensesManager;
    expensesManager = NULL;
}

char SavingsManager::choseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getCharacter();

    return choice;
}

void SavingsManager::addIncome() {
    if (userManager.checkIfUserIsLoggedIn()) {
        incomesManager->addIncome();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void SavingsManager::addExpense() {
    if (userManager.checkIfUserIsLoggedIn()) {
        expensesManager->addExpense();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void SavingsManager::showCurrentMonthBalance() {

    if (userManager.checkIfUserIsLoggedIn()) {
        int beginDate = Date::getCurrentMonthBegin();
        int endDate = Date::getEndOfCurrentMonth();
        system("cls");
        incomesManager->writeOutIncomesByDate(beginDate, endDate);
        cout << endl;
        expensesManager->writeOutExpensesByDate(beginDate, endDate);
        showBalanceTotal();
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void SavingsManager::showLastMonthBalance() {

    if (userManager.checkIfUserIsLoggedIn()) {
        int beginDate = Date::getLastMonthBegin();
        int endDate = Date::getLastMonthEnd();
        system("cls");
        incomesManager->writeOutIncomesByDate(beginDate, endDate);
        cout << endl;
        expensesManager->writeOutExpensesByDate(beginDate, endDate);
        showBalanceTotal();
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void SavingsManager::showChosenPeriodBalance() {

    if (userManager.checkIfUserIsLoggedIn()) {
        system("cls");
        cout << "Wprowadz date rozpoczecia bilansu w formacie rrrr-mm-dd: ";
        int beginDate = Date::convertDateToInt(Date::getDate());
        cout << "Wprowadz date zakonczenia bilansu w formacie rrrr-mm-dd: ";
        int endDate = Date::convertDateToInt(Date::getDate());
        system("cls");
        incomesManager->writeOutIncomesByDate(beginDate, endDate);
        cout << endl;
        expensesManager->writeOutExpensesByDate(beginDate, endDate);
        showBalanceTotal();
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void SavingsManager::showBalanceTotal() {

    double incomesTotal = incomesManager-> getTotalIncomes();
    double expensesTotal = expensesManager->getTotalExpenses();

    if (incomesTotal != 0 || expensesTotal != 0) {
        double balanceTotal = incomesTotal - expensesTotal;
        cout << endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << "|" <<setw(15) << left << " BILANS Z DANEGO OKRESU" << setw(13) << left << "" << setw(15) << left << balanceTotal << " |"  << endl;
        cout << "+----------------------------------------------------+" << endl;
    }
}
