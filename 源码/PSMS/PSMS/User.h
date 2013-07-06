#pragma once
#include "stdafx.h"
#include "Record.h"
#include "TimeRemind.h"
#include "DateRemind.h"
#include "Memo.h"
#include "Diary.h"
#include "Holiday.h"
#include "RecordList.h"
#include "UserDA.h"
class CUser
{
private:
	CString m_szName;
	BOOL  isOnline;
	CUserDA usrDA;

public:
	CUser(void);
	~CUser(void);
	CString GetUserPassword(CString name);
	bool ExistUser(CString name);

	void  PurgeDateRemind();
	void  PurgeDiary();
	void  PurgeMemo();
	void  PurgeTimeRemind();

	void  AddDateRemind(CDateRemind dateRemind);
	void  AddDiary(CDiary diary);
	void  AddMemo(CMemo memo);
	void  AddTimeRemind(CTimeRemind timeRemind);

	void  RemoveDateRemind(CDateRemind CDateRemind);
	void  RemoveDiary(CDiary diary);
	void  RemoveMemo(CMemo memo);
	void  RemoveTimeRemind(CTimeRemind timeRemind);

	void  UpdateDateRemind(CDateRemind CDateRemind);
	void  UpdateDiary(CDiary diary);
	void  UpdateMemo(CMemo memo);
	void  UpdateTimeRemind(CTimeRemind timeRemind);

	void GetAllDiary(CDiary*& list);
	void GetAllMemo(CMemo*& list);
	void GetAllTimeRemind(CTimeRemind*& list);
	void GetAllDateRemind(CDateRemind*& list);
	void GetAllHoliday(CHoliday*& list);

	int CountAllDiary();
	int CountAllMemo();
	int CountAllTimeRemind();
	int CountAllDateRemind();
	int CountAllHoliday();

	bool ExistDiary(CDiary diary);
	bool ExistMemo(CMemo memo);
	bool ExistTimeRemind(CTimeRemind timeRemind);
	bool ExistDateRemind(CDateRemind dateRemind);		
};

