#pragma once

#include <afxwin.h>

class MainWindow : public CFrameWnd
{
public:
    MainWindow();

protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnExit();

    DECLARE_MESSAGE_MAP()
};
