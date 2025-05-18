#pragma once
#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H
#include <string>
using namespace std;

class AuthManager
{
private:
    struct Node
    {
        string password;
        Node* next;
    };

    Node* head;

public:
    AuthManager();
    ~AuthManager();
    void addPassword(const string& newPassword);
    bool authenticate();
};

#endif
