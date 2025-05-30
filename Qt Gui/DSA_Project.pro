TEMPLATE = app
CONFIG += c++11

QT += core gui widgets

SOURCES += LinkedList.cpp \
           App.cpp \
           MainWindow.cpp \
           LoginDialog.cpp \
           Main.cpp \
           MainDashboard.cpp \
           PasswordManagerBackend.cpp \
           Stack.cpp \
           Queue.cpp \
           BST.cpp \
           Graph.cpp

HEADERS += App.h \
           MainWindow.h \
           LoginDialog.h \
           MainDashboard.h \
           PasswordManagerBackend.h \
           Stack.h \
           Queue.h \
           BST.h \
           Graph.h

RESOURCES += PasswordManager.qrc

FORMS += login_dialog.ui \
         mainwindow.ui \
         add_entry.ui \
         view_entries.ui

DISTFILES += .gitattributes \
             DSA_Project.pro.user
