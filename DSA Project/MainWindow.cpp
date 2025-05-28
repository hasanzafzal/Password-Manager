#include "MainWindow.h"
#include "LoginDialog.h"
#include "MainDashboard.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_COMMAND(ID_APP_EXIT, &MainWindow::OnExit)
END_MESSAGE_MAP()

MainWindow::MainWindow()
{
    // Create the main window frame
    Create(NULL, _T("DSA MFC Password Manager"),
        WS_OVERLAPPEDWINDOW,
        CRect(100, 100, 1000, 700));
}

int MainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // Show login dialog at startup
    LoginDialog loginDlg;
    if (loginDlg.DoModal() != IDOK)
    {
        PostQuitMessage(0);
        return -1;
    }

    // Corrected: Call dashboard->Create with only 2 arguments
    MainDashboard* dashboard = new MainDashboard();
    if (!dashboard->Create(this, 1234))
    {
        AfxMessageBox(_T("Failed to create dashboard window."));
        return -1;
    }

    dashboard->Initialize();

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
