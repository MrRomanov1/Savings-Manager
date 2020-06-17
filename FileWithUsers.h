#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"


using namespace std;

class FileWithUsers : public XmlFile {

    User getUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changeUserPassword(string newPassword, int loggedInUserId);
};
#endif
