#pragma once


// CTimeRemindDlg �Ի���

class CTimeRemindDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimeRemindDlg)

public:
	CTimeRemindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTimeRemindDlg();

// �Ի�������
	enum { IDD = IDD_TIMEREMIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
