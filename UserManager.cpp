#include "UserManager.h"

void UserManager::registerUser() {

    User user = insertNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

User UserManager::insertNewUserData() {
    User user;

    user.setId(getNewUserId());
    string login, password, name, surname;

    cout << "Podaj swoje imie: ";
    name = AuxiliaryMethods::loadLine();
    user.setName(AuxiliaryMethods::changeFirstLetterToCapitalAndRemainingToLowercase(name));
    cout << "Podaj swoje nazwisko: ";
    surname = AuxiliaryMethods::loadLine();
    user.setSurname(AuxiliaryMethods::changeFirstLetterToCapitalAndRemainingToLowercase(surname));
    do {
        cout <<"Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::checkPasswordRequirements();
    user.setPassword(password);

    return user;
}

bool UserManager::checkIfLoginExists(string login) {

    for (int i=0; i<users.size(); i++) {
        if (users[i].getLogin()==login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::signInUser() {

    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attemptCount = 3; attemptCount > 0; attemptCount--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptCount << ": ";
                password = AuxiliaryMethods::getPassword();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Witaj " << itr -> getName() << "." << endl << endl;
                    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
                    getch();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
            getch();
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
    return;
}

bool UserManager::checkIfUserIsLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

void UserManager::signOutUser() {
    loggedInUserId = 0;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

void UserManager::changeLoggedInUserPassword() {
    system("cls");
    string newPassword = "", oldPassword = "";

    vector <User>::iterator itr = users.begin();
    cout << "Wprowadz nowe haslo, ktore sklada sie z co najmniej 6 znakow (w tym duzej litery i cyfry): " << endl;
    while (itr != users.end()) {
        if (itr -> getId() == loggedInUserId) {
            oldPassword = itr -> getPassword();
            while (true) {

                newPassword = AuxiliaryMethods::checkPasswordRequirements();
                if (newPassword == oldPassword) {
                    system("cls");
                    cout << "Haslo musi roznic sie od poprzedniego. Wprowadz haslo ponownie." << endl;
                } else {
                    system("cls");
                    itr -> setPassword(newPassword);
                    fileWithUsers.changeUserPassword(newPassword, loggedInUserId);
                    cout << "Haslo zostalo zmienione. Nacisnij dowolny przycisk, aby kontynuowac.";
                    getch();
                    return;
                }
            }
        }
    }
}
