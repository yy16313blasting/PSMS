// SingUp.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SingUp.h"
#include "afxdialogex.h"


// CSingUp 对话框

IMPLEMENT_DYNAMIC(CSingUp, CDialog)

CSingUp::CSingUp(CWnd* pParent /*=NULL*/)
	: CDialog(CSingUp::IDD, pParent)
{

}

CSingUp::~CSingUp()
{
}

void CSingUp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSingUp, CDialog)
END_MESSAGE_MAP()


// CSingUp 消息处理程序
