#pragma once
#include"User.h"

// CDateRemindDlg 对话框

class CDateRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CDateRemindDlg)

public:
	CDateRemindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDateRemindDlg();

// 对话框数据
	enum { IDD = IDD_DATEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser m_user;
	CListCtrl m_DateRemindList;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	void SetUser(CUser user);
	afx_msg void OnBnClickedDateremindAdd();
	afx_msg void OnBnClickedDateremindDelete();
	afx_msg void OnBnClickedDateremindUpdate();
	afx_msg void OnBnClickedDateremindDeleteall();
private:
	CString m_szContent;
	CString m_szTitle;
	CString m_szDateTime;
	CString m_szID;
	bool hasSelectedItem;
	int nItem;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickDateremindList(NMHDR *pNMHDR, LRESULT *pResult);
};
