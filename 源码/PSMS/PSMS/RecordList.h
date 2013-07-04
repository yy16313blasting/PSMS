#pragma once
#include "Record.h"
#define N 10
class CRecordList
{
private:
	CRecord *list;
	int m_nLength;
	int m_nMaxLength;
public:
	CRecordList(void);
	~CRecordList(void);
	void Add(CRecord record);
	void Get(int n);
	void Empty();
	void GetLength();
};

