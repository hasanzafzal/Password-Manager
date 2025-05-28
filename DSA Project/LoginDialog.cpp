#include "LoginDialog.h"

BEGIN_MESSAGE_MAP(LoginDialog, CDialog)
    // No buttons hooked yet
END_MESSAGE_MAP()

LoginDialog::LoginDialog(CWnd* pParent /*=nullptr*/)
    : CDialog(IDD_LOGIN_DIALOG, pParent)
{
}

void LoginDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_USERNAME_EDIT, m_username);
    DDX_Text(pDX, IDC_PASSWORD_EDIT, m_password);
}
