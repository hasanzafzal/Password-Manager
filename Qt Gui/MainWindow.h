#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include "PasswordManagerBackend.h"
#include "Graph.h"  // Include Graph header

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleLogin(const QString &password);  // Remove username
    void onAddButtonClicked();
    void onViewButtonClicked();
    void onDeleteButtonClicked();
    void onSearchButtonClicked();
    void saveEntriesToFile();
    void handlePush();
    void handlePop();
    void handleEnqueue();
    void handleDequeue();
    void handleInsertBST();
    void handleSearchBST();
    void handleDeleteBST();
    void handleAddEdge();
    void handleDFS();
    void handleBFS();

private:
    void openPasswordManager();  // Declare the method

    QLabel *m_welcomeLabel;
    QLineEdit *m_masterPasswordLineEdit;
    QLineEdit *m_accountNameLineEdit;
    QLineEdit *m_passwordLineEdit;
    QPushButton *m_addButton;
    QPushButton *m_viewButton;
    QPushButton *m_deleteButton;
    QPushButton *m_searchButton;
    QListWidget *m_entriesListWidget;
    PasswordManagerBackend *backend;

    Stack m_stack;  // Stack instance
    Queue m_queue;  // Queue instance
    BST m_bst;      // BST instance
    Graph m_graph;  // Graph instance
};

#endif // MAINWINDOW_H
