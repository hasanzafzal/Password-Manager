#pragma once

#include <afxwin.h>

class MainDashboard : public CWnd
{
public:
    MainDashboard();
    virtual ~MainDashboard();

    BOOL Create(CWnd* pParentWnd, UINT nID = AFX_IDW_PANE_FIRST);
    void Initialize();

protected:
    CStatic m_welcomeLabel;
    CButton m_addButton;
    CButton m_viewButton;

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);

    DECLARE_MESSAGE_MAP()
};
