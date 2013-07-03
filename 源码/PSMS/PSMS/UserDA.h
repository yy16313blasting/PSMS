#pragma once
#include "stdafx.h"
#include "Record.h"
#include "TimeRemind.h"
#include "DateRemind.h"
#include "Memo.h"
#include "Diary.h"
#include "Holiday.h"

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
	CRecord AddDiary(CDiary diary);
	CRecord AddMemo(CMemo memo);
	CRecord AddTimeRemind(CTimeRemind timeRemind);
	CRecord AddDateRemind(CDateRemind dateRemind);

	CRecord RemoveDiary(CDiary diary);
	CRecord RemoveMemo(CMemo memo);
	CRecord RemoveTimeRemind(CTimeRemind timeRemind);
	CRecord RemoveDateRemind(CDateRemind dateRemiind);

	CRecord UpdateDiary(CDiary diary);
	CRecord UpdateMemo(CMemo memo);
	CRecord UpdateTimeRemind(CTimeRemind timeRemind);
	CRecord UpdateDateRemind(CDateRemind dateRemind);


};

