// SettingsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SettingsDlg.h"
#include "afxdialogex.h"


// CSettingsDlg 对话框

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
	ON_BN_CLICKED(IDC_EDIT, &CSettingsDlg::OnBnClickedEdit)
END_MESSAGE_MAP()


// CSettingsDlg 消息处理程序


void CSettingsDlg::OnBnClickedUpdatePassword()
{
	CUpdatePasswordDlg dlg;
	dlg.SetUser(m_user);
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CSettingsDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}

void CSettingsDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


//void CSettingsDlg::PreInitDialog()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	CDialog::PreInitDialog();
//}


BOOL CSettingsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(true);
	((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(true);
	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_OUTPUT_USERNAME)->SetWindowTextA("用户名："+m_user.GetName());
	GetDlgItem(IDC_SIGNATURE)->SetWindowTextA(m_user.GetMotto());
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSettingsDlg::OnBnClickedEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	GetDlgItem(IDC_EDIT)->GetWindowTextA(text);
	if(text == "编辑")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(false);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(false);
		//((CEdit*)GetWindow(IDC_SELETE_SEX))->SetReadOnly(false);
		//GetDlgItem(IDC_SIGNATURE)->SetWindowTextA("HEHE");
		//((CComboBox*)GetDlgItem(IDC_SELETE_SEX))->DropDownStyle(
		GetDlgItem(IDC_EDIT)->SetWindowTextA("完成");
	}
	else if(text == "完成")
	{
		//((CEdit*)GetDlgItem(IDC_EDIT2))->SetReadOnly(true);
		((CEdit*)GetDlgItem(IDC_SIGNATURE))->SetReadOnly(true);
		//((CComb*)
		GetDlgItem(IDC_EDIT)->SetWindowTextA("编辑");
		CString str;
		GetDlgItem(IDC_SIGNATURE)->GetWindowTextA(str);
		m_user.UpdateMotto(str);
	}
}


BOOL CSettingsDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}
