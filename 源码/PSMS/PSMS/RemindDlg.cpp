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
END_MESSAGE_MAP()
