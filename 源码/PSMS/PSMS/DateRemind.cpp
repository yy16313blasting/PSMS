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

void CDateRemind::SetRemindFrequency(int frequency)
{
	this->m_nRemindFrequency = frequency;
}

void CDateRemind::SetDateTime(CString date)
{
	COleVariant VariantTime;
	VariantTime = date;
	VariantTime.ChangeType(VT_DATE);
	COleDateTime DateTime = VariantTime;

	m_nYear = DateTime.GetYear();
	m_nMonth = DateTime.GetMonth();
	m_nDay = DateTime.GetDay();
}
