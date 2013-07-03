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

string CRecord::GetTitle(void)
{
	return m_szTitle;
}

string CRecord::GetContent(void)
{
	return m_szContent;
}

void CRecord::SetDate(int year, int month, int day)
{
	this->m_nYear = m_nYear;
	this->m_nMonth = m_nMonth;
	this->m_nDay = m_nDay;
}

void CRecord::SetTitle(string title)
{
	this->m_szTitle = m_szTitle;
}

void CRecord::SetContent(string content)
{
	this->m_szContent = m_szContent;
}