#pragma once


// CSignUpDlg 对话框

class CSignUpDlg : public CDialog
{
	DECLARE_DYNAMIC(CSignUpDlg)

public:
	CSignUpDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignUpDlg();

// 对话框数据
	enum { IDD = IDD_SIGN_UP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignUp();
	afx_msg void OnBnClickedReturn();
};
