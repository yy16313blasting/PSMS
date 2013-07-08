// SignIn.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignInDlg.h"
#include "afxdialogex.h"
#include "PSMSDlg.h"
#include "SignUpDlg.h"
#include "MD5.h"

// CSignInDlg 对话框

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
	ON_BN_CLICKED(IDC_QUIT, &CSignInDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_TO_SIGN_UP, &CSignInDlg::OnBnClickedToSignUp)
	ON_BN_CLICKED(IDC_UPDATE_PASSWORD, &CSignInDlg::OnBnClickedUpdatePassword)
	ON_BN_CLICKED(IDC_CANCEL, &CSignInDlg::OnBnClickedCancel)
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_INPUT_PASSWORD, &CSignInDlg::OnEnChangeInputPassword)
	ON_EN_CHANGE(IDC_INPUT_USERNAME, &CSignInDlg::OnEnChangeInputUsername)
END_MESSAGE_MAP()


// CSignInDlg 消息处理程序


void CSignInDlg::OnBnClickedSignIn()
{  
	//通过配置文件来令一次登录的用户名离线保存-Log In--username
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_INPUT_USERNAME);
	CString str;
	pBoxOne->GetWindowText(str);
	WritePrivateProfileString("Log In","username",str,ROAD);

	BOOL bLogOn=FALSE;
	bool ExistUser;
	CString m_szName,m_szPassword;
	GetDlgItem(IDC_INPUT_USERNAME)->GetWindowText(m_editUserName); 
	GetDlgItem(IDC_INPUT_PASSWORD)->GetWindowText(m_editPassWord); 
	if(m_editUserName.IsEmpty()||m_editPassWord.IsEmpty())
	{
		AfxMessageBox("用户名或密码不能为空!");
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
	ExistUser=m_user.ExistUser(m_editUserName);
	m_szPassword=m_user.GetUserPassword(m_editUserName);

	CMD5 md5;
	md5.GenerateCMD5((unsigned char*)(LPCTSTR)m_editPassWord,m_editPassWord.GetLength());
	m_editPassWord=md5.ToString();

	if(ExistUser==FALSE)
	{
		AfxMessageBox("没有该用户");
		GetDlgItem(IDC_INPUT_USERNAME)->SetWindowText(""); 
		GetDlgItem(IDC_INPUT_PASSWORD)->SetWindowText(""); 
		GetDlgItem(IDC_INPUT_USERNAME)->SetFocus();
		return;
	} 
	else 
	{ 
		if(m_editPassWord==m_szPassword)
		{
			//AfxMessageBox("登陆成功!");
		} 
		else 
		{  
			AfxMessageBox("登录密码不正确");
			//GetDlgItem(IDC_INPUT_USERNAME)->SetWindowText(""); 
			GetDlgItem(IDC_INPUT_PASSWORD)->SetWindowText(""); 
			GetDlgItem(IDC_INPUT_PASSWORD)->SetFocus();
			return;
		}
	}
	m_user.SetName(m_editUserName);

	CPSMSDlg dlg;
	dlg.SetUser(m_user);
	ShowWindow(SW_HIDE);
	dlg.DoModal();
	//this->ShowWindow(SW_HIDE);
	this->DestroyWindow();

	
}
BOOL CSignInDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		OnBnClickedSignIn();
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
		
} 

void CSignInDlg::OnBnClickedQuit()
{  
	this->DestroyWindow();
	// TODO: 在此添加控件通知处理程序代码
}


void CSignInDlg::OnBnClickedToSignUp()
{
	CSignUpDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void CSignInDlg::OnBnClickedUpdatePassword()
{
	// TODO: 在此添加控件通知处理程序代码
	CRect rect;
	GetWindowRect(&rect);
	int height=rect.Height();
	int step=1;
	while(height<m_nMaxWindowHeight)
	{
		this->SetWindowPos(NULL,rect.left,rect.top,rect.Width(),height,SWP_SHOWWINDOW);
		height+=step;
		Sleep(1);
	}
}


BOOL CSignInDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CRect rect;
	CRect son_rect;
	CRect screen_rect;
	
	::AfxGetMainWnd()->CenterWindow();
	
	GetWindowRect(&rect);
	m_nMaxWindowHeight=rect.Height();
	GetDlgItem(IDC_CHANGE_PASSWORD)->GetWindowRect(&son_rect);
	m_nMinWindowHeight=son_rect.top-rect.top;
	SetWindowPos(NULL,rect.left,rect.top,rect.Width(),m_nMinWindowHeight,SWP_SHOWWINDOW);

	 m_brush.CreateSolidBrush(RGB(255,255,255));  
	 m_font.CreatePointFont(150,"微软雅黑");

	 //运用读取配置文件->窗口显示的方式加快用户的操作速度
	 LPTSTR lpStr = new char[255];
	 GetPrivateProfileString("Log In","username","",lpStr,255,ROAD);
	 GetDlgItem(IDC_INPUT_USERNAME)->SetWindowText(lpStr);
	 
	 GetDlgItem(IDC_INPUT_PASSWORD)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSignInDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CRect rect;
	GetWindowRect(&rect);
	int height=rect.Height();
	int step=1;
	while(height>m_nMinWindowHeight)
	{
		this->SetWindowPos(NULL,rect.left,rect.top,rect.Width(),height,SWP_SHOWWINDOW);
		height-=step;
		Sleep(1);
	}
}


HBRUSH CSignInDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
/*	if (pWnd->GetDlgCtrlID()==IDC_S1)    
  {
      pDC->SetTextColor(RGB(0,255,0));  
      pDC->SetBkMode(TRANSPARENT);  
      pDC->SetBkColor(RGB(255,0,0));  
      return m_brush;               
  }   */
  if (pWnd->GetDlgCtrlID()==IDC_S1)  
  {
      pDC->SelectObject(&m_font);   
  }

 return hbr;

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
	//return m_brush;
}


void CSignInDlg::OnEnChangeInputPassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSignInDlg::OnEnChangeInputUsername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
