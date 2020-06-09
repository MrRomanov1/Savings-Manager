#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    //FileWithUsers fileWithUsers;
    User insertNewUserData();
    int getNewUserId();
    bool checkIfLoginExists();
    bool checkIfNewPasswordIsSameAsOld();

public:
    //UserManager();
    void registerUser();
    int signInUser();

    bool checkIfUserIsLoggedIn();
    void changeLoggedInUserPassword();
    void signOutUser();
    int getLoggedInUserId();

};

#endif
