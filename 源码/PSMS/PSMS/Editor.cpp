// Editor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PSMS.h"
#include "Editor.h"
#include "afxdialogex.h"


// CEditor �Ի���

IMPLEMENT_DYNAMIC(CEditor, CDialog)

CEditor::CEditor(CWnd* pParent /*=NULL*/)
	: CDialog(CEditor::IDD, pParent)
{

}

CEditor::~CEditor()
{
}

void CEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditor, CDialog)
END_MESSAGE_MAP()


// CEditor ��Ϣ�������
