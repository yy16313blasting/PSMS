#pragma once
#include"User.h"

// CMemoDlg �Ի���

class CMemoDlg : public CDialog
{
	DECLARE_DYNAMIC(CMemoDlg)

public:
	CMemoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMemoDlg();

// �Ի�������
	enum { IDD = IDD_MEMODLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	void InitListCtrol();
	void ShowList();
	CListCtrl m_MemoList;
};
