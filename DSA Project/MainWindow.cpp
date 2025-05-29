#include "MainWindow.h"
#include "LoginDialog.h"
#include "MainDashboard.h"
#include "resource.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_COMMAND(ID_APP_EXIT, &MainWindow::OnExit)
    ON_COMMAND(ID_BUTTON_ADD, &MainWindow::OnAddPassword)
    ON_COMMAND(ID_BUTTON_VIEW, &MainWindow::OnViewPasswords)
END_MESSAGE_MAP()

MainWindow::MainWindow()
{
    Create(NULL, _T("DSA MFC Password Manager"),
        WS_OVERLAPPEDWINDOW,
        CRect(100, 100, 1000, 700));
}

int MainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // Show login dialog
    LoginDialog loginDlg;
    if (loginDlg.DoModal() != IDOK)
    {
        PostQuitMessage(0);
        return -1;
    }

    // Create Dashboard
    MainDashboard* dashboard = new MainDashboard();
    if (!dashboard->Create(this, 1234))
    {
        AfxMessageBox(_T("Failed to create dashboard window."));
        return -1;
    }

    dashboard->Initialize();

    // Create buttons
    m_btnAdd.Create(_T("Add Password"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(50, 100, 250, 130), this, ID_BUTTON_ADD);

    m_btnView.Create(_T("View Passwords"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(50, 150, 250, 180), this, ID_BUTTON_VIEW);

    m_btnExit.Create(_T("Exit"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(50, 200, 250, 230), this, ID_APP_EXIT);

    return 0;
}

void MainWindow::OnPaint()
{
    CPaintDC dc(this);
    dc.TextOutW(10, 10, _T("Password Manager Dashboard"));
}

void MainWindow::OnExit()
{
    PostMessage(WM_CLOSE);
}

void MainWindow::OnAddPassword()
{
    AfxMessageBox(_T("Add Password button clicked!"));
    // TODO: Add actual logic
}

void MainWindow::OnViewPasswords()
{
    AfxMessageBox(_T("View Passwords button clicked!"));
}
