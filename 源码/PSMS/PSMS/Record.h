#include "iostream"
using namespace std;
#pragma once
class CRecord
{
public:
	CRecord(void);

protected:
	int m_nDay;
	int m_nMonth;
	int m_nYear;
	int m_nType;
	string m_szTitle;
	string m_szContent;
	bool isCanceled;

public:
	int GetDay(void);
	int GetMonth(void);
	int GetType(void);
	int GetYear(void);
	void SetContent(string content);
	void SetTitle(string title);
	string GetContent(void);
	string GetTitle(void);
	virtual void SetDate(int year, int month, int day);
};
