#pragma once


// CSignInDlg �Ի���

class CSignInDlg : public CDialog
{
	DECLARE_DYNAMIC(CSignInDlg)

public:
	CSignInDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignInDlg();

// �Ի�������
	enum { IDD = IDD_SIGN_IN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
