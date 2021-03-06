// SignIn.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignUpDlg.h"
#include "afxdialogex.h"
#include "UserDA.h"


// CSignUpDlg 对话框

IMPLEMENT_DYNAMIC(CSignUpDlg, CDialog)

CSignUpDlg::CSignUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignUpDlg::IDD, pParent)
{

}

CSignUpDlg::~CSignUpDlg()
{
}

void CSignUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	m_font.CreatePointFont(150,"微软雅黑");
}


BEGIN_MESSAGE_MAP(CSignUpDlg, CDialog)
	ON_BN_CLICKED(IDC_SIGN_UP, &CSignUpDlg::OnBnClickedSignUp)
	ON_BN_CLICKED(IDC_RETURN, &CSignUpDlg::OnBnClickedReturn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSignUpDlg 消息处理程序


void CSignUpDlg::OnBnClickedSignUp()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	CString password;
	CString check_password;
	GetDlgItem(IDC_CREATE_USERNAME)->GetWindowText(name);
	GetDlgItem(IDC_CREATE_PASSORD)->GetWindowText(password);
	GetDlgItem(IDC_CHECK_CREATE_PASSWORD)->GetWindowText(check_password);
	if(name.IsEmpty()||password.IsEmpty())
	{
		AfxMessageBox("用户名或密码不能为空!");
		return;
	}
	CUserDA userDA;
	if(userDA.ExistUser(name))
	{
		AfxMessageBox("用户名已存在！");
		return;
	}
	if(check_password!=password)
	{
		AfxMessageBox("两次密码不一致！请重新输入");
		GetDlgItem(IDC_CREATE_PASSORD)->SetWindowText("");
		GetDlgItem(IDC_CHECK_CREATE_PASSWORD)->SetWindowText("");
		return;
	}
	userDA.AddUser(name,password);
	AfxMessageBox("注册成功！");
	this->SendMessage(WM_CLOSE);
}


void CSignUpDlg::OnBnClickedReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->SendMessage(WM_CLOSE);
}


HBRUSH CSignUpDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->GetDlgCtrlID()==IDC_S2)  
  {
      pDC->SelectObject(&m_font);   
  }

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
BOOL CSignUpDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		OnBnClickedSignUp();
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
} 