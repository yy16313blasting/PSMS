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
	if(m_szTitle == "母亲节")
		return "5月的第二个星期日";
	if(m_szTitle == "父亲节")
		return "6月的第三个星期日";
	CString date;
	date.Format("%d月%d日",m_nMonth,m_nDay);
	if(m_szTitle.Left(1) == "L")
		return "农历"+date;
	return date;
}

CString CHoliday::GetHolidayName(void)
{
	if(m_szTitle.Left(1)=="L")
		return m_szTitle.Right(m_szTitle.GetLength()-1);
	return m_szTitle;
}