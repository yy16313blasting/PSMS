#pragma once

#include "UpdatePasswordDlg.h"
#include "User.h"
// CSettingsDlg 对话框

class CSettingsDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingsDlg)

public:
	CSettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingsDlg();

// 对话框数据
	enum { IDD = IDD_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
