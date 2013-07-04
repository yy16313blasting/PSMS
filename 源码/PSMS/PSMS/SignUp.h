#pragma once


// CSignUp 对话框

class CSignUp : public CDialog
{
	DECLARE_DYNAMIC(CSignUp)

public:
	CSignUp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignUp();

// 对话框数据
	enum { IDD = IDD_SIGN_UP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
