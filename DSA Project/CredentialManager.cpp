#include "CredentialManager.h"
#include <iostream>
#include <ctime>
#include <algorithm>

void CredentialManager::addCredential()
{
    Credential c;
    cout << "Enter site: ";
    cin >> c.site;
    cout << "Enter username: ";
    cin >> c.username;
    cout << "Enter password: ";
    cin >> c.password;
    credentials.push_back(c);
}

void CredentialManager::addCredential(const Credential& cred) 
{
    credentials.push_back(cred);
}

void CredentialManager::viewCredentials()
{
    for (const auto& c : credentials) {
        cout << "Site: " << c.site << ", Username: " << c.username << ", Password: " << c.password << endl;
    }
}

string CredentialManager::generatePassword(int length, bool includeSymbols) 
{
    const string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numbers = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string chars = letters + numbers;
    if (includeSymbols) chars += symbols;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distrib(0, static_cast<int>(chars.size()) - 1);

    string password;
    for (int i = 0; i < length; ++i)
        password += chars[distrib(generator)];

    return password;
}

void CredentialManager::addPasswordToHistory(const string& password)
{
    passwordHistory.push(password);
}

void CredentialManager::addPasswordWithStrength(const string& password, int strength) 
{
    strengthHeap.push(make_pair(strength, password));
}

string CredentialManager::getStrongestPassword()
{
    if (!strengthHeap.empty())
        return strengthHeap.top().second;
    return "";
}
