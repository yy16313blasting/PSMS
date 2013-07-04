#include "StdAfx.h"
#include "RecordList.h"
#define N 10

CRecordList::CRecordList(void)
{
	m_nLength=0;
	m_nMaxLength=N;
	list=new CRecord[m_nMaxLength];
}


CRecordList::~CRecordList(void)
{
	delete[] list;
}

void CRecordList::Add(CRecord record)
{
	if(m_nLength==m_nMaxLength)
	{
		CRecord *temp;
		m_nMaxLength+=N;
		temp=new CRecord[m_nMaxLength];
		for(int i=0;i<m_nLength;i++)
		{
			temp[i]=list[i];
		}
		list=temp;
		temp=NULL;
	}
}