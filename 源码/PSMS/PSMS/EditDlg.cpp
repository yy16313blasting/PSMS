// Editor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// CEditDlg �Ի���

IMPLEMENT_DYNAMIC(CEditDlg, CDialog)

CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
}

CEditDlg::~CEditDlg()
{
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	ON_BN_CLICKED(IDC_EDIT, &CEditDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_CANCEL_EDIT, &CEditDlg::OnBnClickedCancelEdit)
END_MESSAGE_MAP()


// CEditDlg ��Ϣ�������


void CEditDlg::OnBnClickedEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CEditDlg::OnBnClickedCancelEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
