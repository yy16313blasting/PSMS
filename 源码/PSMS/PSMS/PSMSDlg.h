
// PSMSDlg.h : 头文件

#pragma once
#include "TimeRemindDlg.h"
#include "DateRemindDlg.h"
#include "MemoDlg.h"
#include "DiaryDlg.h"
#include "HolidayDlg.h"

#define WM_SHOWTASK WM_USER+1
// CPSMSDlg 对话框
class CPSMSDlg : public CDialogEx
{
// 构造
public:
	CPSMSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);
private:
	CTabCtrl m_tab;
	CTimeRemindDlg m_TimeRemindDlg;
	CDateRemindDlg m_DateRemindDlg;
	CDiaryDlg m_DiaryDlg;
	CMemoDlg m_MemoDlg;
	CHolidayDlg m_HolidayDlg;
	NOTIFYICONDATA m_nid;
public:
	afx_msg void OnClose();
	virtual BOOL DestroyWindow();
};
