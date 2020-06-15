#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"


using namespace std;

class XmlFile {

    const string FILE_NAME;

public:
    CMarkup xml;
    XmlFile(string fileName) : FILE_NAME(fileName) {
    }
    string getFileName();
    bool checkIfFileExists();
};

#endif
