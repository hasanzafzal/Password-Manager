#include "App.h"
#include "MainWindow.h"
#include <afxctl.h>  // Required for AfxEnableControlContainer()

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(DSAApp, CWinApp)
    // Add message handlers if needed
END_MESSAGE_MAP()

DSAApp theApp;

BOOL DSAApp::InitInstance()
{
    CWinApp::InitInstance();
    AfxEnableControlContainer(); // ✅ This requires afxctl.h

    MainWindow* mainWnd = new MainWindow();
    m_pMainWnd = mainWnd;
    mainWnd->ShowWindow(SW_SHOW);
    mainWnd->UpdateWindow();

    return TRUE;
}
