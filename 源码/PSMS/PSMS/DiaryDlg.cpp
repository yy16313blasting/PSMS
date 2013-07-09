// DiaryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "DiaryDlg.h"
#include "afxdialogex.h"
#include "EditDlg.h"

// CDiaryDlg �Ի���

IMPLEMENT_DYNAMIC(CDiaryDlg, CDialog)

CDiaryDlg::CDiaryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiaryDlg::IDD, pParent)
{
}

CDiaryDlg::~CDiaryDlg()
{
}

void CDiaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIARY_LIST, m_DiaryList);
}

BEGIN_MESSAGE_MAP(CDiaryDlg, CDialog)
	ON_BN_CLICKED(IDC_DIARY_ADD, &CDiaryDlg::OnBnClickedDiaryAdd)
	ON_BN_CLICKED(IDC_DIARY_DELETE, &CDiaryDlg::OnBnClickedDiaryDelete)
	ON_BN_CLICKED(IDC_DIARY_UPDATE, &CDiaryDlg::OnBnClickedDiaryUpdate)
	ON_BN_CLICKED(IDC_DIARY_DELETEALL, &CDiaryDlg::OnBnClickedDiaryDeleteall)
	ON_NOTIFY(NM_CLICK, IDC_DIARY_LIST, &CDiaryDlg::OnClickDiaryList)
END_MESSAGE_MAP()


// CDiaryDlg ��Ϣ�������
void CDiaryDlg::InitListCtrol()
{

	DWORD dwStyle = m_DiaryList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_DiaryList.SetExtendedStyle(dwStyle);	//������չ���

		m_DiaryList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_DiaryList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_DiaryList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
		m_DiaryList.InsertColumn(3,"ID",LVCFMT_LEFT,0);
	
}

void CDiaryDlg::ShowList()
  {	
	int icount=m_user.CountAllDiary();
	if(0==icount)
	{
		
	return;
	}
	CDiary* list =new CDiary[icount];
	m_user.GetAllDiary(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		CString id;
		id.Format("%d",list[i].GetID());
		m_DiaryList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_DiaryList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_DiaryList.SetItemText(0,1,list[i].GetTitle());
		m_DiaryList.SetItemText(0,2,list[i].GetContent());
		m_DiaryList.SetItemText(0,3,id);
		++i;
	}		
}

void CDiaryDlg::CleanList()
{
m_DiaryList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CDiaryDlg::OnBnClickedDiaryAdd()
{	
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.SetType("Diary");
	dlg.DoModal(); 
	m_DiaryList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
	m_DiaryList.SetItemText(0,0,dlg.GetDateTime());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
	m_DiaryList.SetItemText(0,1,dlg.GetTitle());
	m_DiaryList.SetItemText(0,2,dlg.GetContent());
	m_DiaryList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
	
}


void CDiaryDlg::OnBnClickedDiaryDelete()
{
	if(!hasSelectedItem)
	{
		//AfxMessageBox("�㻹û��ѡ��һ��");
		return;
	}
	POSITION p=m_DiaryList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_DiaryList.GetNextSelectedItem(p); //��ȡѡ���е�����  		
		CDiary d;
		d.SetID(atoi(m_DiaryList.GetItemText(nSelected,3)));
		m_DiaryList.DeleteItem(nSelected); //��������ɾ��
		m_user.RemoveDiary(d);
		p  = m_DiaryList.GetFirstSelectedItemPosition();  
	}
}


void CDiaryDlg::OnBnClickedDiaryUpdate()
{	
	if(!hasSelectedItem)
	{
		//AfxMessageBox("�㻹û��ѡ��һ��");
		return;
	}
	
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.SetDateTime(m_szDateTime);
	dlg.SetTitle(m_szTitle);
	dlg.SetContent(m_szContent);
	dlg.SetID(m_szID);
	dlg.DoModal();
	m_szDateTime = dlg.GetDateTime();
	m_szTitle = dlg.GetTitle();
	m_szContent   = dlg.GetContent();
	m_szID  =dlg.GetID();
	this->ShowWindow(SW_SHOW);
	
}


void CDiaryDlg::OnBnClickedDiaryDeleteall()
{
	CleanList();
	m_user.PurgeDiary();

}

void CDiaryDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}


void CDiaryDlg::OnClickDiaryList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNmListView = (NM_LISTVIEW*)pNMHDR;
	nItem = pNmListView->iItem;
	m_szDateTime = m_DiaryList.GetItemText(nItem, 0);
	m_szTitle = m_DiaryList.GetItemText(nItem, 1);
	m_szContent   = m_DiaryList.GetItemText(nItem, 2);
	m_szID  = m_DiaryList.GetItemText(nItem, 3);
	UpdateData(FALSE);
	*pResult = 0;

	if(-1 == nItem)
	{
		hasSelectedItem = false;
	}
	else
	{
		hasSelectedItem = true;
	}
}


BOOL CDiaryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	hasSelectedItem = false;

	return TRUE;
}