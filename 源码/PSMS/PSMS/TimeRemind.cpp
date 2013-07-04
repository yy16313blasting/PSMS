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
	this->m_nRemindFrequency = m_nRemindFrequency;
}

void CTimeRemind::SetTime(int hour, int minute)
{
	this->m_nHour = m_nHour;
	this->m_nMinute = m_nMinute;
}
