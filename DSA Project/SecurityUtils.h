#pragma once
#ifndef SECURITYUTILS_H
#define SECURITYUTILS_H
#include <string>
#include <ctime>
using namespace std;

class SecurityUtils 
{
public:
    static string encryptAES(const string& plainText, const string& key);
    static string decryptAES(const string& cipherText, const string& key);
    static string generateOTP(const string& secretKey, int interval = 30);
};

#endif