#pragma once
#include "record.h"
class CHoliday : public CRecord
{
public:
	CHoliday(void);
	~CHoliday(void);
	CString GetHolidayDate();
	CString GetHolidayName();
};

