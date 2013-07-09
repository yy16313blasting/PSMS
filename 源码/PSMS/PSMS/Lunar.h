#if !defined(AFX_LUNAR_H__21C6391F_8428_417E_B742_5BEC3022FB17__INCLUDED_)
#define AFX_LUNAR_H__21C6391F_8428_417E_B742_5BEC3022FB17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Lunar.h : header file
//

/////////////////////////////////////////////////////////////////////////////

// CLunar window
extern const WORD START_YEAR;
extern const WORD END_YEAR;
class CLunar 
{
// Construction
public:
	CLunar();
	virtual ~CLunar();


// Operations
private:
	//判断iYear是不是闰年
    static BOOL IsLeapYear(WORD iYear)
	{return !(iYear%4)&&(iYear%100) || !(iYear%400);}

	//返回阴历iLunarYer年阴历iLunarMonth月的天数，如果iLunarMonth为闰月，
	//高字为第二个iLunarMonth月的天数，否则高字为0 
	// 1901年1月---2050年12月
	static LONG LunarMonthDays(WORD iLunarYear, WORD iLunarMonth);

	//返回阴历iLunarYear年的总天数
	// 1901年1月---2050年12月
	static WORD LunarYearDays(WORD iLunarYear);

	//返回阴历iLunarYear年的闰月月份，如没有返回0
	// 1901年1月---2050年12月
	static WORD GetLeapMonth(WORD iLunarYear);
	
	//计算从1901年1月1日过iSpanDays天后的阴历日期
	static BYTE   l_CalcLunarDate(WORD &iYear, WORD &iMonth,WORD &iDay, LONG iSpanDays);

    //计算公历iYear年iMonth月iDay日对应的节气 0-24，0表不是节气
	static WORD   l_GetLunarHolDay(WORD iYear, WORD iMonth, WORD iDay);

	//计算公历两个日期间相差的天数  1年1月1日 --- 65535年12月31日
	static LONG CalcDateDiff(WORD iEndYear, WORD iEndMonth, WORD iEndDay,
		                     WORD iStartYear = START_YEAR, 
							 WORD iStartMonth =1, WORD iStartDay =1);

public:
	//把iYear年格式化成天干记年法表示的字符串
	static void FormatLunarYear(WORD  iYear, char *pBuffer);
	
	//把iMonth格式化成中文字符串
	static void FormatMonth(WORD iMonth, char *pBuffer, BOOL bLunar = TRUE);
	
    //把iDay格式化成中文字符串
	static void FormatLunarDay(WORD  iDay, char *pBuffer);
	
	//计算公历iYear年iMonth月iDay日对应的阴历日期,返回对应的阴历节气 0-24
	//1901年1月1日---2050年12月31日
	static WORD GetLunarDate(WORD iYear, WORD iMonth, WORD iDay,
		                     WORD &iLunarYear, WORD &iLunarMonth, WORD &iLunarDay);

// Implementation
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUNAR_H__21C6391F_8428_417E_B742_5BEC3022FB17__INCLUDED_)
