#pragma once


// CRemindDlg �Ի���

class CRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CRemindDlg)

public:
	CRemindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRemindDlg();

// �Ի�������
	enum { IDD = IDD_REMIND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
