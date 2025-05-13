#include "App.h"
#include "AuthManager.h"
#include "CredentialManager.h"
#include <iostream>
using namespace std;

App::App() 
{
}

void App::run()
{
    AuthManager auth;
    if (!auth.authenticate())
    {
        cout << "Authentication failed. Exiting...\n";
        return;

        CredentialManager manager;
        int choice;
        do
        {
            cout << "\n=== Password Manager ===\n";
            cout << "1. Add Credential\n";
            cout << "2. View Credentials\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                manager.addCredential();
                break;
            case 2:
                manager.viewCredentials();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
}