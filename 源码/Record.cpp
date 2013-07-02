#include "Record.h"

Record::Record()
{
	m_nYear=2013;
	m_nMonth=1;
	m_nDay=1;
	m_nType=UNKNOWN;
}


int Record::GetYear()
{
	return m_nYear;
}

int Record::GetMonth()
{
	return m_nMonth;
}

int Record::GetDay()
{
	return m_nDay;
}

string Record::GetContent()
{
	return m_szContent;
}

string Record::GetTitle()
{
	return m_szTitle;
}

void Record::SetDate(int year,int month,int day)
{
	m_nYear=year;
	m_nMonth=month;
	m_nDay=day;
}

void Record::SetTitle(string title)
{
	m_szTitle=title;
}

void Record::SetContent(string content)
{
	m_szContent=content;
}