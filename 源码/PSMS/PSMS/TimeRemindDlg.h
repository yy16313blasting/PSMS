#pragma once
#include"User.h"

// CTimeRemindDlg 对话框

class CTimeRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeRemindDlg)

public:
	CTimeRemindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTimeRemindDlg();

// 对话框数据
	enum { IDD = IDD_TIMEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser m_user;
	CListCtrl m_TimeRemindList;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	void SetUser(CUser user);
	afx_msg void OnBnClickedTimeremindAdd();
	afx_msg void OnBnClickedTimeremindDelete();
	afx_msg void OnBnClickedTimeremindUpdate();
	afx_msg void OnBnClickedTimeremindDeleteall();
};
