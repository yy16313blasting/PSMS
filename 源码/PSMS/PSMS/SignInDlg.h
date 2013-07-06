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
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedToSignUp();
	afx_msg void OnBnClickedUpdatePassword();
private:
	int m_nMaxWindowHeight;
	int m_nMinWindowHeight;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
private:
	CBrush m_brush;
	CFont m_font;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
