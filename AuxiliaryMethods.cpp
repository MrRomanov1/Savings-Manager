#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int liczbaInt;
    istringstream iss(number);
    iss >> liczbaInt;

    return liczbaInt;
}

string AuxiliaryMethods::loadLine() {
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::changeFirstLetterToCapitalAndRemainingToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::getInteger() {
    string input = "";
    int number = 0;
    cin.sync();
    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

char AuxiliaryMethods::getCharacter() {
    string input = "";
    char character  = {0};
    cin.sync();
    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::checkPasswordRequirements() {

    string password = "";
    cin.sync();
    int passwordLength = 0;

    while (true) {
        getline(cin, password);
        passwordLength = password.length();
        int digits = 0;
        int uppercase = 0;

        if (passwordLength < 6) {
            cout << "Wprowadzone haslo jest za krotkie. Wprowadz haslo ponownie: " << endl;
        } else {

            for (int i = 0; i < passwordLength; i++) {
                if (isdigit (password [i])) {
                    digits++;
                } else if (isupper (password [i])) {
                    uppercase++;
                }
            }
            if ( (digits < 1 ) || ( uppercase < 1) ) {
                cout << "Wprowadzone haslo nie zawiera wielkiej litery lub cyfer. Wprowadz haslo ponownie: " << endl;
            } else
                break;
        }
    }
    return password;
}
