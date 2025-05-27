#pragma once
#include <string>
#include <memory>
#include "LinkedList.h"
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>

using namespace std;

struct Credential {
    string website;
    string username;
    string password;
};

class CredentialManager {
public:
    CredentialManager();
    bool addCredential(const Credential& cred);
    LinkedList<Credential> getAllCredentials();

private:
    sql::Driver* driver;
    unique_ptr<sql::Connection> conn;
};
