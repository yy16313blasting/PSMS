#pragma once

#include "User.h"
#include "DlgFlash.h"
// CUpdatePasswordDlg 对话框

class CUpdatePasswordDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpdatePasswordDlg)

public:
	CUpdatePasswordDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUpdatePasswordDlg();

// 对话框数据
	enum { IDD = IDD_UPDATE_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP();
private:
	CRect m_rect;
	CUser m_user;
	CDlgFlash *myFlash;
public:
	void Hide();
	virtual BOOL OnInitDialog();
	void SetUser(CUser user);
	afx_msg void OnClose();
	afx_msg void OnBnClickedCheck();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
