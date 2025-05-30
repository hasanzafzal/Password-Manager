#pragma once
#ifndef CREDENTIALMANAGER_H
#define CREDENTIALMANAGER_H
#include <stack>
#include <queue>
#include <string>
#include <random>
using namespace std;

struct CredentialNode
{
    string site;
    string username;
    string password;
    CredentialNode* next;
};

class CredentialManager 
{
public:
    CredentialManager();
    ~CredentialManager();
    void addCredential();
    void addCredential(const string& site, const string& username, const string& password);
    void addCredential(const CredentialNode& cred);
    void viewCredentials();
    string generatePassword(int length = 12, bool includeSymbols = true);
    void addPasswordToHistory(const string& password);
    void addPasswordWithStrength(const string& password, int strength);
    string getStrongestPassword();
    CredentialNode* linearSearch(const string& site);
    CredentialNode* binarySearch(const string& site);
    void sortCredentials(); 
private:
    CredentialNode* head;
    stack<string> passwordHistory;
    priority_queue<pair<int, string>> strengthHeap;
    CredentialNode* sortedMerge(CredentialNode* a, CredentialNode* b);
    void frontBackSplit(CredentialNode* source, CredentialNode** frontRef, CredentialNode** backRef);
    void mergeSort(CredentialNode** headRef);
    int getListSize();
    CredentialNode** listToArray(int& size);
};

#endif