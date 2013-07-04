// SignIn.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignUpDlg.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CSignUpDlg 消息处理程序
