#pragma once


// CRemind 对话框

class CRemind : public CDialog
{
	DECLARE_DYNAMIC(CRemind)

public:
	CRemind(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRemind();

// 对话框数据
	enum { IDD = IDD_REMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
