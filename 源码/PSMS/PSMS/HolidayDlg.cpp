// HolidayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"
// CHolidayDlg 对话框

IMPLEMENT_DYNAMIC(CHolidayDlg, CDialog)

CHolidayDlg::CHolidayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHolidayDlg::IDD, pParent)
{
}

CHolidayDlg::~CHolidayDlg()
{
}

void CHolidayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOLIDAY_LIST, m_HolidayList);
}


BEGIN_MESSAGE_MAP(CHolidayDlg, CDialog)
	ON_BN_CLICKED(IDC_HOLIDAY_ADD, &CHolidayDlg::OnBnClickedHolidayAdd)
	ON_BN_CLICKED(IDC_HOLIDAY_DELETE, &CHolidayDlg::OnBnClickedHolidayDelete)
	ON_BN_CLICKED(IDC_HOLIDAY_UPDATE, &CHolidayDlg::OnBnClickedHolidayUpdate)
	ON_BN_CLICKED(IDC_HOLIDAY_DELETEALL, &CHolidayDlg::OnBnClickedHolidayDeleteall)
END_MESSAGE_MAP()


// CHolidayDlg 消息处理程序
void CHolidayDlg::InitListCtrol()
{

	DWORD dwStyle = m_HolidayList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//选中某行使整行高亮（只适用与report风格的listctrl）
          dwStyle |= LVS_EX_GRIDLINES;				//网格线（只适用与report风格的listctrl）
         //dwStyle |= LVS_EX_CHECKBOXES;			//item前生成checkbox控件
		  m_HolidayList.SetExtendedStyle(dwStyle);	//设置扩展风格

		m_HolidayList.InsertColumn(0,"时间",LVCFMT_LEFT,150);        //添加列标题
		m_HolidayList.InsertColumn(1,"标题",LVCFMT_LEFT,200);
		m_HolidayList.InsertColumn(2,"详细内容",LVCFMT_LEFT,350);
	
}

void CHolidayDlg::ShowList()
  {	
	int icount=user.CountAllHoliday();
	if(0==icount)
	{
		
	return;
	}
	CHoliday* list =new CHoliday[icount];
	user.GetAllHoliday(list);
	
	int i=0;
	if (icount == i)
	{
		return;
	}
	while(icount != i) 
	{	
		m_HolidayList.InsertItem(0,"");//开辟一个行，并且设置行的内容为i的内容
		m_HolidayList.SetItemText(0,0,list[i].GetDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_HolidayList.SetItemText(0,1,list[i].GetTitle());
		m_HolidayList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}

void  CHolidayDlg::CleanList()
{
m_HolidayList.DeleteAllItems(); //删除列表控件
}

void CHolidayDlg::OnBnClickedHolidayAdd()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CHolidayDlg::OnBnClickedHolidayDelete()
{
	
	AfxMessageBox("节假日提醒不能删除");
	
	/*POSITION p=m_HolidayList.GetFirstSelectedItemPosition();    //获取首选中行位置

	while (p)      
	{      
		int  nSelected=m_HolidayList.GetNextSelectedItem(p); //获取选中行的索引 

		m_HolidayList.DeleteItem(nSelected); //根据索引删除
		p  = m_HolidayList.GetFirstSelectedItemPosition();  

	}*/
}


void CHolidayDlg::OnBnClickedHolidayUpdate()
{
	//AfxMessageBox("节假日提醒不能更新");
	// TODO: 在此添加控件通知处理程序代码
}


void CHolidayDlg::OnBnClickedHolidayDeleteall()
{
	AfxMessageBox("节假日提醒不能删除");
	// TODO: 在此添加控件通知处理程序代码
}
