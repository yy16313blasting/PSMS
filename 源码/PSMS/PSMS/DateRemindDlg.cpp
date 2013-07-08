// DateRemindDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "PSMS.h"
#include "DateRemindDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"
// CDateRemindDlg �Ի���

IMPLEMENT_DYNAMIC(CDateRemindDlg, CDialog)

CDateRemindDlg::CDateRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateRemindDlg::IDD, pParent)
{
}

CDateRemindDlg::~CDateRemindDlg()
{
}

void CDateRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATEREMIND_LIST, m_DateRemindList);
}

BEGIN_MESSAGE_MAP(CDateRemindDlg, CDialog)
	ON_BN_CLICKED(IDC_DATEREMIND_ADD, &CDateRemindDlg::OnBnClickedDateremindAdd)
	ON_BN_CLICKED(IDC_DATEREMIND_DELETE, &CDateRemindDlg::OnBnClickedDateremindDelete)
	ON_BN_CLICKED(IDC_DATEREMIND_UPDATE, &CDateRemindDlg::OnBnClickedDateremindUpdate)
	ON_BN_CLICKED(IDC_DATEREMIND_DELETEALL, &CDateRemindDlg::OnBnClickedDateremindDeleteall)
END_MESSAGE_MAP()

// CDateRemindDlg ��Ϣ�������

void CDateRemindDlg::InitListCtrol()
{

	DWORD dwStyle = m_DateRemindList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_DateRemindList.SetExtendedStyle(dwStyle);	//������չ���

		m_DateRemindList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_DateRemindList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_DateRemindList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
	
}

void CDateRemindDlg::ShowList()
  {	
	int icount=m_user.CountAllDateRemind();
	if(0==icount)
	{
		
	return;
	}
	CDateRemind* list =new CDateRemind[icount];
	m_user.GetAllDateRemind(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		m_DateRemindList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_DateRemindList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_DateRemindList.SetItemText(0,1,list[i].GetTitle());
		m_DateRemindList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}

void  CDateRemindDlg::CleanList()
{
m_DateRemindList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CDateRemindDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}

void CDateRemindDlg::OnBnClickedDateremindAdd()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CDateRemindDlg::OnBnClickedDateremindDelete()
{
	POSITION p=m_DateRemindList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_DateRemindList.GetNextSelectedItem(p); //��ȡѡ���е�����  
		CDateRemind d;
		d.SetID(atoi(m_DateRemindList.GetItemText(nSelected,3)));
		m_user.RemoveDateRemind(d);
		m_DateRemindList.DeleteItem(nSelected); //��������ɾ��
		p  = m_DateRemindList.GetFirstSelectedItemPosition();  

	}
}


void CDateRemindDlg::OnBnClickedDateremindUpdate()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CDateRemindDlg::OnBnClickedDateremindDeleteall()
{
	CleanList();
	m_user.PurgeDateRemind();
}
