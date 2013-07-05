// HolidayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"


// CHolidayDlg 对话框

IMPLEMENT_DYNAMIC(CHolidayDlg, CDialog)

CHolidayDlg::CHolidayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHolidayDlg::IDD, pParent)
{

}

CHolidayDlg::~CHolidayDlg()
{
}

void CHolidayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHolidayDlg, CDialog)
END_MESSAGE_MAP()


// CHolidayDlg 消息处理程序
