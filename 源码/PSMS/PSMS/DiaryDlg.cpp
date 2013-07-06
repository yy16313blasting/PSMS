// DiaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "DiaryDlg.h"
#include "afxdialogex.h"


// CDiaryDlg 对话框

IMPLEMENT_DYNAMIC(CDiaryDlg, CDialog)

CDiaryDlg::CDiaryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiaryDlg::IDD, pParent)
{
}

CDiaryDlg::~CDiaryDlg()
{
}

void CDiaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDiaryDlg, CDialog)
END_MESSAGE_MAP()


// CDiaryDlg 消息处理程序
