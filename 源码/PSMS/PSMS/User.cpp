#include "StdAfx.h"
#include "User.h"


CUser::CUser(void)
{
}


CUser::~CUser(void)
{
}

CString CUser::GetUserPassword(CString name)
{
	m_szPassword=usrDA.GetUserPassword(name);
	return m_szPassword;
}
bool CUser::ExistUser(CString name)
{
	m_ExistUser=usrDA.ExistUser(name);
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




void CUser::GetAllDiary(CDiary*& list)
{
}

void CUser::GetAllMemo(CMemo*& list)
{
}

void CUser::GetAllTimeRemind(CTimeRemind*& list)
{
}

void CUser::GetAllDateRemind(CDateRemind*& list)
{
}

void CUser::GetAllHoliday(CHoliday*& list)
{
}



int CUser::CountAllDiary()
{return 0;
}

int CUser::CountAllMemo()
{return 0;
}

int CUser::CountAllTimeRemind()
{return 0;
}

int CUser::CountAllDateRemind()
{return 0;
}

int CUser::CountAllHoliday()
{return 0;
}




bool CUser:: ExistDiary(CDiary diary)
{
	return false;
}

bool CUser:: ExistMemo(CMemo memo)
{
	return false;
}

bool CUser:: ExistTimeRemind(CTimeRemind timeRemind)
{
	return false;
}

bool CUser:: ExistDateRemind(CDateRemind dateRemind)
{
	return false;
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