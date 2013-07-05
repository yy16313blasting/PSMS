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
	CString m_szTitle;
	CString m_szContent;
	CString m_szUser;
	bool isCanceled;

public:
	int GetDay(void);
	int GetMonth(void);
	int GetType(void);
	int GetYear(void);
	void SetContent(CString content);
	void SetTitle(CString title);
	void SetUser(CString user);
	CString GetContent(void);
	CString GetTitle(void);
	CString GetUser();
	virtual CString GetDate();
	void SetDate(int year, int month, int day);
	void SetDate(CString date);
};
