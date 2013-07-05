#pragma once


// CTimeRemindDlg 对话框

class CTimeRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeRemindDlg)

public:
	CTimeRemindDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTimeRemindDlg();

// 对话框数据
	enum { IDD = IDD_TIMEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
