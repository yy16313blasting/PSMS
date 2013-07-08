#pragma once
#include"User.h"
// CHolidayDlg 对话框

class CHolidayDlg : public CDialog
{
	DECLARE_DYNAMIC(CHolidayDlg)

public:
	CHolidayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHolidayDlg();

// 对话框数据
	enum { IDD = IDD_HOLIDAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	CListCtrl m_HolidayList;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	afx_msg void OnBnClickedHolidayAdd();
	afx_msg void OnBnClickedHolidayDelete();
	afx_msg void OnBnClickedHolidayUpdate();
	afx_msg void OnBnClickedHolidayDeleteall();
};
