#pragma once
#include"User.h"

// CDiaryDlg 对话框

class CDiaryDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiaryDlg)

public:
	CDiaryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaryDlg();

// 对话框数据
	enum { IDD = IDD_DIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	CListCtrl m_DiaryList;
};
