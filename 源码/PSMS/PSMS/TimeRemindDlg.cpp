// TimeRemindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "TimeRemindDlg.h"
#include "afxdialogex.h"


// CTimeRemindDlg 对话框

IMPLEMENT_DYNAMIC(CTimeRemindDlg, CDialog)

CTimeRemindDlg::CTimeRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeRemindDlg::IDD, pParent)
{
}

CTimeRemindDlg::~CTimeRemindDlg()
{
}

void CTimeRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTimeRemindDlg, CDialog)
END_MESSAGE_MAP()


// CTimeRemindDlg 消息处理程序
