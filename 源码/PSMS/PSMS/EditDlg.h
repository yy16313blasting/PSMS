#pragma once
#include "User.h"

// CEditDlg 对话框

class CEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDlg)

public:
	CEditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditDlg();

// 对话框数据
	enum { IDD = IDD_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedCancelEdit();
	void SetUser(CUser user);
	CDialog *m_pPage;
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
