#pragma once


// CSignIn �Ի���

class CSignIn : public CDialog
{
	DECLARE_DYNAMIC(CSignIn)

public:
	CSignIn(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignIn();

// �Ի�������
	enum { IDD = IDD_SIGNIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
