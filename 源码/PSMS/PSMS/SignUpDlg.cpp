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
}


BEGIN_MESSAGE_MAP(CSignUpDlg, CDialog)
	ON_BN_CLICKED(IDC_SIGN_UP, &CSignUpDlg::OnBnClickedSignUp)
	ON_BN_CLICKED(IDC_RETURN, &CSignUpDlg::OnBnClickedReturn)
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
	this->SendMessage(WM_CLOSE);
}


void CSignUpDlg::OnBnClickedReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->SendMessage(WM_CLOSE);
}
