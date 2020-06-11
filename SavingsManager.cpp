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

        //adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, userManager.pobierzIdZalogowanegoUzytkownika());
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
    /*delete adresatMenedzer;
    adresatMenedzer = NULL;*/
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
