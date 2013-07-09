// UpdatePasswordDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "UpdatePasswordDlg.h"
#include "afxdialogex.h"
#include "MD5.h"

// CUpdatePasswordDlg 对话框

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
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK, &CUpdatePasswordDlg::OnBnClickedCheck)
	ON_WM_SYSCOMMAND()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CUpdatePasswordDlg 消息处理程序


BOOL CUpdatePasswordDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化

	myFlash=new CDlgFlash(this);
	myFlash->SetFlashCreateSpeed(20,20);
	//myFlash->SetFlashDestroySpeed(5);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CUpdatePasswordDlg::OnClose()
{
	//myFlash-> StartFlashDestroyDlg();
	this->OnOK();
}

void CUpdatePasswordDlg::OnBnClickedCheck()
{
	// TODO: 在此添加控件通知处理程序代码
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
		AfxMessageBox("密码输入错误");
		return;
	}
	if(new_password == "")
	{
		AfxMessageBox("新密码不能为空");
		return;
	}
	else if(new_password != check_password)
	{
		AfxMessageBox("两次输入密码不一致！");
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnSysCommand(nID, lParam);
}


BOOL CUpdatePasswordDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
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

void CUpdatePasswordDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	myFlash->OnTimer(nIDEvent);
	CDialog::OnTimer(nIDEvent);
}
