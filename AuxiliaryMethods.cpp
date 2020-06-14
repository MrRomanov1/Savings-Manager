#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxiliaryMethods::convertStringToDouble(string number) {

    double numberDouble;
    numberDouble = stod(number);

    return numberDouble;
}

string AuxiliaryMethods::convertDoubleToString (double number) {

    ostringstream strs;
    strs << number;
    setprecision(2);
    string numberDouble = strs.str();
    return numberDouble;
}

double AuxiliaryMethods::getDouble() {
    cin.sync();
    string input = "";
    double numberDouble;
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            input[i] = '.';
        }
    }
    numberDouble = convertStringToDouble(input);
    return numberDouble;
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

string AuxiliaryMethods::getCurrentDate() {

    time_t theTime;
    struct tm * date;
    char currentDate [80];

    time( & theTime );
    date = localtime( & theTime );
    strftime(currentDate, 80, "%Y-%m-%d", date);

    return currentDate;
}

int AuxiliaryMethods::convertDateToInt(string date) {

    string dateWithoutDashes = "";

    for (int i = 0; i < date.length(); i++) {
        if (date[i] != '-') {
            dateWithoutDashes += date[i];
        }
    }
    int convertedDate = convertStringToInt(dateWithoutDashes);

    return convertedDate;
}

string AuxiliaryMethods::convertDateToStringWithDashes(int date) {

    string temporaryDate = convertIntToString(date);
    string stringDate = "";

    for (int i = 0; i < temporaryDate.length(); i++) {
        if (i == 4 || i == 6 || i == 8) {
            stringDate += "-";
        }
        stringDate += temporaryDate[i];
    }

    return stringDate;
}

string AuxiliaryMethods::getDate() {

    int dateChecker = 0;
    int dateInInt = 0;

    while (true) {

        string date = loadLine();

        for (int i = 0; i < date.length(); i++) {
            if (i == 4 && date[i] == '-') {
                dateChecker++;
            } else if (i == 7 && date[i] == '-') {
                dateChecker++;
            }
        }
        if (dateChecker < 2) {
            cout << "Wprowadzono nieprawidlowa date. Wprowadz ponownie date w formacie rrrr-mm-dd: " << endl;
        } else {
            if (checkIfDateIsValid(date)) {
                dateInInt = convertDateToInt(date);
                if (dateInInt < 20000101 || dateInInt > getEndOfCurrentMonth()) {
                    cout << "Wprowadzono nieprawidlowa date. Wprowadz ponownie date w zakresie od 2000-01-01 do konca biezacego miesiaca: " << endl;
                } else {
                    return date;
                }
            } else {
                cout << "Wprowadzono nieprawidlowa date. Wprowadz ponownie: " << endl;
            }
        }
    }
}

int AuxiliaryMethods::getEndOfCurrentMonth() {

    int lastDay, month, year;
    string currentDate = getCurrentDate();
    string days = "";
    string years = "";
    string months = "";
    string boundaryDate = "";

    for (int i = 0; i < currentDate.length(); i++) {
        if (i < 4) {
            years = years + currentDate[i];
        } else if (i == 5 || i == 6) {
            months = months + currentDate[i];
        } else if ( i == 8 || i == 9) {
            days = days + currentDate[i];
        }
    }
    month = convertStringToInt(months);
    year = convertStringToInt(years);
    lastDay = getLastDayOfTheMonth (month, year);

    boundaryDate = boundaryDate + years + months + convertIntToString(lastDay);

    int boundaryNumericDate = convertStringToInt(boundaryDate);

    return boundaryNumericDate;
}

int AuxiliaryMethods::getLastDayOfTheMonth(int month, int year) {

    int lastDay = 0;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        lastDay = 30;

    else if (month == 2) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
            lastDay = 28;
        else
            lastDay = 29;
    } else
        lastDay = 31;

    return lastDay;
}

bool AuxiliaryMethods::checkIfDateIsValid(string date) {

    int lastDay, month, year, day;
    string days = "";
    string years = "";
    string months = "";
    string boundaryDate = "";

    for (int i = 0; i < date.length(); i++) {
        if (i < 4) {
            years = years + date[i];
        } else if (i == 5 || i == 6) {
            months = months + date[i];
        } else if ( i == 8 || i == 9) {
            days = days + date[i];
        }
    }
    month = convertStringToInt(months);
    year = convertStringToInt(years);
    day = convertStringToInt(days);

    lastDay = getLastDayOfTheMonth (month, year);

    if (day > lastDay || day <= 0) {
        return false;
    } else if (month > 12 || month <= 0) {
        return false;
    } else
        return true;
}

int AuxiliaryMethods::getCurrentMonthBegin() {

    string currentDate = getCurrentDate();
    string days = "01";
    string years = "";
    string months = "";
    string boundaryDate = "";

    for (int i = 0; i < currentDate.length(); i++) {
        if (i < 4) {
            years = years + currentDate[i];
        } else if (i == 5 || i == 6) {
            months = months + currentDate[i];
        }
    }
    boundaryDate = years+months+days;
    int boundaryNumericDate = convertStringToInt(boundaryDate);
    return boundaryNumericDate;
}
