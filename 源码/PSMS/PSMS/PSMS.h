
// PSMS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "SkinMagicLib.h"
#pragma comment(lib, "SkinMagicTrial.lib")

// CPSMSApp:
// �йش����ʵ�֣������ PSMS.cpp
//

class CPSMSApp : public CWinApp
{
public:
	CPSMSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CPSMSApp theApp;