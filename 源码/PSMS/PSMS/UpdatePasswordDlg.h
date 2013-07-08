#pragma once

#include "User.h"
// CUpdatePasswordDlg �Ի���

class CUpdatePasswordDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpdatePasswordDlg)

public:
	CUpdatePasswordDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdatePasswordDlg();

// �Ի�������
	enum { IDD = IDD_UPDATE_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	DECLARE_MESSAGE_MAP();
private:
	CRect m_rect;
	CUser m_user;
public:
	virtual BOOL OnInitDialog();
	void Show();
	void Hide();
	void SetUser(CUser user);
	afx_msg void OnClose();
	afx_msg void OnBnClickedCheck();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
