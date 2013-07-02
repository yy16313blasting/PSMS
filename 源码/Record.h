#include "stdafx.h"

//把数据库里的记录对象化
class Record
{
private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;

	int m_nType;
	string m_szContent;
	string m_szTitle;

public:
	Record();
	int GetYear();
	int GetMonth();
	int GetDay();
	string GetContent();
	string GetTitle();
	void SetTitle(string title);
	void SetContent(string content);
	virtual void SetDate(int year,int month,int day);
};