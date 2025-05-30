#ifndef MAINDASHBOARD_H
#define MAINDASHBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MainDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit MainDashboard(QWidget *parent = nullptr);

private:
    QLabel *m_welcomeLabel;
    QPushButton *m_addButton;
    QPushButton *m_viewButton;

private slots:
    void onAddButtonClicked();
    void onViewButtonClicked();
};

#endif // MAINDASHBOARD_H
