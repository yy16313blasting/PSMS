// SignIn.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignUp.h"
#include "afxdialogex.h"


// CSignUp 对话框

IMPLEMENT_DYNAMIC(CSignUp, CDialog)

CSignUp::CSignUp(CWnd* pParent /*=NULL*/)
	: CDialog(CSignUp::IDD, pParent)
{

}

CSignUp::~CSignUp()
{
}

void CSignUp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignUp, CDialog)
END_MESSAGE_MAP()


// CSignUp 消息处理程序
