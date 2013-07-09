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
	//�ж�iYear�ǲ�������
    static BOOL IsLeapYear(WORD iYear)
	{return !(iYear%4)&&(iYear%100) || !(iYear%400);}

	//��������iLunarYer������iLunarMonth�µ����������iLunarMonthΪ���£�
	//����Ϊ�ڶ���iLunarMonth�µ��������������Ϊ0 
	// 1901��1��---2050��12��
	static LONG LunarMonthDays(WORD iLunarYear, WORD iLunarMonth);

	//��������iLunarYear���������
	// 1901��1��---2050��12��
	static WORD LunarYearDays(WORD iLunarYear);

	//��������iLunarYear��������·ݣ���û�з���0
	// 1901��1��---2050��12��
	static WORD GetLeapMonth(WORD iLunarYear);
	
	//�����1901��1��1�չ�iSpanDays������������
	static BYTE   l_CalcLunarDate(WORD &iYear, WORD &iMonth,WORD &iDay, LONG iSpanDays);

    //���㹫��iYear��iMonth��iDay�ն�Ӧ�Ľ��� 0-24��0���ǽ���
	static WORD   l_GetLunarHolDay(WORD iYear, WORD iMonth, WORD iDay);

	//���㹫���������ڼ���������  1��1��1�� --- 65535��12��31��
	static LONG CalcDateDiff(WORD iEndYear, WORD iEndMonth, WORD iEndDay,
		                     WORD iStartYear = START_YEAR, 
							 WORD iStartMonth =1, WORD iStartDay =1);

public:
	//��iYear���ʽ������ɼ��귨��ʾ���ַ���
	static void FormatLunarYear(WORD  iYear, char *pBuffer);
	
	//��iMonth��ʽ���������ַ���
	static void FormatMonth(WORD iMonth, char *pBuffer, BOOL bLunar = TRUE);
	
    //��iDay��ʽ���������ַ���
	static void FormatLunarDay(WORD  iDay, char *pBuffer);
	
	//���㹫��iYear��iMonth��iDay�ն�Ӧ����������,���ض�Ӧ���������� 0-24
	//1901��1��1��---2050��12��31��
	static WORD GetLunarDate(WORD iYear, WORD iMonth, WORD iDay,
		                     WORD &iLunarYear, WORD &iLunarMonth, WORD &iLunarDay);

// Implementation
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUNAR_H__21C6391F_8428_417E_B742_5BEC3022FB17__INCLUDED_)
