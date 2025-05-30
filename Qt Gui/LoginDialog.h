#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>
#include <QLineEdit>

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    QString getUsername() const;
    QString getPassword() const;

signals:
    void loginAttempted(const QString &username, const QString &password);

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;

private slots:
    void onLoginClicked();
};

#endif // LOGINDIALOG_H
