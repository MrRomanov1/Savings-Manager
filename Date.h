#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Date {

public:
    static string getCurrentDate();
    static int convertDateToInt(string date);
    static string convertDateToStringWithDashes(int date);
    static string getDate();
    static bool checkIfDateIsValid(string date);
    static int getLastDayOfTheMonth(int month, int year);
    static int getEndOfCurrentMonth();
    static int getCurrentMonthBegin();
    static int getLastMonthBegin();
    static int getLastMonthEnd();
};
#endif
