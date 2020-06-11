#include <iostream>
#include "SavingsManager.h"

using namespace std;


int main() {

    char choice;

    SavingsManager savingsManager("users.xml");

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
                ;
                break;
            case '2':
                ;
                break;
            case '3':
                ;
                break;
            case '4':
                ;
                break;
            case '5':
                ;
                break;
            case '6':
                ;
                break;
            case '7':
                savingsManager.signOutUser();
                break;
            }
        }
    }
}
