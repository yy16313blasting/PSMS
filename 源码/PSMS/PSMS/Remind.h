#pragma once


// CRemind �Ի���

class CRemind : public CDialog
{
	DECLARE_DYNAMIC(CRemind)

public:
	CRemind(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRemind();

// �Ի�������
	enum { IDD = IDD_REMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
