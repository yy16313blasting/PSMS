#pragma once
#include"User.h"
#include"RemindDlg.h"

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
	virtual BOOL OnInitDialog();
private:
	bool m_hasSelectedItem;
	int nItem;
	CString m_szTitle;
	CString m_szContent;
	CString m_szDateTime;
	CString m_szID;
	int m_nTimerID;
public:
	afx_msg void OnClickTimeremindList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Remind(CString title,CString content);
};
