#include "AuthManager.h"
#include <iostream>
#include <string>
using namespace std;

bool AuthManager::authenticate()
{
    string input;
    const string masterPassword = "admin";

    cout << "Enter master password: ";
    cin >> input;

    return input == masterPassword;
}