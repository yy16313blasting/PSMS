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
	DDX_Control(pDX, IDC_SELETE_TIMEGAP, m_SetFrequency);
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialog)
	ON_BN_CLICKED(IDC_UPDATE_PASSWORD, &CSettingsDlg::OnBnClickedUpdatePassword)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_EDIT, &CSettingsDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_SELETE_MUSIC, &CSettingsDlg::OnBnClickedSeleteMusic)
	ON_CBN_SELCHANGE(IDC_SELETE_TIMEGAP, &CSettingsDlg::OnCbnSelchangeSeleteTimegap)
	ON_CBN_SELCHANGE(IDC_SELETE_TIMEGAP, &CSettingsDlg::OnCbnSelchangeSeleteTimegap)
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
	GetDlgItem(IDC_SIGNATURE)->SetWindowTextA(m_user.GetMotto());
	m_SetFrequency.AddString("1����");
	m_SetFrequency.AddString("5����");
	m_SetFrequency.AddString("10����");
	int n;
	n = m_user.GetTimeFrequency();
	if( 1 == n)
		m_SetFrequency.SetWindowText( "1����");
	else if ( 5 == n)
		m_SetFrequency.SetWindowTextA("5����");
	else if (10 == n)
		m_SetFrequency.SetWindowTextA("10����");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSettingsDlg::OnBnClickedEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString text;
	GetDlgItem(IDC_EDIT)->GetWindowTextA(text);
	if(text == "�༭")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(false);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(false);
		//((CEdit*)GetWindow(IDC_SELETE_SEX))->SetReadOnly(false);
		//GetDlgItem(IDC_SIGNATURE)->SetWindowTextA("HEHE");
		//((CComboBox*)GetDlgItem(IDC_SELETE_SEX))->DropDownStyle(
		GetDlgItem(IDC_EDIT)->SetWindowTextA("���");
	}
	else if(text == "���")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(true);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(true);
		//((CComb*)
		GetDlgItem(IDC_EDIT)->SetWindowTextA("�༭");
		CString str;
		GetDlgItem(IDC_SIGNATURE)->GetWindowTextA(str);
		m_user.UpdateMotto(str);
	}
}


BOOL CSettingsDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}


void CSettingsDlg::OnBnClickedSeleteMusic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMusicPlayer player;
	player.transferPath();
}




void CSettingsDlg::OnCbnSelchangeSeleteTimegap()
{
	CString str;
	m_SetFrequency.GetWindowTextA(str);
	if("1����"==str)
	{
		m_user.UpdateTimeFrequency(1);
	}
	if("5����"==str)
	{
		m_user.UpdateTimeFrequency(5);
	}
	if("10����"==str)
	{
		m_user.UpdateTimeFrequency(10);
	}
	CString str1;
	str1.Format("%d",m_user.GetTimeFrequency());

}
