#pragma once


// CEditor �Ի���

class CEditor : public CDialog
{
	DECLARE_DYNAMIC(CEditor)

public:
	CEditor(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditor();

// �Ի�������
	enum { IDD = IDD_EDITOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
