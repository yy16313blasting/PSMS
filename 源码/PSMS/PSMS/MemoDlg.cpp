// MemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "MemoDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"

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
	ON_BN_CLICKED(IDC_MEMO_ADD, &CMemoDlg::OnBnClickedMemoAdd)
	ON_BN_CLICKED(IDC_MEMO_DELETE, &CMemoDlg::OnBnClickedMemoDelete)
	ON_BN_CLICKED(IDC_MEMO_UPDATE, &CMemoDlg::OnBnClickedMemoUpdate)
	ON_BN_CLICKED(IDC_MEMO_DELETEALL, &CMemoDlg::OnBnClickedMemoDeleteall)
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

void CMemoDlg::OnBnClickedMemoAdd()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDelete()
{
	POSITION p=m_MemoList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_MemoList.GetNextSelectedItem(p); //��ȡѡ���е�����
		CMemo d;
		d.SetID(atoi(m_MemoList.GetItemText(nSelected,3)));
		m_user.RemoveMemo(d);
		m_MemoList.DeleteItem(nSelected); //��������ɾ��
		p  = m_MemoList.GetFirstSelectedItemPosition();  

	}
}


void CMemoDlg::OnBnClickedMemoUpdate()
{
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDeleteall()
{
	CleanList();
	m_user.PurgeMemo();
}
