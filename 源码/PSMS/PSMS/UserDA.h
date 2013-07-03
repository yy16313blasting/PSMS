#pragma once
#include "stdafx.h"
class CUserDA
{
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
public:
	CUserDA(void);
	~CUserDA(void);
	bool InitConnection();
	void CloseConnection();
	void test();
};

