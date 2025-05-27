#include "CredentialManager.h"
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_driver.h>

CredentialManager::CredentialManager() {
    driver = sql::mysql::get_mysql_driver_instance();
    conn.reset(driver->connect("tcp://127.0.0.1:3306", "root", "Bahria123")); // Replace password
    conn->setSchema("password_manager");
}


bool CredentialManager::addCredential(const Credential& cred) {
    try {
        unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("INSERT INTO credentials(website, username, password) VALUES (?, ?, ?)"));
        pstmt->setString(1, cred.website);
        pstmt->setString(2, cred.username);
        pstmt->setString(3, cred.password);
        pstmt->execute();
        return true;
    }
    catch (...) {
        return false;
    }
}

LinkedList<Credential> CredentialManager::getAllCredentials() {
    LinkedList<Credential> creds;
    unique_ptr<sql::Statement> stmt(conn->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT website, username, password FROM credentials"));

    while (res->next()) {
        Credential c;
        c.website = res->getString("website");
        c.username = res->getString("username");
        c.password = res->getString("password");
        creds.append(c);
    }
    return creds;
}
