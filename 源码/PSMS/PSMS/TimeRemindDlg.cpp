// TimeRemindDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "TimeRemindDlg.h"
#include "afxdialogex.h"


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
	{	
		m_TimeRemindList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_TimeRemindList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_TimeRemindList.SetItemText(0,1,list[i].GetTitle());
		m_TimeRemindList.SetItemText(0,2,list[i].GetContent());
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CTimeRemindDlg::OnBnClickedTimeremindDelete()
{
	POSITION p=m_TimeRemindList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_TimeRemindList.GetNextSelectedItem(p); //��ȡѡ���е�����  
	
		m_TimeRemindList.DeleteItem(nSelected); //��������ɾ��
		p  = m_TimeRemindList.GetFirstSelectedItemPosition();  

	}
}


void CTimeRemindDlg::OnBnClickedTimeremindUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CTimeRemindDlg::OnBnClickedTimeremindDeleteall()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
