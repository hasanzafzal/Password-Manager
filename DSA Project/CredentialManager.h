#pragma once
#ifndef CREDENTIALMANAGER_H
#define CREDENTIALMANAGER_H
#include <vector>
#include <string>
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
    void viewCredentials();

private:
    vector<Credential> credentials;
};

#endif