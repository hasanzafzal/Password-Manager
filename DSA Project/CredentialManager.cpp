#include "CredentialManager.h"
#include <iostream>
using namespace std;

CredentialManager::CredentialManager() : head(nullptr) {}

CredentialManager::~CredentialManager() 
{
    clear();
}

void CredentialManager::addCredential()
{
    Credential cred;
    cout << "Enter site: ";
    cin >> cred.site;
    cout << "Enter username: ";
    cin >> cred.username;
    cout << "Enter password: ";
    cin >> cred.password;
    Node* newNode = new Node(cred);
    newNode->next = head;
    head = newNode;
    cout << "Credential added.\n";
}

void CredentialManager::viewCredentials()
{
    if (head == nullptr)
    {
        cout << "No credentials saved.\n";
        return;
    }

    cout << "\nSaved Credentials:\n";
    Node* current = head;
    while (current != nullptr)
    {
        cout << "Site: " << current->data.site
            << ", Username: " << current->data.username
            << ", Password: " << current->data.password << "\n";
        current = current->next;
    }
}

void CredentialManager::clear() 
{
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
