#pragma once
#include"User.h"

// CDiaryDlg �Ի���

class CDiaryDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiaryDlg)

public:
	CDiaryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaryDlg();

// �Ի�������
	enum { IDD = IDD_DIARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CUser user;
	void InitListCtrol();
	void ShowList();
	void CleanList();
	CListCtrl m_DiaryList;
};
