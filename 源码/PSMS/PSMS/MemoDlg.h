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

	bool hasSelectedItem;
	CString m_szTitle;
	CString m_szContent;
	CString m_szDateTime;
	int m_nID;
	int m_nItem;
public:
	CUser m_user;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	CListCtrl m_MemoList;
	void SetUser(CUser user);
	afx_msg void OnBnClickedMemoAdd();
	afx_msg void OnBnClickedMemoDelete();
	afx_msg void OnBnClickedMemoUpdate();
	afx_msg void OnBnClickedMemoDeleteall();
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedMemoList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickMemoList(NMHDR *pNMHDR, LRESULT *pResult);
};
