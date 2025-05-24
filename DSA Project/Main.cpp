#include <iostream>
#include <memory>
#include "App.h"
#include "CredentialManager.h"
#include "SecurityUtils.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
using namespace std;
using namespace sql;

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
        cout << "\nLinear Search Found: " << found->site << " -> " << found->username << endl;
    else
        cout << "\nLinear Search: Site not found!" << endl;

    searchSite = "google.com";
    found = manager.binarySearch(searchSite);
    if (found)
        cout << "\nBinary Search Found: " << found->site << " -> " << found->username << endl;
    else
        cout << "\nBinary Search: Site not found!" << endl;

    try
    {
        Driver* driver = mysql::get_mysql_driver_instance();
        unique_ptr<Connection> con(driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password"));
        con->setSchema("PasswordManager");

        cout << "\nConnected to MySQL database successfully!" << endl;

        unique_ptr<Statement> stmt(con->createStatement());
        unique_ptr<ResultSet> res(stmt->executeQuery("SELECT * FROM Users"));

        while (res->next())
            cout << "User: " << res->getString("username") << endl;
    }
    catch (SQLException& e)
    {
        cout << "MySQL error: " << e.what() << endl;
        return 1;
    }
    try 
    {
        sql::Driver* driver = get_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password"));
        con->setSchema("PasswordManager");

        cout << "Connected to MySQL database successfully!" << endl;

        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Users"));

        while (res->next()) {
            cout << "User: " << res->getString("username") << endl;
        }

    }
    catch (sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
