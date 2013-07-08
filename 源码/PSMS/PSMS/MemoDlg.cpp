// MemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "MemoDlg.h"
#include "afxdialogex.h"


// CMemoDlg �Ի���

IMPLEMENT_DYNAMIC(CMemoDlg, CDialog)

CMemoDlg::CMemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemoDlg::IDD, pParent)
{
}

CMemoDlg::~CMemoDlg()
{
}

void CMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MEMO_LIST, m_MemoList);
}


BEGIN_MESSAGE_MAP(CMemoDlg, CDialog)
END_MESSAGE_MAP()


// CMemoDlg ��Ϣ�������
void CMemoDlg::InitListCtrol()
{

	DWORD dwStyle = m_MemoList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_MemoList.SetExtendedStyle(dwStyle);	//������չ���

		m_MemoList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_MemoList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_MemoList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
	
}

void CMemoDlg::ShowList()
  {	
	int icount=m_user.CountAllMemo();
	if(0==icount)
	{
		AfxMessageBox("û�м�¼");
	return;
	}
	CMemo* list =new CMemo[icount];
	m_user.GetAllMemo(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		m_MemoList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_MemoList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_MemoList.SetItemText(0,1,list[i].GetTitle());
		m_MemoList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}

void  CMemoDlg::CleanList()
{
m_MemoList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CMemoDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}