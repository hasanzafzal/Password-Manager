#include <iostream>
#include <memory>
#include <string>
#include "App.h"
#include "CredentialManager.h"
#include "SecurityUtils.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
using namespace std;
using namespace sql;

void saveToDatabase(const string& site, const string& username, const string& password) {
    try {
        sql::Driver* driver = get_driver_instance();
        unique_ptr<Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "Bahria123"));
        con->setSchema("PasswordManager");

        unique_ptr<PreparedStatement> pstmt(con->prepareStatement("INSERT INTO Credentials(site, username, password) VALUES (?, ?, ?)"));
        pstmt->setString(1, site);
        pstmt->setString(2, username);
        pstmt->setString(3, password);
        pstmt->executeUpdate();

        cout << "Saved " << site << " to database." << endl;
    } catch (sql::SQLException& e) {
        cerr << "Database insert error: " << e.what() << endl;
    }
}

int main()
{
    App app;
    app.run();

    cout << "\n--- Feature Demonstration ---" << endl;

    CredentialManager manager;

    manager.addCredential("example.com", "user123", "pass456");
    saveToDatabase("example.com", "user123", "pass456");

    manager.addCredential("google.com", "alice", "pass789");
    saveToDatabase("google.com", "alice", "pass789");

    manager.addCredential("github.com", "bob", "code123");
    saveToDatabase("github.com", "bob", "code123");

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
        sql::Driver* driver = get_driver_instance();
        unique_ptr<Connection> con(driver->connect("tcp://127.0.0.1:3306", "your_username", "your_password"));
        con->setSchema("PasswordManager");

        unique_ptr<Statement> stmt(con->createStatement());
        unique_ptr<ResultSet> res(stmt->executeQuery("SELECT username FROM Users"));

        cout << "\nConnected to MySQL database successfully!" << endl;

        while (res->next())
        {
            cout << "User: " << res->getString("username") << endl;
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "MySQL error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
