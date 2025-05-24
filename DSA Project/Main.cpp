#include <iostream>
#include "App.h"
#include "CredentialManager.h"
#include "SecurityUtils.h"
using namespace std;

int main()
{
    App app;
    app.run();

    cout << "\n--- Feature Demonstration ---" << endl;
    CredentialManager manager;
    manager.addCredential("example.com", "user123", "pass456");
    manager.addCredential("google.com", "alice", "pass789");
    manager.addCredential("github.com", "bob", "code123");
    cout << "\nSaved Credentials:" << endl;
    manager.viewCredentials();
    string generated = manager.generatePassword(14, true);
    cout << "\nGenerated Password: " << generated << endl;
    manager.addPasswordToHistory(generated);
    manager.addPasswordWithStrength(generated, 85);
    cout << "Strongest Password: " << manager.getStrongestPassword() << endl;
    string aesKey = "1234567890abcdef";
    string encrypted = SecurityUtils::encryptAES("secretPassword", aesKey);
    string decrypted = SecurityUtils::decryptAES(encrypted, aesKey);
    cout << "\nEncrypted: " << encrypted << "\nDecrypted: " << decrypted << endl;
    string otp = SecurityUtils::generateOTP("mySecretKey");
    cout << "\nGenerated OTP: " << otp << endl;
    string searchSite = "github.com";
    CredentialNode* found = manager.linearSearch(searchSite);
    if (found) 
    {
        cout << "\nLinear Search Found: " << found->site << " -> " << found->username << endl;
    }
    else 
    {
        cout << "\nLinear Search: Site not found!" << endl;
    }
    searchSite = "google.com";
    found = manager.binarySearch(searchSite);
    if (found) 
    {
        cout << "\nBinary Search Found: " << found->site << " -> " << found->username << endl;
    }
    else 
    {
        cout << "\nBinary Search: Site not found!" << endl;
    }

    return 0;
}