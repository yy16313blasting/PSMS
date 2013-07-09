#pragma once
#include"User.h"

// CDiaryDlg �Ի���

class CDiaryDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiaryDlg)

public:
	CDiaryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaryDlg();

// �Ի�������
	enum { IDD = IDD_DIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CUser m_user;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	CListCtrl m_DiaryList;
	afx_msg void OnBnClickedDiaryAdd();
	afx_msg void OnBnClickedDiaryDelete();
	afx_msg void OnBnClickedDiaryUpdate();
	afx_msg void OnBnClickedDiaryDeleteall();
	void SetUser(CUser user);
private:
	CString m_szContent;
	CString m_szTitle;
	CString m_szDateTime;
	CString m_szID;
	bool hasSelectedItem;
	int nItem;
public:
	afx_msg void OnClickDiaryList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
