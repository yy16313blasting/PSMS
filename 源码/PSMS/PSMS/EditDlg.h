#pragma once


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
};
