#include "MainWindow.h"

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_COMMAND(ID_APP_EXIT, &MainWindow::OnExit)
END_MESSAGE_MAP()

MainWindow::MainWindow()
{
    Create(NULL, _T("DSA MFC App Window"));
}

int MainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    return 0;
}

void MainWindow::OnPaint()
{
    CPaintDC dc(this); // required in OnPaint
    dc.TextOutW(10, 10, _T("Welcome to the MFC-based Password Manager"));
}

void MainWindow::OnExit()
{
    PostMessage(WM_CLOSE);
}
