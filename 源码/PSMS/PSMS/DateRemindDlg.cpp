// DateRemindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "DateRemindDlg.h"
#include "afxdialogex.h"


// CDateRemindDlg 对话框

IMPLEMENT_DYNAMIC(CDateRemindDlg, CDialog)

CDateRemindDlg::CDateRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateRemindDlg::IDD, pParent)
{

}

CDateRemindDlg::~CDateRemindDlg()
{
}

void CDateRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDateRemindDlg, CDialog)
END_MESSAGE_MAP()


// CDateRemindDlg 消息处理程序
