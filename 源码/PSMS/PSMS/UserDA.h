#pragma once
#include "stdafx.h"
class UserDA
{
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	string DataBaseUrl;
public:
	UserDA(void);
	~UserDA(void);
	bool InitConnection();
	void CloseConnection();
};

