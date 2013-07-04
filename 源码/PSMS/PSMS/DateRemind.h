#include "iostream"
using namespace std;
#include "Record.h"
#pragma once
class CDateRemind : public CRecord
{
public:
	CDateRemind(void);

private:
	int m_nRemindFrequency;

public:
	int GetRemindFrequency(void);
	void SetRemindFrequency(string frequency);
	void SetDate(int year, int month, int day);

};
