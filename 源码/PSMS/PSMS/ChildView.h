
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once
#include "UserDA.h"

// CChildView ����

class CChildView : public CWnd
{
// ����
private:
	UserDA m_userDA;
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

