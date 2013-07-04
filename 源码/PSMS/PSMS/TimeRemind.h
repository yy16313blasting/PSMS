#include "iostream"
using namespace std;
#include "Record.h"
#pragma once
class CTimeRemind : public CRecord
{
public:
	CTimeRemind(void);

private:
	int m_nHour;
	int m_nMinute;
	int m_nRemindFrequency;

public:
	int GetHour(void);
	int GetMinute(void);
	int GetRemindFrequency(void);
	void SetRemindFrequency(int frequency);
	void SetTime(int hour, int minute);
};

