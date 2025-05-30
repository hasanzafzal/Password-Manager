#include "SecurityUtils.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

string SecurityUtils::encryptAES(const string& plainText, const string& key) 
{
    string result = plainText;
    reverse(result.begin(), result.end());
    result += to_string(key.length());
    return result;
}

string SecurityUtils::decryptAES(const string& cipherText, const string& key) 
{
    string result = cipherText.substr(0, cipherText.length() - to_string(key.length()).length());
    reverse(result.begin(), result.end());
    return result;
}

string SecurityUtils::generateOTP(const string& secretKey, int interval) 
{
    time_t rawTime = time(nullptr);
    int timestep = static_cast<int>(rawTime / interval);
    srand(timestep);
    int otp = rand() % 1000000;
    stringstream ss;
    ss << setfill('0') << setw(6) << otp;
    return ss.str();
}
