#include "MainDashboard.h"
#include <QVBoxLayout>
#include <QPushButton>

MainDashboard::MainDashboard(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_welcomeLabel = new QLabel("Welcome to the Dashboard!", this);
    m_addButton = new QPushButton("Add", this);
    m_viewButton = new QPushButton("View", this);

    layout->addWidget(m_welcomeLabel);
    layout->addWidget(m_addButton);
    layout->addWidget(m_viewButton);

    connect(m_addButton, &QPushButton::clicked, this, &MainDashboard::onAddButtonClicked);
    connect(m_viewButton, &QPushButton::clicked, this, &MainDashboard::onViewButtonClicked);
}

void MainDashboard::onAddButtonClicked()
{
    // Handle add button click
}

void MainDashboard::onViewButtonClicked()
{
    // Handle view button click
}
