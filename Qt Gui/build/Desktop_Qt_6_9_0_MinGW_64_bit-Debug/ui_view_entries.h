/********************************************************************************
** Form generated from reading UI file 'view_entries.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_ENTRIES_H
#define UI_VIEW_ENTRIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewEntriesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *entriesLabel;
    QListView *entriesListView;
    QPushButton *closeButton;

    void setupUi(QDialog *ViewEntriesDialog)
    {
        if (ViewEntriesDialog->objectName().isEmpty())
            ViewEntriesDialog->setObjectName("ViewEntriesDialog");
        ViewEntriesDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ViewEntriesDialog);
        verticalLayout->setObjectName("verticalLayout");
        entriesLabel = new QLabel(ViewEntriesDialog);
        entriesLabel->setObjectName("entriesLabel");

        verticalLayout->addWidget(entriesLabel);

        entriesListView = new QListView(ViewEntriesDialog);
        entriesListView->setObjectName("entriesListView");

        verticalLayout->addWidget(entriesListView);

        closeButton = new QPushButton(ViewEntriesDialog);
        closeButton->setObjectName("closeButton");

        verticalLayout->addWidget(closeButton);


        retranslateUi(ViewEntriesDialog);

        QMetaObject::connectSlotsByName(ViewEntriesDialog);
    } // setupUi

    void retranslateUi(QDialog *ViewEntriesDialog)
    {
        ViewEntriesDialog->setWindowTitle(QCoreApplication::translate("ViewEntriesDialog", "View Entries", nullptr));
        entriesLabel->setText(QCoreApplication::translate("ViewEntriesDialog", "Saved Entries:", nullptr));
        closeButton->setText(QCoreApplication::translate("ViewEntriesDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewEntriesDialog: public Ui_ViewEntriesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_ENTRIES_H
