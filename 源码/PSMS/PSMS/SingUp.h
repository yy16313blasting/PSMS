#pragma once


// CSingUp �Ի���

class CSingUp : public CDialog
{
	DECLARE_DYNAMIC(CSingUp)

public:
	CSingUp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSingUp();

// �Ի�������
	enum { IDD = IDD_SINGUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
