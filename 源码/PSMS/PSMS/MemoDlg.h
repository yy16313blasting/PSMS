#pragma once
#include"User.h"

// CMemoDlg 对话框

class CMemoDlg : public CDialog
{
	DECLARE_DYNAMIC(CMemoDlg)

public:
	CMemoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMemoDlg();

// 对话框数据
	enum { IDD = IDD_MEMODLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	void InitListCtrol();
	void ShowList();
	CListCtrl m_MemoList;
};
