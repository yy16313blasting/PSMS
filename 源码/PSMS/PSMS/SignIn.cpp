// SignIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignIn.h"
#include "afxdialogex.h"


// CSignIn �Ի���

IMPLEMENT_DYNAMIC(CSignIn, CDialog)

CSignIn::CSignIn(CWnd* pParent /*=NULL*/)
	: CDialog(CSignIn::IDD, pParent)
{

}

CSignIn::~CSignIn()
{
}

void CSignIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignIn, CDialog)
END_MESSAGE_MAP()


// CSignIn ��Ϣ�������
