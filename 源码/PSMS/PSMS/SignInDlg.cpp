// SignIn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "SignInDlg.h"
#include "afxdialogex.h"
#include "PSMSDlg.h"
#include "SignUpDlg.h"
#include "MD5.h"

// CSignInDlg �Ի���

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
END_MESSAGE_MAP()

// CSignInDlg ��Ϣ�������

void CSignInDlg::OnBnClickedSignIn()
{  

	BOOL bLogOn=FALSE;
	bool ExistUser;
	CString m_szName,m_szPassword;
	GetDlgItem(IDC_INPUT_USERNAME)->GetWindowText(m_editUserName); 
	GetDlgItem(IDC_INPUT_PASSWORD)->GetWindowText(m_editPassWord); 
	if(m_editUserName.IsEmpty()||m_editPassWord.IsEmpty())
	{
		AfxMessageBox("�û��������벻��Ϊ��!");
		return;
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ExistUser=user.ExistUser(m_editUserName);
	m_szPassword=user.GetUserPassword(m_editUserName);

	CMD5 md5;
	md5.GenerateCMD5((unsigned char*)(LPCTSTR)m_editPassWord,m_editPassWord.GetLength());
	m_editPassWord=md5.ToString();

	if(ExistUser==FALSE)
	{
		AfxMessageBox("û�и��û�");
		GetDlgItem(IDC_INPUT_USERNAME)->SetWindowText(""); 
		GetDlgItem(IDC_INPUT_PASSWORD)->SetWindowText(""); 
		GetDlgItem(IDC_INPUT_USERNAME)->SetFocus();
		return;
	} 
	else 
	{ 
		if(m_editPassWord==m_szPassword)
		{
			//AfxMessageBox("��½�ɹ�!");
		} 
		else 
		{  
			AfxMessageBox("��¼���벻��ȷ");
			//GetDlgItem(IDC_INPUT_USERNAME)->SetWindowText(""); 
			GetDlgItem(IDC_INPUT_PASSWORD)->SetWindowText(""); 
			GetDlgItem(IDC_INPUT_PASSWORD)->SetFocus();
			return;
		}
	}

	CPSMSDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
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
}

void CSignInDlg::OnBnClickedToSignUp()
{
	CSignUpDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}

void CSignInDlg::OnBnClickedUpdatePassword()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CDialog::OnInitDialog();

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
	 m_font.CreatePointFont(150,"΢���ź�");

	return TRUE; 
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSignInDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	if (pWnd->GetDlgCtrlID()==IDC_S1)  
	{
		pDC->SelectObject(&m_font);   
	}
	return hbr;
}
