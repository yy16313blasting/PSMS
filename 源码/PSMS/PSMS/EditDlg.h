#pragma once
#include "User.h"

// CEditDlg �Ի���

class CEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditDlg)

public:
	CEditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditDlg();

// �Ի�������
	enum { IDD = IDD_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedCancelEdit();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	void SetUser(CUser user);
	void SetType(CString type);
	void SetDateTime(CString datetime);
	void SetTitle(CString title);
	void SetContent(CString content);
	void SetID(CString ID);
	void SetID(int id);
	CString GetTitle();
	CString GetContent();
	CString GetDateTime();
	CDateTimeCtrl m_Date;
	CDateTimeCtrl m_Time;
	CString GetID();
	virtual BOOL OnInitDialog();
	void Update(bool);
private:
	CString m_editTitle;
	CString m_editContent;
	CString m_strDateTime;
	int m_nID;
	CUser	m_user;
	CString m_szType;
	bool m_isUpdate;
};
