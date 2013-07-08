// DiaryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "DiaryDlg.h"
#include "afxdialogex.h"


// CDiaryDlg �Ի���

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


// CDiaryDlg ��Ϣ�������
void CDiaryDlg::InitListCtrol()
{

	DWORD dwStyle = m_DiaryList.GetExtendedStyle();
		  dwStyle |= LVS_EX_FULLROWSELECT;			//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
          dwStyle |= LVS_EX_GRIDLINES;				//�����ߣ�ֻ������report����listctrl��
         //dwStyle |= LVS_EX_CHECKBOXES;			//itemǰ����checkbox�ؼ�
		  m_DiaryList.SetExtendedStyle(dwStyle);	//������չ���

		m_DiaryList.InsertColumn(0,"ʱ��",LVCFMT_LEFT,150);        //����б���
		m_DiaryList.InsertColumn(1,"����",LVCFMT_LEFT,200);
		m_DiaryList.InsertColumn(2,"��ϸ����",LVCFMT_LEFT,350);
	
}

void CDiaryDlg::ShowList()
  {	
	int icount=m_user.CountAllDiary();
	if(0==icount)
	{
		AfxMessageBox("û�м�¼");
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
		m_DiaryList.InsertItem(0,"");//����һ���У����������е�����Ϊi������
		m_DiaryList.SetItemText(0,0,list[i].GetDate());//i��ָ�ڵڼ��в������ݣ��ڶ���������ָ�ڼ��У�������������ָ�������ݵ�ֵ
		m_DiaryList.SetItemText(0,1,list[i].GetTitle());
		m_DiaryList.SetItemText(0,2,list[i].GetContent());
		++i;
	}		
}

void CDiaryDlg::CleanList()
{
m_DiaryList.DeleteAllItems(); //ɾ���б�ؼ�
}

void CDiaryDlg::OnBnClickedDiaryAdd()
{
	
}


void CDiaryDlg::OnBnClickedDiaryDelete()
{
	
}


void CDiaryDlg::OnBnClickedDiaryUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDiaryDlg::OnBnClickedDiaryDeleteall()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CDiaryDlg::SetUser(CUser user)
{
	m_user.SetName(user.GetName());
}