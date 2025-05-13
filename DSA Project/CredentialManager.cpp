#include "CredentialManager.h"
#include <iostream>
using namespace std;

void CredentialManager::addCredential()
{
    Credential cred;
    cout << "Enter site: ";
    cin >> cred.site;
    cout << "Enter username: ";
    cin >> cred.username;
    cout << "Enter password: ";
    cin >> cred.password;
    credentials.push_back(cred);
    cout << "Credential added.\n";
}

void CredentialManager::viewCredentials() 
{
    if (credentials.empty()) 
    {
        cout << "No credentials saved.\n";
        return;
    }
    cout << "\nSaved Credentials:\n";
    for (const auto& cred : credentials) 
    {
        cout << "Site: " << cred.site
            << ", Username: " << cred.username
            << ", Password: " << cred.password << "\n";
    }
}