#include "StdAfx.h"
#include "User.h"


CUser::CUser(void)
{
}


CUser::~CUser(void)
{
}

CString CUser::GetUserPassword(CString name)
{m_szPassword=usrDA.GetUserPassword(name);
 return m_szPassword;
}
bool CUser::ExistUser(CString name)
{m_ExistUser=usrDA.ExistUser(name);
 return m_ExistUser;
}

void CUser::AddDiary(CDiary diary)
{
}

void CUser::AddMemo(CMemo memo)
{
}

void CUser::AddTimeRemind(CTimeRemind timeRemind)
{
}

void CUser::AddDateRemind(CDateRemind dateRemind)
{
}




void CUser::RemoveDiary(CDiary diary)
{
}

void CUser::RemoveMemo(CMemo memo)
{
}

void CUser::RemoveTimeRemind(CTimeRemind timeRemind)
{
}


void CUser::RemoveDateRemind(CDateRemind dateRemiind)
{
}







void CUser::UpdateDiary(CDiary diary)
{
}

void CUser::UpdateMemo(CMemo memo)
{
}

void CUser::UpdateDateRemind(CDateRemind dateRemind)
{
}

void CUser::UpdateTimeRemind(CTimeRemind timeRemind)
{
}







CRecordList CUser::GetAllDiary()
{
	return list;
}

CRecordList CUser::GetAllMemo()
{
	return list;
}

CRecordList CUser::GetAllTimeRemind()
{
	return list;
}

CRecordList CUser::GetAllDateRemind()
{
	return list;
}

CRecordList CUser::GetAllHoliday()
{
	return list;
}







void CUser::PurgeDiary()
{
}

void CUser::PurgeMemo()
{
}

void CUser::PurgeTimeRemind()
{
}

void CUser::PurgeDateRemind()
{
}