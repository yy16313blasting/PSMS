#pragma once


// CSignIn 对话框

class CSignIn : public CDialog
{
	DECLARE_DYNAMIC(CSignIn)

public:
	CSignIn(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignIn();

// 对话框数据
	enum { IDD = IDD_SIGN_IN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
