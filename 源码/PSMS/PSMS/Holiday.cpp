#include "StdAfx.h"
#include "Holiday.h"

CHoliday::CHoliday(void)
{
}

CHoliday::~CHoliday(void)
{
}

CString CHoliday::GetHolidayDate(void)
{
	if(m_szTitle == "ĸ�׽�")
		return "5�µĵڶ���������";
	if(m_szTitle == "���׽�")
		return "6�µĵ�����������";
	CString date;
	date.Format("%d��%d��",m_nMonth,m_nDay);
	if(m_szTitle.Left(1) == "L")
		return "ũ��"+date;
	return date;
}

CString CHoliday::GetHolidayName(void)
{
	if(m_szTitle.Left(1)=="L")
		return m_szTitle.Right(m_szTitle.GetLength()-1);
	return m_szTitle;
}