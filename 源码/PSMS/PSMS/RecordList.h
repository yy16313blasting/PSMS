#pragma once
#include"Record.h"
#define N 10

class CRecordList
{
private:
	CRecord *records;
	int m_nLength;
	int m_nMaxLength;
public:
	CRecordList(void);
	~CRecordList(void);

	int GetLength();
	void Add(CRecord record);
	CRecord* Get(int n);
	void Remove(CRecord record);
};

