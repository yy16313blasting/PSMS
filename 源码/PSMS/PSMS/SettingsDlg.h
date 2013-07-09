#pragma once

#include "UpdatePasswordDlg.h"
#include "User.h"
// CSettingsDlg �Ի���

class CSettingsDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingsDlg)

public:
	CSettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingsDlg();

// �Ի�������
	enum { IDD = IDD_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUpdatePassword();
	void SetUser(CUser user);
private:
	CUser m_user;
public:
	afx_msg void OnBnClickedButton1();
//	virtual void PreInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdit();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedSeleteMusic();
};
