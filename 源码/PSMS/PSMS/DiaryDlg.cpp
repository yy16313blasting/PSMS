// DiaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "DiaryDlg.h"
#include "afxdialogex.h"


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
	
}

void CDiaryDlg::ShowList()
  {	
	int icount=user.CountAllDiary();
	if(0==icount)
	{
		AfxMessageBox("没有记录");
	return;
	}
	CDiary* list =new CDiary[icount];
	user.GetAllDiary(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		m_DiaryList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_DiaryList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_DiaryList.SetItemText(0,1,list[i].GetTitle());
		m_DiaryList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}