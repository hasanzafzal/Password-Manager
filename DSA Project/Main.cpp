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
    // Add a test credential
    Credential cred = { "example.com", "user123", "pass456" };
    manager.addCredential(cred);

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
    return 0;
}