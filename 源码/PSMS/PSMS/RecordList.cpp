#include "StdAfx.h"
#include "RecordList.h"

CRecordList::CRecordList(void)
{
	m_nLength=0;
	m_nMaxLength=N;
	records=new CRecord[m_nMaxLength];
}


CRecordList::~CRecordList(void)
{
	delete[] records;
}

void CRecordList::Add(CRecord record)
{
	m_nLength++;
	if(m_nLength>N)
	{
		m_nMaxLength*=N;
		CRecord* temp;
		temp=new CRecord[m_nMaxLength];
		for(int i=0;i<m_nLength;i++)
		{
			temp[i]=records[i];
		}
		records=temp;
	}
}

CRecord* CRecordList::Get(int n)
{
	if(n>m_nLength)
	{
		return NULL;
	}
	return &records[n];
}