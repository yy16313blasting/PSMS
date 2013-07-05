// SignIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignInDlg.h"
#include "afxdialogex.h"
#include "PSMSDlg.h"


// CSignInDlg �Ի���

IMPLEMENT_DYNAMIC(CSignInDlg, CDialog)

CSignInDlg::CSignInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignInDlg::IDD, pParent)
	, m_editUserName(_T(""))
	, m_editPassWord(_T(""))
{

}

CSignInDlg::~CSignInDlg()
{
}

void CSignInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_USERNAME, m_editUserName);
	DDX_Text(pDX, IDC_INPUT_PASSWORD, m_editPassWord);
}


BEGIN_MESSAGE_MAP(CSignInDlg, CDialog)
	ON_BN_CLICKED(IDC_SIGN_IN, &CSignInDlg::OnBnClickedSignIn)
END_MESSAGE_MAP()


// CSignInDlg ��Ϣ�������


void CSignInDlg::OnBnClickedSignIn()
{  
	
	BOOL bLogOn=FALSE;
	bool ExistUser;
	CString m_szName,m_szPassword;
	GetDlgItem(IDC_INPUT_USERNAME)->GetWindowText(m_editUserName); 
	 GetDlgItem(IDC_INPUT_PASSWORD)->GetWindowText(m_editPassWord); 
	 if(m_editUserName.IsEmpty()||m_editPassWord.IsEmpty())
	{
		AfxMessageBox("�û��������벻��Ϊ��!");
		return;
	}// TODO: �ڴ���ӿؼ�֪ͨ����������
	 ExistUser=user.ExistUser(m_editUserName);
	 m_szPassword=user.GetUserPassword(m_editUserName);
	 if(ExistUser==FALSE)
	{AfxMessageBox("û�и��û�");
	  return;
	} 
	else 
	{ 
		if(m_editPassWord==m_szPassword)
	{AfxMessageBox("��½�ɹ�!");
	} 
	else 
	{  AfxMessageBox("��¼���벻��ȷ");
	   return;
	}
	}
	
	
	CPSMSDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->DestroyWindow();
}
