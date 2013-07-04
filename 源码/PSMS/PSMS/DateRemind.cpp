#include "StdAfx.h"
#include "DateRemind.h"


CDateRemind::CDateRemind(void)
{
	m_nRemindFrequency = 0;
}

int CDateRemind::GetRemindFrequency(void)
{
	return m_nRemindFrequency;
}

void CDateRemind::SetRemindFrequency(string frequency)
{
	this->m_nRemindFrequency = m_nRemindFrequency;
}

void CDateRemind::SetDate(int year, int month, int day)
{
	this->m_nYear = m_nYear;
	this->m_nMonth = m_nMonth;
	this->m_nDay = m_nDay;
}
