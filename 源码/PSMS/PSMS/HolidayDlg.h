#pragma once
#include"User.h"
// CHolidayDlg �Ի���

class CHolidayDlg : public CDialog
{
	DECLARE_DYNAMIC(CHolidayDlg)

public:
	CHolidayDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHolidayDlg();

// �Ի�������
	enum { IDD = IDD_HOLIDAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	CListCtrl m_HolidayList;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	afx_msg void OnBnClickedHolidayAdd();
	afx_msg void OnBnClickedHolidayDelete();
	afx_msg void OnBnClickedHolidayUpdate();
	afx_msg void OnBnClickedHolidayDeleteall();
};
