
// PSMSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "PSMSDlg.h"
#include "afxdialogex.h"
#include "UserDA.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CPSMSDlg �Ի���

CPSMSDlg::CPSMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPSMSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPSMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CPSMSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CPSMSDlg::OnTcnSelchangeTab)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CPSMSDlg ��Ϣ�������

BOOL CPSMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_nid.cbSize  = (DWORD)sizeof(NOTIFYICONDATA);
    m_nid.hWnd    = this->m_hWnd;
    m_nid.uID     = IDR_MAINFRAME;
    m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
    m_nid.uCallbackMessage = WM_SHOWTASK;             // �Զ������Ϣ����
    m_nid.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
    strcpy(m_nid.szTip, "�����ճ̹���");                // ��Ϣ��ʾ��Ϊ"�����ճ̹���"��VS2008 UNICODE������wcscpy_s()����
    Shell_NotifyIcon(NIM_ADD, &m_nid);                // �����������ͼ��

	CRect tabRect;

	m_tab.InsertItem(0, _T("��ʱ����"));           
	m_tab.InsertItem(1, _T("��������"));  
	m_tab.InsertItem(2, _T("�����ռ�"));
	m_tab.InsertItem(3, _T("����¼"));
	m_tab.InsertItem(4, _T("�̶��ڼ���"));

	m_TimeRemindDlg.Create(IDD_TIMEREMIND,&m_tab);
	m_DateRemindDlg.Create(IDD_DATEREMIND,&m_tab);
	m_DiaryDlg.Create(IDD_DIARY,&m_tab);
	m_MemoDlg.Create(IDD_MEMODLG,&m_tab);
	m_HolidayDlg.Create(IDD_HOLIDAY,&m_tab);
	//ScreenToClient(&tabRect);

	m_tab.GetClientRect(&tabRect);    // ��ȡ��ǩ�ؼ��ͻ���Rect   

	// ����tabRect��ʹ�串�Ƿ�Χ�ʺϷ��ñ�ǩҳ   
    tabRect.left += 1;                  
    tabRect.right -= 1;   
	tabRect.top += 25; 
	tabRect.bottom -= 1;

	// ���ݵ����õ�tabRect�����ӶԻ��򣬲�����Ϊ��ʾ   
	m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
	m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
	m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_TimeRemindDlg.InitListCtrol();
	m_TimeRemindDlg.ShowList();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPSMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPSMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPSMSDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CRect tabRect;    // ��ǩ�ؼ��ͻ�����Rect   
	  
	// ��ȡ��ǩ�ؼ��ͻ���Rect����������������ʺϷ��ñ�ǩҳ   
	m_tab.GetClientRect(&tabRect);   
    tabRect.left += 1;   
    tabRect.right -= 1;   
    tabRect.top += 25;   
    tabRect.bottom -= 1;   
	  
    switch (m_tab.GetCurSel())   
    {   
		// �����ǩ�ؼ���ǰѡ���ǩΪ����ʱ���ѡ�������ʾTimeReminddlg�Ի������������Ի���   
		case 0:   
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
			m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_TimeRemindDlg.InitListCtrol();
			m_TimeRemindDlg.ShowList();
			break;   

		// �����ǩ�ؼ���ǰѡ���ǩΪ���������ѡ�������ʾDateRemindDlg�Ի������������Ի���   
		case 1:   
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW); 
	        m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);   
			m_DateRemindDlg.InitListCtrol();
			m_DateRemindDlg.ShowList();
			break; 

		// �����ǩ�ؼ���ǰѡ���ǩΪ��������־��������ʾDiaryDlg�Ի������������Ի���
		case 2:
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
	        m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
	        m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_DiaryDlg.InitListCtrol();
			m_DiaryDlg.ShowList();
			break;

		// �����ǩ�ؼ���ǰѡ���ǩΪ������¼��������ʾMemoDlg�Ի������������Ի���
		case 3:
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
			m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_MemoDlg.InitListCtrol();
			m_MemoDlg.ShowList();
			break;

		// �����ǩ�ؼ���ǰѡ���ǩΪ���̶��ڼ��ա�������ʾHolidayDlg�Ի������������Ի���
		case 4:
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW); 
			m_HolidayDlg.InitListCtrol();
			m_HolidayDlg.ShowList();
			break;

		default:   
			break;   
	}
}

LRESULT CPSMSDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
           if(wParam != IDR_MAINFRAME)
                  return 1;
           switch(lParam)
           {
			case WM_RBUTTONUP:                                        // �Ҽ�����ʱ�����˵�
            {
                    
                    LPPOINT lpoint = new tagPOINT;
                    ::GetCursorPos(lpoint);                    // �õ����λ��
                    CMenu menu;
                    menu.CreatePopupMenu();                    // ����һ������ʽ�˵�
                    menu.AppendMenu(MF_STRING, WM_DESTROY, "�ر�");
                    menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x ,lpoint->y, this);
                    HMENU hmenu = menu.Detach();
                    menu.DestroyMenu();
                    delete lpoint;
					lpoint=NULL;
            }
            break;
			 case WM_LBUTTONDBLCLK:                                 // ˫������Ĵ���
            {
                    this->ShowWindow(SW_SHOW);         // ��ʾ������
            }
				break;
			}
    return 0;
}

void CPSMSDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->ShowWindow(SW_HIDE);
}

//BOOL CPSMSDlg::DestroyWindow()
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	//Shell_NotifyIcon(NIM_DELETE, &m_nid);
//	return CDialog::DestroyWindow();
//	
//}

BOOL CPSMSDlg::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	Shell_NotifyIcon(NIM_DELETE, &m_nid);
	return CDialogEx::DestroyWindow();
}
