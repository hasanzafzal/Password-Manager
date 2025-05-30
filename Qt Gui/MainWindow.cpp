#include "MainWindow.h"
#include "LoginDialog.h"
#include "Graph.h"  // Include Graph header
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QString>
#include <QMessageBox>
#include <QInputDialog> // Include QInputDialog
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    LoginDialog *loginDialog = new LoginDialog(this);
    connect(loginDialog, &LoginDialog::loginAttempted, this, &MainWindow::handleLogin);
    loginDialog->exec();
}

MainWindow::~MainWindow() {}

void MainWindow::handleLogin(const QString &password) {
    std::ifstream masterPasswordFile("master_password.txt");
    std::string storedPassword;
    if (masterPasswordFile.is_open()) {
        std::getline(masterPasswordFile, storedPassword);
        masterPasswordFile.close();
    }

    if (password == QString::fromStdString(storedPassword)) {
        openPasswordManager();
    } else {
        QMessageBox::warning(this, "Authentication Failed", "Incorrect Master Password.");
        qApp->quit();
    }
}

void MainWindow::openPasswordManager()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    m_welcomeLabel = new QLabel("Welcome to the Password Manager Dashboard!", this);
    m_masterPasswordLineEdit = new QLineEdit(this);
    m_masterPasswordLineEdit->setPlaceholderText("Enter Master Password");

    m_accountNameLineEdit = new QLineEdit(this);
    m_accountNameLineEdit->setPlaceholderText("Enter Account Name");

    m_passwordLineEdit = new QLineEdit(this);
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);
    m_passwordLineEdit->setPlaceholderText("Enter Password");

    m_addButton = new QPushButton("Add New Entry", this);
    m_viewButton = new QPushButton("View Entries", this);
    m_deleteButton = new QPushButton("Delete Entry", this);
    m_searchButton = new QPushButton("Search Entry", this);

    m_entriesListWidget = new QListWidget(this);

    QHBoxLayout *formLayout = new QHBoxLayout();
    formLayout->addWidget(m_accountNameLineEdit);
    formLayout->addWidget(m_passwordLineEdit);

    layout->addWidget(m_welcomeLabel);
    layout->addLayout(formLayout);
    layout->addWidget(m_addButton);
    layout->addWidget(m_searchButton);
    layout->addWidget(m_deleteButton);
    layout->addWidget(m_viewButton);
    layout->addWidget(m_entriesListWidget);

    setCentralWidget(centralWidget);
    setWindowTitle("Password Manager");

    backend = new PasswordManagerBackend();

    connect(m_addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(m_viewButton, &QPushButton::clicked, this, &MainWindow::onViewButtonClicked);
    connect(m_deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
    connect(m_searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
}

void MainWindow::onAddButtonClicked()
{
    QString accountName = m_accountNameLineEdit->text();
    QString password = m_passwordLineEdit->text();

    if (accountName.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both account name and password.");
        return;
    }

    backend->add_entry(accountName.toStdString(), password.toStdString());
    m_welcomeLabel->setText("New entry added!");
    m_accountNameLineEdit->clear();
    m_passwordLineEdit->clear();

    // Save to file
    backend->save_to_file("passwords.txt");
}

void MainWindow::onViewButtonClicked() {
    LinkedList::Node* entries = backend->list_entries();
    m_entriesListWidget->clear();

    while (entries) {
        m_entriesListWidget->addItem(QString::fromStdString(entries->account_name) + ": " + QString::fromStdString(entries->password));
        entries = entries->next;  // Move to the next node
    }

    m_welcomeLabel->setText("Displaying all entries...");
}

void MainWindow::onDeleteButtonClicked()
{
    QString accountName = m_accountNameLineEdit->text();

    if (accountName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an account name to delete.");
        return;
    }

    bool deleted = backend->delete_entry(accountName.toStdString());
    if (deleted) {
        m_welcomeLabel->setText("Entry deleted.");
        m_accountNameLineEdit->clear();

        // Save updated entries to file
        backend->save_to_file("passwords.txt");
    } else {
        QMessageBox::warning(this, "Delete Failed", "Entry not found.");
    }
}

void MainWindow::onSearchButtonClicked()
{
    QString accountName = m_accountNameLineEdit->text();

    if (accountName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an account name to search.");
        return;
    }

    std::string password = backend->find_entry(accountName.toStdString());
    if (!password.empty()) {
        m_welcomeLabel->setText("Password found: " + QString::fromStdString(password));
    } else {
        m_welcomeLabel->setText("Entry not found.");
    }

    m_accountNameLineEdit->clear();
}

void MainWindow::saveEntriesToFile() {
    std::ofstream outFile("passwords.txt");
    LinkedList::Node* entries = backend->list_entries();
    while (entries) {
        outFile << entries->account_name << ":" << entries->password << "\n";
        entries = entries->next;
    }
}

void MainWindow::handlePush() {
    bool ok;
    QString val = QInputDialog::getText(this, "Stack Push", "Value to push:", QLineEdit::Normal, "", &ok);
    if (ok && !val.isEmpty()) {
        m_stack.push(val.toStdString());
        m_welcomeLabel->setText("Pushed to stack: " + val);
    }
}

void MainWindow::handlePop() {
    if (!m_stack.isEmpty()) {
        std::string val = m_stack.top();
        m_stack.pop();
        m_welcomeLabel->setText("Popped from stack: " + QString::fromStdString(val));
    } else {
        m_welcomeLabel->setText("Stack is empty.");
    }
}

void MainWindow::handleEnqueue() {
    bool ok;
    QString val = QInputDialog::getText(this, "Queue Enqueue", "Value to enqueue:", QLineEdit::Normal, "", &ok);
    if (ok && !val.isEmpty()) {
        m_queue.enqueue(val.toStdString());
        m_welcomeLabel->setText("Enqueued to queue: " + val);
    }
}

void MainWindow::handleDequeue() {
    if (!m_queue.isEmpty()) {
        std::string val = m_queue.front();
        m_queue.dequeue();
        m_welcomeLabel->setText("Dequeued from queue: " + QString::fromStdString(val));
    } else {
        m_welcomeLabel->setText("Queue is empty.");
    }
}

void MainWindow::handleInsertBST() {
    bool ok;
    QString val = QInputDialog::getText(this, "BST Insert", "Value to insert:", QLineEdit::Normal, "", &ok);
    if (ok && !val.isEmpty()) {
        m_bst.insert(val.toStdString());
        m_welcomeLabel->setText("Inserted into BST: " + val);
    }
}

void MainWindow::handleSearchBST() {
    bool ok;
    QString val = QInputDialog::getText(this, "BST Search", "Value to search:", QLineEdit::Normal, "", &ok);
    if (ok && !val.isEmpty()) {
        bool found = m_bst.search(val.toStdString());
        m_welcomeLabel->setText(found ? "Found in BST: " + val : "Not found in BST.");
    }
}

void MainWindow::handleDeleteBST() {
    bool ok;
    QString val = QInputDialog::getText(this, "BST Delete", "Value to delete:", QLineEdit::Normal, "", &ok);
    if (ok && !val.isEmpty()) {
        m_bst.remove(val.toStdString());
        m_welcomeLabel->setText("Deleted from BST: " + val);
    }
}

void MainWindow::handleAddEdge() {
    bool ok1, ok2;
    int v1 = QInputDialog::getInt(this, "Graph Add Edge", "First vertex:", 0, -10000, 10000, 1, &ok1);
    int v2 = QInputDialog::getInt(this, "Graph Add Edge", "Second vertex:", 0, -10000, 10000, 1, &ok2);
    if (ok1 && ok2) {
        m_graph.addEdge(v1, v2);
        m_welcomeLabel->setText("Edge added between " + QString::number(v1) + " and " + QString::number(v2));
    }
}

void MainWindow::handleDFS() {
    bool ok;
    int start = QInputDialog::getInt(this, "Graph DFS", "Start vertex:", 0, -10000, 10000, 1, &ok);
    if (ok) {
        int size;
        int* result = m_graph.dfs(start, size);
        QString output = "DFS result: ";
        for (int i = 0; i < size; ++i) {
            output += QString::number(result[i]) + " ";
        }
        m_welcomeLabel->setText(output);
    }
}

void MainWindow::handleBFS() {
    bool ok;
    int start = QInputDialog::getInt(this, "Graph BFS", "Start vertex:", 0, -10000, 10000, 1, &ok);
    if (ok) {
        int size;
        int* result = m_graph.bfs(start, size);
        QString output = "BFS result: ";
        for (int i = 0; i < size; ++i) {
            output += QString::number(result[i]) + " ";
        }
        m_welcomeLabel->setText(output);
    }
}
