// SettingsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SettingsDlg.h"
#include "afxdialogex.h"


// CSettingsDlg �Ի���

IMPLEMENT_DYNAMIC(CSettingsDlg, CDialog)

CSettingsDlg::CSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDlg::IDD, pParent)
{

}

CSettingsDlg::~CSettingsDlg()
{
}

void CSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialog)
	ON_BN_CLICKED(IDC_UPDATE_PASSWORD, &CSettingsDlg::OnBnClickedUpdatePassword)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSettingsDlg ��Ϣ�������


void CSettingsDlg::OnBnClickedUpdatePassword()
{
	CUpdatePasswordDlg dlg;
	dlg.SetUser(m_user);
	dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CSettingsDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}

void CSettingsDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString text;
	GetDlgItem(IDC_BUTTON1)->GetWindowTextA(text);
	if(text == "�༭")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(false);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(false);
		//((CEdit*)GetWindow(IDC_SELETE_SEX))->SetReadOnly(false);
		GetDlgItem(IDC_SELETE_SEX)->ShowWindow(SW_SHOW);
		//((CComboBox*)GetDlgItem(IDC_SELETE_SEX))->DropDownStyle(
		GetDlgItem(IDC_BUTTON1)->SetWindowTextA("���");
	}
	else if(text == "���")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(true);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(true);
		GetDlgItem(IDC_SELETE_SEX)->ShowWindow(SW_HIDE);
		//((CComb*)
		GetDlgItem(IDC_BUTTON1)->SetWindowTextA("�༭");
	}
}


//void CSettingsDlg::PreInitDialog()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//	CDialog::PreInitDialog();
//}


BOOL CSettingsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(true);
	((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(true);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_OUTPUT_USERNAME)->SetWindowTextA("�û�����"+m_user.GetName());
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
