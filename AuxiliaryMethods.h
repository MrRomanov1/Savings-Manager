#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class AuxiliaryMethods {

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static double convertStringToDouble(string number);
    static string convertDoubleToString (double number);
    static string changeFirstLetterToCapitalAndRemainingToLowercase(string text);
    static int getInteger();
    static char getCharacter();
    static string loadLine();
    static string checkPasswordRequirements();
    static double getDouble();
};
#endif
