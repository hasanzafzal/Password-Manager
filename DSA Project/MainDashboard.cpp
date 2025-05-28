#include "MainDashboard.h"

BEGIN_MESSAGE_MAP(MainDashboard, CWnd)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

MainDashboard::MainDashboard()
{
}

MainDashboard::~MainDashboard()
{
}

BOOL MainDashboard::Create(CWnd* pParentWnd, UINT nID)
{
    CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);
    return CWnd::CreateEx(
        0, className, _T("Main Dashboard"),
        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
        CRect(0, 0, 800, 600), pParentWnd, nID, NULL);
}

int MainDashboard::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // Corrected CStatic::Create
    m_welcomeLabel.Create(_T("Welcome to your Password Manager!"),
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        CRect(0, 0, 300, 30), this, 1001);

    // Corrected CButton::Create — 5 arguments
    m_addButton.Create(_T("Add Entry"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(0, 0, 150, 30), this, 1002);

    m_viewButton.Create(_T("View Entries"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        CRect(0, 0, 150, 30), this, 1003);

    return 0;
}

void MainDashboard::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    int centerX = cx / 2;

    m_welcomeLabel.MoveWindow(centerX - 150, 40, 300, 30);
    m_addButton.MoveWindow(centerX - 75, 90, 150, 30);
    m_viewButton.MoveWindow(centerX - 75, 130, 150, 30);
}

void MainDashboard::Initialize()
{
    // Optional future logic
}
