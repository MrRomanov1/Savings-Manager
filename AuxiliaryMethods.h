#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static float convertStringToFloat(string number);
    //static string getNumber(string text, int pozycjaZnaku);
    static string changeFirstLetterToCapitalAndRemainingToLowercase(string text);
    static int getInteger();
    static char getCharacter();
    //static string sprawdzPoprawnoscTelefonu();
    //static string sprawdzPoprawnoscEmail();
    static string loadLine();
};
#endif
