// TimeRemindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "TimeRemindDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"

// CTimeRemindDlg 对话框

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


// CTimeRemindDlg 消息处理程序

void CTimeRemindDlg::InitListCtrol()
{

	DWORD dwStyle = m_TimeRemindList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//选中某行使整行高亮（只适用与report风格的listctrl）
          dwStyle |= LVS_EX_GRIDLINES;				//网格线（只适用与report风格的listctrl）
         //dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件
		  m_TimeRemindList.SetExtendedStyle(dwStyle);	//设置扩展风格

		m_TimeRemindList.InsertColumn(0,"时间",LVCFMT_LEFT,150);        //添加列标题
		m_TimeRemindList.InsertColumn(1,"标题",LVCFMT_LEFT,200);
		m_TimeRemindList.InsertColumn(2,"详细内容",LVCFMT_LEFT,350);
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
		m_TimeRemindList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_TimeRemindList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_TimeRemindList.SetItemText(0,1,list[i].GetTitle());
		m_TimeRemindList.SetItemText(0,2,list[i].GetContent());
		m_TimeRemindList.SetItemText(0,3,id);
		++i;
	}
}
void CTimeRemindDlg::CleanList()
{
m_TimeRemindList.DeleteAllItems(); //删除列表控件
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
	m_TimeRemindList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
	m_TimeRemindList.SetItemText(0,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_TimeRemindList.SetItemText(0,1,dlg.GetTitle());
	m_TimeRemindList.SetItemText(0,2,dlg.GetContent());
	m_TimeRemindList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CTimeRemindDlg::OnBnClickedTimeremindDelete()
{
	POSITION p=m_TimeRemindList.GetFirstSelectedItemPosition();    //获取首选中行位置

	while (p)      
	{      
		int  nSelected=m_TimeRemindList.GetNextSelectedItem(p); //获取选中行的索引  
		
		CTimeRemind d;
		d.SetID(atoi(m_TimeRemindList.GetItemText(nSelected,3)));
		m_TimeRemindList.DeleteItem(nSelected); //根据索引删除
		m_user.RemoveTimeRemind(d);
		p  = m_TimeRemindList.GetFirstSelectedItemPosition();  
	}
}


void CTimeRemindDlg::OnBnClickedTimeremindUpdate()
{

	if(!m_hasSelectedItem)
	{
		//AfxMessageBox("你还没有选中一项");
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
	m_TimeRemindList.SetItemText(nItem,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
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

	// TODO:  在此添加额外的初始化

	m_nTimerID = 0;
	SetTimer(m_nTimerID,60*1000*m_user.GetTimeFrequency(),NULL);
	m_hasSelectedItem = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTimeRemindDlg::OnClickTimeremindList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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