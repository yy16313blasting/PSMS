// HolidayDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "HolidayDlg.h"
#include "afxdialogex.h"
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
		m_HolidayList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_HolidayList.SetItemText(0,1,list[i].GetTitle());
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
