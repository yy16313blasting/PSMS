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
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	void SetUser(CUser user);
	void SetType(CString type);
	CString GetTitle();
	CString GetContent();
	CString GetDateTime();
	CString GetID();
	CDateTimeCtrl m_Date;
	CDateTimeCtrl m_Time;
private:
	CString m_editTitle;
	CString m_editContent;
	CString m_strDateTime;
	CString m_strID;
	CUser m_user;
	CString m_szType;

	
};
