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
	CRecordList list;
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

	void RemoveDiary(CDiary diary);
	void RemoveMemo(CMemo memo);
	void RemoveTimeRemind(CTimeRemind timeRemind);
	void RemoveDateRemind(CDateRemind dateRemiind);

	void UpdateDiary(CDiary diary);
	void UpdateMemo(CMemo memo);
	void UpdateTimeRemind(CTimeRemind timeRemind);
	void UpdateDateRemind(CDateRemind dateRemind);

	CRecordList GetAllDiary();
	CRecordList GetAllMemo();
	CRecordList GetAllTimeRemind();
	CRecordList GetAllDateRemind();
	CRecordList GetAllHoliday();

	void PurgeDiary();
	void PurgeMemo();
	void PurgeTimeRemind();
	void PurgeDateRemind();

	bool ExistDiary(CDiary diary);
	bool ExistMemo(CMemo memo);
	bool ExistTimeRemind(CTimeRemind timeRemind);
	bool ExistDateRemind(CDateRemind dateRemind);

	CString GetUserPassword(CString name);
	

	void ExcuteSql(CString sql);

};

