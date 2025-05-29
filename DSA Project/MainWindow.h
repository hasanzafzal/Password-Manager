#pragma once
#include <afxwin.h>

class MainWindow : public CFrameWnd
{
public:
    MainWindow();

protected:
    DECLARE_MESSAGE_MAP()

    CButton m_btnAdd;
    CButton m_btnView;
    CButton m_btnExit;

public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnExit();
    afx_msg void OnAddPassword();
    afx_msg void OnViewPasswords();
};
