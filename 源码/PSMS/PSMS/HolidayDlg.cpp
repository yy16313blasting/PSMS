// HolidayDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"
#include "Lunar.h"
// CHolidayDlg �Ի���

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


// CHolidayDlg ��Ϣ�������
void CHolidayDlg::InitListCtrol()
{

	DWORD dwStyle = m_HolidayList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_HolidayList.SetExtendedStyle(dwStyle);	//������չ���

		m_HolidayList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_HolidayList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_HolidayList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
	
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
		m_HolidayList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_HolidayList.SetItemText(0,0,list[i].GetHolidayDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_HolidayList.SetItemText(0,1,list[i].GetHolidayName());
		m_HolidayList.SetItemText(0,2,list[i].GetContent());
		++i;
	}
}

void  CHolidayDlg::CleanList()
{
m_HolidayList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CHolidayDlg::OnBnClickedHolidayAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CHolidayDlg::OnBnClickedHolidayDelete()
{
	
	AfxMessageBox("�ڼ������Ѳ���ɾ��");
	
	/*POSITION p=m_HolidayList.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��

	while (p)      
	{      
		int  nSelected=m_HolidayList.GetNextSelectedItem(p); //��ȡѡ���е����� 

		m_HolidayList.DeleteItem(nSelected); //��������ɾ��
		p  = m_HolidayList.GetFirstSelectedItemPosition();  

	}*/
}


void CHolidayDlg::OnBnClickedHolidayUpdate()
{
	//AfxMessageBox("�ڼ������Ѳ��ܸ���");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CHolidayDlg::OnBnClickedHolidayDeleteall()
{
	AfxMessageBox("�ڼ������Ѳ���ɾ��");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CHolidayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//GetDlgItem(IDC_HOLIDAY_DELETE)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_HOLIDAY_UPDATE)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_HOLIDAY_DELETEALL)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


int CHolidayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	CUser user;
	// TODO:  �ڴ������ר�õĴ�������
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
		if(list[i].GetTitle() == "ĸ�׽�")
		{
			if(list[i].GetMonth() == 5)
			{
				if(time.GetDayOfWeek() == 7 && (Day >= 8 && Day <= 14))
					Remind("ĸ�׽�",list[i].GetContent());
			}
			continue;
		}
		if(list[i].GetTitle() == "���׽�")
		{
			if(list[i].GetMonth() == 6)
			{
				if(time.GetDayOfWeek() == 7 && (Day >= 15 && Day <= 21))
					Remind("���׽�",list[i].GetContent());
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