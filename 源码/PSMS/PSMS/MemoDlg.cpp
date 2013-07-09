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
	ON_NOTIFY(NM_CLICK, IDC_MEMO_LIST, &CMemoDlg::OnClickMemoList)
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
		m_MemoList.InsertColumn(3,"ID",LVCFMT_LEFT,0);
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
	{	CString id;
		id.Format("%d",list[i].GetID());
		m_MemoList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_MemoList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_MemoList.SetItemText(0,1,list[i].GetTitle());
		m_MemoList.SetItemText(0,2,list[i].GetContent());
		m_MemoList.SetItemText(0,3,id);
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
	dlg.Update(false);
	dlg.SetType("Memo");
	dlg.DoModal();
	m_MemoList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
	m_MemoList.SetItemText(0,0,dlg.GetDateTime());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
	m_MemoList.SetItemText(0,1,dlg.GetTitle());
	m_MemoList.SetItemText(0,2,dlg.GetContent());
	m_MemoList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDelete()
{
	POSITION p=m_MemoList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��
	if(!hasSelectedItem)
	{
		AfxMessageBox("�㻹û��ѡ��һ��");
		return;
	}
	while (p)      
	{      
		int  nSelected=m_MemoList.GetNextSelectedItem(p); //��ȡѡ���е�����
		CMemo d;
		d.SetID(atoi(m_MemoList.GetItemText(nSelected,3)));
		m_MemoList.DeleteItem(nSelected); //��������ɾ��
		m_user.RemoveMemo(d);
		p  = m_MemoList.GetFirstSelectedItemPosition();  
	}


}


void CMemoDlg::OnBnClickedMemoUpdate()
{

	if(!hasSelectedItem)
	{
		AfxMessageBox("�㻹û��ѡ��һ��");
		return;
	}
	
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetType("Memo");
	dlg.Update(true);
	dlg.SetUser(m_user);
	dlg.SetDateTime(m_szDateTime);
	dlg.SetTitle(m_szTitle);
	dlg.SetContent(m_szContent);
	dlg.SetID(m_nID);
	dlg.DoModal();
	m_MemoList.SetItemText(m_nItem,0,dlg.GetDateTime());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
	m_MemoList.SetItemText(m_nItem,1,dlg.GetTitle());
	m_MemoList.SetItemText(m_nItem,2,dlg.GetContent());
	m_MemoList.SetItemText(m_nItem,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDeleteall()
{
	if( AfxMessageBox("ɾ�����У�",MB_YESNO|MB_ICONQUESTION) == IDYES)
	{
		CleanList();
		m_user.PurgeMemo();
	}
}


BOOL CMemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	hasSelectedItem = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CMemoDlg::OnClickMemoList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNmListView = (NM_LISTVIEW*)pNMHDR;
	m_nItem = pNmListView->iItem;
	m_szDateTime = m_MemoList.GetItemText(m_nItem, 0);
	m_szTitle = m_MemoList.GetItemText(m_nItem, 1);
	m_szContent   = m_MemoList.GetItemText(m_nItem, 2);
	m_nID  = atoi(m_MemoList.GetItemText(m_nItem, 3));
	UpdateData(FALSE);
	*pResult = 0;

	if(-1 == m_nItem)
	{
		hasSelectedItem = false;
	}
	else
	{
		hasSelectedItem = true;
	}
	*pResult = 0;
}
