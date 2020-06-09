#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User insertNewUserData();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    bool checkIfNewPasswordIsSameAsOld();

public:

    UserManager(string fileName) : fileWithUsers(fileName) {
        loggedInUserId = 0;
    };
    void registerUser();
    int signInUser();

    bool checkIfUserIsLoggedIn();
    void changeLoggedInUserPassword();
    void signOutUser();
    int getLoggedInUserId();

};

#endif
