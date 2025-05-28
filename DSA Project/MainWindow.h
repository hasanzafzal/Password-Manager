#pragma once

#include <afxwin.h>

// Forward declare MainDashboard to avoid include loop
class MainDashboard;

class MainWindow : public CFrameWnd
{
public:
    MainWindow();

protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnExit();

    DECLARE_MESSAGE_MAP()

private:
    MainDashboard* m_dashboard; // Pointer to the dashboard window
};
