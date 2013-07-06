
// PSMSDlg.h : ͷ�ļ�

#pragma once
#include "TimeRemindDlg.h"
#include "DateRemindDlg.h"
#include "MemoDlg.h"
#include "DiaryDlg.h"
#include "HolidayDlg.h"

// CPSMSDlg �Ի���
class CPSMSDlg : public CDialogEx
{
// ����
public:
	CPSMSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CTabCtrl m_tab;
	CTimeRemindDlg m_TimeRemindDlg;
	CDateRemindDlg m_DateRemindDlg;
	CDiaryDlg m_DiaryDlg;
	CMemoDlg m_MemoDlg;
	CHolidayDlg m_HolidayDlg;
};
