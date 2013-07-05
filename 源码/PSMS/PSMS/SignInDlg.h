#pragma once
#include "User.h"

// CSignInDlg 对话框

class CSignInDlg : public CDialog
{
	DECLARE_DYNAMIC(CSignInDlg)

public:
	CSignInDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignInDlg();

// 对话框数据
	enum { IDD = IDD_SIGN_IN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	afx_msg void OnBnClickedSignIn();
	CString m_editUserName;
	CString m_editPassWord;
};
