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
	ON_NOTIFY(NM_CLICK, IDC_TIMEREMIND_LIST, &CTimeRemindDlg::OnClickTimeremindList)
	ON_WM_TIMER()
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
	dlg.Update(false);
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

	if(!m_hasSelectedItem)
	{
		//AfxMessageBox("�㻹û��ѡ��һ��");
		return;
	}
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetType("TimeRemind");
	dlg.Update(true);
	dlg.SetUser(m_user);
	dlg.SetDateTime(m_szDateTime);
	dlg.SetTitle(m_szTitle);
	dlg.SetContent(m_szContent);
	dlg.SetID(m_szID);
	dlg.DoModal();
	m_TimeRemindList.SetItemText(nItem,0,dlg.GetDateTime());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
	m_TimeRemindList.SetItemText(nItem,1,dlg.GetTitle());
	m_TimeRemindList.SetItemText(nItem,2,dlg.GetContent());
	m_TimeRemindList.SetItemText(nItem,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CTimeRemindDlg::OnBnClickedTimeremindDeleteall()
{
	CleanList();
	m_user.PurgeTimeRemind();
}


BOOL CTimeRemindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_nTimerID = 0;
	SetTimer(m_nTimerID,60*1000*m_user.GetTimeFrequency(),NULL);
	m_hasSelectedItem = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTimeRemindDlg::OnClickTimeremindList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNmListView = (NM_LISTVIEW*)pNMHDR;
	nItem = pNmListView->iItem;
	m_szDateTime = m_TimeRemindList.GetItemText(nItem, 0);
	m_szTitle = m_TimeRemindList.GetItemText(nItem, 1);
	m_szContent   = m_TimeRemindList.GetItemText(nItem, 2);
	m_szID  = m_TimeRemindList.GetItemText(nItem, 3);
	UpdateData(FALSE);
	*pResult = 0;

	if(-1 == nItem)
	{
		m_hasSelectedItem = false;
	}
	else
	{
		m_hasSelectedItem = true;
	}
	*pResult = 0;
}


void CTimeRemindDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime time = CTime::GetCurrentTime();   
    int Year = time.GetYear();     
    int Month = time.GetMonth();      
    int Day = time.GetDay();   
	int icount = m_user.CountAllTimeRemind();
	if( icount == 0)
		return;
	CTimeRemind *list = new CTimeRemind[icount];
	m_user.GetAllTimeRemind(list);
	//int j;
	for(int i = 0;i < icount;i++)
	{
		if(time.GetHour() == list[i].GetHour() && time.GetMinute() == list[i].GetMinute() )
		{
			Remind(list[i].GetTitle(),list[i].GetContent());
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CTimeRemindDlg::Remind(CString title,CString content)
{
	CRemindDlg *dlg = new CRemindDlg();
	dlg->SetType("TimeRemind");
	dlg->SetContent(content);
	dlg->SetRemindFrequency(m_user.GetTimeFrequency());
	//dlg->SetRemindFrequency(1);
	dlg->Create(IDD_REMIND_DIALOG,NULL);
	dlg->ShowWindow(SW_SHOW);
}