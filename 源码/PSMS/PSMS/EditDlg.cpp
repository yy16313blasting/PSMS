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
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Date);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_Time);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_BN_CLICKED(IDC_EDIT, &CEditDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_CANCEL_EDIT, &CEditDlg::OnBnClickedCancelEdit)
END_MESSAGE_MAP()


// CEditDlg 消息处理程序


void CEditDlg::OnBnClickedEdit()
{

	GetDlgItem(IDC_EDIT_TITLE)->GetWindowText(m_editTitle); 
	GetDlgItem(IDC_EDIT_CONTENT)->GetWindowText(m_editContent); 
	CTime date,time;
	m_Date.GetTime(date);
	m_Time.GetTime(time);
	
	//CString str=("00:00:00");
	 m_strDateTime=date.Format("%Y/%m/%d ")+time.Format("%H:%M:%S");
	if("Diary" == m_szType)
	{
		CDiary d;
		d.SetTitle(m_editTitle);
		d.SetContent(m_editContent);
		d.SetDate(m_strDateTime);
		d.SetUser(m_user.GetName());
		m_user.AddDiary(d);
		m_strID.Format("%d",d.GetID());
	}
	if("Memo" == m_szType)
	{
		CMemo d;
		d.SetTitle(m_editTitle);
		d.SetContent(m_editContent);
		d.SetDate(m_strDateTime);
		d.SetUser(m_user.GetName());
		m_user.AddMemo(d);
	}
	if("TimeRemind" == m_szType)
	{
		CTimeRemind d;
		d.SetTitle(m_editTitle);
		d.SetContent(m_editContent);
		d.SetDate(m_strDateTime);
		d.SetUser(m_user.GetName());
		d.SetRemindFrequency(10);
		m_user.AddTimeRemind(d);
	}
	if("DateRemind" == m_szType)
	{
		CDateRemind d;
		d.SetTitle(m_editTitle);
		d.SetContent(m_editContent);
		d.SetDate(m_strDateTime);
		d.SetUser(m_user.GetName());
		d.SetRemindFrequency(100);
		m_user.AddDateRemind(d);
	}
	this->OnOK();
}


void CEditDlg::OnBnClickedCancelEdit()
{
	this->OnCancel();
	//exit(0);
}
void CEditDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}

void CEditDlg::SetType(CString type)
{
	m_szType=type;
}

CString CEditDlg::GetTitle()
{
	return m_editTitle;
}

CString CEditDlg::GetContent()
{
	return m_editContent;;
}

CString CEditDlg::GetDateTime()
{
	return m_strDateTime;;
}

CString CEditDlg::GetID()
{
	return m_strID;
}

BOOL CEditDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{
		OnBnClickedEdit();
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
} 