#pragma once


// CEditor 对话框

class CEditor : public CDialog
{
	DECLARE_DYNAMIC(CEditor)

public:
	CEditor(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEditor();

// 对话框数据
	enum { IDD = IDD_EDITOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
