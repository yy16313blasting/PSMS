// SignIn.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignInDlg.h"
#include "afxdialogex.h"
#include "PSMSDlg.h"


// CSignInDlg 对话框

IMPLEMENT_DYNAMIC(CSignInDlg, CDialog)

CSignInDlg::CSignInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignInDlg::IDD, pParent)
{

}

CSignInDlg::~CSignInDlg()
{
}

void CSignInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignInDlg, CDialog)
	ON_BN_CLICKED(IDC_SIGN_IN, &CSignInDlg::OnBnClickedSignIn)
END_MESSAGE_MAP()


// CSignInDlg 消息处理程序


void CSignInDlg::OnBnClickedSignIn()
{
	// TODO: 在此添加控件通知处理程序代码
	CPSMSDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->DestroyWindow();
}
