// MemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "MemoDlg.h"
#include "afxdialogex.h"


// CMemoDlg 对话框

IMPLEMENT_DYNAMIC(CMemoDlg, CDialog)

CMemoDlg::CMemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemoDlg::IDD, pParent)
{
}

CMemoDlg::~CMemoDlg()
{
}

void CMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMemoDlg, CDialog)
END_MESSAGE_MAP()


// CMemoDlg 消息处理程序
