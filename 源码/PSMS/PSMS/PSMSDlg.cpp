
// PSMSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PSMS.h"
#include "PSMSDlg.h"
#include "afxdialogex.h"
#include "UserDA.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// CPSMSDlg 对话框

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

// CPSMSDlg 消息处理程序

BOOL CPSMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_nid.cbSize  = (DWORD)sizeof(NOTIFYICONDATA);
    m_nid.hWnd    = this->m_hWnd;
    m_nid.uID     = IDR_MAINFRAME;
    m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
    m_nid.uCallbackMessage = WM_SHOWTASK;             // 自定义的消息名称
    m_nid.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
    strcpy(m_nid.szTip, "个人日程管理");                // 信息提示条为"个人日程管理"，VS2008 UNICODE编码用wcscpy_s()函数
    Shell_NotifyIcon(NIM_ADD, &m_nid);                // 在托盘区添加图标

	CRect tabRect;

	m_tab.InsertItem(0, _T("定时提醒"));           
	m_tab.InsertItem(1, _T("定期提醒"));  
	m_tab.InsertItem(2, _T("个人日记"));
	m_tab.InsertItem(3, _T("备忘录"));
	m_tab.InsertItem(4, _T("固定节假日"));

	m_TimeRemindDlg.Create(IDD_TIMEREMIND,&m_tab);
	m_DateRemindDlg.Create(IDD_DATEREMIND,&m_tab);
	m_DiaryDlg.Create(IDD_DIARY,&m_tab);
	m_MemoDlg.Create(IDD_MEMODLG,&m_tab);
	m_HolidayDlg.Create(IDD_HOLIDAY,&m_tab);
	//ScreenToClient(&tabRect);

	m_tab.GetClientRect(&tabRect);    // 获取标签控件客户区Rect   

	// 调整tabRect，使其覆盖范围适合放置标签页   
    tabRect.left += 1;                  
    tabRect.right -= 1;   
	tabRect.top += 25; 
	tabRect.bottom -= 1;

	// 根据调整好的tabRect放置子对话框，并设置为显示   
	m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
	m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
	m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	m_TimeRemindDlg.InitListCtrol();
	m_TimeRemindDlg.ShowList();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPSMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPSMSDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CRect tabRect;    // 标签控件客户区的Rect   
	  
	// 获取标签控件客户区Rect，并对其调整，以适合放置标签页   
	m_tab.GetClientRect(&tabRect);   
    tabRect.left += 1;   
    tabRect.right -= 1;   
    tabRect.top += 25;   
    tabRect.bottom -= 1;   
	  
    switch (m_tab.GetCurSel())   
    {   
		// 如果标签控件当前选择标签为“定时提醒”，则显示TimeReminddlg对话框，隐藏其它对话框   
		case 0:   
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
			m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_TimeRemindDlg.InitListCtrol();
			m_TimeRemindDlg.ShowList();
			break;   

		// 如果标签控件当前选择标签为“定期提醒”，则显示DateRemindDlg对话框，隐藏其它对话框   
		case 1:   
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW); 
	        m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);   
			m_DateRemindDlg.InitListCtrol();
			m_DateRemindDlg.ShowList();
			break; 

		// 如果标签控件当前选择标签为“个人日志”，则显示DiaryDlg对话框，隐藏其它对话框
		case 2:
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
	        m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
	        m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
	        m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_DiaryDlg.InitListCtrol();
			m_DiaryDlg.ShowList();
			break;

		// 如果标签控件当前选择标签为“备忘录”，则显示MemoDlg对话框，隐藏其它对话框
		case 3:
			m_TimeRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DateRemindDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
			m_DiaryDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);  
			m_MemoDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
			m_HolidayDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
			m_MemoDlg.InitListCtrol();
			m_MemoDlg.ShowList();
			break;

		// 如果标签控件当前选择标签为“固定节假日”，则显示HolidayDlg对话框，隐藏其它对话框
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
			case WM_RBUTTONUP:                                        // 右键起来时弹出菜单
            {
                    
                    LPPOINT lpoint = new tagPOINT;
                    ::GetCursorPos(lpoint);                    // 得到鼠标位置
                    CMenu menu;
                    menu.CreatePopupMenu();                    // 声明一个弹出式菜单
                    menu.AppendMenu(MF_STRING, WM_DESTROY, "关闭");
                    menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x ,lpoint->y, this);
                    HMENU hmenu = menu.Detach();
                    menu.DestroyMenu();
                    delete lpoint;
					lpoint=NULL;
            }
            break;
			 case WM_LBUTTONDBLCLK:                                 // 双击左键的处理
            {
                    this->ShowWindow(SW_SHOW);         // 显示主窗口
            }
				break;
			}
    return 0;
}

void CPSMSDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->ShowWindow(SW_HIDE);
}

//BOOL CPSMSDlg::DestroyWindow()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	//Shell_NotifyIcon(NIM_DELETE, &m_nid);
//	return CDialog::DestroyWindow();
//	
//}

BOOL CPSMSDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	Shell_NotifyIcon(NIM_DELETE, &m_nid);
	return CDialogEx::DestroyWindow();
}
