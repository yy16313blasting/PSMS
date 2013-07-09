// Remind.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "RemindDlg.h"
#include "afxdialogex.h"


// CRemindDlg 对话框

IMPLEMENT_DYNAMIC(CRemindDlg, CDialog)

CRemindDlg::CRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemindDlg::IDD, pParent)
{
}

CRemindDlg::~CRemindDlg()
{
}

void CRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemindDlg, CDialog)
	ON_BN_CLICKED(IDC_CHECK, &CRemindDlg::OnBnClickedCheck)
	ON_BN_CLICKED(IDC_REMIND_LATER, &CRemindDlg::OnBnClickedRemindLater)
	ON_WM_TIMER()
END_MESSAGE_MAP()


void CRemindDlg::OnBnClickedCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnOK();
}


void CRemindDlg::OnBnClickedRemindLater()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_szType == "TimeRemind")
	{
		SetTimer(m_nTimerID,m_nFrequency*1000,NULL);
		this->ShowWindow(SW_HIDE);
		m_MusicPlayer.playAudioOfTimeRemind();
	}
}

void CRemindDlg::SetType(CString type)
{
	m_szType = type;
}

void CRemindDlg::SetRemindFrequency(int frequency)
{
	m_nFrequency = frequency;
}

void CRemindDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_szType == "TimeRemind")
	{
		this->ShowWindow(SW_SHOW);
		m_MusicPlayer.playAudioOfTimeRemind();
		KillTimer(m_nTimerID);
	}
	CDialog::OnTimer(nIDEvent);
}


BOOL CRemindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_MusicPlayer.playAudioOfTimeRemind();
	m_nTimerID = 0;

	CRect rect;
	this->GetWindowRect(&rect);
	int nWidth=GetSystemMetrics(SM_CXFULLSCREEN);  //屏幕宽度    
	int nHeight=GetSystemMetrics(SM_CYFULLSCREEN); //屏幕高度
	rect.left = nWidth - rect.Width();
	rect.top = nHeight - rect.Height();
	rect.bottom = nHeight;
	rect.right = nWidth;
	this->SetWindowPos(NULL,rect.left,rect.top,rect.Width(),rect.Height(),SWP_SHOWWINDOW);

	CString msg;
	GetDlgItem(IDC_STATIC)->GetWindowTextA(msg);
	msg+='\n';
	msg+=m_szContent;
	GetDlgItem(IDC_STATIC)->SetWindowTextA(msg);
	if(m_szType == "DateRemind" || m_szType == "Holiday")
		GetDlgItem(IDC_REMIND_LATER)->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CRemindDlg::SetContent(CString content)
{
	m_szContent = content;
}