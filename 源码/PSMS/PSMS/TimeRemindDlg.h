#pragma once
#include"User.h"

// CTimeRemindDlg �Ի���

class CTimeRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeRemindDlg)

public:
	CTimeRemindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTimeRemindDlg();

// �Ի�������
	enum { IDD = IDD_TIMEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CUser m_user;
	CListCtrl m_TimeRemindList;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	void SetUser(CUser user);
	afx_msg void OnBnClickedTimeremindAdd();
	afx_msg void OnBnClickedTimeremindDelete();
	afx_msg void OnBnClickedTimeremindUpdate();
	afx_msg void OnBnClickedTimeremindDeleteall();
};
