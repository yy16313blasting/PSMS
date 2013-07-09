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
	DDX_Control(pDX, IDC_SELETE_TIMEGAP, m_SetFrequency);
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialog)
	ON_BN_CLICKED(IDC_UPDATE_PASSWORD, &CSettingsDlg::OnBnClickedUpdatePassword)
	ON_BN_CLICKED(IDC_BUTTON1, &CSettingsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_EDIT, &CSettingsDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_SELETE_MUSIC, &CSettingsDlg::OnBnClickedSeleteMusic)
	ON_CBN_SELCHANGE(IDC_SELETE_TIMEGAP, &CSettingsDlg::OnCbnSelchangeSeleteTimegap)
	ON_CBN_SELCHANGE(IDC_SELETE_TIMEGAP, &CSettingsDlg::OnCbnSelchangeSeleteTimegap)
	ON_BN_CLICKED(IDC_SELETE_, &CSettingsDlg::OnBnClickedSelete)
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
	m_SetFrequency.AddString("1分钟");
	m_SetFrequency.AddString("5分钟");
	m_SetFrequency.AddString("10分钟");
	int n;
	n = m_user.GetTimeFrequency();
	if( 1 == n)
		m_SetFrequency.SetWindowText( "1分钟");
	else if ( 5 == n)
		m_SetFrequency.SetWindowTextA("5分钟");
	else if (10 == n)
		m_SetFrequency.SetWindowTextA("10分钟");

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


void CSettingsDlg::OnBnClickedSeleteMusic()
{
	// TODO: 在此添加控件通知处理程序代码
	CMusicPlayer player;
	player.transferPath();
	player.write();
}




void CSettingsDlg::OnCbnSelchangeSeleteTimegap()
{
	CString str;
	m_SetFrequency.GetWindowTextA(str);
	if("1分钟"==str)
	{
		m_user.UpdateTimeFrequency(1);
	}
	if("5分钟"==str)
	{
		m_user.UpdateTimeFrequency(5);
	}
	if("10分钟"==str)
	{
		m_user.UpdateTimeFrequency(10);
	}
	CString str1;
	str1.Format("%d",m_user.GetTimeFrequency());

}


void CSettingsDlg::OnBnClickedSelete()
{
//	// TODO: 在此添加控件通知处理程序代码
HKEY hKey;
 char path[MAX_PATH];
 ::GetModuleFileName(NULL,path,MAX_PATH);
 CString str;
 str.Format("%s",path);
 LPCTSTR DATA_SET = _T("SoftWare\\Microsoft\\Windows\\CurrentVersion\\Run");
 ::RegOpenKeyEx(HKEY_CURRENT_USER, 
	 _T("SoftWare\\Microsoft\\Windows\\CurrentVersion\\Run"),0,KEY_ALL_ACCESS,&hKey);
 CButton *P = (CButton*)GetDlgItem(IDC_SELECT_1);
 bool a = P->GetCheck();
 if (P->GetCheck())
 {
	 int ret = ::RegSetValueEx(hKey,str,0,REG_SZ,(BYTE*)(LPCSTR)str,strlen(str)+1);
  if(ERROR_SUCCESS == ret)
   ::AfxMessageBox("系统自启动设置成功！");
  ::RegCloseKey(hKey);
 }
 else
 {
  if (ERROR_SUCCESS == ::RegSetValueEx(hKey,str,0,REG_SZ,NULL,NULL))
  {
   ::AfxMessageBox("取消开机开机自启动！");
  }
  ::RegCloseKey(hKey);
 }
	 //HKEY hKey;  
  //  HKEY hNewKey;  
  //  DWORD dwDisposition=0;  
  //
  //  __try  
  //  {  
  //      char binPath[MAX_PATH]="D:\\Program Files\\QQ\\Bin\\QQ.exe";//在这里设置你要启动的程序的路径  
  //        
		//::GetModuleFileName(NULL,binPath,MAX_PATH);
  //      if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,  
  //          _T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),  
  //          0,KEY_ALL_ACCESS,&hKey)!=ERROR_SUCCESS)  
  //          __leave;  
  //
  //
  //      if(RegSetValueEx(hKey,  
  //          _T("AutoStart"),  
  //          0,REG_SZ,(const BYTE*)binPath,  
  //          strlen(binPath)+1)!=ERROR_SUCCESS)  
  //          __leave;  
  //    
  //  }  
  //  __finally  
  //  {  
  //      RegCloseKey(hKey);  
  //  }      
  //    
    //system("pause");  
}
