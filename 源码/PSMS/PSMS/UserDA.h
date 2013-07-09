#pragma once
#include "stdafx.h"
#include "Record.h"
#include "TimeRemind.h"
#include "DateRemind.h"
#include "Memo.h"
#include "Diary.h"
#include "Holiday.h"
#include "RecordList.h"

class CUserDA
{
private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
public:
	CUserDA(void);
	~CUserDA(void);
	bool InitConnection();
	void test();
	void CreateTable(CString tableName);

	void AddDiary(CDiary diary);
	void AddMemo(CMemo memo);
	void AddTimeRemind(CTimeRemind timeRemind);
	void AddDateRemind(CDateRemind dateRemind);
	void AddUser(CString name, CString password);

	void RemoveDiary(CDiary diary);
	void RemoveMemo(CMemo memo);
	void RemoveTimeRemind(CTimeRemind timeRemind);
	void RemoveDateRemind(CDateRemind dateRemiind);

	void UpdateDiary(CDiary diary);
	void UpdateMemo(CMemo memo);
	void UpdateTimeRemind(CTimeRemind timeRemind);
	void UpdateDateRemind(CDateRemind dateRemind);
	void UpdatePassword(CString name, CString password);

	void GetAllDiary(CDiary*& list, CString user);
	void GetAllMemo(CMemo*& list, CString user);
	void GetAllTimeRemind(CTimeRemind*& list, CString user);
	void GetAllDateRemind(CDateRemind*& list, CString user);
	void GetAllHoliday(CHoliday*& list);

	int CountAllDiary(CString user);
	int CountAllMemo(CString user);
	int CountAllTimeRemind(CString user);
	int CountAllDateRemind(CString user);
	int CountAllHoliday();

	void PurgeDiary(CString user);
	void PurgeMemo(CString user);
	void PurgeTimeRemind(CString user);
	void PurgeDateRemind(CString user);

	bool ExistDiary(CDiary diary);
	bool ExistMemo(CMemo memo);
	bool ExistTimeRemind(CTimeRemind timeRemind);
	bool ExistDateRemind(CDateRemind dateRemind);

	CString GetUserPassword(CString name);
	bool ExistUser(CString name);

	void ExcuteSql(CString sql);
};

