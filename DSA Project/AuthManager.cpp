#include "AuthManager.h"
#include <iostream>
using namespace std;

AuthManager::AuthManager()
{
    head = nullptr;
    addPassword("admin");
    addPassword("root");
    addPassword("1234"); addPassword("0000");
}

AuthManager::~AuthManager()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void AuthManager::addPassword(const string& newPassword)
{
    Node* newNode = new Node{ newPassword, head };
    head = newNode;
}

bool AuthManager::authenticate()
{
    string input;
    cout << "Enter master password: ";
    cin >> input;

    Node* current = head;
    while (current != nullptr)
    {
        if (current->password == input)
            return true;
        current = current->next;
    }
    return false;
}
