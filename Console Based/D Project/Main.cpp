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

void saveToDatabase(int user_id, const string& site, const string& username, const string& password) {
    try
    {
        const string host = "127.0.0.1";
        const int port = 3306;
        const string user = "root";
        const string pass = "Waleed * 02";
        const string schema = "PasswordManager";

        cout << "Connecting to MySQL at " << host << ":" << port << endl;

        sql::Driver* driver = get_driver_instance();
        if (!driver)
        {
            cerr << "Failed to get MySQL driver instance in saveToDatabase!" << endl;
            return;
        }

        sql::ConnectOptionsMap connection_properties;
        connection_properties["hostName"] = host;
        connection_properties["port"] = port;
        connection_properties["userName"] = user;
        connection_properties["password"] = pass;

        unique_ptr<Connection> con(driver->connect(connection_properties));
        con->setSchema(schema);

        unique_ptr<PreparedStatement> pstmt(con->prepareStatement(
            "INSERT INTO Credentials(user_id, service_name, service_username, service_password) VALUES (?, ?, ?, ?)"));
        pstmt->setInt(1, user_id);
        pstmt->setString(2, site);
        pstmt->setString(3, username);
        pstmt->setString(4, password);
        pstmt->executeUpdate();

        cout << "Saved " << site << " to database." << endl;
    }
    catch (const sql::SQLException& e)
    {
        cerr << "MySQL insert error: " << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        cerr << "Standard exception in saveToDatabase: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error in saveToDatabase." << endl;
    }
}

int main()
{
    App app;
    app.run();

    try {
        const string host = "127.0.0.1";
        const int port = 3306;
        const string user = "root";
        const string pass = "Waleed*02";
        const string schema = "PasswordManager";

        cout << "Connecting to MySQL at " << host << ":" << port << endl;

        sql::Driver* driver = get_driver_instance();
        if (!driver)
        {
            cerr << "Failed to get MySQL driver instance in main!" << endl;
            return 1;
        }

        sql::ConnectOptionsMap connection_properties;
        connection_properties["hostName"] = host;
        connection_properties["port"] = port;
        connection_properties["userName"] = user;
        connection_properties["password"] = pass;

        unique_ptr<Connection> con(driver->connect(connection_properties));
        con->setSchema(schema);

        unique_ptr<Statement> stmt(con->createStatement());
        unique_ptr<ResultSet> res(stmt->executeQuery("SELECT username FROM Users"));

        cout << "Connected to MySQL database successfully!" << endl;
        while (res->next()) {
            cout << "User: " << res->getString("username") << endl;
        }
    }
    catch (const sql::SQLException& e)
    {
        cerr << "MySQL error: " << e.what() << endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        cerr << "Standard exception: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown error occurred." << endl;
        return 1;
    }
    return 0;
}