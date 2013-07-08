// Editor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// CEditDlg �Ի���

IMPLEMENT_DYNAMIC(CEditDlg, CDialog)

CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
}

CEditDlg::~CEditDlg()
{
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_BN_CLICKED(IDC_EDIT, &CEditDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_CANCEL_EDIT, &CEditDlg::OnBnClickedCancelEdit)
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CEditDlg ��Ϣ�������


void CEditDlg::OnBnClickedEdit()
{	
	this->OnCancel();
}


void CEditDlg::OnBnClickedCancelEdit()
{
	this->OnCancel();
	//exit(0);
}
void CEditDlg::SetUser(CUser user)
{
	user.SetName(user.GetName());
}

HCURSOR CEditDlg::OnQueryDragIcon()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_pPage->UpdateWindow();
	return CDialog::OnQueryDragIcon();
}


void CEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if( (nID & 0xFFF0) == WM_WINDOWPOSCHANGED)
	{
		GetDlgItem(IDC_EDIT2)->SetWindowTextA("hehe");
	}
	CDialog::OnSysCommand(nID, lParam);
}
