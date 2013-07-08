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
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CTimeRemindDlg::OnBnClickedTimeremindDeleteall()
{
	CleanList();
	m_user.PurgeTimeRemind();
}
