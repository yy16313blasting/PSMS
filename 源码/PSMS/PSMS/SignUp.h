#pragma once


// CSignUp �Ի���

class CSignUp : public CDialog
{
	DECLARE_DYNAMIC(CSignUp)

public:
	CSignUp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignUp();

// �Ի�������
	enum { IDD = IDD_SIGN_UP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
