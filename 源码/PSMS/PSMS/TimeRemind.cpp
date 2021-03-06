#include "StdAfx.h"
#include "TimeRemind.h"


CTimeRemind::CTimeRemind(void)
{
	m_nHour = 0;
	m_nMinute = 0;
	m_nRemindFrequency = 0;
}

int CTimeRemind::GetHour(void)
{
	return m_nHour;
}

int CTimeRemind::GetMinute(void)
{
	return m_nMinute;
}

int CTimeRemind::GetRemindFrequency(void)
{
	return m_nRemindFrequency;
}

void CTimeRemind::SetRemindFrequency(int frequency)
{
	this->m_nRemindFrequency = frequency;
}

/*
void CTimeRemind::SetTime(int hour, int minute)
{
	this->m_nHour = hour;
	this->m_nMinute = minute;
}
*/

void CTimeRemind::SetDateTime(CString date)
{
	COleVariant VariantTime;
	VariantTime = date;
	VariantTime.ChangeType(VT_DATE);
	COleDateTime DateTime = VariantTime;

	m_nYear = DateTime.GetYear();
	m_nMonth = DateTime.GetMonth();
	m_nDay = DateTime.GetDay();
	m_nHour = DateTime.GetHour();
	m_nMinute = DateTime.GetMinute();
}

CString CTimeRemind::GetDate()
{
	CString str;
	str.Format("%d/%d/%d %d:%d:00",m_nYear,m_nMonth,m_nDay,m_nHour,m_nMinute);
	return str;
}

void CTimeRemind::SetDate(CString date)
{
	COleVariant VariantTime;
	VariantTime = date;
	VariantTime.ChangeType(VT_DATE);
	COleDateTime DateTime = VariantTime;

	m_nYear = DateTime.GetYear();
	m_nMonth = DateTime.GetMonth();
	m_nDay = DateTime.GetDay();
	m_nHour = DateTime.GetHour();
	m_nMinute = DateTime.GetMinute();
}