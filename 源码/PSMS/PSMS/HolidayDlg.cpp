// HolidayDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"
#include "Lunar.h"
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
	ON_WM_CREATE()
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
		m_HolidayList.SetItemText(0,0,list[i].GetHolidayDate());//i代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
		m_HolidayList.SetItemText(0,1,list[i].GetHolidayName());
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


BOOL CHolidayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//GetDlgItem(IDC_HOLIDAY_DELETE)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_HOLIDAY_UPDATE)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_HOLIDAY_DELETEALL)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


int CHolidayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	CUser user;
	// TODO:  在此添加您专用的创建代码
	CTime time = CTime::GetCurrentTime();  
    int Year = time.GetYear();     
    int Month = time.GetMonth();      
    int Day = time.GetDay();   

	int icount = user.CountAllHoliday();
	CHoliday *list = new CHoliday[icount];
	user.GetAllHoliday(list);
	//int j;
	int i=0;
	for(; i < icount; i++)
	{
		if(list[i].GetTitle() == "母亲节")
		{
			if(list[i].GetMonth() == 5)
			{
				if(time.GetDayOfWeek() == 7 && (Day >= 8 && Day <= 14))
					Remind("母亲节",list[i].GetContent());
			}
			continue;
		}
		if(list[i].GetTitle() == "父亲节")
		{
			if(list[i].GetMonth() == 6)
			{
				if(time.GetDayOfWeek() == 7 && (Day >= 15 && Day <= 21))
					Remind("父亲节",list[i].GetContent());
			}
			continue;
		}
		if(list[i].GetTitle().Left(1) == "L")
		{
			WORD year,month,day;
			CLunar lunar;
			lunar.GetLunarDate(Year,Month,Day,year,month,day);
			if( month == list[i].GetMonth() && day == list[i].GetDay() )
			{
				Remind(list[i].GetTitle(),list[i].GetContent());
			}
			continue;
		}
		if( Month == list[i].GetMonth() && Day == list[i].GetDay() )
		{
			Remind(list[i].GetTitle(),list[i].GetContent());
		}
	}

	return 0;
}

void CHolidayDlg::Remind(CString title,CString content)
{
	CRemindDlg *dlg = new CRemindDlg();
	dlg->SetType("Holiday");
	dlg->SetContent(content);
	//dlg->SetRemindFrequency(1);
	dlg->Create(IDD_REMIND_DIALOG,NULL);
	dlg->ShowWindow(SW_SHOW);

}