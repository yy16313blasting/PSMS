#pragma once
#include "stdafx.h"
#include "Record.h"
#include "TimeRemind.h"
#include "DateRemind.h"
#include "Memo.h"
#include "Diary.h"
#include "Holiday.h"
#include "RecordList.h"
class CUser
{
		private:
			 CString m_szName;
			 CString m_szPassword;
			 BOOL  isOnline;
 
		public:
			CUser(void);
			~CUser(void);
			CString GetName();
			CString GetPassword();
			void  PurgeCDateRemind();
			void  PurgeDiary();
			void  PurgeMemo();
			void  PurgeTimeRemind();
			CRecord  AddCDateRemind(CDateRemind dateRemind);
			CRecord  AddDiary(CDiary diary);
			CRecord  AddMemo(CMemo memo);
			CRecord  AddTimeRemind(CTimeRemind timeRemind);
			CRecord  RemoveCDateRemind(CDateRemind CDateRemind);
			CRecord  RemoveDiary(CDiary diary);
			CRecord  RemoveMemo(CMemo memo);
			CRecord  RemoveTimeRemind(CTimeRemind timeRemind);
			CRecord  UpdateCDateRemind(CDateRemind CDateRemind);
			CRecord  UpdateDiary(CDiary diary);
			CRecord  UpdateMemo(CMemo memo);
			CRecord  UpdateTimeRemind(CTimeRemind timeRemind);
			CRecordList GetAllCDateRemind();
			CRecordList GetAllDiary();
			CRecordList GetAllMemo();
			CRecordList GetAllTimeRemind();

};

