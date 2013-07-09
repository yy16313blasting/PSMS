#pragma once

#include "MusicPlayer.h"
// CRemindDlg �Ի���

class CRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CRemindDlg)

public:
	CRemindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRemindDlg();

// �Ի�������
	enum { IDD = IDD_REMIND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck();
	afx_msg void OnBnClickedRemindLater();
	void SetRemindFrequency(int frequency);
	void SetType(CString type);
private:
	CString m_szType;
	int m_nFrequency;
	int m_nTimerID;
	CMusicPlayer m_MusicPlayer;
	CString m_szContent;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	void SetContent(CString content);
};
