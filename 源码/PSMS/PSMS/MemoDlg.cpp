// MemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "MemoDlg.h"
#include "afxdialogex.h"
#include"EditDlg.h"

// CMemoDlg 对话框

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


// CMemoDlg 消息处理程序
void CMemoDlg::InitListCtrol()
{

	DWORD dwStyle = m_MemoList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//选中某行使整行高亮（只适用与report风格的listctrl）
          dwStyle |= LVS_EX_GRIDLINES;				//网格线（只适用与report风格的listctrl）
         //dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件
		  m_MemoList.SetExtendedStyle(dwStyle);	//设置扩展风格

		m_MemoList.InsertColumn(0,"时间",LVCFMT_LEFT,150);        //添加列标题
		m_MemoList.InsertColumn(1,"标题",LVCFMT_LEFT,200);
		m_MemoList.InsertColumn(2,"详细内容",LVCFMT_LEFT,350);
	
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
		m_MemoList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_MemoList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_MemoList.SetItemText(0,1,list[i].GetTitle());
		m_MemoList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}

void  CMemoDlg::CleanList()
{
m_MemoList.DeleteAllItems(); //删除列表控件
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
	POSITION p=m_MemoList.GetFirstSelectedItemPosition();    //获取首选中行位置

	while (p)      
	{      
		int  nSelected=m_MemoList.GetNextSelectedItem(p); //获取选中行的索引
		CMemo d;
		d.SetID(atoi(m_MemoList.GetItemText(nSelected,3)));
		m_user.RemoveMemo(d);
		m_MemoList.DeleteItem(nSelected); //根据索引删除
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
