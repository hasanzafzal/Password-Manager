/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QPushButton *addButton;
    QPushButton *viewButton;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QListWidget *entriesListWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName("welcomeLabel");

        verticalLayout->addWidget(welcomeLabel);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        viewButton = new QPushButton(centralwidget);
        viewButton->setObjectName("viewButton");

        verticalLayout->addWidget(viewButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        verticalLayout->addWidget(deleteButton);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        entriesListWidget = new QListWidget(centralwidget);
        entriesListWidget->setObjectName("entriesListWidget");

        verticalLayout->addWidget(entriesListWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Password Manager Dashboard", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to the Password Manager Dashboard!", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add New Entry", nullptr));
        viewButton->setText(QCoreApplication::translate("MainWindow", "View Entries", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Entry", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search Entry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
