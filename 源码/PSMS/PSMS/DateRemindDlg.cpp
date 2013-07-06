// DateRemindDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "PSMS.h"
#include "DateRemindDlg.h"
#include "afxdialogex.h"

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
	
}

void CDateRemindDlg::ShowList()
  {	
	int icount=user.CountAllDateRemind();
	if(0==icount)
	{
		AfxMessageBox("没有记录");
	return;
	}
	CDateRemind* list =new CDateRemind[icount];
	user.GetAllDateRemind(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		m_DateRemindList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_DateRemindList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_DateRemindList.SetItemText(0,1,list[i].GetTitle());
		m_DateRemindList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}