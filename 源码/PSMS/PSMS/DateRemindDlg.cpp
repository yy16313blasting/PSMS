// DateRemindDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "PSMS.h"
#include "DateRemindDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"
#include "RemindDlg.h"
// CDateRemindDlg 对话框

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
	ON_NOTIFY(NM_CLICK, IDC_DATEREMIND_LIST, &CDateRemindDlg::OnClickDateremindList)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDateRemindDlg 消息处理程序

void CDateRemindDlg::InitListCtrol()
{

	DWORD dwStyle = m_DateRemindList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//选中某行使整行高亮（只适用与report风格的listctrl）
          dwStyle |= LVS_EX_GRIDLINES;				//网格线（只适用与report风格的listctrl）
         //dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件
		  m_DateRemindList.SetExtendedStyle(dwStyle);	//设置扩展风格

		m_DateRemindList.InsertColumn(0,"时间",LVCFMT_LEFT,150);        //添加列标题
		m_DateRemindList.InsertColumn(1,"标题",LVCFMT_LEFT,200);
		m_DateRemindList.InsertColumn(2,"详细内容",LVCFMT_LEFT,350);
		m_DateRemindList.InsertColumn(3,"ID",LVCFMT_LEFT,0);
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
	{	CString id;
		id.Format("%d",list[i].GetID());
		m_DateRemindList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_DateRemindList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_DateRemindList.SetItemText(0,1,list[i].GetTitle());
		m_DateRemindList.SetItemText(0,2,list[i].GetContent());
		m_DateRemindList.SetItemText(0,3,id);
		++i;
	}
}

void  CDateRemindDlg::CleanList()
{
m_DateRemindList.DeleteAllItems(); //删除列表控件
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
	dlg.SetType("DateRemind");
	dlg.DoModal();
	m_DateRemindList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
	m_DateRemindList.SetItemText(0,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_DateRemindList.SetItemText(0,1,dlg.GetTitle());
	m_DateRemindList.SetItemText(0,2,dlg.GetContent());
	m_DateRemindList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CDateRemindDlg::OnBnClickedDateremindDelete()
{
	if(!hasSelectedItem)
	{
		//AfxMessageBox("你还没有选中一项");
		return;
	}
	POSITION p=m_DateRemindList.GetFirstSelectedItemPosition();    //获取首选中行位置

	while (p)      
	{      
		int  nSelected=m_DateRemindList.GetNextSelectedItem(p); //获取选中行的索引  
		CDateRemind d;
		d.SetID(atoi(m_DateRemindList.GetItemText(nSelected,3)));
		m_DateRemindList.DeleteItem(nSelected); //根据索引删除
		m_user.RemoveDateRemind(d);
		p  = m_DateRemindList.GetFirstSelectedItemPosition();  
	}
	
}


void CDateRemindDlg::OnBnClickedDateremindUpdate()
{
	if(!hasSelectedItem)
	{
		//AfxMessageBox("你还没有选中一项");
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
	m_DateRemindList.SetItemText(nItem,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_DateRemindList.SetItemText(nItem,1,dlg.GetTitle());
	m_DateRemindList.SetItemText(nItem,2,dlg.GetContent());
	m_DateRemindList.SetItemText(nItem,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CDateRemindDlg::OnBnClickedDateremindDeleteall()
{
	CleanList();
	m_user.PurgeDateRemind();
}


void CDateRemindDlg::OnClickDateremindList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	NM_LISTVIEW* pNmListView = (NM_LISTVIEW*)pNMHDR;
	nItem = pNmListView->iItem;
	m_szDateTime = m_DateRemindList.GetItemText(nItem, 0);
	m_szTitle = m_DateRemindList.GetItemText(nItem, 1);
	m_szContent   = m_DateRemindList.GetItemText(nItem, 2);
	m_szID  = m_DateRemindList.GetItemText(nItem, 3);
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


BOOL CDateRemindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	hasSelectedItem = false;

	return TRUE;
}

int CDateRemindDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CTime time = CTime::GetCurrentTime();   
    int Year = time.GetYear();     
    int Month = time.GetMonth();      
    int Day = time.GetDay();   

	int icount = m_user.CountAllDateRemind();
	if( icount == 0)
		return 0;
	CDateRemind *list = new CDateRemind[icount];
	m_user.GetAllDateRemind(list);
	//int j;
	for(int i = 0;i < icount;i++)
	{
		if(Year == list[i].GetYear() && Month == list[i].GetMonth() && Day == list[i].GetDay())
		{
			Remind(list[i].GetTitle(),list[i].GetContent());
		}
	}

	return 0;
}

void CDateRemindDlg::Remind(CString title,CString content)
{
	CRemindDlg *dlg = new CRemindDlg();
	dlg->SetType("DateRemind");
	dlg->SetContent(content);
	//dlg->SetRemindFrequency(1);
	dlg->Create(IDD_REMIND_DIALOG,NULL);
	dlg->ShowWindow(SW_SHOW);
}