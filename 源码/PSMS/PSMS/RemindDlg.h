#pragma once

#include "MusicPlayer.h"
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
