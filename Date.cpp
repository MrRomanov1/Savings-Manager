#include "Date.h"

string Date::getCurrentDate() {

    time_t theTime;
    struct tm * date;
    char currentDate [80];

    time( & theTime );
    date = localtime( & theTime );
    strftime(currentDate, 80, "%Y-%m-%d", date);

    return currentDate;
}

int Date::convertDateToInt(string date) {

    string dateWithoutDashes = "";

    for (int i = 0; i < date.length(); i++) {
        if (date[i] != '-') {
            dateWithoutDashes += date[i];
        }
    }
    int convertedDate = AuxiliaryMethods::convertStringToInt(dateWithoutDashes);

    return convertedDate;
}

string Date::convertDateToStringWithDashes(int date) {

    string temporaryDate = AuxiliaryMethods::convertIntToString(date);
    string stringDate = "";

    for (int i = 0; i < temporaryDate.length(); i++) {
        if (i == 4 || i == 6 || i == 8) {
            stringDate += "-";
        }
        stringDate += temporaryDate[i];
    }

    return stringDate;
}

string Date::getDate() {

    int dateChecker = 0;
    int dateInInt = 0;

    while (true) {

        string date = AuxiliaryMethods::loadLine();

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

int Date::getEndOfCurrentMonth() {

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
    month = AuxiliaryMethods::convertStringToInt(months);
    year = AuxiliaryMethods::convertStringToInt(years);
    lastDay = getLastDayOfTheMonth (month, year);

    boundaryDate = boundaryDate + years + months + AuxiliaryMethods::convertIntToString(lastDay);

    int boundaryNumericDate = AuxiliaryMethods::convertStringToInt(boundaryDate);

    return boundaryNumericDate;
}

int Date::getLastDayOfTheMonth(int month, int year) {

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

bool Date::checkIfDateIsValid(string date) {

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
    month = AuxiliaryMethods::convertStringToInt(months);
    year = AuxiliaryMethods::convertStringToInt(years);
    day = AuxiliaryMethods::convertStringToInt(days);

    lastDay = getLastDayOfTheMonth (month, year);

    if (day > lastDay || day <= 0) {
        return false;
    } else if (month > 12 || month <= 0) {
        return false;
    } else
        return true;
}

int Date::getCurrentMonthBegin() {

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
    int boundaryNumericDate = AuxiliaryMethods::convertStringToInt(boundaryDate);
    return boundaryNumericDate;
}

int Date::getLastMonthBegin() {

    int sameDayLastMonth =  convertDateToInt(getCurrentDate()) - 100;
    string lastMonthDate = convertDateToStringWithDashes(sameDayLastMonth);

    lastMonthDate[8] = '0';
    lastMonthDate[9] = '1';

    int lastMonthBegin = convertDateToInt(lastMonthDate);
    return lastMonthBegin;
}

int Date::getLastMonthEnd() {

    string lastMonthBegin = convertDateToStringWithDashes(getLastMonthBegin());

    string days = "";
    string years = "";
    string months = "";
    int lastDay, month, year;

    for (int i = 0; i < lastMonthBegin.length(); i++) {
        if (i < 4) {
            years = years + lastMonthBegin[i];
        } else if (i == 5 || i == 6) {
            months = months + lastMonthBegin[i];
        }
    }
    month = AuxiliaryMethods::convertStringToInt(months);
    year = AuxiliaryMethods::convertStringToInt(years);
    lastDay = getLastDayOfTheMonth (month, year);

    int lastMonthEnd = AuxiliaryMethods::convertStringToInt(years + months + AuxiliaryMethods::convertIntToString(lastDay));

    return lastMonthEnd;
}
