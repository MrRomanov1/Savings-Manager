#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"


using namespace std;

class FileWithUsers : public XmlFile {

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user);
    User getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};
#endif
