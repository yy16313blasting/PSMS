// Remind.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "RemindDlg.h"
#include "afxdialogex.h"


// CRemindDlg 对话框

IMPLEMENT_DYNAMIC(CRemindDlg, CDialog)

CRemindDlg::CRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemindDlg::IDD, pParent)
{
}

CRemindDlg::~CRemindDlg()
{
}

void CRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemindDlg, CDialog)
	ON_BN_CLICKED(IDC_CHECK, &CRemindDlg::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_REMIND_LATER, &CRemindDlg::OnBnClickedRemindLater)
END_MESSAGE_MAP()


void CRemindDlg::OnBnClickedCheck()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CRemindDlg::OnBnClickedRemindLater()
{
	// TODO: 在此添加控件通知处理程序代码
}
