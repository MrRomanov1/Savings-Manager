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

    xml.Save("users.xml");
}
