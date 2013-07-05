// SignIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignUpDlg.h"
#include "afxdialogex.h"
#include "UserDA.h"


// CSignUpDlg �Ի���

IMPLEMENT_DYNAMIC(CSignUpDlg, CDialog)

CSignUpDlg::CSignUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignUpDlg::IDD, pParent)
{

}

CSignUpDlg::~CSignUpDlg()
{
}

void CSignUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignUpDlg, CDialog)
	ON_BN_CLICKED(IDC_SIGN_UP, &CSignUpDlg::OnBnClickedSignUp)
	ON_BN_CLICKED(IDC_RETURN, &CSignUpDlg::OnBnClickedReturn)
END_MESSAGE_MAP()


// CSignUpDlg ��Ϣ�������


void CSignUpDlg::OnBnClickedSignUp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	CString password;
	CString check_password;
	GetDlgItem(IDC_CREATE_USERNAME)->GetWindowText(name);
	GetDlgItem(IDC_CREATE_PASSORD)->GetWindowText(password);
	GetDlgItem(IDC_CHECK_CREATE_PASSWORD)->GetWindowText(check_password);
	if(name.IsEmpty()||password.IsEmpty())
	{
		AfxMessageBox("�û��������벻��Ϊ��!");
		return;
	}
	CUserDA userDA;
	if(userDA.ExistUser(name))
	{
		AfxMessageBox("�û����Ѵ��ڣ�");
		return;
	}
	if(check_password!=password)
	{
		AfxMessageBox("�������벻һ�£�����������");
		GetDlgItem(IDC_CREATE_PASSORD)->SetWindowText("");
		GetDlgItem(IDC_CHECK_CREATE_PASSWORD)->SetWindowText("");
		return;
	}
	userDA.AddUser(name,password);
	this->SendMessage(WM_CLOSE);
}


void CSignUpDlg::OnBnClickedReturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->SendMessage(WM_CLOSE);
}
