// SignIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignUp.h"
#include "afxdialogex.h"


// CSignUp �Ի���

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


// CSignUp ��Ϣ�������
