#pragma once


// CHolidayDlg 对话框

class CHolidayDlg : public CDialog
{
	DECLARE_DYNAMIC(CHolidayDlg)

public:
	CHolidayDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHolidayDlg();

// 对话框数据
	enum { IDD = IDD_HOLIDAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
