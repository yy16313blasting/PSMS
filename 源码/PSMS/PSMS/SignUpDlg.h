#pragma once


// CSignUpDlg �Ի���

class CSignUpDlg : public CDialog
{
	DECLARE_DYNAMIC(CSignUpDlg)

public:
	CSignUpDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignUpDlg();

// �Ի�������
	enum { IDD = IDD_SIGN_UP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignUp();
	afx_msg void OnBnClickedReturn();
};
