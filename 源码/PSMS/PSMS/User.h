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
             CRecordList list;
		public:
			CUser(void);
			~CUser(void);
			CString GetName();
			CString GetPassword();

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

			CRecordList GetAllDateRemind();
			CRecordList GetAllDiary();
			CRecordList GetAllMemo();
			CRecordList GetAllTimeRemind();
			CRecordList GetAllHoliday();
};

