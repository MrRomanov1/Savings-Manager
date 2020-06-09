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
    cin >> name;
    user.setName(name);
    cout << "Podaj swoje nazwisko: ";
    cin >> surname;
    user.setSurname(surname);
    do {
        cout <<"Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    cin >> password;
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
