// DiaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "DiaryDlg.h"
#include "afxdialogex.h"
#include "EditDlg.h"

// CDiaryDlg 对话框

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
END_MESSAGE_MAP()


// CDiaryDlg 消息处理程序
void CDiaryDlg::InitListCtrol()
{

	DWORD dwStyle = m_DiaryList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//选中某行使整行高亮（只适用与report风格的listctrl）
          dwStyle |= LVS_EX_GRIDLINES;				//网格线（只适用与report风格的listctrl）
         //dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件
		  m_DiaryList.SetExtendedStyle(dwStyle);	//设置扩展风格

		m_DiaryList.InsertColumn(0,"时间",LVCFMT_LEFT,150);        //添加列标题
		m_DiaryList.InsertColumn(1,"标题",LVCFMT_LEFT,200);
		m_DiaryList.InsertColumn(2,"详细内容",LVCFMT_LEFT,350);
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
		m_DiaryList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_DiaryList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_DiaryList.SetItemText(0,1,list[i].GetTitle());
		m_DiaryList.SetItemText(0,2,list[i].GetContent());
		m_DiaryList.SetItemText(0,3,id);
		++i;
	}		
}

void CDiaryDlg::CleanList()
{
m_DiaryList.DeleteAllItems(); //删除列表控件
}

void CDiaryDlg::OnBnClickedDiaryAdd()
{	
	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.SetType("Diary");
	dlg.DoModal(); 
	m_DiaryList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
	m_DiaryList.SetItemText(0,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_DiaryList.SetItemText(0,1,dlg.GetTitle());
	m_DiaryList.SetItemText(0,2,dlg.GetContent());
	m_DiaryList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
	
}


void CDiaryDlg::OnBnClickedDiaryDelete()
{
	POSITION p=m_DiaryList.GetFirstSelectedItemPosition();    //获取首选中行位置

	while (p)      
	{      
		int  nSelected=m_DiaryList.GetNextSelectedItem(p); //获取选中行的索引  		
		CDiary d;
		d.SetID(atoi(m_DiaryList.GetItemText(nSelected,3)));
		m_DiaryList.DeleteItem(nSelected); //根据索引删除
		m_user.RemoveDiary(d);
		p  = m_DiaryList.GetFirstSelectedItemPosition();  
	}
}


void CDiaryDlg::OnBnClickedDiaryUpdate()
{	CEditDlg dlg;
	ShowWindow(SW_HIDE);
	dlg.SetUser(m_user);
	dlg.DoModal();
	
	this->ShowWindow(SW_SHOW);
	
}


void CDiaryDlg::OnBnClickedDiaryDeleteall()
{
	/* TODO: 在此添加控件通知处理程序代码
	CDiary d;
	d.SetID(atoi(m_DiaryList.GetItemText(1,3)));
	m_user.RemoveDiary(d);*/
	CleanList();
	m_user.PurgeDiary();

}

void CDiaryDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}
