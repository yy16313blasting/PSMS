// DateRemindDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "PSMS.h"
#include "DateRemindDlg.h"
#include "afxdialogex.h"

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
	int icount=user.CountAllDateRemind();
	if(0==icount)
	{
		AfxMessageBox("û�м�¼");
	return;
	}
	CDateRemind* list =new CDateRemind[icount];
	user.GetAllDateRemind(list);
	
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