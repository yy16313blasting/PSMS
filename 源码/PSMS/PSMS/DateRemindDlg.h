#pragma once


// CDateRemindDlg 对话框

class CDateRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CDateRemindDlg)

public:
	CDateRemindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDateRemindDlg();

// 对话框数据
	enum { IDD = IDD_DATEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
