#pragma once
#ifndef CREDENTIALMANAGER_H
#define CREDENTIALMANAGER_H
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <random>
using namespace std;

struct Credential 
{
    string site;
    string username;
    string password;
};

class CredentialManager 
{
public:
    void addCredential(); 
    void addCredential(const Credential& cred);
    void viewCredentials();
    string generatePassword(int length = 12, bool includeSymbols = true);
    void addPasswordToHistory(const string& password);
    void addPasswordWithStrength(const string& password, int strength);
    string getStrongestPassword();
private:
    list<Credential> credentials;
    stack<string> passwordHistory;
    priority_queue<pair<int, string>> strengthHeap;
};

 #endif
