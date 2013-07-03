// Remind.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "Remind.h"
#include "afxdialogex.h"


// CRemind 对话框

IMPLEMENT_DYNAMIC(CRemind, CDialog)

CRemind::CRemind(CWnd* pParent /*=NULL*/)
	: CDialog(CRemind::IDD, pParent)
{

}

CRemind::~CRemind()
{
}

void CRemind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemind, CDialog)
END_MESSAGE_MAP()


// CRemind 消息处理程序
