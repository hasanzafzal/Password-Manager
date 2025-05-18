#pragma once
#ifndef CREDENTIALMANAGER_H
#define CREDENTIALMANAGER_H
#include <string>
using namespace std;

struct Credential
{
    string site;
    string username;
    string password;
};

struct Node
{
    Credential data;
    Node* next;
    Node(const Credential& cred) : data(cred), next(nullptr) {}
};

class CredentialManager
{
public:
    CredentialManager();
    ~CredentialManager();
    void addCredential();
    void viewCredentials();
private:
    Node* head;
    void clear();
};

#endif
