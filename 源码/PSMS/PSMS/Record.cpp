#include "StdAfx.h"
#include "Record.h"


CRecord::CRecord(void)
{
	isCanceled=false;
}


int CRecord::GetYear(void)
{
	return m_nYear;
}

int CRecord::GetMonth(void)
{
	return m_nMonth;
}

int CRecord::GetDay(void)
{
	return m_nDay;
}

int CRecord::GetType(void)
{
	return m_nType;
}

CString CRecord::GetTitle(void)
{
	return m_szTitle;
}

CString CRecord::GetContent(void)
{
	return m_szContent;
}

void CRecord::SetDate(int year, int month, int day)
{
	this->m_nYear = year;
	this->m_nMonth = month;
	this->m_nDay = day;
}

void CRecord::SetTitle(CString title)
{
	this->m_szTitle = title;
}

void CRecord::SetContent(CString content)
{
	this->m_szContent = content;
}

CString CRecord::GetDate()
{
	CString str;
	str.Format("%d/%d/%d 00:00:00:",m_nYear,m_nMonth,m_nDay);
	return str;
}