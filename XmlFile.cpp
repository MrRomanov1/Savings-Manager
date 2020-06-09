#include "XmlFile.h"

string XmlFile::getFileName() {
    return FILE_NAME;
}

bool XmlFile::checkIfFileExists() {
    bool fileExists = xml.Load(getFileName());
    return fileExists;
}
