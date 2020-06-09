#include <iostream>
#include "SavingsManager.h"

using namespace std;

int main() {
    SavingsManager savingsManager("users.xml");
    savingsManager.registerUser();

    return 0;
}
