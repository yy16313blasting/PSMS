#pragma once


// CRemindDlg 对话框

class CRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CRemindDlg)

public:
	CRemindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRemindDlg();

// 对话框数据
	enum { IDD = IDD_REMIND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck();
	afx_msg void OnBnClickedRemindLater();
};
