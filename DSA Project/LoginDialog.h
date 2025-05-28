#pragma once

#include <afxwin.h>       // MFC core
#include "resource.h"     // Dialog and control IDs

class LoginDialog : public CDialog
{
public:
    LoginDialog(CWnd* pParent = nullptr);

    enum { IDD = IDD_LOGIN_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX) override;

    DECLARE_MESSAGE_MAP()

private:
    CString m_username;
    CString m_password;

public:
    CString GetUsername() const { return m_username; }
    CString GetPassword() const { return m_password; }
};
