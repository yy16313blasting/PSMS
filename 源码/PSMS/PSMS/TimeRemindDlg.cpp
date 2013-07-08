// TimeRemindDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "TimeRemindDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"

// CTimeRemindDlg �Ի���

IMPLEMENT_DYNAMIC(CTimeRemindDlg, CDialog)

CTimeRemindDlg::CTimeRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeRemindDlg::IDD, pParent)
{
}

CTimeRemindDlg::~CTimeRemindDlg()
{
}

void CTimeRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIMEREMIND_LIST, m_TimeRemindList);
}


BEGIN_MESSAGE_MAP(CTimeRemindDlg, CDialog)
	ON_BN_CLICKED(IDC_TIMEREMIND_ADD, &CTimeRemindDlg::OnBnClickedTimeremindAdd)
	ON_BN_CLICKED(IDC_TIMEREMIND_DELETE, &CTimeRemindDlg::OnBnClickedTimeremindDelete)
	ON_BN_CLICKED(IDC_TIMEREMIND_UPDATE, &CTimeRemindDlg::OnBnClickedTimeremindUpdate)
	ON_BN_CLICKED(IDC_TIMEREMIND_DELETEALL, &CTimeRemindDlg::OnBnClickedTimeremindDeleteall)
END_MESSAGE_MAP()


// CTimeRemindDlg ��Ϣ�������

void CTimeRemindDlg::InitListCtrol()
{

	DWORD dwStyle = m_TimeRemindList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_TimeRemindList.SetExtendedStyle(dwStyle);	//������չ���

		m_TimeRemindList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_TimeRemindList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_TimeRemindList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
		m_TimeRemindList.InsertColumn(3,"ID",LVCFMT_LEFT,0);
	
}

void CTimeRemindDlg::ShowList()
  {	
	int icount=m_user.CountAllTimeRemind();
	if(0==icount)
	{
		
	return;
	}
	CTimeRemind* list =new CTimeRemind[icount];
	m_user.GetAllTimeRemind(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	CString id;
		id.Format("%d",list[i].GetID());
		m_TimeRemindList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_TimeRemindList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_TimeRemindList.SetItemText(0,1,list[i].GetTitle());
		m_TimeRemindList.SetItemText(0,2,list[i].GetContent());
		m_TimeRemindList.SetItemText(0,3,id);
		++i;
	}
}
void CTimeRemindDlg::CleanList()
{
m_TimeRemindList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CTimeRemindDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}

void CTimeRemindDlg::OnBnClickedTimeremindAdd()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.SetType("TimeRemind");
	dlg.DoModal();
	m_TimeRemindList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
	m_TimeRemindList.SetItemText(0,0,dlg.GetDateTime());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
	m_TimeRemindList.SetItemText(0,1,dlg.GetTitle());
	m_TimeRemindList.SetItemText(0,2,dlg.GetContent());
	m_TimeRemindList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CTimeRemindDlg::OnBnClickedTimeremindDelete()
{
	POSITION p=m_TimeRemindList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_TimeRemindList.GetNextSelectedItem(p); //��ȡѡ���е�����  
		
		CTimeRemind d;
		d.SetID(atoi(m_TimeRemindList.GetItemText(nSelected,3)));
		m_TimeRemindList.DeleteItem(nSelected); //��������ɾ��
		m_user.RemoveTimeRemind(d);
		p  = m_TimeRemindList.GetFirstSelectedItemPosition();  
	}
}


void CTimeRemindDlg::OnBnClickedTimeremindUpdate()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CTimeRemindDlg::OnBnClickedTimeremindDeleteall()
{
	CleanList();
	m_user.PurgeTimeRemind();
}
