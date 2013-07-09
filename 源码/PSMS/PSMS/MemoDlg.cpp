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
	ON_NOTIFY(NM_CLICK, IDC_MEMO_LIST, &CMemoDlg::OnClickMemoList)
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
		m_MemoList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_MemoList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_MemoList.SetItemText(0,1,list[i].GetTitle());
		m_MemoList.SetItemText(0,2,list[i].GetContent());
		m_MemoList.SetItemText(0,3,id);
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
	dlg.Update(false);
	dlg.SetType("Memo");
	dlg.DoModal();
	m_MemoList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
	m_MemoList.SetItemText(0,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_MemoList.SetItemText(0,1,dlg.GetTitle());
	m_MemoList.SetItemText(0,2,dlg.GetContent());
	m_MemoList.SetItemText(0,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDelete()
{
	POSITION p=m_MemoList.GetFirstSelectedItemPosition();    //获取首选中行位置
	if(!hasSelectedItem)
	{
		AfxMessageBox("你还没有选中一项");
		return;
	}
	while (p)      
	{      
		int  nSelected=m_MemoList.GetNextSelectedItem(p); //获取选中行的索引
		CMemo d;
		d.SetID(atoi(m_MemoList.GetItemText(nSelected,3)));
		m_MemoList.DeleteItem(nSelected); //根据索引删除
		m_user.RemoveMemo(d);
		p  = m_MemoList.GetFirstSelectedItemPosition();  
	}


}


void CMemoDlg::OnBnClickedMemoUpdate()
{

	if(!hasSelectedItem)
	{
		AfxMessageBox("你还没有选中一项");
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
	m_MemoList.SetItemText(m_nItem,0,dlg.GetDateTime());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	m_MemoList.SetItemText(m_nItem,1,dlg.GetTitle());
	m_MemoList.SetItemText(m_nItem,2,dlg.GetContent());
	m_MemoList.SetItemText(m_nItem,3,dlg.GetID());
	this->ShowWindow(SW_SHOW);
}


void CMemoDlg::OnBnClickedMemoDeleteall()
{
	if( AfxMessageBox("删除所有？",MB_YESNO|MB_ICONQUESTION) == IDYES)
	{
		CleanList();
		m_user.PurgeMemo();
	}
}


BOOL CMemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	hasSelectedItem = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMemoDlg::OnClickMemoList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
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
