#include <iostream>
#include "SavingsManager.h"

using namespace std;


int main() {

    char choice;

    SavingsManager savingsManager("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!savingsManager.checkIfUserIsLoggedIn()) {
            choice = savingsManager.choseOptionFromMainMenu();

            switch (choice) {
            case '1':
                savingsManager.registerUser();
                break;
            case '2':
                savingsManager.signInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
                getch();
                break;
            }
        } else {
            choice = savingsManager.choseOptionFromUserMenu();

            switch (choice) {
            case '1':
                savingsManager.addIncome();
                break;
            case '2':
                savingsManager.addExpense();
                break;
            case '3':
                savingsManager.showCurrentMonthBalance();
                break;
            case '4':
                savingsManager.showLastMonthBalance();
                break;
            case '5':
                savingsManager.showChosenPeriodBalance();
                break;
            case '6':
                savingsManager.changeLoggedInUserPassword();
                break;
            case '7':
                savingsManager.signOutUser();
                break;
            }
        }
    }
}
