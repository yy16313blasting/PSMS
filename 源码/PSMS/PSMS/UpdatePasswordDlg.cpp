// UpdatePasswordDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "UpdatePasswordDlg.h"
#include "afxdialogex.h"
#include "MD5.h"

// CUpdatePasswordDlg �Ի���

IMPLEMENT_DYNAMIC(CUpdatePasswordDlg, CDialog)

CUpdatePasswordDlg::CUpdatePasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdatePasswordDlg::IDD, pParent)
{

}

CUpdatePasswordDlg::~CUpdatePasswordDlg()
{
}

void CUpdatePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUpdatePasswordDlg, CDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK, &CUpdatePasswordDlg::OnBnClickedCheck)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CUpdatePasswordDlg ��Ϣ�������


void CUpdatePasswordDlg::Show()
{
	int swidth= GetSystemMetrics(SM_CXFULLSCREEN);
	int sheight= GetSystemMetrics(SM_CYFULLSCREEN);
	this->GetClientRect(&m_rect);
	m_rect.left=(swidth-m_rect.Width())/2;
	m_rect.top=(sheight-m_rect.Height())/2;
	int height = 0;
	while(height<m_rect.Height())
	{
		this->SetWindowPos(NULL,m_rect.left,m_rect.top,m_rect.Width(),height,SWP_SHOWWINDOW);
		height++;
		Sleep(1);
	}
}

void CUpdatePasswordDlg::Hide()
{
	this->GetClientRect(&m_rect);
	int height=m_rect.Height();
	while(height>0)
	{
		this->SetWindowPos(NULL,m_rect.left,m_rect.top,m_rect.Width(),height,SWP_SHOWWINDOW);
		height--;
		Sleep(1);
	}
}

BOOL CUpdatePasswordDlg::OnInitDialog()
{
	::AfxGetMainWnd()->CenterWindow();
	CDialog::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CUpdatePasswordDlg::OnClose()
{
	CDialog::OnClose();
}

void CUpdatePasswordDlg::OnBnClickedCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString password;
	CString new_password;
	CString check_password;

	GetDlgItem(IDC_INPUT_ORIGINAL_PASSWORD)->GetWindowTextA(password);
	GetDlgItem(IDC_INPUT_NEWPASSWORD)->GetWindowTextA(new_password);
	GetDlgItem(IDC_CHECK_NEWPASSWORD)->GetWindowTextA(check_password);

	CMD5 md5;
	md5.GenerateCMD5((unsigned char*)(LPCTSTR)password,password.GetLength());
	password = md5.ToString();
	if(m_user.GetUserPassword(m_user.GetName()) != password)
	{
		AfxMessageBox("�����������");
		return;
	}
	if(new_password == "")
	{
		AfxMessageBox("�����벻��Ϊ��");
		return;
	}
	else if(new_password != check_password)
	{
		AfxMessageBox("�����������벻һ�£�");
		return;
	}
	else
	{
		m_user.UpdatePassword(new_password);
		this->OnOK();
	}
}


void CUpdatePasswordDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnSysCommand(nID, lParam);
}


BOOL CUpdatePasswordDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		OnBnClickedCheck();
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}


void CUpdatePasswordDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}