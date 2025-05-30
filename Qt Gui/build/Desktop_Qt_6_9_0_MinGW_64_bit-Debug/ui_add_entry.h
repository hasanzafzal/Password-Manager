/********************************************************************************
** Form generated from reading UI file 'add_entry.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ENTRY_H
#define UI_ADD_ENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEntryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelUsername;
    QLineEdit *usernameEdit;
    QLabel *labelPassword;
    QLineEdit *passwordEdit;
    QPushButton *saveButton;

    void setupUi(QDialog *AddEntryDialog)
    {
        if (AddEntryDialog->objectName().isEmpty())
            AddEntryDialog->setObjectName("AddEntryDialog");
        AddEntryDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddEntryDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelUsername = new QLabel(AddEntryDialog);
        labelUsername->setObjectName("labelUsername");

        verticalLayout->addWidget(labelUsername);

        usernameEdit = new QLineEdit(AddEntryDialog);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        labelPassword = new QLabel(AddEntryDialog);
        labelPassword->setObjectName("labelPassword");

        verticalLayout->addWidget(labelPassword);

        passwordEdit = new QLineEdit(AddEntryDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        saveButton = new QPushButton(AddEntryDialog);
        saveButton->setObjectName("saveButton");

        verticalLayout->addWidget(saveButton);


        retranslateUi(AddEntryDialog);

        QMetaObject::connectSlotsByName(AddEntryDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEntryDialog)
    {
        AddEntryDialog->setWindowTitle(QCoreApplication::translate("AddEntryDialog", "Add New Entry", nullptr));
        labelUsername->setText(QCoreApplication::translate("AddEntryDialog", "Username:", nullptr));
        labelPassword->setText(QCoreApplication::translate("AddEntryDialog", "Password:", nullptr));
        saveButton->setText(QCoreApplication::translate("AddEntryDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEntryDialog: public Ui_AddEntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ENTRY_H
