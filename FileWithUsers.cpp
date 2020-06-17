#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    if (!checkIfFileExists()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password",user.getPassword());

    xml.Save(getFileName());
}

vector <User> FileWithUsers::loadUsersFromFile() {

    User user;
    vector <User> users;

    xml.ResetPos();
    if (checkIfFileExists()) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {

            xml.FindChildElem("UserID");
            user.setId(AuxiliaryMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem("Name");
            user.setName(xml.GetChildData());
            xml.FindChildElem("Surname");
            user.setSurname(xml.GetChildData());
            xml.FindChildElem("Login");
            user.setLogin(xml.GetChildData());
            xml.FindChildElem("Password");
            user.setPassword(xml.GetChildData());

            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::changeUserPassword(string newPassword, int loggedInUserId) {
    xml.ResetPos();
    if (checkIfFileExists()) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.FindChildElem("UserID");
            if (xml.GetChildData() == AuxiliaryMethods::convertIntToString(loggedInUserId)) {
                xml.FindChildElem("Password");
                xml.SetChildData(newPassword);
            }
        }
    }
    xml.Save(getFileName());
}
