#include "LoginDialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Create UI elements
    QLabel *usernameLabel = new QLabel("Username:", this);
    m_usernameEdit = new QLineEdit(this);  // Store username input
    QLabel *passwordLabel = new QLabel("Password:", this);
    m_passwordEdit = new QLineEdit(this);  // Store password input
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    QPushButton *loginButton = new QPushButton("Login", this);

    // Add UI elements to the layout
    layout->addWidget(usernameLabel);
    layout->addWidget(m_usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(m_passwordEdit);
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
}

LoginDialog::~LoginDialog() {}

QString LoginDialog::getUsername() const
{
    return m_usernameEdit->text();  // Return username input
}

QString LoginDialog::getPassword() const
{
    return m_passwordEdit->text();  // Return password input
}

void LoginDialog::onLoginClicked()
{
    // Close the dialog and emit a signal to pass the input to MainWindow
    emit loginAttempted(getUsername(), getPassword());
    accept();
}
