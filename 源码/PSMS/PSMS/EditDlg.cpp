// Editor.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// CEditDlg 对话框

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


// CEditDlg 消息处理程序


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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pPage->UpdateWindow();
	return CDialog::OnQueryDragIcon();
}


void CEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if( (nID & 0xFFF0) == WM_WINDOWPOSCHANGED)
	{
		GetDlgItem(IDC_EDIT2)->SetWindowTextA("hehe");
	}
	CDialog::OnSysCommand(nID, lParam);
}
